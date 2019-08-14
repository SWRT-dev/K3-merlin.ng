#include "common.h"
#include "config.h"
#include "frame.h"
#include "gpio.h"
#include "handlers.h"
#include "infocenter.h"
#include "logging.h"
#include "mcu_proto.h"
#include "mem_util.h"
#include "pages.h"
#include "requests.h"
#include "serial_port.h"
#include "signals.h"
#include "hwdef.h"
#include "firmware_upgrade.h"
#include <errno.h>
#include <poll.h>
#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <unistd.h>
#if defined(BCMARM)
#include <shared.h>
#endif

static void frame_handler(const unsigned char *frame, int len) {
    if (frame[0] != FRAME_APP) {
        syslog(LOG_WARNING, "frame with unknown type received: %hhx\n",
               frame[0]);
        return;
    }
    extern RESPONSE_HANDLER g_response_handlers[];
    for (RESPONSE_HANDLER *handler = &g_response_handlers[0]; handler != NULL;
         handler++) {
        if (handler->type == frame[1]) {
            handler->handler(frame + 2,
                             len - 2); /* Start from payload content */
            return;
        }
    }

    syslog(LOG_WARNING, "frame with unknown response type received: %hhx\n",
           frame[1]);
}

static int screen_initialize(int skip_reset, int enter_dfu) {
    int boot_gpio = !!enter_dfu;
#if defined(BCMARM)
	system("devmem 0x1800c1c1 32 0x00001f0f");
#else
    mask_memory_byte(0x1800c1c1, 0xf0, 0); /* Enable UART2 in DMU */
#endif
    if (!skip_reset) {
#if defined(BCMARM)
		if (set_gpio(SCREEN_BOOT_MODE_GPIO, boot_gpio) == FAILURE ||
			set_gpio(SCREEN_RESET_GPIO, 0) == FAILURE ||
			set_gpio(SCREEN_RESET_GPIO, 1) == FAILURE) {
			syslog(LOG_ERR, "Could not reset screen\n");
			return FAILURE;
		}
#else
        if (gpio_export(SCREEN_BOOT_MODE_GPIO) == FAILURE ||
            gpio_export(SCREEN_RESET_GPIO) == FAILURE) {
            syslog(LOG_ERR, "Could not export GPIOs\n");
            return FAILURE;
        }

        if (gpio_set_direction(SCREEN_BOOT_MODE_GPIO, GPIO_OUT) == FAILURE ||
            gpio_set_direction(SCREEN_RESET_GPIO, GPIO_OUT) == FAILURE) {
            syslog(LOG_ERR, "Could not set GPIO direction\n");
            return FAILURE;
        }

        if (gpio_set_value(SCREEN_BOOT_MODE_GPIO, boot_gpio) == FAILURE ||
            gpio_set_value(SCREEN_RESET_GPIO, 0) == FAILURE ||
            gpio_set_value(SCREEN_RESET_GPIO, 1) == FAILURE) {
            syslog(LOG_ERR, "Could not reset screen\n");
            return FAILURE;
        }
#endif
	}
    return SUCCESS;
}

/* Parameters here are too ugly */
void pollin_loop(int serial_fd, int signal_fd) {
    struct pollfd fds[2];
    fds[0].fd = serial_fd;
    fds[0].events = POLLIN;
    fds[1].fd = signal_fd;
    fds[1].events = POLLIN;

    while (1) {
        int readyfds = poll(fds, sizeof(fds) / sizeof(struct pollfd),
                            SERIAL_POLL_INTERVAL_MS);
        if (readyfds < 0) {
            syslog(LOG_ERR, "poll() failed: %s", strerror(errno));
            return;
        } else if (readyfds > 0) {
            if (fds[0].revents & POLLIN) {
                frame_notify_serial_recv();
            } else if (fds[1].revents & POLLIN) {
                signal_notify();
            }
        }
    }
}

void cleanup() {
    serial_close();
    config_free();
    syslog_stop();
}

int main(int argc, char *argv[]) {
    int signal_fd;
    int serial_fd;
    int boot_mode = BOOT_MODE_APP;

    atexit(cleanup);

    config_load_defaults();
    config_parse_cmdline(argc, argv);
    if (CFG->firmware_path[0] != '\0') {
        boot_mode = BOOT_MODE_BOOTLOADER;
    }

    syslog_setup(CFG->foreground);

    update_all_info();

    if (CFG->test_mode) {
        print_all_info();
        return 0;
    }

    if (screen_initialize(CFG->skip_reset, boot_mode) == FAILURE) {
        return -EIO;
    }

    if ((serial_fd = serial_setup(SERIAL_PORT_PATH)) < 0) {
        return -EIO;
    }

    if ((signal_fd = signal_setup()) < 0) {
        return -EIO;
    }

    if (boot_mode == BOOT_MODE_APP) {
        frame_set_received_callback(frame_handler);
        request_mcu_version();
        page_send_initial_data();
        refresh_screen_timeout();
        alarm(CFG->update_interval);
    } else if (boot_mode == BOOT_MODE_BOOTLOADER) {
        /* Make it handle everything */
        fwupgrade_start();
    }

    pollin_loop(serial_fd, signal_fd);
}
