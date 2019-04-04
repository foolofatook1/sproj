#include "level_3.h"
#include "../text/text.h"
#include "../battle/battle.h"
#include "../level_2/level_2.h"
#include "../level_2/crab_catch.h"
#include "../assets/level_assets/level_assets.h"

void level_3_ctrl(void)
{
    GOT_INFO = 0;
    DISPLAY_OFF;
    clear_screen();
    delay(500);
    sprite_clean();
    LETTER_COUNT = 0;
    print("chapter 3\0", 48, 56);
    print("rxvxlxtxxn\0", 44, 72);
    DISPLAY_ON;
    delay(1000);
    DISPLAY_OFF;
    shit_pot_setup();
    shit_pot_sprites();
    DISPLAY_ON;
    moving = 1;
    while(!GOT_INFO)
    {
        while(moving)
        {
            hero_walk();
            pos_check_shit_pot();
            if(conv_check())
                break;
        }
        if(!GOT_INFO)
        {
            asakawa_enters_deck();
            asakawa_before_work();
            crab_catch_ctrl();
            asakawa_enters_deck();
            asakawa_after_work();
            delay(500);
            DISPLAY_OFF;
            shit_pot_setup();
            shit_pot_sprites();
            delay(500);
            DISPLAY_ON;
            moving = 1;
            SLEPT = 0;
        }
    }
    shit_pot_setup();
    shit_pot_sprites();
    /* 1344 bits */
    /* now we need to add a fisherman */
    set_sprite_tile(12, 12);
    set_sprite_tile(13, 12);
    set_sprite_prop(13, S_FLIPX);
    move_sprite(12, fisherman2_posx, fisherman2_posy);
    move_sprite(13, fisherman2_posx+sprite_width, fisherman2_posy);
    moving = 1;
    while(moving)
    {
        hero_walk();
        pos_check_shit_pot();
        conv_check();
    }
    /* 1275 bits */
}
