#include <stdlib.h>
#include "../../text/text.h"
#include "battle.h"
#include "asakawa_battle.h"

UINT8 SPRITE_WIDTH = 8;

UINT8 BATTLE_CHOICE = 0;
UINT8 FIGHT_CHOICE = 1;
UINT8 RUN_CHOICE = 2;
UINT8 ITEM_CHOICE = 3;
UINT8 FIGHTING = 4;

UINT8 STATE = BATTLE_CHOICE;

void asakawa_battle_ctrl(void)
{
    while(1)
    {
        wait_vbl_done();
        asakawa_battle_check();
        while(STATE == FIGHTING)
        {
            choice_handler(arrow_y);
            //            hero_fight(&ASAKAWA_HP, &HERO_HP);
            npc_fight(&HERO_HP);
            delay(400);
            /* basically does back but only when everything is done */
            DISPLAY_OFF;
            battle_menu();
            STATE = BATTLE_CHOICE;
            choice = 0;
            DISPLAY_ON;
            battle_menu();
        }
    }
}

void show_fighter_stats(void)
{
    /* HP */
    battle_print("hero", 88, 40);
    battle_print("hp", 88, 56);

    itoa(HERO_HP, h_hp);
    battle_print(h_hp, 120, 56);
    battle_print("/10", 136, 56);
    LETTER_COUNT = 0;
}

void asakawa_battle_check(void)
{
    SPRITES_8x8;

    if(joypad() & J_A)
    {
        if(STATE == FIGHT_CHOICE)
            STATE = FIGHTING;
        else
            battle_nav();
    }

    if(joypad() & J_B)
        back();

    /* toggle down options */
    if(joypad() & J_DOWN && STATE == BATTLE_CHOICE)
        battle_toggle_down();
    /*if(joypad() & J_DOWN && state == FIGHT_OPT)
      if(joypad() & J_DOWN && state == ITEM_OPT)*/

    /* toggle up options */
    if(joypad() & J_UP && STATE == BATTLE_CHOICE)
        battle_toggle_up();
    /*    if(joypad() & J_DOWN && state == FIGHT_OPT)
          if(joypad() & J_DOWN && state == ITEM_OPT)*/


}

void main(void)
{
    wait_vbl_done();

    ENABLE_RAM_MBC1;
    SWITCH_4_32_MODE_MBC1;

    DISPLAY_OFF;
    HIDE_BKG;
    HIDE_SPRITES;
    HIDE_WIN;

    battle_menu();
    
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
    asakawa_battle_ctrl();
}
