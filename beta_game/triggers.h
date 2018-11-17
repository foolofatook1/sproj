#include "sprites/door_trig.c"

void open_door(void);
void setup_doors(void);
void at_door(void);

/*typedef struct door
{
    UINT8 x;
    UINT8 y;
} door;*/

UINT8 door[2][2];

/*door doors[2];*/

void setup_doors(void)
{
    /* Init position */
    door[0][0] = 90;
    door[0][1] = 30;
    door[1][0] = 90+8; /* right half */
    door[1][1] = 30;
   
    /* Two 8x16 sprites. */
    set_sprite_data(32, 52, door_trig); /* allocate 32 8x8 blocks */ 

    /* Initialize forward facing sprite */
    set_sprite_tile(2,32); /* left half */
    move_sprite(2, door[0][0], door[0][1]);
    set_sprite_tile(3,34); /* right half */
    move_sprite(3, door[1][0], door[1][1]);
}

void open_door(void)
{
    set_sprite_tile(2,32);
    move_sprite(2, door[0][0], door[0][1]);
    set_sprite_tile(3,34); 
    move_sprite(3, door[1][0], door[1][1]);
    delay(100);

    set_sprite_tile(2,36);
    move_sprite(2, door[0][0], door[0][1]);
    set_sprite_tile(3,38);
    move_sprite(3, door[1][0], door[1][1]);
    delay(100);

    set_sprite_tile(2,40);
    move_sprite(2, door[0][0], door[0][1]);
    set_sprite_tile(3,42);
    move_sprite(3, door[1][0], door[1][1]);
    delay(100);
    
    set_sprite_tile(2,44);
    move_sprite(2, door[0][0], door[0][1]);
    set_sprite_tile(3,46);
    move_sprite(3, door[1][0], door[1][1]);
    delay(100);

    set_sprite_tile(2,48);
    move_sprite(2, door[0][0], door[0][1]);
    set_sprite_tile(3,50);
    move_sprite(3, door[1][0], door[1][1]);
}
