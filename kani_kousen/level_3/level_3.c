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
    while(!revolt)
    {
        while(moving)
        {
            hero_walk();
            pos_check_shit_pot();
            if(conv_check())
                break;
        }
        if(!revolt)
            leaves_shit_pot();
    }
    /* first attempt at revolution is ready */
    /**
     * Add follow up for if you say yes,
     * where the fisherman gives you a game plan
     * where you try and gather people up.
     * if you say no, increase the amount of crabs necessary to catch,
     * and lower HP by one, and keep doing that every time you say no.
     */
     /**
      * So the following is if you say yes, and "no,"
      * response is in conv_check()
      */
}

void leaves_shit_pot(void)
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
    caught_crabs = 0;
}
