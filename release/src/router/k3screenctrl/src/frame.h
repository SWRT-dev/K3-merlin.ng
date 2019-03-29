#ifndef _FRAME_TX_H
#define _FRAME_TX_H
#include "mcu_proto.h"

/*
 * Send payload to serial port.
 * Only raw data (PAYLOAD_*) and FRAME_TYPE needs to be given, header + CRC +
 * trailer + escaping will be added automatically.
 */
int frame_send(FRAME_TYPE type, const unsigned char* data, int len);

/*
 * Callback when a complete frame is received and validated by checksum.
 *
 * The prototype is:
 * void callback(const unsigned char* frame, int len);
 *
 * The `frame` contains unescaped FRAME_TYPE + PAYLOAD_* + CRC.
 */
void frame_set_received_callback(void (*func)(const unsigned char*, int));

/*
 * Should be set in serial_set_pollin_callback()
 */
void frame_notify_serial_recv();
#endif
