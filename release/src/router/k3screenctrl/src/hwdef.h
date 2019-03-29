#ifndef __HWDEF_H
#define __HWDEF_H

/*
 * Hardware definition for the screen on PHICOMM K3.
 */

/*
 * Detected on rising edge of RESET GPIO.
 * Low = Run app from ROM
 * High = Enter download mode and wait for a new app
 */
#define SCREEN_BOOT_MODE_GPIO 7
#define BOOT_MODE_APP 0
#define BOOT_MODE_BOOTLOADER 1

/*
 * Resets the screen on rising edge
 */
#define SCREEN_RESET_GPIO 8

#define SERIAL_PORT_PATH "/dev/ttyS1"

#endif
