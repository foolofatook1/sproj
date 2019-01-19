#include "sprites/wizard.c"
#include "rooms/castle_town.c"
#include "rooms/the_tiles.c"

#include "triggers.h"

void setup_sprites(void);
void display_sprites(void);
void sprite_walk(void);
void bkg(void);

UINT8 down = 1;
UINT8 up = 0;
UINT8 left = 0;
UINT8 right = 0;

/* Draw the background */
void bkg(void)
{
    DISPLAY_ON;
    set_bkg_data(0,10,the_tiles);
    set_bkg_tiles(0,0,40,36,castle_town);
}

/* Initialize the sprite. */
void setup_sprites(void)
{
    /* Init position */
    player[0][0] = 75;
    player[0][1] = 40;
    player[1][0] = 75+8; /* right half */
    player[1][1] = 40;
   
    /* Two 8x16 sprites. */
    SPRITES_8x16;
    set_sprite_data(0, 32, wizard); /* allocate 32 8x8 blocks */ 

    /* Initialize forward facing sprite */
    set_sprite_tile(0,0); /* left half */
    move_sprite(0, player[0][0], player[0][1]);
    set_sprite_tile(1,2); /* right half */
    move_sprite(1, player[1][0], player[1][1]);

    setup_doors(); /* Display the doors. */

    SHOW_SPRITES;
    /**
     * HIDE_WIN and SHOW_BKG are necessary
     * so that screen refreshes. 
     */
    HIDE_WIN;
    SHOW_BKG;
}

/* Make the sprite change location with joypad. */
void sprite_walk(void)
{
 
    /* DOWN */
    if(joypad() & J_DOWN)
    {
        scroll_bkg(0,4);
        scroll_doors(0,-4);

        down = 1;
        up = 0;
        left = 0;
        right = 0;
    }
    
    /* UP */
    if(joypad() & J_UP)
    {
        scroll_bkg(0,-4);
        scroll_doors(0,4);

        down = 0; 
        up = 1;
        left = 0; 
        right = 0;
    }

    /* LEFT */
    if(joypad() & J_LEFT)
    {
        scroll_bkg(-4,0);
        scroll_doors(4,0);

        down = 0;
        up = 0;
        left = 1;
        right = 0;
    }

    /* RIGHT */
    if(joypad() & J_RIGHT)
    {
        scroll_bkg(4,0);
        scroll_doors(-4,0);

        down = 0; 
        up = 0; 
        left = 0; 
        right = 1;
    }

    /* we are at a door -> go inside */
    if(door_collide() == 1)
    {
        open_door();
        enter_room();
    }
}

/* Make the sprite move. */
void display_sprites(void)
{
    if(up == 1)
    {
        set_sprite_tile(0,28);
        move_sprite(0, player[0][0], player[0][1]);
        set_sprite_tile(1,30);
        move_sprite(1, player[1][0], player[1][1]);
        delay(100);

        set_sprite_tile(0,24);
        move_sprite(0, player[0][0], player[0][1]);
        set_sprite_tile(1,26);
        move_sprite(1, player[1][0], player[1][1]);
        delay(100);
    }

    if(down == 1)
    {
        set_sprite_tile(0,4);
        move_sprite(0, player[0][0], player[0][1]);
        set_sprite_tile(1,6);
        move_sprite(1, player[1][0], player[1][1]);
        delay(100);

        set_sprite_tile(0,0);
        move_sprite(0, player[0][0], player[0][1]);
        set_sprite_tile(1,2);
        move_sprite(1, player[1][0], player[1][1]);
        delay(100);
    }

    if(left == 1)
    {
        set_sprite_tile(0,12);
        move_sprite(0, player[0][0], player[0][1]);
        set_sprite_tile(1,14);
        move_sprite(1, player[1][0], player[1][1]);
        delay(100);

        set_sprite_tile(0,8);
        move_sprite(0, player[0][0], player[0][1]);
        set_sprite_tile(1,10);
        move_sprite(1, player[1][0], player[1][1]);
        delay(100);
    }

    if(right == 1)
    {
        set_sprite_tile(0,20);
        move_sprite(0,player[0][0],player[0][1]);
        set_sprite_tile(1,22);
        move_sprite(1,player[1][0],player[1][1]);
        delay(100);

        set_sprite_tile(0,16);
        move_sprite(0, player[0][0], player[0][1]);
        set_sprite_tile(1,18);
        move_sprite(1, player[1][0], player[1][1]);
        delay(100);
    }
}
