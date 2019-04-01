#include <rand.h>
#include "crab_catch.h"
#include "../level_1/asakawa_battle.h"
#include "../assets/level_assets/level_assets.h"
#include "../text/text.h"
#include "../assets/sprites/norm_crab.h"
#include "../assets/sprites/king_crab.h"
#include "../assets/sprites/hero_back_idle.h"
#include "../battle/battle.h"

UINT8 crab = 0;
UINT8 CRAB_HP = 5;

/**
 * master method for a work day
 */
void crab_catch_ctrl(void)
{
    /**
     * 1. opening screen chooses between two types of crabs & anounces
     *    their coming
     *      * king crab
     *      * normal crab
     * 2. then battle with that crab
     *      * battle relies on your ability to first catch, 
     *      * then batter the crab. 
     *      * if that sequence is not followed, it's a miss 
     * 3. repeat 10 times.
     */
    HERO_HP = 10;
    crab_catch_setup();
    delay(500);
    battle_menu();
    while(STATE != DEAD)
    {
        wait_vbl_done();
        battle_toggle_ctrl();
        /*while(STATE == FIGHTING)
        {
            choice_handler(arrow_y);
            fight(&HERO_HP, &CRAB_HP);
        }*/
        
    }
}

void crab_catch_setup(void)
{
    seed = DIV_REG;
    seed |= (UWORD)DIV_REG << 8;
    initarand(seed);

    /* which crab are we going to use? */
    crab = rand()&0x1;

    /* normal crab is chosen */
    if(crab == 0)
    {
        sprite_clean();
        LETTER_COUNT = 0;
        clear_screen();
        print("a crab!\0", 56, 80);
        DISPLAY_OFF;
        DISPLAY_ON;
        DISPLAY_OFF;
        DISPLAY_ON;
        sprite_setup(8, hero_back_idle, 8, norm_crab);
        CRAB_HP = 5;
    }
    /* king crab is chosen */
    if(crab == 1)
    {
        sprite_clean();
        LETTER_COUNT = 0;
        clear_screen();
        print("a king\0", 56, 80);
        print("crab!\0", 60, 80);
        DISPLAY_OFF;
        DISPLAY_ON;
        DISPLAY_OFF;
        DISPLAY_ON;
        sprite_setup(8, hero_back_idle, 8, king_crab);
        CRAB_HP = 10;
    }
}
