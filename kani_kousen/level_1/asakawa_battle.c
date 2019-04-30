/**
 * asakawa_battle.c
 *
 * methods for handling battles with asakawa
 */

#include <stdio.h>
#include <stdlib.h>
#include "../text/text.h"
#include "../battle/battle.h"
#include "asakawa_battle.h"
#include "../assets/level_assets/level_assets.h"
#include "../start_up/start_up.h"

UINT8 state = BATTLE_CHOICE;

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
    state = BATTLE_CHOICE;
    choice = 0;
    battle_menu();
    while(state != DEAD || option != GAME_OVER)
    {
        wait_vbl_done();
        battle_toggle_ctrl();
        while(state == FIGHTING)
        {
            choice_handler(arrow_y);
            fight(&hero_hp, &asakawa_hp);
            delay(400);
            // basically does back but only when everything is done 
            if(state == BATTLE_WIN && REVOLUTION_2)
                break;
            if(state != DEAD)
            {
                DISPLAY_OFF;
                battle_menu();
                state = BATTLE_CHOICE;
                choice = 0;
                DISPLAY_ON;
                battle_menu();
            }
        }
        if((state == BATTLE_WIN) && REVOLUTION_2)
            break;
    }
    /* the battle that leads to level 2 */
    if(!revolt && !REVOLUTION_2)
        option = LEVEL_2;
}
