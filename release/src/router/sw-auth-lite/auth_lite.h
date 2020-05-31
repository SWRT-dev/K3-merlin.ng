 /*
 * Copyright 2020, paldier <paldier@hotmail.com>.
 * All Rights Reserved.
 *
 */

#ifndef _auth_lite_h_
#define _auth_lite_h_

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <unistd.h>

#define SW_AUTH_LITE_DEBUG             "/tmp/SW_AUTH_LITE_DEBUG"
#define AUTH_DBG(fmt,args...) \
	if(f_exists(SW_AUTH_LITE_DEBUG) > 0) { \
		printf("[SW_AUTH_LITE][%s:(%d)]"fmt, __FUNCTION__, __LINE__, ##args); \
	}

extern void auth_key(const char *time, char out[48]);

extern void encrypt_key(const char *time, char out[48]);
#endif
