/*
 * =====================================================================================
 *
 *       Filename:  kernel.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/23/2014 08:51:39 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  oleksii bobko (none), skellag@gmail.com
 *        Company:  free icecream
 *
 * =====================================================================================
 */

void kmain(void) {
   // char *str = "my first auto kernel!";
    char *vidptr = (char*)0xb8000;
    unsigned int i = 0;
    unsigned int j = 0;

    while(j < 80 * 25 * 2) {
       vidptr[j] = ' ';
       vidptr[j + 1] = 0x12;
       j = j + 2;
    }

    j = 0;
    
   for(i=0; i < 254; i++) {
       vidptr[i * 2] = i;
       vidptr[i * 2 + 1] = 0x12;
   }

   i = 0;

/*   while(str[j] != '\0') {
       vidptr[i] = str[j];
       vidptr[i + 1] = 0x17;
       ++j;
       i = i + 2;

    }*/
    return;

}
