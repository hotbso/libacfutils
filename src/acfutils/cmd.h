/*
 * CDDL HEADER START
 *
 * This file and its contents are supplied under the terms of the
 * Common Development and Distribution License ("CDDL"), version 1.0.
 * You may only use this file in accordance with the terms of version
 * 1.0 of the CDDL.
 *
 * A full copy of the text of the CDDL should have accompanied this
 * source.  A copy of the CDDL is also available via the Internet at
 * http://www.illumos.org/license/CDDL.
 *
 * CDDL HEADER END
*/
/*
 * Copyright 2017 Saso Kiselkov. All rights reserved.
 */

#ifndef	_ACFUTILS_CMD_H_
#define	_ACFUTILS_CMD_H_

#include <stdarg.h>
#include <XPLMUtilities.h>
#include <acfutils/types.h>

#ifdef	__cplusplus
extern "C" {
#endif

typedef int (*cmd_cb_t)(XPLMCommandRef ref, XPLMCommandPhase phase,
    void *refcon);

API_EXPORT XPLMCommandRef cmd_bind(const char *fmt, cmd_cb_t cb,
    bool_t before, void *refcon, ...);
API_EXPORT XPLMCommandRef cmd_bind_v(const char *fmt, cmd_cb_t cb,
    bool_t before, void *refcon, va_list ap);
API_EXPORT XPLMCommandRef fcmd_bind(const char *fmt, cmd_cb_t cb,
    bool_t before, void *refcon, ...);

API_EXPORT bool_t cmd_unbind(const char *fmt, cmd_cb_t cb, bool_t before,
    void *refcon, ...);
API_EXPORT bool_t cmd_unbind_v(const char *fmt, cmd_cb_t cb, bool_t before,
    void *refcon, va_list ap);
API_EXPORT void fcmd_unbind(const char *fmt, cmd_cb_t cb, bool_t before,
    void *refcon, ...);

#ifdef	__cplusplus
}
#endif

#endif	/* _ACFUTILS_CMD_H_ */
