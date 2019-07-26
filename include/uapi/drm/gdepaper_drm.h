/* SPDX-License-Identifier: GPL-2.0+ WITH Linux-syscall-note */
/* gdepaper_drm.h
 *
 * Copyright (c) 2019 Jan Sebastian Götte
 */

#ifndef _UAPI_GDEPAPER_DRM_H_
#define _UAPI_GDEPAPER_DRM_H_

#include "drm.h"

#if defined(__cplusplus)
extern "C" {
#endif

/* Immediately load new LUTs to the panel and switch from OTP ROM to the newly
 * loaded RAM LUTs. */
struct gdepaper_luts {
	__u8 lut_vcom_dc[44];
	__u8 lut_ww[42];
	__u8 lut_bw[42];
	__u8 lut_bb[42];
	__u8 lut_wb[42];
};

/* Force a full display refresh */
#define DRM_GDEPAPER_FORCE_FULL_REFRESH		0x00
#define DRM_GDEPAPER_LOAD_LUTS_IMM		0x01
#define DRM_GDEPAPER_SET_PARTIAL_UPDATE_EN	0x02

#define DRM_IOCTL_GDEPAPER_FORCE_FULL_REFRESH \
	DRM_IO(DRM_COMMAND_BASE + DRM_GDEPAPER_FORCE_FULL_REFRESH)
#define DRM_IOCTL_GDEPAPER_LOAD_LUTS_IMM \
	DRM_IOR(DRM_COMMAND_BASE + DRM_GDEPAPER_LOAD_LUTS_IMM, \
	struct gdepaper_luts)
#define DRM_IOCTL_GDEPAPER_SET_PARTIAL_UPDATE_EN \
	DRM_IOR(DRM_COMMAND_BASE + DRM_GDEPAPER_SET_PARTIAL_UPDATE_EN, __u32)

#if defined(__cplusplus)
}
#endif

#endif /* _UAPI_GDEPAPER_DRM_H_ */
