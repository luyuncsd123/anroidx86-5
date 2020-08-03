/*
 * Copyright © 2014-2017 Intel Corporation
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sub license, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice (including the
 * next paragraph) shall be included in all copies or substantial portions
 * of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT.
 * IN NO EVENT SHALL PRECISION INSIGHT AND/OR ITS SUPPLIERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

/*
 * This file defines some vp8 probability tables, and
 * they are ported from libvpx (https://github.com/mrchapp/libvpx/).
 * The original copyright and licence statement as below.
 */

/*
 *  Copyright (c) 2010 The WebM project authors. All Rights Reserved.
 *
 *  Use of this source code is governed by a BSD-style license
 *  that can be found in the LICENSE file in the root of the source
 *  tree. An additional intellectual property rights grant can be found
 *  in the file PATENTS.  All contributing project authors may
 *  be found in the AUTHORS file in the root of the source tree.
 */

#ifndef VP8_PROBS_H
#define VP8_PROBS_H

extern const unsigned char vp8_ymode_prob[4];

extern const unsigned char vp8_kf_ymode_prob[4];

extern const unsigned char vp8_uv_mode_prob[3];

extern const unsigned char vp8_kf_uv_mode_prob[3];

extern const unsigned char vp8_base_skip_false_prob[128];

extern const unsigned char vp8_mv_update_probs[2][19];

extern const unsigned char vp8_default_mv_context[2][19];

extern const unsigned char vp8_default_coef_probs[4][8][3][11];

extern const int vp8_bits_per_mb[2][128];

extern const unsigned short vp8_prob_cost[256];

extern const unsigned char vp8_coef_update_probs[4][8][3][11];

extern const unsigned char vp8_probs_update_flag[4][8][3][11];

#endif /* _VP8_PROBS_H_ */
