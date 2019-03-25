#include <gb/gb.h>
#include "../kani_kousen/assets/sprites/miner_walk_up.h"

void main(void)
{
    wait_vbl_done();
    DISPLAY_ON;
    SHOW_SPRITES;
    set_sprite_data(0,4, miner_walk_up);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 1);
    set_sprite_tile(2, 2);
    set_sprite_tile(3, 3);
    move_sprite(0, 80, 75); // left part of head
    move_sprite(1, 80, 83); // left leg
    move_sprite(2, 88, 75); // right part of head
    move_sprite(3, 88, 83); // right leg
    while(1)
    {
        delay(200);
        set_sprite_prop(0, S_FLIPX);
        set_sprite_prop(1, S_FLIPX);
        set_sprite_prop(2, S_FLIPX);
        set_sprite_prop(3, S_FLIPX);
        move_sprite(0, 88, 75);
        move_sprite(1, 88, 83);
        move_sprite(2, 80, 75);
        move_sprite(3, 80, 83);
        delay(200);
        set_sprite_prop(0, S_FLIPX&0x0);
        set_sprite_prop(1, S_FLIPX&0x0);
        set_sprite_prop(2, S_FLIPX&0x0);
        set_sprite_prop(3, S_FLIPX&0x0);
        move_sprite(0, 80, 75);
        move_sprite(1, 80, 83);
        move_sprite(2, 88, 75);
        move_sprite(3, 88, 83);
    }
} 
