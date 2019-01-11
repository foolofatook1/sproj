#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>

/* My function for setting up things on the screen. */
#include "lcdc.h"

void main(void)
{
    setup_sprites();
    bkg();

    while(1)
    {
        sprite_walk();
        display_sprites();
        wait_vbl_done();
    }
}
