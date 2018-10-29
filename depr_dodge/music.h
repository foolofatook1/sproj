/** 
 * Trying to figure out how to work with music registers in gbdk. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>

void collide_sound(void);

UBYTE sound_on = 1;

void collide_sound(void)
{
    // int i  = 0;
    // while(i<10000)
    //{
    if(sound_on)
    {
        NR52_REG = 0x80;
        NR51_REG = 0x11;
        NR50_REG = 0x77;

        NR10_REG = 0xF7;
        NR11_REG = 0x80;
        NR12_REG = 0xF0;
        NR13_REG = 0xB8;
        NR14_REG = 0xC1;
    }
    /*     ++i;
           }
           i=0;
           while(i<50000)
           {++i;}
           i=0;
           while(i<10000)
           {
           NR52_REG = 0x80;
           NR51_REG = 0x11;
           NR50_REG = 0x77;

           NR10_REG = 0xF7;
           NR11_REG = 0x80;
           NR12_REG = 0xF0;
           NR13_REG = 0xB8;
           NR14_REG = 0xC1;
           ++i;
           }
           i=0;
           while(i<1000)
           {
           NR52_REG = 0x80;
           NR51_REG = 0x11;
           NR50_REG = 0x77;

           NR10_REG = 0xF7;
           NR11_REG = 0x80;
           NR12_REG = 0xF0;
           NR13_REG = 0xB8;
           NR14_REG = 0xC1;
           ++i;
           }
           i=0;
           while(i<10000)
           {
           NR52_REG = 0x80;
           NR51_REG = 0x11;
           NR50_REG = 0x77;

           NR10_REG = 0xF7;
           NR11_REG = 0x80;
           NR12_REG = 0xF0;
           NR13_REG = 0xB8;
           NR14_REG = 0xC1;
           ++i;
           }

           while(i<20000)
           {

           NR10_REG = 0xF7;
           NR11_REG = 0x80;
           NR12_REG = 0xF0;
           NR13_REG = 0x70;
           NR14_REG = 0xC3;
           ++i;
           }
           while(i<30000)
           {
           NR10_REG = 0xF7;
           NR11_REG = 0x80;
           NR12_REG = 0xF0;
           NR13_REG = 0x28;
           NR14_REG = 0xc5;
           ++i;
           }*/

}
