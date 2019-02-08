#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>
/*#include "/opt/gbdk/include/gb/console.h"*/
/*#include "../text/text.h"*/

/* start level 1 screen tiles */
#include "assets/level_1_screen_tiles.c"
#include "assets/level_1_screen.c"


/* text boxes */
#include "assets/text/font.c" /* text tiles */
#include "assets/text/text_1_level_1.c" /* first text box */
#include "assets/text/text_2_level_1.c" /* second text box */
#include "assets/text/text_3_level_1.c" /* third text box */


/* starting sprites */
#include "../assets/sprites/hero_front_idle.c"
#include "../assets/sprites/fisherman_front_idle.c"

void level_1_ctrl(void);
void level_1_bkg_start(void);
void level_1_sprite_setup(void);
void joypad_check(void);
void output_text(void);


UINT8 text_count = 0;
UINT8 hero_pos[2][2];

/* The big control function */
void level_1_ctrl(void)
{
    level_1_bkg_start();
    while(1)
    {
        wait_vbl_done();
        joypad_check();
    }
}

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

    /* setting up first set of text */
    set_bkg_data(0, 55, font);
    set_bkg_tiles(0, 0, 20, 18, text_1_level_1);

    //level_1_sprite_setup();

    DISPLAY_ON;
}

void joypad_check(void)
{
    if(joypad() & J_A)
    {
        output_text();
    }
}

void output_text(void)
{
    delay(100);
    ++text_count;
    delay(100);
    if(text_count == 1)
    {
        DISPLAY_OFF;
        set_bkg_tiles(0, 0, 20, 18, text_2_level_1);
        DISPLAY_ON;
    }
    if(text_count == 2)
    {
        DISPLAY_OFF;
        set_bkg_tiles(0,0,20,18,text_3_level_1);
        DISPLAY_ON;
    }
    /*
    if(text_count == 3)
    {}*/
}

void level_1_sprite_setup(void)
{
    UINT8 sprite_width = 8;
    /* left half */
    hero_pos[0][0] = 15;
    hero_pos[0][1] = 90;
    /* right half */
    hero_pos[1][0] = hero_pos[0][0]+8;
    hero_pos[1][1] = hero_pos[0][1];

    SPRITES_8x16;
    set_sprite_data(0, 7, hero_front_idle);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);

    SHOW_SPRITES;
}
