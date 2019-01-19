#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>
/* background tiles and sprite */
#include "ship_tiles.c"
#include "open_screen.c"


/* functions */
void setup_sprite(void);
void setup_bkg(void);
void toggle(void);

/* arrow sprite coordinates */
UINT8 arrow_x = 72;
UINT8 arrow_y = 56;
/* variable for deciding the location of our arrow */
UINT8 loc = 0;


void main(void)
{
    setup_sprite();
    setup_bkg();

    while(1)
    {
        toggle();
        wait_vbl_done();
    }
}    

void toggle(void)
{
    delay(100);
    if(joypad() & J_DOWN)
    {
        if(arrow_y > 64)
        {
            arrow_y = 48;
            move_sprite(0, arrow_x, arrow_y);
        }
        arrow_y+=8;
        move_sprite(0, arrow_x, arrow_y);
    }

    if(joypad() & J_UP)
    {
        if(arrow_y < 64)
        {
            arrow_y = 80;
            move_sprite(0, arrow_x, arrow_y);
        }
        arrow_y-=8;
        move_sprite(0, arrow_x, arrow_y);
    }
}

void setup_sprite(void)
{
    /* First we setup sprites */
    SPRITES_8x8;
    set_sprite_data(0, 89, ship_tiles);

    set_sprite_tile(0,80);
    move_sprite(0, arrow_x, arrow_y);

    SHOW_SPRITES;
}

void setup_bkg(void)
{
    HIDE_WIN;
    SHOW_BKG;

    /* setup bkg */
    set_bkg_data(0, 89, ship_tiles);
    set_bkg_tiles(0,0,32,32,open_screen);
    scroll_bkg(96,0);

    DISPLAY_ON;
}
