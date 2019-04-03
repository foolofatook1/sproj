#include <rand.h>
#include <gb/drawing.h>
#include <stdlib.h>
#include <stdio.h>
#include <rand.h>
#include "../level_1/asakawa_battle.h"
#include "battle.h"
#include "../text/text.h"
#include "../start_up/start_up.h"
#include "../level_2/crab_catch.h"

/**
 * 0 = asakawa;
 * 1 = crab
 * 2 = king crab
 * 3 = beriberi
 * 4 = lice
 */
UINT8 ENEMY = 0;
UINT8 BATTLE_NUM = 0;

UINT8 BATTLE_CHOICE = 0;
UINT8 FIGHT_CHOICE = 1;
UINT8 RUN_CHOICE = 2;
UINT8 ITEM_CHOICE = 3;
UINT8 FIGHTING = 4;
UINT8 DEAD = 5;
UINT8 BATTLE_WIN = 6;

UBYTE ITEMS = 0;
UINT8 CHOSEN_ITEM = 0;
UINT8 CHOOSING = 0;

UINT8 PUNCH = 1;
UINT8 DEFEND = 2;
UINT8 ITEM = 3;

UINT8 NET = 2;
UINT8 CLUB = 5;

UINT8 SHOOT = 10;
UINT8 CLAW = 2;
UINT8 KING_CLAW = 3;

UINT8 PUNCH_LOC = 32;

UINT8 enemy_choice;

UWORD seed;

UBYTE npc_act, npc_acc, hero_acc, first_fighter = 0; //UBYTE

/* a stepping variable for character animations */
UINT8 y = 72;
UINT8 enemy_y = 40;
/* another animation counter */
UINT8 a = 0;

UWORD h_hp[4];
UWORD e_hp[4];

void battle_nav(void)
{
    if(arrow_y == 32)
    {
        STATE = FIGHT_CHOICE;
        fight_opt();
    }
    if(arrow_y == 48)
    {
        choice = DEFEND;
        STATE = FIGHTING;
    }
    if(arrow_y == 64)
    {
        STATE = RUN_CHOICE;
        run();
    }
    if(arrow_y == 80)
    {
        STATE = ITEM_CHOICE;
        item_opt();
    }
}

void run(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
    battle_bkg_clean();
    if(BATTLE_NUM == 1)
    {
        battle_print("asakawa:\0", 18, 32);
        battle_print("you\0", 18, 48);
        battle_print("can't\0", 18, 64);
        battle_print("leave!\0", 18, 80); 
        show_fighter_stats();
        delay(500);
        sprite_clean();
        LETTER_COUNT = 0;
        battle_bkg_clean();
        battle_print("asakawa:\0", 18, 32);
        battle_print("not 'til\0", 16, 48);
        battle_print("you're\0", 18, 64);
        battle_print("done!\0", 18, 80);
        show_fighter_stats();
        delay(1000);
        back();
    }
    else 
    {
        battle_print("you\0", 18, 32);
        battle_print("can't\0", 18, 48);
        battle_print("escape!\0", 18, 64); 
        show_fighter_stats();
        delay(500);
    }
}

void back(void)
{
    if(STATE < FIGHTING)
    {
        battle_menu();
        STATE = BATTLE_CHOICE;
        choice = 0;
    }
}

void fight_opt(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
    battle_bkg_clean();
    battle_print(">", 18, 32);
    battle_print(" punch", 18, 32);
    battle_print("a select", 16, 130);
    battle_print("b back", 16, 142);
    show_fighter_stats();
}

void item_opt(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
    battle_bkg_clean();
    if(ITEMS == 0)
    {
        battle_print(" empty", 18, 32);
        battle_print("a select", 16, 130);
        battle_print("b back", 16, 142);
    }
    if(ITEMS == 2)
    {
        CHOOSING = 1;
        arrow_x = 24;
        arrow_y = 32;
        battle_print(">\0", arrow_x, arrow_y);
        battle_print(" club\0", 24, 32);
        battle_print(" net\0", 24, 48);
        battle_print("a select\0", 16, 130);
        battle_print("b back\0", 16, 142);
        show_fighter_stats();
        arrow_y = 32;
        while(CHOOSING)
            choose_item_toggle();
    }
}

