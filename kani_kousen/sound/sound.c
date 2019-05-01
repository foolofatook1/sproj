#include "sound.h"

/**
 * f = 131072/(2048-x) Hz
 */

unsigned short freq_a = 1750; // approx 440 Hz
unsigned short freq_a_lo = 473; // apporx 110 Hz?
UINT16 q;

void text_sound(void)
{
    q = 0;
    while(q < 500)
    {
        NR50_REG = 0xFF; /* all channels on */
        NR51_REG = 0xFF; /* all sound outputs */
        NR52_REG = 0x80; /* all sound on */

        NR10_REG = 0x00; /* no sweep */
        NR11_REG = 0x30; /* sound length */
        NR12_REG = 0xF0; /* max volume */
        NR13_REG = (unsigned char)freq_a;
        NR14_REG = 0x80 | (freq_a>>8); /* start output */
        ++q;
    }

    NR12_REG = 0;
    NR14_REG = 0x80;
}

void hit_sound(void)
{
    q = 0;
    while(q < 100)
    {
        NR50_REG = 0xFF;
        NR51_REG = 0xFF;
        NR52_REG = 0x80;

        NR10_REG = 0x7F;
        NR11_REG = 0x1D;
        NR12_REG = (unsigned char)freq_a_lo;
        NR13_REG = 0xF0;
        NR14_REG = 0x80 | (8>>freq_a_lo);
        ++q;

    }
    NR12_REG = 0;
    NR14_REG = 0x80;

}

/*void main(void)
{
    while(1)
    {
        if(joypad() & J_A)
            text_sound(); // sound you want to test goes here
    }
}*/
