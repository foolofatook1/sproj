#include <stdio.h>
#include <stdlib.h>
#include "../text/text.h"
#include "../battle/battle.h"
#include "asakawa_battle.h"
#include "../assets/level_assets/level_assets.h"
#include "../start_up/start_up.h"

UINT8 STATE = BATTLE_CHOICE;

/* hp settings for this level */
UINT8 start_hp = 10;

/**
 * If level is:
 *  0) run first battle
 *  1) run second battle
 *  2) run third battle
 */
void asakawa_battle_ctrl(void)
{
    choice = 0;
    sprite_clean(0);
    LETTER_COUNT = 0;
    battle_menu();
    back();
    while(STATE != DEAD)
    {
        wait_vbl_done();
        battle_toggle_ctrl();
        while(STATE == FIGHTING)
        {
            choice_handler(arrow_y);
            fight(&HERO_HP, &ASAKAWA_HP);
            delay(400);
            // basically does back but only when everything is done 
            if(STATE != DEAD)
            {
                DISPLAY_OFF;
                battle_menu();
                STATE = BATTLE_CHOICE;
                choice = 0;
                DISPLAY_ON;
                battle_menu();
            }
        }
    }
    if(!revolt)
        option = LEVEL_2;
}