void choose_item_toggle(void)
{
    if(joypad() & J_UP)
    {
        if(arrow_y <= 32)
            arrow_y = 64;
        delay(100);
        move_sprite(0, arrow_x, arrow_y-=16);
    }
    if(joypad() & J_DOWN)
    {
        if(arrow_y >= 48)
            arrow_y = 16;
        delay(100);
        move_sprite(0, arrow_x, arrow_y+=16);
    }
    if(joypad() & J_A)
    {
        if(arrow_y == 32)
        {
            CHOSEN_ITEM = CLUB;
            STATE = FIGHTING;
        }
        if(arrow_y == 48)
        {
            CHOSEN_ITEM = NET;
            STATE = FIGHTING;
        }
        CHOOSING = 0;
    }
    if(joypad() & J_B)
    {
        CHOOSING = 0;
        back();
    }
}

void battle_menu(void)
{

    arrow_x = 20;
    arrow_y = 32;
    /* setup the bkg */
    set_bkg_data(0,10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18,small_chain_border);

    sprite_clean();
    LETTER_COUNT = 0;
    hide_sprites();
    /* selection menu */
    battle_print(">", arrow_x, arrow_y);
    battle_print(" fight", 18, 32);
    battle_print(" defend", 18, 48);
    battle_print(" run", 18, 64);
    battle_print(" item", 18, 80);
    show_fighter_stats();
}

void battle_toggle_up(void)
{
    /* if at top && up */
    if(arrow_y == 32)
    {
        arrow_y = 96;
        delay(100);
        move_sprite(0, arrow_x, arrow_y-=16);
        delay(100);
    }
    else
    {
        delay(100);
        move_sprite(0, arrow_x, arrow_y-=16);
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
        move_sprite(0, arrow_x, arrow_y);
        delay(100);
    }
    else
    {
        delay(100);
        move_sprite(0, arrow_x, arrow_y+=16);
        delay(100);
    }
}

void battle_toggle_ctrl(void)
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

    /* toggle up options */
    if(joypad() & J_UP && STATE == BATTLE_CHOICE)
        battle_toggle_up();
}

void choice_handler(UINT8 arrow_y) 
{
    if(arrow_y == PUNCH_LOC && choice != ITEM)
        choice = PUNCH;
    if(CHOSEN_ITEM == CLUB)
        choice = ITEM;
    if(CHOSEN_ITEM == NET)
        choice = ITEM;

    if(choice == ITEM)
    {
        clear_screen();
        sprite_clean();
        LETTER_COUNT = 0;
        print("item:\0", 24, 32);
        if(CHOSEN_ITEM == CLUB)
            print("club\0", 24, 48);
        if(CHOSEN_ITEM == NET)
            print("net\0", 24, 48);
        delay(500);
    }
    if(choice == PUNCH)
    {
        clear_screen();
        sprite_clean();
        LETTER_COUNT = 0;
        print("punching\0", 24, 32);
    }
    delay(500);
}

void hero_fight(void)//UINT8 *enemy_hp)
{

    if(choice == PUNCH || choice == ITEM)
    {
        /* figher chooses punch and hits */
        hero_fight_anim();
        for(a = 0; a < 6; ++a)
        {
            delay(100);
            DISPLAY_OFF;
            delay(100);
            DISPLAY_ON;
        }
        sprite_clean();
        LETTER_COUNT = 0;
        if(choice == PUNCH && (ENEMY == 1 || ENEMY == 2))
        {
            print(" no use\0", 56, 56);
            print("punching\0", 56, 72);
            print(" a crab!\0", 56, 88);
            delay(500);
        }
        if(choice == PUNCH && ENEMY == 0 && hero_acc >= 3)
        {
            print("hit!\0", 72, 80);
            delay(500);
        }
        if((choice == ITEM) && (CHOSEN_ITEM == NET) && 
                (hero_acc > 0))
        {
            print("caught!\0", 72, 80);
            CRAB_CAUGHT = 1;
            delay(500);
        }
        if((choice == ITEM) && (CHOSEN_ITEM == CLUB) && 
                (CRAB_CAUGHT) && (hero_acc > 0))
        {
            print("crushed!\0", 72, 80);
            delay(500);
        }
        if((choice == ITEM) && (CHOSEN_ITEM == CLUB) && 
                (!CRAB_CAUGHT))
        {
            print("you need\0", 72, 64);
            print("to catch\0", 72, 80);
            print("the crab!\0", 72, 96);
            delay(500);
        }
        /* fighter chooses punch and misses */
        else if(((choice == PUNCH) && (hero_acc < 3)) || 
                ((choice == ITEM) && (hero_acc == 0)))
        {
            sprite_clean();
            LETTER_COUNT = 0;
            print("you miss!", 64, 80);
            delay(500);
            clear_screen();
        }
    }
    /* fighter defends */
    if(choice == DEFEND)
        hero_defend_anim();
}

