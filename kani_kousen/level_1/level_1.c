#include <stdio.h>
#include "level_1.h"

/* The big control function */
void level_1_ctrl(void) 
{
    level_1_bkg_start();
    while(start_animate == 0)
    {
        joypad_check();
        wait_vbl_done();
    }
    while(enter_miner() == 0)
    {
        animate();
        enter_miner();
        wait_vbl_done();
    }
    DISPLAY_OFF;
    HIDE_SPRITES;
    set_bkg_data(0, 10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18,chain_border);
    scroll_bkg(-40, 0);
    DISPLAY_ON;
    print("Hello world", 100, 100, 0);
}

/* where miner intro used to be */

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
    SHOW_SPRITES;
    SHOW_BKG;

    /* setting up first set of text */
    //set_bkg_data(0, 55, font);
    //set_sprite_data(0, 10, font);
    print("we're all", 24, 32, 0);
    print("goin' to", 24, 48, 1);
    print("hell!", 24, 64, 2);
    //print("you hear!?", 24, 64, 2);


    //set_bkg_tiles(0, 0, 20, 18, text_1_level_1);

    DISPLAY_ON;
}

void joypad_check(void) 
{
    if(joypad() & J_A)
    {
        scene_1();
    }
}

void scene_1(void) 
{
    delay(100);
    ++text_count;
    delay(100);
    if(text_count == 1)
    {
        DISPLAY_OFF;
        //set_bkg_tiles();
        print("4 months on", 24, 32, 0);
        print("kamchatkas", 24, 48, 1);
        print("northern", 24, 64, 2);
        print("waters. it", 24, 80, 3);
        print("it would be a", 24, 106, 4);
        print("cold death", 24, 122, 5);
        print("indeed...", 24, 138, 6);

//        set_bkg_tiles(0, 0, 20, 18, text_2_level_1);
        DISPLAY_ON;
    }
    if(text_count == 2)
    {
        DISPLAY_OFF;
 //       set_bkg_tiles(0,0,20,18,text_3_level_1);
        DISPLAY_ON;
    }
    if(text_count == 3)
    {
        DISPLAY_OFF;
        scroll_bkg(40,0);

        /* center on the door */
        set_bkg_data(0,16,shit_pot_tiles);
        set_bkg_tiles(0,0,32,32,shit_pot);
        DISPLAY_ON;
        HIDE_SPRITES;
        level_1_sprite_setup();
    }
}

int enter_miner(void) 
{
    UINT8 step_x = 4;
    UINT8 step_y = 0;

    if(miner_pos[0][0] <= 80) /* if we are far enough to the left */
    {
        step_y = 4;
        step_x = 0;
        set_sprite_data(16, 8, miner_walk_up); 
        if(miner_pos[0][1] <= 90) /* stop walking */
        {
            step_y = 0;
            set_sprite_data(16, 8, miner_idle_back);
            delay(100);

            return 1; /* we're done */
        }

        miner_pos[0][0] -= step_x;
        miner_pos[0][1] -= step_y;
        miner_pos[1][0] -= step_x;
        miner_pos[1][1] -= step_y;

        set_sprite_tile(4, 16);
        move_sprite(4, miner_pos[0][0], miner_pos[0][1]);
        set_sprite_tile(5, 18);
        move_sprite(5, miner_pos[1][0], miner_pos[1][1]);
        delay(140);

        miner_pos[0][0] -= step_x;
        miner_pos[0][1] -= step_y;
        miner_pos[1][0] -= step_x;
        miner_pos[1][1] -= step_y;

        set_sprite_tile(4, 20);
        move_sprite(4, miner_pos[0][0], miner_pos[0][1]);
        set_sprite_tile(5, 22);
        move_sprite(5, miner_pos[1][0], miner_pos[1][1]);
    }

    /* start by walking left */
    miner_pos[0][0] -= step_x;
    miner_pos[0][1] -= step_y;
    miner_pos[1][0] -= step_x;
    miner_pos[1][1] -= step_y;

    set_sprite_tile(4, 16);
    move_sprite(4, miner_pos[0][0], miner_pos[0][1]);
    set_sprite_tile(5, 18);
    move_sprite(5, miner_pos[1][0], miner_pos[1][1]);
    delay(140);

    miner_pos[0][0] -= step_x;
    miner_pos[0][1] -= step_y;
    miner_pos[1][0] -= step_x;
    miner_pos[1][1] -= step_y;

    set_sprite_tile(4, 20);
    move_sprite(4, miner_pos[0][0], miner_pos[0][1]);
    set_sprite_tile(5, 22);
    move_sprite(5, miner_pos[1][0], miner_pos[1][1]);

    return 0;
}

/* a helper function to animate the sprites when they appear */
void animate(void) 
{
    set_sprite_tile(0, 4);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    set_sprite_tile(1, 6);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);

    set_sprite_tile(2, 12);
    move_sprite(2, fisherman_pos[0][0], fisherman_pos[0][1]); 
    set_sprite_tile(3, 14);
    move_sprite(3, fisherman_pos[1][0], fisherman_pos[1][1]);
    delay(100);

    set_sprite_tile(0, 0);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    set_sprite_tile(1, 2);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);

    set_sprite_tile(2, 8);
    move_sprite(2, fisherman_pos[0][0], fisherman_pos[0][1]);
    set_sprite_tile(3, 10);
    move_sprite(3, fisherman_pos[1][0], fisherman_pos[1][1]);
    delay(100);
}

int level_1_sprite_setup(void) 
{
    /* hero on screen at door */
    /* left half */
    hero_pos[0][0] = 70; 
    hero_pos[0][1] = 65;
    /* right half */
    hero_pos[1][0] = hero_pos[0][0]+sprite_width; 
    hero_pos[1][1] = hero_pos[0][1];

    /* fisherman on screen at door */
    /* left half */
    fisherman_pos[0][0] = 86;
    fisherman_pos[0][1] = 65;
    /* right half */
    fisherman_pos[1][0] = fisherman_pos[0][0]+sprite_width;
    fisherman_pos[1][1] = fisherman_pos[0][1];

    /* miner positioning for the coming scene */
    /* left half */
    miner_pos[0][0] = 150;
    miner_pos[0][1] = 100;
    /* right half */
    miner_pos[1][0] = miner_pos[0][0]+sprite_width;
    miner_pos[1][1] = miner_pos[0][1];

    SPRITES_8x16;
    /* hero */
    set_sprite_data(0, 8, hero_front_idle);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    /* fisherman */
    set_sprite_data(8, 8, fisherman_front_idle);
    set_sprite_tile(2, 8);
    set_sprite_tile(3, 10);

    /* miner */
    set_sprite_data(16, 8, miner_walk_left);

    /* display the hero */
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    /* display the fisherman */
    move_sprite(2, fisherman_pos[0][0], fisherman_pos[0][1]);
    move_sprite(3, fisherman_pos[1][0], fisherman_pos[1][1]);

    delay(400); /* a pause before appearing at door */
    SHOW_SPRITES;
    start_animate = 1;
}
