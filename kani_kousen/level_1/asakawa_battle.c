#include <stdio.h>
#include <stdlib.h>
#include "../text/text.h"
#include "../battle/battle.h"
#include "asakawa_battle.h"
#include "../start_up/start_up.h"

UINT8 STATE = BATTLE_CHOICE;

/* hp settings for this level */
UINT8 ASAKAWA_HP = 100;
UINT8 HERO_HP = 10;

void asakawa_battle_ctrl(void)
{
    choice = 0;
    sprite_clean();
    LETTER_COUNT = 0;
    battle_menu();
    while(STATE != DEAD)
    {
        wait_vbl_done();
        battle_toggle_ctrl();
        while(STATE == FIGHTING)
        {
            choice_handler(arrow_y);
            fight(&HERO_HP, &ASAKAWA_HP);
            delay(400);
            /* basically does back but only when everything is done */
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
    option = LEVEL_2;
}
