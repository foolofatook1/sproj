#include "sprites/wizard.c"
#include "rooms/room1.c"
#include "rooms/the_tiles.c"

void setup_sprite(void);
void display_sprite(void);
void sprite_walk(void);
void bkg(void);

#define STEP 2 /* Size of sprite step. */

/* Sprite Vector 2 for the left half and right half. */
UINT8 player[2][2];

UINT8 down = 1;
UINT8 up = 0;
UINT8 left = 0;
UINT8 right = 0;

/* Draw the background */
void bkg(void)
{
    DISPLAY_ON;
    set_bkg_data(0,10,the_tiles);
    set_bkg_tiles(0,0,20,18,room1);
}

/* Initialize the sprite. */
void setup_sprite(void)
{
    /* Init position */
    player[0][0] = 75;
    player[0][1] = 75;
    player[1][0] = 75+8; /* right half */
    player[1][1] = 75;
   
    /* Two 8x16 sprites. */
    SPRITES_8x16;
    set_sprite_data(0, 32, wizard); /* allocate 32 8x8 blocks */ 

    /* Initialize forward facing sprite */
    set_sprite_tile(0,0); /* left half */
    move_sprite(0, player[0][0], player[0][1]);
    set_sprite_tile(1,2); /* right half */
    move_sprite(1, player[1][0], player[1][1]);

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
        player[0][1]+=STEP;
        player[1][1]+=STEP;

        down = 1;
        up = 0;
        left = 0;
        right = 0;
    }
    
    /* UP */
    if(joypad() & J_UP)
    {
        player[0][1]-=STEP;
        player[1][1]-=STEP;

        down = 0; 
        up = 1;
        left = 0; 
        right = 0;
    }

    /* LEFT */
    if(joypad() & J_LEFT)
    {
        player[0][0]-=STEP;
        player[1][0]-=STEP;
    
        down = 0;
        up = 0;
        left = 1;
        right = 0;
    }

    /* RIGHT */
    if(joypad() & J_RIGHT)
    {
        player[0][0]+=STEP;
        player[1][0]+=STEP;

        down = 0; 
        up = 0; 
        left = 0; 
        right = 1;
    }
}

/* Make the sprite move. */
void display_sprite(void)
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
