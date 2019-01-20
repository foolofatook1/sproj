#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#include "level_1_screen_tiles.c"
#include "level_1_screen.c"

void level_1_bkg_start(void);


/* setup the background for the opening screen. */
void level_1_bkg_start(void)
{
    HIDE_WIN;
    SHOW_BKG;

    HIDE_SPRITES;

    /* setup bkg */
    set_bkg_data(0, 40, level_1_screen_tiles);
    set_bkg_tiles(0,0,20,18,level_1_screen);

    scroll_bkg(-96,0);

    DISPLAY_ON;
}