void hero_defend_anim(void) 
{
    if(ENEMY == 0)
        sprite_setup(8, hero_back_idle, 8, asakawa_front_idle);
    if(ENEMY == 1)
        sprite_setup(8, hero_back_idle, 8, norm_crab);
    if(ENEMY == 2)
        sprite_setup(8, hero_back_idle, 8, king_crab);
    for(a = 0; a < 21; a+=3)
    {
        delay(100);
        set_sprite_tile(4, (8+(a&0x4)));
        move_sprite(4, 77, y);
        set_sprite_tile(5, (9+(a&0x4)));
        move_sprite(5, 77, y+8);
        set_sprite_tile(6, (10+(a&0x4)));
        move_sprite(6, 84, y);
        set_sprite_tile(7, (11+(a&0x4)));
        move_sprite(7, 84, y+8);
        delay(100);
    }
    y = 72;
}

void enemy_defend_anim(void)
{
    /* enemy */ 
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 1);
    set_sprite_tile(2, 2);
    set_sprite_tile(3, 3);

    move_sprite(0, 77, 40); // top left of the head
    move_sprite(1, 77, 48); // bottom left of body
    move_sprite(2, 84, 40); // top right of head
    move_sprite(3, 84, 48); // bottom right of body
    sprite_setup(8, hero_back_idle, 8, asakawa_front_idle);
    for(a = 0; a < 21; a+=3)
    {
        delay(100);
        set_sprite_tile(0, (0+(a&0x4)));
        move_sprite(0, 77, y);
        set_sprite_tile(1, (1+(a&0x4)));
        move_sprite(1, 77, y+8);
        set_sprite_tile(2, (2+(a&0x4)));
        move_sprite(2, 84, y);
        set_sprite_tile(3, (3+(a&0x4)));
        move_sprite(3, 84, y+8);
        delay(100);
    }
    enemy_y = 40;
}

void hero_fight_anim(void) 
{
    if(ENEMY == 0)
        sprite_setup(8, hero_back_idle, 8, asakawa_front_idle);
    if(ENEMY == 1)
        sprite_setup(8, hero_back_idle, 8, norm_crab);
    if(ENEMY == 2)
        sprite_setup(8, hero_back_idle, 8, king_crab);
    delay(300);
    /* essentially hiding one sprite */
    for(i = 4; i < 8; ++i)
        move_sprite(i, 200, 200);

    delay(300);
    move_sprite(4, 77, 58);
    move_sprite(5, 77, 66);
    move_sprite(6, 84, 58);
    move_sprite(7, 84, 66);
    for(a = 0; a < 21; a+=3)
    {
        delay(100);
        set_sprite_tile(4, (8+(a&0x4)));
        set_sprite_tile(5, (9+(a&0x4)));
        set_sprite_tile(6, (10+(a&0x4)));
        set_sprite_tile(7, (11+(a&0x4)));
    }
}

void enemy_fight_anim(void)
{
    if(ENEMY == 0)
        sprite_setup(8, hero_back_idle, 8, asakawa_front_idle);
    if(ENEMY == 1)
        sprite_setup(8, hero_back_idle, 8, norm_crab);
    if(ENEMY == 2)
        sprite_setup(8, hero_back_idle, 8, king_crab);
    delay(300);
    /* essentially hiding one sprite */
    for(i = 0; i < 4; ++i)
        move_sprite(i, 200, 200);

    delay(300);
    move_sprite(0, 77, 52);
    move_sprite(1, 77, 60);
    move_sprite(2, 84, 52);
    move_sprite(3, 84, 60);
    for(a = 0; a < 21; a+=3)
    {
        delay(100);
        set_sprite_tile(0, (0+(a&0x4)));
        set_sprite_tile(1, (1+(a&0x4)));
        set_sprite_tile(2, (2+(a&0x4)));
        set_sprite_tile(3, (3+(a&0x4)));
    }
}

void clear_screen(void) 
{
    /* clear the bkg */
    set_bkg_data(0,4, blank_screen_tiles);
    set_bkg_tiles(0,0,20,18,blank_screen);
}

/**
 * hnb    -- hero number of tiles
 * enb    -- enemy number of tiles
 * x_data -- sprite sheet
 */
