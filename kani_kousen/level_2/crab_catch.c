/**
 * crab_catch.c
 * 
 * methods for handling
 * crab battles
 */

#include <rand.h>
#include <stdlib.h>
#include "crab_catch.h"
#include "../level_1/asakawa_battle.h"
#include "../assets/level_assets/level_assets.h"
#include "../text/text.h"
#include "../assets/sprites/hero_back_idle.h"
#include "../start_up/start_up.h"
#include "../battle/battle.h"

UINT8 crab = 0;
UINT8 caught_crabs = 0; 
UINT8 CRAB_CAUGHT = 0;
UINT8 CRAB_HP = 5;

/**
 * master method for a work day
 */
void crab_catch_ctrl(void)
{
    items = 2;
    battle_num = 1;
    state = BATTLE_CHOICE;
    /**
     * 1. opening screen chooses between two types of crabs & anounces
     *    their coming
     *      * king crab
     *      * normal crab
     * 2. then battle with that crab
     *      * battle relies on your ability to first catch, 
     *      * then batter the crab. 
     *      * if that sequence is not followed, it's a miss 
     * 3. repeat crabs_to_catch many times.
     */
    while(caught_crabs < crabs_to_catch && state != DEAD && 
            option != GAME_OVER)
    {
        hero_hp=(10-health_loss);
        crab_catch_setup();
        delay(500);
        battle_menu();
        while(state != DEAD && state != BATTLE_WIN &&
                option != GAME_OVER)
        {
            wait_vbl_done();
            battle_toggle_ctrl();
            while(state == FIGHTING && option != GAME_OVER)
            {
                choice_handler(arrow_y);
                fight(&hero_hp, &CRAB_HP);
                delay(400);
                if(option == GAME_OVER || state == DEAD)
                    break;
                if(state != DEAD && state != BATTLE_WIN)
                {
                    DISPLAY_OFF;
                    battle_menu();
                    state = BATTLE_CHOICE;
                    choice = 0;
                    DISPLAY_ON;
                    battle_menu();
                }

            }
            if(option == GAME_OVER || state == DEAD)
                break;
        }
        if(state == BATTLE_WIN && option != GAME_OVER)
        {
            clear_screen();
            sprite_clean(0);
            LETTER_COUNT = 0;
            print("YOUiWINl", 56, 80);
            delay(500);
            CRAB_CAUGHT = 0;
            ++caught_crabs;
            state = BATTLE_CHOICE;
        }
    }
    delay(1000);
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
        sprite_clean(0);
        LETTER_COUNT = 0;
        clear_screen();
        print("AiCRABl\0", 56, 80);
        delay(1000);
        sprite_setup(8, hero_back_idle, 8, norm_crab);
        CRAB_HP = 5;
        enemy = 1;
    }
    /* king crab is chosen */
    if(crab == 1)
    {
        sprite_clean(0);
        LETTER_COUNT = 0;
        clear_screen();
        print("AiKING\0", 56, 80);
        print("CRABl\0", 60, 96);
        delay(1000);
        sprite_setup(8, hero_back_idle, 8, king_crab);
        CRAB_HP = 10;
        enemy = 2;
    }
}
