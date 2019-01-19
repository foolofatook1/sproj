#include "include.h"

#include "sprites/door_trig.c"
#include "rooms/room1.c"
#include "rooms/black.c"

void open_door(void);
void setup_doors(void);
void at_door(void);
void scroll_doors(int, int);
int door_collide(void);

/* a temporary quick test for scene changes. */
void enter_room(void);

/*typedef struct door
{
    UINT8 x; UINT8 y;
} door;*/

UINT8 door[2][2];

/*door doors[2];*/

void setup_doors(void)
{
    /* Init position */
    door[0][0] = 64;
    door[0][1] = 152;
    door[1][0] = 64+8; 
    door[1][1] = 152;
  
    /* Two 8x16 sprites. */
    set_sprite_data(32, 52, door_trig); /* allocate 32 8x8 blocks */ 

    /* door 0 */
    set_sprite_tile(2,32); 
    move_sprite(2, door[0][0], door[0][1]);
    set_sprite_tile(3,34); 
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

void scroll_doors(int x, int y)
{
    move_sprite(2, door[0][0]+=x, door[0][1]+=y);
    move_sprite(3, door[1][0]+=x, door[1][1]+=y);
}

int door_collide(void)
{
    if(player[0][0] > door[0][0]-8 && player[0][0] < door[0][0]+8 &&
        player[0][1] > door[0][1] && player[0][0] < door[0][0] &&
        (joypad() & J_UP))
        return 1;
    else
        return 0;
}

void enter_room(void)
{
   set_bkg_tiles(0,0,40,36,black);
   set_bkg_tiles(0,10,20,18,room1);
}