void sprite_setup(UINT8 hnb, unsigned char *hero_data,
        UINT8 enb, unsigned char *enemy_data) 
{
    sprite_clean();
    LETTER_COUNT = 0;
    clear_screen();

    /* setup sprites */
    set_sprite_data(0, 8, enemy_data);
    set_sprite_data(hnb, enb, hero_data);

    /* enemy */ 
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 1);
    set_sprite_tile(2, 2);
    set_sprite_tile(3, 3);

    move_sprite(0, 77, 40); // top left of the head
    move_sprite(1, 77, 48); // bottom left of body
    move_sprite(2, 84, 40); // top right of head
    move_sprite(3, 84, 48); // bottom right of body

    /* hero */
    set_sprite_tile(4, 8);
    set_sprite_tile(5, 9);
    set_sprite_tile(6, 10);
    set_sprite_tile(7, 11);

    move_sprite(4, 77, 72);
    move_sprite(5, 77, 80);
    move_sprite(6, 84, 72);
    move_sprite(7, 84, 80);
}

/**
 * Note to self: npc_fight does not ever defend...
 */
void npc_fight(void)
{
    /* enemy fights and hits */
    if(npc_act >= 1 && npc_acc >= 1)
    {
        enemy_fight_anim();
        for(a = 0; a < 6; ++a)
        {
            delay(100);
            DISPLAY_OFF;
            delay(100);
            DISPLAY_ON;
        }
        DISPLAY_OFF;
        sprite_clean();
        LETTER_COUNT = 0;
        print("hit!\0", 72, 80);
        clear_screen();
        DISPLAY_ON;
        delay(500);
    }
    /* enemy fights and misses */
    if(npc_act >= 1 && npc_acc < 1)
    {
        enemy_fight_anim();
        for(a = 0; a < 6; ++a)
        {
            delay(100);
            DISPLAY_OFF;
            delay(100);
            DISPLAY_ON;
        }
        DISPLAY_OFF;
        sprite_clean();
        LETTER_COUNT = 0;
        print("miss!\0", 64, 80);
        clear_screen();
        DISPLAY_ON;
        delay(500);
    }


    /* enemy defends */
    if(npc_act == 0)
    {
        DISPLAY_OFF;
        clear_screen();
        sprite_clean();
        LETTER_COUNT = 0; 
        if(ENEMY == 0)
        {
            print("asakawa\0", 56, 75);
            print("defends\0", 56, 91);
        }
        if(ENEMY == 1)
        {
            print("the crab\0", 56, 75);
            print("defends\0", 56, 91);
        }
        if(ENEMY == 2)
        {
            print("king crab\0", 56, 75);
            print("defends\0", 56, 91);
        }
        DISPLAY_ON;
        delay(800);
    }
}

/**
 * fight helper function. 
 * makes number decision before appearance.
 */
void fight_config(void)
{
    /** 
     * generate random number to find 
     * out asakawa's action and accuracy
     */
    seed = DIV_REG;
    seed |= (UWORD)DIV_REG << 8;
    initarand(seed);
    /* enemies action */
    npc_act = rand()%5;
    /* enemies accuracy */
    npc_acc = rand()%5;
    /* hero's accuracy */
    hero_acc = rand()%10;
    /* enemies action */
    first_fighter = rand()%5;
}


/* checking to see if you're dead */
void damage(UINT8 *fighter_hp)
{
    if(ENEMY == 0)
    {
        if(choice == DEFEND && npc_acc >= 1 && npc_act >= 1)
        {
            for(i = (SHOOT-DEFEND); i > 0; --i)
            {
                --(*fighter_hp);
                if((*fighter_hp) == 0)
                {
                    option = GAME_OVER;
                    STATE = DEAD;
                }
            }
        }
        else if(npc_acc >= 1 && npc_act >= 1 && choice == PUNCH)
        {
            for(i = SHOOT; i > 0; --i)
            {
                --(*fighter_hp);
                if((*fighter_hp) == 0)
                {
                    option = GAME_OVER;
                    STATE = DEAD;
                }
            }
        }
    }
    if(ENEMY == 1)
    {
        if(choice == DEFEND && npc_acc >= 1 && npc_act >= 1)
        {
            for(i = (CLAW-DEFEND); i > 0; --i)
            {
                --(*fighter_hp);
                if((*fighter_hp) == 0)
                {
                    option = GAME_OVER;
                    STATE = DEAD;
                }
            }
        }
        else if(npc_acc >= 1 && npc_act >= 1 && (choice == PUNCH || 
                    choice == ITEM))
        {
            for(i = CLAW; i > 0; --i)
            {
                --(*fighter_hp);
                if((*fighter_hp) == 0)
                {
                    option = GAME_OVER;
                    STATE = DEAD;
                }
            }
        }
    }
    if(ENEMY == 2)
    {
        if(choice == DEFEND && npc_acc >= 1 && npc_act >= 1)
        {
            for(i = (KING_CLAW-DEFEND); i > 0; --i)
            {
                --(*fighter_hp);
                if((*fighter_hp) == 0)
                {
                    option = GAME_OVER;
                    STATE = DEAD;
                }
            }
        }
        else if(npc_acc >= 1 && npc_act >= 1 && (choice == PUNCH ||
                    choice == ITEM))
        {
            for(i = KING_CLAW; i > 0; --i)
            {
                --(*fighter_hp);
                if((*fighter_hp) == 0)
                {
                    option = GAME_OVER;
                    STATE = DEAD;
                }
            }
        }
    }
}

