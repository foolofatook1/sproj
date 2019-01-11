/** 
 * Trying to figure out how to work with music registers in gbdk. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>

void collide_sound(void);

void collide_sound(void)
{
	while(1)
	{
        NR52_REG = 0x80; /* All sound on/off. */
        NR51_REG = 0x11; /* Selection of Sound output terminal (R/W). */
        NR50_REG = 0x77; /* Channel control / ON-OFF / Volume (R/W). */

		/* Sound Mode 1 register. */
        NR10_REG = 0x00; /* Sweep reigister (R/W). */
        NR11_REG = 0x87; /* Sound length/Wave pattern duty (R/W). */
        NR12_REG = 0xf7; /* Envelope (R/W). */
        NR13_REG = 0xb8; /* Frequency lo (W). */
        NR14_REG = 0xb1; /* Frequency hi (R/W). */
	}
}

void main(void)
{
    collide_sound();
}
