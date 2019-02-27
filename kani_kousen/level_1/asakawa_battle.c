#include "asakawa_battle.h"

void asakawa_battle_ctrl(void)
{
    while(1)
    {
        wait_vbl_done();
        asakawa_battle_check();
        //show_sprites();
    }
}

void battle_nav(void)
{
    if(arrow_y == 32)
    {
        fight_opt();
        state = FIGHT_OPT;
    }
}

void back(void)
{
    if(state < FIGHTING)
    {
        battle_menu();
        state = BATTLE_OPT;
    }
}

void fight_opt(void)
{
    sprite_clean();
    battle_bkg_clean();
    battle_print(">", 18, 32);
    battle_print(" punch", 18, 32);
    show_fighter();
    LETTER_COUNT = 0;
}

void battle_menu(void)
{
    /* setup the bkg */
    set_bkg_data(0,10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18,small_chain_border);

    sprite_clean();
    hide_sprites();
    /* selection menu */
    battle_print(">", arrow_x, arrow_y);
    battle_print(" fight", 18, 32);
    battle_print(" defend", 18, 48);
    battle_print(" run", 18, 64);
    battle_print(" item", 18, 80);
    show_fighter();
}

void show_fighter(void)
{
    /* HP */
    battle_print("hero", 88, 40);
    battle_print("hp", 88, 56);
    battle_print("10/10", 120, 56);
    LETTER_COUNT = 0;
}

void battle_toggle_up(void)
{
    /* if at top && up */
    if(arrow_y == 32)
    {
        arrow_y = 80;
        battle_bkg_clean();
        delay(100);
        battle_bkg_clean();
        battle_print(">", arrow_x, arrow_y);
        LETTER_COUNT = 0;
        delay(100);
    }
    else
    {
        battle_bkg_clean();
        delay(100);
        battle_bkg_clean();
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
        battle_bkg_clean();
        delay(100);
        battle_bkg_clean();
        battle_print(">", arrow_x, arrow_y);
        LETTER_COUNT = 0;
        delay(100);
    }
    else
    {
        battle_bkg_clean();
        delay(100);
        battle_bkg_clean();
        battle_print(">", arrow_x, arrow_y+=16);
        LETTER_COUNT = 0;
        delay(100);
    }
}

void asakawa_battle_check(void)
{
    SPRITES_8x8;

    if(joypad() & J_A)
        battle_nav();

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

void show_sprites(void)
{
    SPRITES_8x16;

    /* setup sprites */
    /* hero */
    hero_pos[0][0] = 80;
    hero_pos[0][1] = 72;
    hero_pos[1][0] = hero_pos[0][0]+SPRITE_WIDTH;
    hero_pos[1][1] = hero_pos[0][1];

    set_sprite_data(46, 8, hero_idle_back);
    set_sprite_tile(LETTER_COUNT+1, 46);
    set_sprite_tile(LETTER_COUNT+2, 48);
    /* asakawa */
    asakawa_pos[0][0] = 80;
    asakawa_pos[0][1] = 40;
    asakawa_pos[1][0] = asakawa_pos[0][0]+SPRITE_WIDTH;
    asakawa_pos[1][1] = asakawa_pos[0][1];

    set_sprite_data(54, 8, asakawa_front_idle);
    set_sprite_tile(LETTER_COUNT+3, 54);
    set_sprite_tile(LETTER_COUNT+4, 56);


    /* display sprites */
    /* hero */
    move_sprite(LETTER_COUNT+1, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(LETTER_COUNT+2, hero_pos[1][0], hero_pos[1][1]);
    /* asakawa */
    move_sprite(LETTER_COUNT+3, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(LETTER_COUNT+4, asakawa_pos[1][0], asakawa_pos[1][1]);
}

void main(void)
{
    wait_vbl_done();

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
