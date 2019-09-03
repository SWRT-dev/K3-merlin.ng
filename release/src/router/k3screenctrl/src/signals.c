#include <errno.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/signalfd.h>
#include <syslog.h>
#include <time.h>
#include <unistd.h>

#include "config.h"
#include "mcu_proto.h"
#include "pages.h"
#include "requests.h"
#include "firmware_upgrade.h"

static int g_signal_fd;

int signal_setup() {
    sigset_t mask;

    sigemptyset(&mask);
    sigaddset(&mask, SIGALRM); // Timed update
    sigaddset(&mask, SIGTERM); // Router reboot
    sigaddset(&mask, SIGUSR1); // Factory reset
    sigaddset(&mask, SIGUSR2); // Firmware update

    /* Block in order to prevent default disposition */
    if (sigprocmask(SIG_BLOCK, &mask, NULL) == -1) {
        syslog(LOG_WARNING, "could not block signals: %s\n", strerror(errno));
    }

    g_signal_fd = signalfd(-1, &mask, 0);
    if (g_signal_fd < 0) {
        syslog(LOG_WARNING, "could not set up signal fd: %s\n",
               strerror(errno));
    }

    return g_signal_fd;
}

static time_t g_last_check_time;
void refresh_screen_timeout() { g_last_check_time = time(NULL); }

extern int g_is_screen_on;
static void check_screen_timeout() {
    if (CFG->screen_timeout != 0 &&
        time(NULL) - g_last_check_time >= CFG->screen_timeout && g_is_screen_on != 0) {
        g_is_screen_on = 0; /* Do not process key messages - just wake up if there are any */
	page_switch_to(PAGE_BASIC_INFO);//page wan have a bug
        request_notify_event(EVENT_SLEEP);
    }
}

void signal_notify() {
    struct signalfd_siginfo siginfo;
    if (read(g_signal_fd, &siginfo, sizeof(siginfo)) <= 0) {
        syslog(LOG_WARNING,
               "could not read from signalfd, signal ignored: %s\n",
               strerror(errno));
        return;
    }

    /* Signal handling is completely different in firmware upgrades.
     */
    if (CFG->firmware_path[0] != '\0') {
        fwupgrade_notify_signal(siginfo.ssi_signo);
        return;
    }

    switch (siginfo.ssi_signo) {
    case SIGALRM:
        page_update();
        page_refresh();
        check_screen_timeout();
        alarm(CFG->update_interval);
        break;
    case SIGTERM:
        request_notify_event(EVENT_REBOOT);
        exit(0);
        break;
    case SIGUSR1:
        request_notify_event(EVENT_RESET);
        break;
    case SIGUSR2:
        request_notify_event(EVENT_UPGRADE);
        break;
    default:
        syslog(LOG_INFO, "someone forgot to add his signal (%d) handler here\n",
               siginfo.ssi_signo);
        break;
    }
}
