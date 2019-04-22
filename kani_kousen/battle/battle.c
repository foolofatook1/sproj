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
#include "../assets/level_assets/level_assets.h"
#include "../assets/sprites/soldier.h"
#include "../assets/sprites/asakawa_front_idle.h"
#include "../assets/sprites/hero_back_idle.h"
#include "../assets/sprites/fisherman_idle_back.h"
#include "../assets/sprites/student_idle_back.h"
#include "../assets/sprites/asakawa_air_shot.h"

/**
 * 0 = asakawa;
 * 1 = crab
 * 2 = king crab
 * 3 = beriberi
 * 4 = lice
 */

UINT8 PUNCH = 1;
UINT8 DEFEND = 2;
UINT8 ITEM = 3;

UINT8 NET = 2;
UINT8 CLUB = 5;

UINT8 SHOOT = 10;
UINT8 CLAW = 2;
UINT8 KING_CLAW = 3;

UINT8 PUNCH_LOC = 32;

/** change above to define **/
UINT8 BATTLE_CHOICE = 0;
UINT8 FIGHT_CHOICE = 1;
UINT8 RUN_CHOICE = 2;
UINT8 ITEM_CHOICE = 3;
UINT8 FIGHTING = 4;
UINT8 DEAD = 5;
UINT8 BATTLE_WIN = 6;

UINT8 ENEMY = 0;
UINT8 BATTLE_NUM = 0;

UBYTE ITEMS = 0;
UINT8 CHOSEN_ITEM = 0;
UINT8 CHOOSING = 0;

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
    sprite_clean(0);
    LETTER_COUNT = 0;
    //battle_bkg_clean();
    battle_print("YOU\0", 18, 32);
    battle_print("CANkT\0", 18, 48);
    battle_print("ESCAPEl\0", 18, 64); 
    show_fighter_stats();
    delay(1500);
    back();
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
    sprite_clean(0);
    LETTER_COUNT = 0;
    battle_bkg_clean();
    battle_print("j\0", 18, 32);
    battle_print("iPUNCH\0", 18, 32);
    battle_print("AiSELECT\0", 16, 130);
    battle_print("BiBACK\0", 16, 142);
    show_fighter_stats();
}

