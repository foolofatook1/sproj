#include "level_2.h"
#include "../assets/level_assets/level_assets.h"
#include "../text/text.h"
#include "../battle/battle.h"
#include "../level_1/assets/shit_pot.h"

UINT8 talking = 1;

void level_2_ctrl(void)
{
    wait_vbl_done();
    level_2_bkg_start();
    l2_scene_1();

    /*while(talking)
    {
        joypad_check_l2_scene_1();
    }*/
}

void level_2_bkg_start(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
    HIDE_SPRITES;
    HIDE_BKG;

    set_sprite_palette(0, 3, sprite_palette);
    /* load the black clear screen */
    set_bkg_tiles(0,0,20,18, black_screen);

    SHOW_SPRITES;
    SHOW_BKG;

    delay(2000);
    print("chapter 2\0", 48, 64);
    print("  lost\0", 48, 80);
    print(" at sea\0", 48, 96);
    for(i = 0; i < LETTER_COUNT; ++i)
        set_sprite_prop(i,1);
    delay(2500);
}

void joypad_check_l2_scene_1(void)
{
    if(joypad() & J_A)
        return;
        //l2_scene_1_fisherman_enter();
}

/**
 * Should probably make hero_pos and fisherman_pos 
 * global at some point.
 */
void l2_scene_1(void)
{
    /* waking up the hero */
    sprite_clean();
    LETTER_COUNT = 0;
    delay(800);
    print("wake up!\0", 56, 75);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    delay(500);
    print("wake up!\0", 56, 75);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    delay(500);
    print("wake up!\0", 56, 75);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("we have to\0", 48, 75);
    print("get\0", 72, 91);
    print("to work!\0", 56, 107);
    /* start the next part */
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    hide_sprites();
    /* reset sprite properties back to normal */
    for(i = 0; i < MAX_SPRITES; ++i)
        set_sprite_prop(i, 0);
    /* hero lying down in shit pot */
    set_bkg_tiles(0,0,20,18,shit_pot);
    SPRITES_8x16;
    set_sprite_data(0, 4, hero_lie_down);
    set_sprite_data(4, 4, hero_front_idle);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    move_sprite(0, 80, 75);
    move_sprite(1, 88, 75);
    /* hero stands up */
    delay(500);
    set_sprite_tile(0, 4);
    set_sprite_tile(1, 6);
    /* setting up fisherman data for his walk in */
    set_sprite_data(8, 8, fisherman_walk_side);
    set_sprite_tile(2, 8);
    set_sprite_tile(3, 10);
    /** 
     * enter fisherman (the -5 adds a little extra distance) 
     * i = 160 is the right side of the screen.
     */
     /* hero_pos[1][0]-SPRITE_WIDTH+5) */
    for(i = 160; i > 95; --i)
    {
        delay(50);
        move_sprite(2, i, 75);
        move_sprite(3, i+8, 75);
        set_sprite_tile(2, (8+(4*(0x1&i))));
        set_sprite_tile(3, (10+(4*(0x1&i))));
    }
    set_sprite_data(0, 4, hero_walk_sideways);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);

    delay(500);
    bkg_clean();
    sprite_clean();
    LETTER_COUNT = 0;
    print("wassup!?\0", 56, 75);
}
