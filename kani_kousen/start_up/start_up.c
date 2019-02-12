#include "start_up.h"

void opening(void)
{
    //option = NOTHING; 

    setup_sprite();
    setup_bkg();
    while(option == NOTHING)
    {
        start_up();        
        wait_vbl_done();
    }
}

/* toggle between start, new game and quit */
void start_up(void)
{
    delay(100);


    if(joypad() & J_DOWN)
    {
        if(arrow_y > NEW_GAME_POS)
        {
            arrow_y = 48; /* actual location of START */
            move_sprite(0, arrow_x, arrow_y);
        }
        arrow_y+=8;
        move_sprite(0, arrow_x, arrow_y);
    }

    if(joypad() & J_UP)
    {
        if(arrow_y < NEW_GAME_POS)
        {
            arrow_y = 80; /* actual location of QUIT */
            move_sprite(0, arrow_x, arrow_y);
        }
        arrow_y-=8;
        move_sprite(0, arrow_x, arrow_y);
    }

    if(joypad() & J_A)
        option = check_pos();
}

/* checks the position of the arrow */
int check_pos(void)
{
    if(arrow_y == START_POS)
        return START;
    if(arrow_y == NEW_GAME_POS)
        return NEW_GAME;
    if(arrow_y == QUIT_POS)
        return QUIT;
}

/* setup the sprites. In this case. the arrow. */
void setup_sprite(void)
{
    SPRITES_8x8;
    set_sprite_data(0, 89, ship_tiles);

    set_sprite_tile(0,80);
    move_sprite(0, arrow_x, arrow_y);

    SHOW_SPRITES;
}

/* setup the background for the opening screen. */
void setup_bkg(void)
{
    HIDE_WIN;
    SHOW_BKG;

    /* setup bkg */
    set_bkg_data(0, 89, ship_tiles);
    set_bkg_tiles(0,0,32,32,open_screen);
    scroll_bkg(96,0);

    DISPLAY_ON;
}
