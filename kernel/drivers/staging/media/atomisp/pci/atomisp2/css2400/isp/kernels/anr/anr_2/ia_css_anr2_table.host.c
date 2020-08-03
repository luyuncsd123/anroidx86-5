/*
 * Support for Intel Camera Imaging ISP subsystem.
 * Copyright (c) 2015, Intel Corporation.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 */

#include "system_global.h"
#include "ia_css_types.h"
#include "ia_css_anr2_table.host.h"

#if 1
const struct ia_css_anr_thres default_anr_thres = {
{128, 384, 640, 896, 896, 640, 384, 128, 384, 1152, 1920, 2688, 2688, 1920, 1152, 384, 640, 1920, 3200, 4480, 4480, 3200, 1920, 640, 896, 2688, 4480, 6272, 6272, 4480, 2688, 896, 896, 2688, 4480, 6272, 6272, 4480, 2688, 896, 640, 1920, 3200, 4480, 4480, 3200, 1920, 640, 384, 1152, 1920, 2688, 2688, 1920, 1152, 384, 128, 384, 640, 896, 896, 640, 384, 128,
0, 0, 30, 30, 10, 10, 20, 20, 0, 0, 30, 30, 10, 10, 20, 20, 0, 0, 30, 30, 10, 10, 20, 20, 0, 0, 30, 30, 10, 10, 20, 20, 0, 0, 30, 30, 10, 10, 20, 20, 0, 0, 30, 30, 10, 10, 20, 20, 0, 0, 30, 30, 10, 10, 20, 20, 0, 0, 30, 30, 10, 10, 20, 20,
0, 0, 60, 60, 20, 20, 40, 40, 0, 0, 60, 60, 20, 20, 40, 40, 0, 0, 60, 60, 20, 20, 40, 40, 0, 0, 60, 60, 20, 20, 40, 40, 0, 0, 60, 60, 20, 20, 40, 40, 0, 0, 60, 60, 20, 20, 40, 40, 0, 0, 60, 60, 20, 20, 40, 40, 0, 0, 60, 60, 20, 20, 40, 40,
0, 0, 90, 90, 30, 30, 60, 60, 0, 0, 90, 90, 30, 30, 60, 60, 0, 0, 90, 90, 30, 30, 60, 60, 0, 0, 90, 90, 30, 30, 60, 60, 0, 0, 90, 90, 30, 30, 60, 60, 0, 0, 90, 90, 30, 30, 60, 60, 0, 0, 90, 90, 30, 30, 60, 60, 0, 0, 90, 90, 30, 30, 60, 60,
30, 30, 60, 60, 40, 40, 50, 50, 30, 30, 60, 60, 40, 40, 50, 50, 30, 30, 60, 60, 40, 40, 50, 50, 30, 30, 60, 60, 40, 40, 50, 50, 30, 30, 60, 60, 40, 40, 50, 50, 30, 30, 60, 60, 40, 40, 50, 50, 30, 30, 60, 60, 40, 40, 50, 50, 30, 30, 60, 60, 40, 40, 50, 50,
60, 60, 120, 120, 80, 80, 100, 100, 60, 60, 120, 120, 80, 80, 100, 100, 60, 60, 120, 120, 80, 80, 100, 100, 60, 60, 120, 120, 80, 80, 100, 100, 60, 60, 120, 120, 80, 80, 100, 100, 60, 60, 120, 120, 80, 80, 100, 100, 60, 60, 120, 120, 80, 80, 100, 100, 60, 60, 120, 120, 80, 80, 100, 100,
90, 90, 180, 180, 120, 120, 150, 150, 90, 90, 180, 180, 120, 120, 150, 150, 90, 90, 180, 180, 120, 120, 150, 150, 90, 90, 180, 180, 120, 120, 150, 150, 90, 90, 180, 180, 120, 120, 150, 150, 90, 90, 180, 180, 120, 120, 150, 150, 90, 90, 180, 180, 120, 120, 150, 150, 90, 90, 180, 180, 120, 120, 150, 150,
10, 10, 40, 40, 20, 20, 30, 30, 10, 10, 40, 40, 20, 20, 30, 30, 10, 10, 40, 40, 20, 20, 30, 30, 10, 10, 40, 40, 20, 20, 30, 30, 10, 10, 40, 40, 20, 20, 30, 30, 10, 10, 40, 40, 20, 20, 30, 30, 10, 10, 40, 40, 20, 20, 30, 30, 10, 10, 40, 40, 20, 20, 30, 30,
20, 20, 80, 80, 40, 40, 60, 60, 20, 20, 80, 80, 40, 40, 60, 60, 20, 20, 80, 80, 40, 40, 60, 60, 20, 20, 80, 80, 40, 40, 60, 60, 20, 20, 80, 80, 40, 40, 60, 60, 20, 20, 80, 80, 40, 40, 60, 60, 20, 20, 80, 80, 40, 40, 60, 60, 20, 20, 80, 80, 40, 40, 60, 60,
30, 30, 120, 120, 60, 60, 90, 90, 30, 30, 120, 120, 60, 60, 90, 90, 30, 30, 120, 120, 60, 60, 90, 90, 30, 30, 120, 120, 60, 60, 90, 90, 30, 30, 120, 120, 60, 60, 90, 90, 30, 30, 120, 120, 60, 60, 90, 90, 30, 30, 120, 120, 60, 60, 90, 90, 30, 30, 120, 120, 60, 60, 90, 90,
20, 20, 50, 50, 30, 30, 40, 40, 20, 20, 50, 50, 30, 30, 40, 40, 20, 20, 50, 50, 30, 30, 40, 40, 20, 20, 50, 50, 30, 30, 40, 40, 20, 20, 50, 50, 30, 30, 40, 40, 20, 20, 50, 50, 30, 30, 40, 40, 20, 20, 50, 50, 30, 30, 40, 40, 20, 20, 50, 50, 30, 30, 40, 40,
40, 40, 100, 100, 60, 60, 80, 80, 40, 40, 100, 100, 60, 60, 80, 80, 40, 40, 100, 100, 60, 60, 80, 80, 40, 40, 100, 100, 60, 60, 80, 80, 40, 40, 100, 100, 60, 60, 80, 80, 40, 40, 100, 100, 60, 60, 80, 80, 40, 40, 100, 100, 60, 60, 80, 80, 40, 40, 100, 100, 60, 60, 80, 80,
60, 60, 150, 150, 90, 90, 120, 120, 60, 60, 150, 150, 90, 90, 120, 120, 60, 60, 150, 150, 90, 90, 120, 120, 60, 60, 150, 150, 90, 90, 120, 120, 60, 60, 150, 150, 90, 90, 120, 120, 60, 60, 150, 150, 90, 90, 120, 120, 60, 60, 150, 150, 90, 90, 120, 120, 60, 60, 150, 150, 90, 90, 120, 120}
};
#else
const struct ia_css_anr_thres default_anr_thres = {
{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
#endif
