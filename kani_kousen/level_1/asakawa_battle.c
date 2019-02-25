#include <gb/gb.h>
#include <stdio.h>

/* sprites */
#include "../assets/sprites/hero_idle_back.c"
#include "../assets/sprites/asakawa_front_idle.c"

/* bkg */
#include "../text/text.c"
#include "assets/small_chain_border.c"

UINT8 hero_pos[2][2];
UINT8 asakawa_pos[2][2];

UINT8 SPRITE_WIDTH = 8;

void main(void)
{
    wait_vbl_done();

    DISPLAY_OFF;
    HIDE_BKG;
    HIDE_SPRITES;
    HIDE_WIN;

    SPRITES_8x16;

    /* setup the bkg */
    set_bkg_data(0,10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18,small_chain_border);

    /* setup sprites */
    /* hero */
    hero_pos[0][0] = 80;
    hero_pos[0][1] = 72;
    hero_pos[1][0] = hero_pos[0][0]+SPRITE_WIDTH;
    hero_pos[1][1] = hero_pos[0][1];

    set_sprite_data(0, 8, hero_idle_back);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    /* asakawa */
    asakawa_pos[0][0] = 80;
    asakawa_pos[0][1] = 40;
    asakawa_pos[1][0] = asakawa_pos[0][0]+SPRITE_WIDTH;
    asakawa_pos[1][1] = asakawa_pos[0][1];

    set_sprite_data(8, 8, asakawa_front_idle);
    set_sprite_tile(2, 8);
    set_sprite_tile(3, 10);


    /* display sprites */
    /* hero */
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    /* asakawa */
    move_sprite(2, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(3, asakawa_pos[1][0], asakawa_pos[1][1]);

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
}
