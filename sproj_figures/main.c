#include <gb/gb.h>
#include "main.h"
#include "text.h"

void main(void)
{
    /* sprites */
    /*set_sprite_data(  0,32, asakawa_air_shot);
    set_sprite_data( 32, 8, asakawa_front_idle);
    set_sprite_data( 40, 8, asakawa_walk_side);
    set_sprite_data( 48, 4, bed);
    set_sprite_data( 52, 4, fisherman_front_idle);
    set_sprite_data( 56, 8, fisherman_idle_back);
    set_sprite_data( 64, 8, fisherman_walk_side);
    set_sprite_data( 72, 4, fisherman_walk_up);
    set_sprite_data( 76, 8, hero_back_idle);
    set_sprite_data( 84, 8, hero_front_idle);
    set_sprite_data( 92, 4, hero_lie_down);
    set_sprite_data( 96, 4, hero_walk_down);
    set_sprite_data(100, 8, hero_walk_sideways);
    set_sprite_data(108, 8, hero_walk_up);
    set_sprite_data(116, 8, king_crab);
    set_sprite_data(124, 4, miner_front_idle);
    set_sprite_data(128, 8, miner_idle_back);
    set_sprite_data(136, 8, miner_walk_left);
    set_sprite_data(144, 8, miner_walk_up);
    set_sprite_data(152, 8, norm_crab);
    set_sprite_data(160, 4, soldier);
    set_sprite_data(164, 4, student_front_idle);
    set_sprite_data(168, 8, student_idle_back);
    set_sprite_data(176, 4, student_lie_down);*/
    set_sprite_data(0,46, font);
    print("HELLO\nWORLD\0", 24, 32);
   
    DISPLAY_ON;
    SHOW_SPRITES;

    /* bkg */
    set_bkg_data( 0, 4, blank_screen_tiles);
    set_bkg_data( 4,10, chain_border_tiles); 
    set_bkg_data(14,18, sh_tiles);
}
