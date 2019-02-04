#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>

/* start level 1 screen tiles */
#include "assets/level_1_screen_tiles.c"
#include "assets/level_1_screen.c"

/* may not need this file but it has numbers and stuff */
#include "assets/font.c"

/* Files for text border */
#include "assets/chain_border_tiles.c"
#include "assets/chain_border.c"

void level_1_bkg_start(void);


/* setup the background for the opening screen. */
void level_1_bkg_start(void)
{
    DISPLAY_OFF;
    HIDE_WIN;
    SHOW_BKG;

    HIDE_SPRITES;

    /* setup bkg */
    set_bkg_data(0, 40, level_1_screen_tiles);
    set_bkg_tiles(0,0,20,18,level_1_screen);

    scroll_bkg(-96,0);

    DISPLAY_ON;

    delay(1000);

    DISPLAY_OFF;
    HIDE_WIN;
    SHOW_BKG;

    HIDE_SPRITES;

    /* setting up text box for */
    set_bkg_data(0, 7, chain_border_tiles);
    set_bkg_tiles(0,8,20,10,chain_border);

    DISPLAY_ON;
}
