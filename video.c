/*
 * =====================================================================================
 *
 *       Filename:  video.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/19/2015 09:32:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  oleksii bobko (none), skellag@gmail.com
 *        Company:  free icecream
 *
 * =====================================================================================
 */
#include "video.h"

#include "io.h"
#include "types.h"
#include "memory.h"

static unit8 video_attr=18;
static unit8 *videohidden = 0;

void video_putchar(int32 x, int32 y, uint8 code)
{
    if((x < 0) || (y < 0) || (x>=80) || (y >=25)) return;
    videohidden[(y*80+x)*2] = code;
    videohidden[(y*80+x)*2+1] = video_attr;
};

void video_flood(int32 x, int32 y, int32 width, int32 height, uint8 code)
{
   int32 a, b;

   for(a = x; a < x+width; ++a)
     for(b=y; b < y+height; ++b)
      video_putchar(a, b, code);
};

void video_update()
{
  memcpy((uint8)0xb8000, videohidden, 80*25*2);
};

void video_initialize()
{
   videohidden = malloc(80*25*2);
};
