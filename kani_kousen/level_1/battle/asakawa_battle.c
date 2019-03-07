#include "asakawa_battle.h"

UINT8 arrow_x = 18;
UINT8 arrow_y = 32;

UINT8 state = BATTLE_OPT;

void asakawa_battle_ctrl(void)
{
    while(1)
    {
        wait_vbl_done();
        asakawa_battle_check();
        while(state == FIGHTING)
        {
            choice_handler(arrow_y);
            //            hero_fight(&ASAKAWA_HP, &HERO_HP);
            SWITCH_RAM_MBC1(2);
            SWITCH_ROM_MBC1(2);
            npc_fight(&HERO_HP);
            delay(400);
            /* basically does back but only when everything is done */
            DISPLAY_OFF;
            battle_menu();
            state = BATTLE_OPT;
            choice = 0;
            DISPLAY_ON;
            battle_menu();
        }
    }
}

void battle_nav(void)
{
    if(arrow_y == 32)
    {
        state = FIGHT_OPT;
        fight_opt();
    }
    if(arrow_y == 48)
    {
        choice = DEFEND;
        state = FIGHTING;
    }
    if(arrow_y == 64)
    {
        state = RUN;
        run();
    }
    if(arrow_y == 80)
    {
        state = ITEM_OPT;
        item_opt();
    }
}

void run(void)
{
    SWITCH_ROM_MBC1(2);
    sprite_clean();
    battle_bkg_clean();
    battle_print("you", 18, 32);
    battle_print("can't", 18, 48);
    battle_print("escape!", 18, 64); 
    show_fighter_stats();
    LETTER_COUNT = 0;
    delay(300);
    back();
}

void back(void)
{
    if(state < FIGHTING)
    {
        battle_menu();
        state = BATTLE_OPT;
        choice = 0;
    }
}

void fight_opt(void)
{
    SWITCH_ROM_MBC1(2);
    sprite_clean();
    battle_bkg_clean();
    battle_print(">", 18, 32);
    battle_print(" punch", 18, 32);
    battle_print("a select", 16, 130);
    battle_print("b back", 16, 142);
    show_fighter_stats();
    LETTER_COUNT = 0;
}

void item_opt(void)
{
    SWITCH_ROM_MBC1(2);
    sprite_clean();
    battle_bkg_clean();
    battle_print(" empty", 18, 32);
    battle_print("a select", 16, 130);
    battle_print("b back", 16, 142);
    show_fighter_stats();
    LETTER_COUNT = 0;

}

void battle_menu(void)
{
    /* setup the bkg */
    set_bkg_data(0,10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18,small_chain_border);

    SWITCH_ROM_MBC1(2);
    sprite_clean();
    hide_sprites();
    /* selection menu */
    battle_print(">", arrow_x, arrow_y);
    battle_print(" fight", 18, 32);
    battle_print(" defend", 18, 48);
    battle_print(" run", 18, 64);
    battle_print(" item", 18, 80);
    show_fighter_stats();
}

void show_fighter_stats(void)
{
    SWITCH_ROM_MBC1(2);
    /* HP */
    battle_print("hero", 88, 40);
    battle_print("hp", 88, 56);

    itoa(HERO_HP, h_hp);
    battle_print(h_hp, 120, 56);
    battle_print("/10", 136, 56);
    LETTER_COUNT = 0;
}

void battle_toggle_up(void)
{
    /* if at top && up */
    if(arrow_y == 32)
    {
        arrow_y = 80;
        delay(100);
        SWITCH_ROM_MBC1(2);
        battle_print(">", arrow_x, arrow_y);
        LETTER_COUNT = 0;
        delay(100);
    }
    else
    {
        delay(100);
        SWITCH_ROM_MBC1(2);
        battle_print(">", arrow_x, arrow_y-=16);
        LETTER_COUNT = 0;
        delay(100);
    }
}

void battle_toggle_down(void)
{
    /* if at bottom && down */
    if(arrow_y == 80)
    {
        arrow_y = 32;
        delay(100);
        SWITCH_ROM_MBC1(2);
        battle_print(">", arrow_x, arrow_y);
        LETTER_COUNT = 0;
        delay(100);
    }
    else
    {
        delay(100);
        SWITCH_ROM_MBC1(2);
        battle_print(">", arrow_x, arrow_y+=16);
        LETTER_COUNT = 0;
        delay(100);
    }
}

void asakawa_battle_check(void)
{
    SPRITES_8x8;

    if(joypad() & J_A)
    {
        if(state == FIGHT_OPT)
            state = FIGHTING;
        else
            battle_nav();
    }

    if(joypad() & J_B)
        back();

    /* toggle down options */
    if(joypad() & J_DOWN && state == BATTLE_OPT)
        battle_toggle_down();
    /*if(joypad() & J_DOWN && state == FIGHT_OPT)
      if(joypad() & J_DOWN && state == ITEM_OPT)*/

    /* toggle up options */
    if(joypad() & J_UP && state == BATTLE_OPT)
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
