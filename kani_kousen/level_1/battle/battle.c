#include "battle.h"

/*void fight_ctrl(void)
{
    while(1)
    {
    }
}*/

/**
 * hnb    -- hero number of tiles
 * enb    -- enemy number of tiles
 * x_data -- sprite sheet
 */
void sprite_setup(UINT8 hnb, unsigned char *hero_data,
                  UINT8 enb, unsigned char *enemy_data)

{
    sprite_clean();
    bkg_clean();
    SPRITES_8x16;
    set_sprite_data(0, 8, hero_data);
    set_sprite_data(hnb, enb, enemy_data);

    /* asakawa */ 
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 1);
    set_sprite_tile(2, 2);
    set_sprite_tile(3, 3);

    move_sprite(0, 16, 32); // top left of the head
    move_sprite(1, 16, 40); // bottom left of body
    move_sprite(2, 24, 32); // top right of head
    move_sprite(3, 24, 40); // bottom right of body

    /* hero */
    set_sprite_tile(4, hnb);
    set_sprite_tile(5, hnb+1);
    set_sprite_tile(6, hnb+2);
    set_sprite_tile(7, hnb+3);

    move_sprite(4, 16, 56);
    move_sprite(5, 16, 64);
    move_sprite(6, 24, 56);
    move_sprite(7, 24, 64);
}

void fight(void)
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

    npc_act = rand() & 1;
    npc_acc = rand() & 1;

/* prints randomly generated number 
    itoa(npc_act, a);
    itoa(npc_acc, b);
    
    battle_bkg_clean();
    sprite_clean();
    battle_print(a, 16, 32);
    battle_print(b, 16, 48);
    LETTER_COUNT = 0;*/

}
