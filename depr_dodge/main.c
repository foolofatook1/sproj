/**
 * Depression Dodge.
 * A game built based on Dan Cox's tutorial on basic 
 * GameBoy game building. The majority of tiles and sprites 
 * his. And the majority of the code at this point is mine. 
 * Jacob Fisher and Dan Cox.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <gb/gb.h>

/* Sprites */
#include "tiles.c"
#include "dungeon.c"
#include "sprites.c"
#include "alpha.c"

/* Jacob's added sprites/backgrounds. */
#include "heart.c"

/* Jacob's added functions. */
#include "my_functs.h"


void init(void);
void check_input(void);
void update_switches(void);



int x = 89;


/** 
 * The amount of lives you get. Because collisions decrease 
 * counter in roughly three points the lives are multiples of three. 
 */
UINT8 lives =  80;/* eight lives. */

/* The player array will hold the player's position as (0,0) */
UINT8 player[2];


/* Velocity of enemy. */
UINT8 velocity[MAX_ENEMY][2];

/* Initialize the screen and set up sound. */
void init(void)
{
    /*set_bkg_data(0, 47, alpha); Load 47 tiles into background memory */
    /* Use the hello_world array to write background tiles starting at 
       (0, 6) and write for 10 tiles in width and 2 tiles in height. */
    /*set_bkg_tiles(0,6,10,2,hello_world);*/

    DISPLAY_ON;                      /* Turn on the display */

    set_bkg_data(0,100,tiles);        /* Load 23 tiles into background mem */
    set_bkg_tiles(0,0,20,18,dungeon); /*Load the 'sprites' tiles into sprite mem*/

    /* Load the 'sprites' tiles into sprite mem */
    set_sprite_data(0,14,sprites);

    /* Load the 'heart' tiles into sprite mem */
    set_sprite_data(14,22,heart);

    /* Set the first movable sprite (0) to be the first tile in the sprite
     * memory (0). 
     */
    /* smiles */
    set_sprite_tile(0,0);


    /* set up enemies */
    set_sprite_tile(1,1);
    set_sprite_tile(2,1);
    set_sprite_tile(3,1);
    set_sprite_tile(4,1);
    set_sprite_tile(5,1);
    set_sprite_tile(6,1);
    set_sprite_tile(7,1);
    set_sprite_tile(8,1);
    set_sprite_tile(9,1);
    set_sprite_tile(10,1);
    set_sprite_tile(11,1);
    set_sprite_tile(12,1);
    set_sprite_tile(13,1);


    /* hearts */
    set_sprite_tile(14,14);
    set_sprite_tile(15,14);
    set_sprite_tile(16,14);
    set_sprite_tile(17,14);
    set_sprite_tile(18,14);    
    set_sprite_tile(19,14);    
    set_sprite_tile(20,14);
    set_sprite_tile(21,14);
    /*set_sprite_tile(22,14);    
      set_sprite_tile(23,14);
      set_sprite_tile(24,14);
      set_sprite_tile(25,14);
      set_sprite_tile(26,14);
      set_sprite_tile(27,14);
      set_sprite_tile(28,14);
      set_sprite_tile(29,14);
      set_sprite_tile(30,14);
      set_sprite_tile(31,14);
      set_sprite_tile(32,14);*/

    player[0] = 160/2;
    player[1] = 140/2;

    /* enter first enemy! */
    //enemies[0][0] = (rand()%60);
    //enemies[0][1] = 40;

    //for(i = 0; i < MAX_ENEMY; ++i)
    //{
        enemies[0][0] = (rand()%160);
        enemies[0][1] = 40;

/*        enemies[1][0] = (rand()%160);
        enemies[1][1] = 40;

        enemies[2][0] = (rand()%160);
        enemies[2][1] = 40;*/
    //}

    for(i = 0; i < MAX_ENEMY; ++i)
    {
        velocity[i][0] = 1;
        velocity[i][1] = 1;
    }
}

void update_swithces(void)
{
    /* Only show the sprites if we're still playing the game */
    /*if(score(&enemies[0][0],&enemies[0][1],&player[0],&player[1], &lives) == 0 ||
       score(&enemies[0][0],&enemies[0][1],&player[0],&player[1], &lives) <
       100)*/
    SHOW_SPRITES;
    HIDE_WIN;
    SHOW_BKG;
}

