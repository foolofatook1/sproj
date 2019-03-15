#include <rand.h>
#include <gb/drawing.h>
#include "asakawa_battle.h"
#include "battle.h"
#include "../../text/text.h"

UINT8 PUNCH = 1;
UINT8 DEFEND = 2;
UINT8 SHOOT = 5;

UINT8 PUNCH_LOC = 32;

UINT8 ASAKAWA_HP = 100;
UINT8 HERO_HP = 10;
UWORD h_hp[4];
UINT8 choice = 0;
UINT8 enemy_choice;


/* a stepping variable for character animations */
UINT8 y = 72;
/* another animation counter */
UINT8 a = 0;



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

    arrow_x = 20;
    arrow_y = 32;

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



void choice_handler(UINT8 arrow_y) 
{
    if(arrow_y == PUNCH_LOC)
        choice = PUNCH;
}

void hero_fight(UINT8 *enemy_hp, UINT8 *hero_hp) 
{
    if(choice == PUNCH)
    {
        UBYTE hero_acc = 0; //UBYTE
        UWORD seed;
        seed = DIV_REG;
        seed |= (UWORD)DIV_REG << 8;

        initarand(seed);

        /* hero's accuracy */
        hero_acc = rand() & 1;

        if(hero_acc == 1)
        {
            hero_fight_anim();
            for(a = 0; a < 6; ++a)
            {
                delay(100);
                DISPLAY_OFF;
                delay(100);
                DISPLAY_ON;
            }
            DISPLAY_OFF;
            sprite_clean();
            print("hit!", 72, 80);
            clear_screen();
            *enemy_hp -= PUNCH;
            DISPLAY_ON;
        }
        else
        {
            hero_fight_anim();
            for(a = 0; a < 6; ++a)
            {
                delay(100);
                DISPLAY_OFF;
                delay(100);
                DISPLAY_ON;
            }
            DISPLAY_OFF;
            sprite_clean();
            print("miss!", 64, 80);
            clear_screen();
            DISPLAY_ON;
        }
    }

    if(choice == DEFEND)
    {
        hero_defend_anim();
        *hero_hp += DEFEND;
    }

}

void hero_defend_anim(void) 
{
    sprite_setup(8, hero_back_idle, 8, asakawa_front_idle);
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

void hero_fight_anim(void) 
{
    sprite_setup(8, hero_back_idle, 8, asakawa_front_idle);

    while(y > 58)
    {
        delay(100);
        move_sprite(4, 77, y);
        move_sprite(5, 77, y+8);
        move_sprite(6, 84, y);
        move_sprite(7, 84, y+8);
        delay(100);
        --y;
    }
    /**
     * 0000 0100 & 0001 0010 = 0000 0000 
     * 0000 0100 & 0000 0110 = 0000 0100
     * sprites second imgs are 4 apart.
     */
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
    y = 72; // reset y
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

void npc_fight(UINT8 *hero_hp)/*, UINT8 *enemy_hp)*/ 
{

    /** 
     * generate random number to find 
     * out asakawa's action and accuracy
     */
    UBYTE npc_act, npc_acc = 0; //UBYTE
    //UWORD a[4];
    //UWORD b[4];
    UWORD seed;
    seed = DIV_REG;
    seed |= (UWORD)DIV_REG << 8;

    initarand(seed);

    /* enemies action */
    npc_act = rand() & 1;
    /* enemies accuracy */
    npc_acc = rand() & 1;

    if(npc_act == 1 && npc_acc == 1)
    {
        //    asakawa_shoot_anim();

        *hero_hp -= SHOOT;
        for(a = 0; a < 6; ++a)
        {
            delay(100);
            DISPLAY_OFF;
            delay(100);
            DISPLAY_ON;
        }
        DISPLAY_OFF;
        sprite_clean();
        print("hit!", 72, 80);
        clear_screen();
        DISPLAY_ON;
    }
    if(npc_act == 1 && npc_acc == 0)
    {
        //   asakawa_shoot_anim();
        for(a = 0; a < 6; ++a)
        {
            delay(100);
            DISPLAY_OFF;
            delay(100);
            DISPLAY_ON;
        }
        DISPLAY_OFF;
        sprite_clean();
        print("miss!", 64, 80);
        clear_screen();
        DISPLAY_ON;
    }
    //if(npc_act == 0) 
    //{



    /* prints randomly generated number 
       itoa(npc_act, a);
       itoa(npc_acc, b);

       battle_bkg_clean();
       sprite_clean();
       battle_print(a, 16, 32);
       battle_print(b, 16, 48);
       LETTER_COUNT = 0;*/
}
