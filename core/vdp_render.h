/***************************************************************************************
 *  Genesis Plus
 *  Video Display Processor (pixel output rendering)
 *
 *  Support for all TMS99xx modes, Mode 4 & Mode 5 rendering
 *
 *  Copyright (C) 1998, 1999, 2000, 2001, 2002, 2003  Charles Mac Donald (original code)
 *  Copyright (C) 2007-2016  Eke-Eke (Genesis Plus GX)
 *  Copyright (C) 2022  AlexKiri (enhanced vscroll mode rendering function)
 *
 *  Redistribution and use of this code or any derivative works are permitted
 *  provided that the following conditions are met:
 *
 *   - Redistributions may not be sold, nor may they be used in a commercial
 *     product or activity.
 *
 *   - Redistributions that are modified from the original source must include the
 *     complete source code, including the source code for all components used by a
 *     binary built from the modified sources. However, as a special exception, the
 *     source code distributed need not include anything that is normally distributed
 *     (in either source or binary form) with the major components (compiler, kernel,
 *     and so on) of the operating system on which the executable runs, unless that
 *     component itself accompanies the executable.
 *
 *   - Redistributions must reproduce the above copyright notice, this list of
 *     conditions and the following disclaimer in the documentation and/or other
 *     materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************************/

#ifndef _RENDER_H_
#define _RENDER_H_

/* 3:3:2 RGB */
#if defined(USE_8BPP_RENDERING)
#define PIXEL(r,g,b) (((r) << 5) | ((g) << 2) | (b))
#define GET_R(pixel) (((pixel) & 0xe0) >> 5)
#define GET_G(pixel) (((pixel) & 0x1c) >> 2)
#define GET_B(pixel) (((pixel) & 0x03) >> 0)

/* 5:5:5 RGB */
#elif defined(USE_15BPP_RENDERING)
#if defined(USE_ABGR)
#define PIXEL(r,g,b) ((1 << 15) | ((b) << 10) | ((g) << 5) | (r))
#define GET_B(pixel) (((pixel) & 0x7c00) >> 10)
#define GET_G(pixel) (((pixel) & 0x03e0) >> 5)
#define GET_R(pixel) (((pixel) & 0x001f) >> 0)
#else
#define PIXEL(r,g,b) ((1 << 15) | ((r) << 10) | ((g) << 5) | (b))
#define GET_R(pixel) (((pixel) & 0x7c00) >> 10)
#define GET_G(pixel) (((pixel) & 0x03e0) >> 5)
#define GET_B(pixel) (((pixel) & 0x001f) >> 0)
#endif

/* 5:6:5 RGB */
#elif defined(USE_16BPP_RENDERING)
#define PIXEL(r,g,b) (((r) << 11) | ((g) << 5) | (b))
#define GET_R(pixel) (((pixel) & 0xf800) >> 11)
#define GET_G(pixel) (((pixel) & 0x07e0) >> 5)
#define GET_B(pixel) (((pixel) & 0x001f) >> 0)

/* 8:8:8 RGB */
#elif defined(USE_32BPP_RENDERING)
#define PIXEL(r,g,b) ((0xff << 24) | ((r) << 16) | ((g) << 8) | (b))
#define GET_R(pixel) (((pixel) & 0xff0000) >> 16)
#define GET_G(pixel) (((pixel) & 0x00ff00) >> 8)
#define GET_B(pixel) (((pixel) & 0x0000ff) >> 0)
#endif

#define MY_COLOR_1_1 MAKE_PIXEL(0xa, 0xc, 0xe)
#define MY_COLOR_1_2 MAKE_PIXEL(0x8, 0xa, 0xc)

#define MY_COLOR_2_1 MAKE_PIXEL(0xa, 0xc, 0xc)
#define MY_COLOR_2_2 MAKE_PIXEL(0x8, 0xa, 0xa)

#define MY_COLOR_3_1 MAKE_PIXEL(0xc, 0xa, 0xa)
#define MY_COLOR_3_2 MAKE_PIXEL(0xa, 0x8, 0x8)

#define MY_COLOR_4_1 MAKE_PIXEL(0xe, 0xa, 0x8)
#define MY_COLOR_4_2 MAKE_PIXEL(0xc, 0x6, 0x6)

#define MY_COLOR_5_1 MAKE_PIXEL(0xe, 0xa, 0x6)
#define MY_COLOR_5_2 MAKE_PIXEL(0xe, 0x6, 0x4)

#define MY_COLOR_6_1 MAKE_PIXEL(0xe, 0xa, 0x4)
#define MY_COLOR_6_2 MAKE_PIXEL(0xe, 0x6, 0x2)

#define MY_COLOR_7_1 MAKE_PIXEL(0xe, 0xa, 0x4)
#define MY_COLOR_7_2 MAKE_PIXEL(0xe, 0x6, 0x0)

