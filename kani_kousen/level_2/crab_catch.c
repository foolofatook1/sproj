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
    // delete this ITEMS thing later?
    //UWORD crab_num[4];
    ITEMS = 2;
    BATTLE_NUM = 1;
    STATE = BATTLE_CHOICE;
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
    while(caught_crabs < crabs_to_catch && STATE != DEAD && 
            option != GAME_OVER)
    {
        HERO_HP=(10-health_loss);
        crab_catch_setup();
        delay(500);
        battle_menu();
        while(STATE != DEAD && STATE != BATTLE_WIN &&
                option != GAME_OVER)
        {
            wait_vbl_done();
            battle_toggle_ctrl();
            while(STATE == FIGHTING && option != GAME_OVER)
            {
                choice_handler(arrow_y);
                fight(&HERO_HP, &CRAB_HP);
                delay(400);
                if(option == GAME_OVER || STATE == DEAD)
                    break;
                if(STATE != DEAD && STATE != BATTLE_WIN)
                {
                    DISPLAY_OFF;
                    battle_menu();
                    STATE = BATTLE_CHOICE;
                    choice = 0;
                    DISPLAY_ON;
                    battle_menu();
                }

            }
            if(option == GAME_OVER || STATE == DEAD)
                break;
        }
        if(STATE == BATTLE_WIN && option != GAME_OVER)
        {
            clear_screen();
            sprite_clean(0);
            LETTER_COUNT = 0;
            print("YOUiWINl", 56, 80);
            delay(500);
            CRAB_CAUGHT = 0;
            ++caught_crabs;
            STATE = BATTLE_CHOICE;
        }
    }
   /*    DISPLAY_OFF;
          clear_screen();
          sprite_clean();
          LETTER_COUNT = 0;
          itoa(caught_crabs, crab_num);
          print("you have\0", 24, 32);
          print("caught \0", 24, 48);
          print(crab_num, 80, 48);
          print("crabs\0", 24, 64);
          DISPLAY_ON;*/

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
        /*DISPLAY_OFF;
          delay(500);
          DISPLAY_ON;
          delay(500);
          DISPLAY_OFF;
          delay(500);
          DISPLAY_ON;*/
        sprite_setup(8, hero_back_idle, 8, norm_crab);
        CRAB_HP = 5;
        ENEMY = 1;
    }
    /* king crab is chosen */
    if(crab == 1)
    {
        sprite_clean(0);
        LETTER_COUNT = 0;
        clear_screen();
        print("AiKING\0", 56, 80);
        print("CRABl\0", 60, 96);
        /*DISPLAY_OFF;
          delay(500);
          DISPLAY_ON;
          delay(500);
          DISPLAY_OFF;
          delay(500);
          DISPLAY_ON;*/
        sprite_setup(8, hero_back_idle, 8, king_crab);
        CRAB_HP = 10;
        ENEMY = 2;
    }
}
