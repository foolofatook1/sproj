#include "level_3.h"
#include "../text/text.h"
#include "../battle/battle.h"
#include "../level_2/level_2.h"
#include "../level_2/crab_catch.h"
#include "../assets/level_assets/level_assets.h"
#include "../start_up/start_up.h"

void level_3_ctrl(void)
{
    option = LEVEL_3;
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
    while(!striking)
    {
        while(moving)
        {
            option = LEVEL_3;
            hero_walk();
            pos_check_shit_pot();
            if(conv_check())
                break;
        }
        if(!striking)
            leaves_shit_pot();
    }
    clear_screen();
    sprite_clean();
    LETTER_COUNT = 0;
    print("made it!\0", 24, 32);
    /**
     * Now we need to:
     *  1) have battle with asakawa and imperial army
     *  2) lose battle
     *  3) have another battle with different tactic
     *  4) win battle
     */
}

void leaves_shit_pot(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
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
    GOT_INFO = 0;
    SLEPT = 0;
    caught_crabs = 0;
}
