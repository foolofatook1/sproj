#include <gb/gb.h>
#include <stdio.h> 
/* sprites */
#include "../assets/sprites/hero_idle_back.c"
#include "../assets/sprites/asakawa_front_idle.c"

/* bkg */
#include "../text/text.c"


void asakawa_battle_ctrl(void);
void battle_menu(void);
void asakawa_battle_check(void);
void show_sprites(void);


UINT8 hero_pos[2][2];
UINT8 asakawa_pos[2][2];

UINT8 arrow_x = 16;
UINT8 arrow_y = 92;

UINT8 SPRITE_WIDTH = 8;

void asakawa_battle_ctrl(void)
{
    while(1)
    {
        wait_vbl_done();
        asakawa_battle_check();
        //show_sprites();
    }
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
    battle_print(" fight", 16, 92);
    battle_print(" defend", 16, 108);
    battle_print(" run", 16, 124);
    battle_print(" item", 16, 140);
    /* HP */
    battle_print("hero", 88, 100);
    battle_print("hp", 88, 116);
    battle_print("10/10", 120, 116);
    LETTER_COUNT = 0;
}

void asakawa_battle_check(void)
{
    SPRITES_8x8;
    //if(joypad() & J_A);
    if(joypad() & J_DOWN)
    {
        /* check the arrow */
        if(arrow_y == 140)
        {
            arrow_y = 92;
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
    if(joypad() & J_UP)
    {
        /* check the arrow */
        if(arrow_y == 92)
        {
            arrow_y = 140;
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
