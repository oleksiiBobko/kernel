#ifndef __VIDEO_H
#define __VIDEO_H

#include "types.h"

void video_putchar(int32 x, int32 y, uint8 code);
void video_flood(int32 x, int32 y, int32 width, int32 height, uint8 code);
void video_update();
void video_initialize();

#endif