void item_opt(void)
{
    sprite_clean(0);
    LETTER_COUNT = 0;
    battle_bkg_clean();
    if(ITEMS == 0)
    {
        battle_print("iEMPTY\0", 18, 32);
        battle_print("AiSELECT\0", 16, 130);
        battle_print("BiBACK\0", 16, 142);
    }
    if(ITEMS == 2)
    {
        CHOOSING = 1;
        arrow_x = 24;
        arrow_y = 32;
        battle_print("j\0", arrow_x, arrow_y);
        battle_print("iCLUB\0", 24, 32);
        battle_print("iNET\0", 24, 48);
        battle_print("AiSELECT\0", 16, 130);
        battle_print("BiBACK\0", 16, 142);
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

    sprite_clean(0);
    LETTER_COUNT = 0;

    arrow_x = 20;
    arrow_y = 32;
    /* setup the bkg */
    set_bkg_data(0,10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18,small_chain_border);

    hide_sprites();
    /* selection menu */
    battle_print("j\0", arrow_x, arrow_y);
    battle_print("iFIGHT\0", 18, 32);
    battle_print("iDEFEND\0", 18, 48);
    battle_print("iRUN\0", 18, 64);
    battle_print("iITEM\0", 18, 80);
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
}

/**
 * need to refine this logic 
 */
void hero_fight(void)
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
        sprite_clean(0);
        LETTER_COUNT = 0;
        if((choice == ITEM) && (CHOSEN_ITEM == CLUB) && 
                (ENEMY > 0) && (!CRAB_CAUGHT))
        {
            print("YOUiNEED\0", 72, 64);
            print("TOiCATCH\0", 72, 80);
            print("THEiCRABl\0", 72, 96);
            delay(500);
        }
        else if((choice == ITEM) && (CHOSEN_ITEM == NET) && 
                (hero_acc > 0))
        {
            print("CAUGHTl\0", 72, 80);
            CRAB_CAUGHT = 1;
            delay(500);
        }
        else if(((choice == PUNCH) && (hero_acc >= 3)) || 
                ((choice == ITEM) && hero_acc > 0))
        {
            print("YOUiHIT\0", 56, 72);
            if(ENEMY == 0)
                print("ASAKAWA\0", 56, 88);
            if(ENEMY == 1)
                print("AiCRAB\0", 56, 88);
            if(ENEMY == 2)
                print("KINGiCRAB\0", 56, 88);
            delay(500);
        }
        /*        if(choice == PUNCH && (ENEMY == 1 || ENEMY == 2))
                  {
                  print(" no use\0", 56, 56);
                  print("punching\0", 56, 72);
                  print(" a crab!\0", 56, 88);
                  delay(500);
                  };
                  if(choice == PUNCH && ENEMY == 0 && hero_acc >= 3)
                  {
                  print("hit!\0", 72, 80);
                  delay(500);
                  }

                  if((choice == ITEM) && (CHOSEN_ITEM == CLUB) && 
                  (CRAB_CAUGHT) && (hero_acc > 0))
                  {
                  print("crushed!\0", 72, 80);
                  delay(500);
                  }
         */
        /* fighter chooses punch and misses */
                  else if(((choice == PUNCH) && (hero_acc < 3)) || 
                          ((choice == ITEM) && (hero_acc == 0)))
                  {
                      sprite_clean(0);
                      LETTER_COUNT = 0;
                      print("YOUiMISSl\0", 64, 80);
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
    sprite_clean(0);
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

    if(striking)
    {
        if(!REVOLUTION_2)
        {
            set_sprite_data(16, 2, soldier);
            /* soldiers */
            set_sprite_tile(8, 16); // two on the left
            set_sprite_tile(9, 17);
            set_sprite_tile(10, 16); // two on the right
            set_sprite_tile(11, 17);
            set_sprite_tile(12, 16); 
            set_sprite_tile(13, 17);
            set_sprite_tile(14, 16);
            set_sprite_tile(15, 17);
            set_sprite_prop(14, S_FLIPX);
            set_sprite_prop(15, S_FLIPX);
            set_sprite_prop(10, S_FLIPX);
            set_sprite_prop(11, S_FLIPX);
            move_sprite(8, 51, 40);
            move_sprite(9, 51, 48);
            move_sprite(10,51+sprite_width, 40);
            move_sprite(11,51+sprite_width, 48);
            move_sprite(12,99, 40);
            move_sprite(13,99, 48);
            move_sprite(14,99+sprite_width, 40);
            move_sprite(15,99+sprite_width, 48);
        }

        /* fisherman && student */
        set_sprite_data(18, 2, fisherman_idle_back);
        set_sprite_data(20, 2, student_idle_back);
        set_sprite_tile(16, 18);
        set_sprite_tile(17, 19);
        set_sprite_tile(18, 18);
        set_sprite_tile(19, 19);
        set_sprite_tile(20, 20);
        set_sprite_tile(21, 21);
        set_sprite_tile(22, 20);
        set_sprite_tile(23, 21);
        set_sprite_prop(18, S_FLIPX);
        set_sprite_prop(19, S_FLIPX);
        set_sprite_prop(22, S_FLIPX);
        set_sprite_prop(23, S_FLIPX);
        move_sprite(16, 51, 72);
        move_sprite(17, 51, 80);
        move_sprite(18, 51+sprite_width, 72);
        move_sprite(19, 51+sprite_width, 80);
        move_sprite(20, 99, 72);
        move_sprite(21, 99, 80);
        move_sprite(22, 99+sprite_width, 72);
        move_sprite(23, 99+sprite_width, 80);
    }
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
        sprite_clean(0);
        LETTER_COUNT = 0;
        print("YOUkREiHITl\0", 60, 80);
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
        sprite_clean(0);
        LETTER_COUNT = 0;
        clear_screen();
        print("THEYiMISSl\0", 60, 80);
        DISPLAY_ON;
        delay(500);
    }

    /* enemy defends */
    if(npc_act == 0)
    {
        DISPLAY_OFF;
        clear_screen();
        sprite_clean(0);
        LETTER_COUNT = 0; 
        if(ENEMY == 0)
            print("ASAKAWA\0", 56, 75);
        if(ENEMY == 1)
            print("THEiCRAB\0", 56, 75);
        if(ENEMY == 2)
            print("KINGiCRAB\0", 56, 75);

        print("DEFENDS\0", 56, 91);
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
    if(start_hp == 50)
        SHOOT = 30; // going to need to set this back to 10 later.
    if(start_hp == 100)
        SHOOT = 10;
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
        else if(npc_acc >= 1 && npc_act >= 1 && choice == PUNCH || 
                choice == ITEM)
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
    if(start_hp == 50)
        (*hit) = 3;
    if(start_hp == 100)
        (*hit) = 10;
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
            lower_hp(&PUNCH, 1, enemy_hp);
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
            hero_fight();
            enemy_damage(enemy_hp);
        }
    }
    else
    {
        hero_fight();
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
    battle_print("HP\0", 88, 56);
    itoa(HERO_HP, h_hp);
    
    for(i = 0; h_hp[i] != '\0'; ++i)
        h_hp[i] = (h_hp[i]+43);
    battle_print(h_hp, 88, 72);
    /* HP */
    if(start_hp == 10)
    {
        if(HERO_HP == start_hp)
            battle_print("[\0", 96, 72);
        battle_print("WORKER\0", 88, 40);
        battle_print("h\\[\0", 122, 72);
    }
    if(start_hp == 50)
    {
        battle_print("LEADERS\0", 88, 40);
        battle_print("[\0", 96, 72);
        battle_print("h`[\0", 122, 72);
    }
    if(start_hp == 100)
    {
        battle_print("EVRY\\\0", 88, 40);
        if(HERO_HP == start_hp)
            battle_print("[[\0", 96, 72);
        else
            battle_print("[\0", 96, 72);
        battle_print("h\\[[\0", 122, 72);
    }
}

/*void game_over_screen(void)
{
    sprite_clean(0);
    LETTER_COUNT = 0;
    clear_screen();
    print("AiCRUSHING", 48, 72);
    print("DAY", 72, 88);
    //print("GAMEiOVER", 44, 72);
    delay(1000);
    sprite_clean(0);
    LETTER_COUNT = 0;
    clear_screen();
    print("AiCONTINUE\0", 44, 72);
    print("BiQUIT\0", 60, 88);
    while(1)
    {
        if(joypad() & J_A)
        {
            option = SAVE;
            HERO_HP = start_hp;
            break;
        }
        if(joypad() & J_B)
        {
            ENEMY = 0;
            SAVE = 0;
            option = START;
            HERO_HP = 10;
            break;
        }
    }
}*/