#define MY_COLOR_8_1 MAKE_PIXEL(0xc, 0xc, 0x6)
#define MY_COLOR_8_2 MAKE_PIXEL(0xc, 0x8, 0x2)

#define MY_COLOR_9_1 MAKE_PIXEL(0xa, 0xc, 0x8)
#define MY_COLOR_9_2 MAKE_PIXEL(0xa, 0x8, 0x4)

#define MY_COLOR_10_1 MAKE_PIXEL(0x8, 0xc, 0xa)
#define MY_COLOR_10_2 MAKE_PIXEL(0x8, 0x8, 0x6)

#define MY_COLOR_11_1 MAKE_PIXEL(0x8, 0xc, 0xc)
#define MY_COLOR_11_2 MAKE_PIXEL(0x6, 0x8, 0x8)

#define MY_COLOR_12_1 MAKE_PIXEL(0x8, 0xc, 0xc)
#define MY_COLOR_12_2 MAKE_PIXEL(0x4, 0x8, 0x8)

#define MY_COLOR_13_1 MAKE_PIXEL(0xa, 0xc, 0xe)
#define MY_COLOR_13_2 MAKE_PIXEL(0x6, 0xa, 0xa)

/* LCD image persistence (ghosting) filter */
/* Simulates (roughly) the slow decay response time of passive-matrix LCD */
/* Rate value is formatted as 0.8 fixed-point integer (between 0.0 and 0.99609375), a higher value meaning a slower decay */
/* Required for proper display of some effects in a few Game Gear games (James Pond 3, Power Drift, Super Monaco GP II,...) */
#define RENDER_PIXEL_LCD(in,out,table,bgbuf) \
{ \
  PIXEL_OUT_T pixel_left = table[*(bgbuf-1)]; \
  PIXEL_OUT_T pixel_right = table[*(bgbuf+1)]; \
  PIXEL_OUT_T pixel_current = table[*bgbuf++]; \
  PIXEL_OUT_T pixel_out = table[*in++]; \
  PIXEL_OUT_T pixel_old  = *out; \
  uint8 r = GET_R(pixel_out); \
  uint8 g = GET_G(pixel_out); \
  uint8 b = GET_B(pixel_out); \
  uint16 rl = GET_R(pixel_left); \
  uint16 gl = GET_G(pixel_left); \
  uint16 bl = GET_B(pixel_left); \
  uint i, j, cur_idx; \
  bool should_break = false; \
  if ((pixel_left == pixel_right) && (pixel_current == pixel_out) && (pixel_left != pixel_out)) { \
    for (i = 0; i < 2 && !should_break; i++) { \
      cur_idx = (i + my_pixel_index) % 13; \
      for (j = 0; j < 2 && !should_break; j++) { \
        if (my_pixel_lut[cur_idx][j][0] == pixel_current && \
            my_pixel_lut[cur_idx][j][1] == pixel_left) { \
          r = (uint8)((r + rl) >> 1); \
          g = (uint8)((g + gl) >> 1); \
          b = (uint8)((b + bl) >> 1); \
          my_pixel_index = cur_idx; \
          should_break = true; \
        } \
      } \
    } \
  } \
  *out++ = PIXEL(r,g,b); \
}

/* Global variables */
extern uint16 spr_col;

/* Function prototypes */
extern void render_init(void);
extern void render_reset(void);
extern void render_line(int line);
extern void blank_line(int line, int offset, int width);
extern void remap_line(int line);
extern void window_clip(unsigned int data, unsigned int sw);
extern void render_bg_m0(int line);
extern void render_bg_m1(int line);
extern void render_bg_m1x(int line);
extern void render_bg_m2(int line);
extern void render_bg_m3(int line);
extern void render_bg_m3x(int line);
extern void render_bg_inv(int line);
extern void render_bg_m4(int line);
extern void render_bg_m5(int line);
extern void render_bg_m5_vs(int line);
extern void render_bg_m5_vs_enhanced(int line);
extern void render_bg_m5_im2(int line);
extern void render_bg_m5_im2_vs(int line);
extern void render_obj_tms(int line);
extern void render_obj_m4(int line);
extern void render_obj_m5(int line);
extern void render_obj_m5_ste(int line);
extern void render_obj_m5_im2(int line);
extern void render_obj_m5_im2_ste(int line);
extern void parse_satb_tms(int line);
extern void parse_satb_m4(int line);
extern void parse_satb_m5(int line);
extern void update_bg_pattern_cache_m4(int index);
extern void update_bg_pattern_cache_m5(int index);
extern void color_update_m4(int index, unsigned int data);
extern void color_update_m5(int index, unsigned int data);

/* Function pointers */
extern void (*render_bg)(int line);
extern void (*render_obj)(int line);
extern void (*parse_satb)(int line);
extern void (*update_bg_pattern_cache)(int index);

#endif /* _RENDER_H_ */
