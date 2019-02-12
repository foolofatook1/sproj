/* start level 1 screen tiles */
#include "assets/level_1_screen_tiles.c"
#include "assets/level_1_screen.c"


/* text boxes */
#include "assets/text/font.c" /* text tiles */
#include "assets/text/text_1_level_1.c" /* first text box */
#include "assets/text/text_2_level_1.c" /* second text box */
#include "assets/text/text_3_level_1.c" /* third text box */

/* shit pot assets */
#include "assets/shit_pot_tiles.c" 
#include "assets/shit_pot.c"

/* starting sprites */
#include "../assets/sprites/hero_front_idle.c"
/*#include "../assets/sprites/fisherman.c"*/

void level_1_ctrl(void);
void level_1_bkg_start(void);
void level_1_sprite_setup(void);
void joypad_check(void);
void output_text(void);


UINT8 text_count = 0;
UINT8 hero_pos[2][2];
UINT8 fisherman_pos[2][2];

/* The big control function */
void level_1_ctrl(void)
{
    level_1_bkg_start();
    while(1)
    {
        joypad_check();
        wait_vbl_done();
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

    /* setting up first set of text */
    set_bkg_data(0, 55, font);
    set_bkg_tiles(0, 0, 20, 18, text_1_level_1);

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
    text_count++;
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
    if(text_count >= 3)
    {
        DISPLAY_OFF;
        scroll_bkg(40,0); /* center on the door */
        set_bkg_data(0, 16, shit_pot_tiles);
        set_bkg_tiles(0,0,32,32,shit_pot);
        DISPLAY_ON;
        delay(500);
        level_1_sprite_setup();
    }
}

void level_1_sprite_setup(void)
{

    UINT8 sprite_width = 8;
   
    /* hero on screen at door */
    /* left half */
    hero_pos[0][0] = 70; 
    hero_pos[0][1] = 65;
    /* right half */
    hero_pos[1][0] = hero_pos[0][0]+sprite_width; 
    hero_pos[1][1] = hero_pos[0][1];

    /* fisherman on screen at door */
    /* left half */
    //fisherman_pos[0][0] = 85;
    //fisherman_pos[0][1] = 65;
    /* right half */
    /*fisherman_pos[1][0] = fisherman_pos[0][0]+sprite_width;
    fisherman_pos[1][1] = fisherman_pos[0][1];*/

    SPRITES_8x16;
    set_sprite_data(0, 7, hero_front_idle);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);


    /*set_sprite_data(8, 7, fisherman);
    set_sprite_tile(2,8);
    set_sprite_tile(3,10);*/

    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);

    /*move_sprite(2, fisherman_pos[0][0], fisherman_pos[0][1]);
    move_sprite(3, fisherman_pos[1][0], fisherman_pos[1][1]);*/

    SHOW_SPRITES;
}
