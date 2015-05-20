/*
 * =====================================================================================
 *
 *       Filename:  start.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/14/2015 10:46:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  oleksii bobko (none), skellag@gmail.com
 *        Company:  free icecream
 *
 * =====================================================================================
 */
#include "start.h"
#include "video.h"
#include "types.h"

void start()
{
      video_initialize();
      debug('1');
      video_flood(10,10,20,20,48);
      debug('2');
      video_putchar(20,20,48);
      debug('3');
      video_update();
      debug('4');
};

void debug(uint8 code)
{
char *vidptr = (char*)0xb8000;
vidptr[0] = code;
vidptr[1] = 0x12;
} 

