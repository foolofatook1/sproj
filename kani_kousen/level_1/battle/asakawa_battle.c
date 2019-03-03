#include "asakawa_battle.h"

void asakawa_battle_ctrl(void)
{
    while(1)
    {
        wait_vbl_done();
        asakawa_battle_check();
        /*while(state == FIGHTING)
        {
            //show_sprites();
        }*/
    }
}

void battle_nav(void)
{
    if(arrow_y == 32)
    {
        state = FIGHT_OPT;
        fight_opt();
    }
    /*if(arrow_y == 48)
    {
        fight();
        state = FIGHTING;
    }*/
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
    }
}

void fight_opt(void)
{
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
    {
        if(state == FIGHT_OPT)
        {

            sprite_clean();

            set_bkg_data(0,4, blank_screen_tiles);
            set_bkg_tiles(0,0,20,18,blank_screen);

            set_sprite_data(0, 8, hero_back_idle);
            set_sprite_data(8, 8, asakawa_front_idle);

            /* hero */
            set_sprite_tile(0, 0);
            set_sprite_tile(1, 1);
            set_sprite_tile(2, 2);
            set_sprite_tile(3, 3);

            move_sprite(0, 72, 72);
            move_sprite(1, 72, 80);
            move_sprite(2, 84, 72);
            move_sprite(3, 84, 80);

            /* asakawa */
            set_sprite_tile(4, 8);
            set_sprite_tile(5, 9);
            set_sprite_tile(6, 10);
            set_sprite_tile(7, 11);

            move_sprite(4, 80, 40);
            move_sprite(5, 80, 48);
            move_sprite(6, 84, 40);
            move_sprite(7, 84, 48);
        }
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

void show_sprites(void)
{
    SPRITES_8x16;

    /* setup sprites */
    /* hero */
    hero_pos[0][0] = 80;
    hero_pos[0][1] = 72;
    hero_pos[1][0] = hero_pos[0][0]+SPRITE_WIDTH;
    hero_pos[1][1] = hero_pos[0][1];

                  //46
    set_sprite_data(0, 8, hero_back_idle);
    set_sprite_tile(0, 0);//LETTER_COUNT+1, 46);
    set_sprite_tile(1, 2);//LETTER_COUNT+2, 48);
    /* asakawa */
    asakawa_pos[0][0] = 80;
    asakawa_pos[0][1] = 40;
    asakawa_pos[1][0] = asakawa_pos[0][0]+SPRITE_WIDTH;
    asakawa_pos[1][1] = asakawa_pos[0][1];

                // 54
    set_sprite_data(8, 8, asakawa_front_idle);
    set_sprite_tile(2, 8);//LETTER_COUNT+3, 54);
    set_sprite_tile(3, 10);//LETTER_COUNT+4, 56);


    /* display sprites */
    /* hero */
              //LETTER_COUNT+x
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    /* asakawa */
    move_sprite(2, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(3, asakawa_pos[1][0], asakawa_pos[1][1]);
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