void lower_hp(UINT8 *hit, UINT8 defended, UINT8 *enemy_hp)
{
    if(defended)
    {
        for(i = ((*hit)-DEFEND); i > 0; --i)
        {
            --(*enemy_hp);
            if((*enemy_hp) == 0)
                STATE = BATTLE_WIN;
        }
    }
    else
    {
        if(ENEMY == 0 || CRAB_CAUGHT)
        {
            for(i = (*hit); i > 0; --i)
            {
                --(*enemy_hp);
                if((*enemy_hp) == 0)
                    STATE = BATTLE_WIN;
            }
        }
    }
}

void enemy_damage(UINT8 *enemy_hp)
{
    if(npc_act == 0)
    {
        if(choice == ITEM && CHOSEN_ITEM == NET && hero_acc > 0)
            return;
        if(choice == ITEM && CHOSEN_ITEM == CLUB && hero_acc > 0)
            lower_hp(&CLUB, 1, enemy_hp);
        if(choice == PUNCH && ENEMY == 0 && hero_acc >= 3)
            return;
    }
    if(npc_act > 0)
    {
        if(choice == ITEM && CHOSEN_ITEM == NET && hero_acc > 0)
            lower_hp(&NET, 0, enemy_hp);
        if(choice == ITEM && CHOSEN_ITEM == CLUB && hero_acc > 0)
            lower_hp(&CLUB, 0, enemy_hp);
        if(choice == PUNCH && ENEMY == 0 && hero_acc >= 3)
            lower_hp(&PUNCH, 0, enemy_hp);
    }

    /*if(npc_act == 0 && choice == ITEM && CHOSEN_ITEM == CLUB)
      {
      for(i = ((CLUB)-DEFEND); i > 0; --i)
      {
      --(*enemy_hp);
      if((*enemy_hp) == 0)
      STATE = BATTLE_WIN;
      }
      }
      if(
      else
      {
      for(i = (*damage_amnt); i > 0; --i)
      --(*enemy_hp);
      if((*enemy_hp) == 0)
      STATE = BATTLE_WIN;
      }*/
}

/**
 * make decision on randomly generated numbers.
 */
void fight(UINT8 *fighter_hp, UINT8 *enemy_hp)
{
    fight_config();
    if(first_fighter >= 1)
    {
        npc_fight();
        damage(fighter_hp);
        if(STATE != DEAD)
        {
            hero_fight();//enemy_hp);
            enemy_damage(enemy_hp);
        }
    }
    else
    {
        hero_fight();//enemy_hp);
        enemy_damage(enemy_hp);
        if(STATE != BATTLE_WIN)
        {
            npc_fight();
            damage(fighter_hp);
        }
    }
    npc_act = 0;
    npc_acc = 0;
    hero_acc = 0;
    choice = 0;
    CHOSEN_ITEM = 0;
    first_fighter = 0;
}

void show_fighter_stats(void)
{
    /* HP */
    battle_print("hero\0", 88, 40);
    battle_print("hp\0", 88, 56);

    itoa(HERO_HP, h_hp);
    battle_print(h_hp, 96, 72);
    battle_print("/10\0", 122, 72);
    /**
     * if you're experiencing problems, 
     * try cleaning sprites and setting LETTER_COUNT to 0. 
     */
    /*itoa(CRAB_HP, e_hp);
      battle_print(e_hp, 96, 104);
      if(ENEMY == 0)
      battle_print("100\0", 122, 104);
      if(crab == 0)
      battle_print("/5\0", 122, 104);
      if(crab == 1)
      battle_print("/10\0", 122, 104);*/
}

void game_over_screen(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
    clear_screen();
    print("game over", 44, 72);
}
