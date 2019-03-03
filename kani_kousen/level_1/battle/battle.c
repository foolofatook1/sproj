#include "battle.h"

/*void fight_ctrl(void)
  {
  while(1)
  {
  }
  }*/


void choice_handler(UINT8 arrow_y)
{
    if(arrow_y == PUNCH_LOC)
        choice = PUNCH;
}

void hero_fight(UINT8 enemy_hp)
{
    if(choice == PUNCH)
    {
        hero_fight_anim();
        enemy_hp -= PUNCH;
    }

    /*   if(choice == DEFEND)
         {
         hero_defend_anim();
         hero_hp += DEFEND;
         }*/

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

    /* clear the bkg */
    set_bkg_data(0,4, blank_screen_tiles);
    set_bkg_tiles(0,0,20,18,blank_screen);

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

void npc_fight(UINT8 hero_hp)
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

    hero_hp -= SHOOT;
    /* prints randomly generated number 
       itoa(npc_act, a);
       itoa(npc_acc, b);

       battle_bkg_clean();
       sprite_clean();
       battle_print(a, 16, 32);
       battle_print(b, 16, 48);
       LETTER_COUNT = 0;*/

}
