#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>

#include "lcdc.h"

void main(void)
{
    setup_sprite();
    bkg();

    while(1)
    {
        sprite_walk();
        display_sprite();
        wait_vbl_done();
    }
}
