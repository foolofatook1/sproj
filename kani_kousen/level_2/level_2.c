#include <gb/gb.h>
#include <gb/cgb.h>
#include "level_2.h"
#include "../text/text.h"
#include "../battle/battle.h"
void level_2_ctrl(void)
{
    wait_vbl_done();
    level_2_bkg_start();
    l2_scene_1();
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

void l2_scene_1(void)
{
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
    print("get\0", 72, 75);
    print("to work!\0", 56, 91);
}