/* Check if any buttons are being pressed. */
void check_input(void)
{
    /* B button */
    if(joypad() & J_B)
    {
        /* DO NOTHING AS OF NOW */
        /**
         * Use the 'blank_screen' array to write background tiles starting at 
         * (0,0) and for 20 tiles in width and 18 tiles in height.
         */
        /*set_bkg_tiles(0,0,20,18,blank_screen);*/
    }

    /* UP */
    if(joypad() & J_UP)
    {
        player[1]--;
    }

    /* DOWN */
    if(joypad() & J_DOWN)
    {
        player[1]++;
    }

    /* LEFT */
    if(joypad() & J_LEFT)
    {
        player[0]--;
    }

    /* RIGHT */
    if(joypad() & J_RIGHT)
    {
        player[0]++;
    }

    /** 
     * Move the sprite in the first movable sprite list (0)
     * the position of X (player[0]) and y (player[1])
     */
    move_sprite(0, player[0], player[1]);

    /**
     * Just move the first sprite to start. 
     */
    move_sprite(1, enemies[0][0], enemies[0][1]);

    /* Place the hearts. */
    move_sprite (14, 30, 35);
    move_sprite (15, 40, 35);
    move_sprite (16, 50, 35);
    move_sprite (17, 60, 35);
    move_sprite (18, 70, 35);
    move_sprite (19, 80, 35);
    move_sprite (20, 90, 35);
    move_sprite (21, 100, 35);
    /*move_sprite (22, 105, 35);
      move_sprite (23, 110, 35);    
      move_sprite (24, 115, 35);    
      move_sprite (25, 140, 35);   
      move_sprite (26, 150, 35);    
      move_sprite (27, 160, 35);    
      move_sprite (28, 170, 35);
      move_sprite (29, 180, 35);
      move_sprite (30, 190, 35);
      move_sprite (31, 200, 35);
      move_sprite (32, 210, 35);*/

    /* Is the player colliding with the enemy? */
    for(i = 0; i < enemy_count; ++i)
    {
        if(collision_check(&enemies[i][0], &enemies[i][1], 8, 8, 
                    &player[0], &player[1], 8, 8) == 1)
            set_sprite_tile(0,1);

        else
            set_sprite_tile(0,0);
    }

    /* Is the player colliding with the walls? */
    wall_check(&player[0], &player[1]);   
    for(i = 0; i < enemy_count; ++i)
        wall_check(&enemies[i][0], &enemies[i][1]);
}


void main(void) 
{
    init();

        /*gotogxy(1, 3);
        printf("ENEMY1(x: %d, y: %d)", enemies[1][0], enemies[1][0]);

        gotogxy(1, 4);
        printf("ENEMY2(x: %d, y: %d)", enemies[2][0], enemies[2][0]);

        gotogxy(1, 5);
        printf("ENEMY3(x: %d, y: %d)", enemies[3][0], enemies[3][0]);*/




    while(1)
    {
        check_input();    /* Check for user input */
        update_swithces();/* Make sure the SHOW_SPRITES & SHOW_BKG are on */
        wait_vbl_done();/* Wait until VBLANK to avoid corrupting vis mem */


        for(i = 0; i < enemy_count; ++i)
        {
            /* Keeps track of score. */
            if(score(&enemies[i][0], &enemies[i][1], &player[0], 
                        &player[1], &lives) < 80)
                set_sprite_tile(21,19);

            if(score(&enemies[i][0], &enemies[i][1], &player[0], 
                        &player[1], &lives) < 70)
                set_sprite_tile(20,19);

            if(score(&enemies[i][0], &enemies[i][1], &player[0], 
                        &player[1], &lives) < 60)
                set_sprite_tile(19,19);

            if(score(&enemies[i][0], &enemies[i][1], &player[0], 
                        &player[1], &lives) < 50)
                set_sprite_tile(18,19);

            if(score(&enemies[i][0], &enemies[i][1], &player[0], 
                        &player[1], &lives) < 40)
                set_sprite_tile(17,19);

            if(score(&enemies[i][0], &enemies[i][1], &player[0], 
                        &player[1], &lives) < 30)
                set_sprite_tile(16,19);

            if(score(&enemies[i][0], &enemies[i][1], &player[0], 
                        &player[1], &lives) < 20)
                set_sprite_tile(15,19);

            if(score(&enemies[i][0], &enemies[i][1], &player[0], 
                        &player[1], &lives) < 10)
                set_sprite_tile(14,19);


            /* Game Over.*/
            if(score(&enemies[i][0], &enemies[i][1], &player[0], 
                        &player[1], &lives) <= 0 || score(&enemies[i][0], 
                            &enemies[i][1], &player[0], &player[1], &lives) >
                    100)
            {
                lives = 0;
            }
        }
        /* Game Over cont. */
        if(lives <= 0)
        {
            set_sprite_tile(14,19);
            set_sprite_tile(0,1);
            PRINT_MESSAGE(5,7,"GAME OVER");
            break;
        }


        /*gotogxy(1, 4);
        gprintf("ENEMY1 x: %d", enemies[1][0]);
        gotogxy(14, 4);
        gprintf("y: %d", enemies[1][1]);

        gotogxy(1, 5);
        gprintf("ENEMY2 x: %d", enemies[2][0]);
        gotogxy(14, 5);
        gprintf("y: %d", enemies[2][1]);

        gotogxy(1, 6);
        gprintf("ENEMY3 x: %d", enemies[3][0]);
        gotogxy(14, 6);
        gprintf("y: %d", enemies[3][1]);*/

    /**
     * Move the sprite in the second movable sprite list (1)
     * to the position of X (enemy[0]) and y (enemy[1])
     */
        for(i = 0; i < enemy_count; ++i)
        {
            enemy_move(i,&enemies[i][0],&enemies[i][1],&player[0], 
                    &player[1], &velocity[i][0], &velocity[i][1]);
        }

        level_change();

    }
}
