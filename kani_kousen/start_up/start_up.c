#include "start_up.h"

/* positions of the arrow */
UINT8 START_POS = 56;
UINT8 NEW_GAME_POS = 64;
UINT8 QUIT_POS = 72;

/* actions that can be taken and returned */
UINT8 NOTHING = 0;
UINT8 START = 1;
UINT8 NEW_GAME = 2;
UINT8 QUIT = 3;

/* option chosen */
UINT8 option;

/* chosen decision */
UINT8 choice = NOTHING;

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
            sprite_clean();
            arrow_y = 48;
            print(">", arrow_x, arrow_y);
            LETTER_COUNT = 0;
        }
        sprite_clean();
        arrow_y+=8;
        print(">", arrow_x, arrow_y);
        LETTER_COUNT = 0;
    }

    if(joypad() & J_UP)
    {
        if(arrow_y < NEW_GAME_POS)
        {
            sprite_clean();
            arrow_y = 80; /* actual location of QUIT */
            print(">", arrow_x, arrow_y);
            LETTER_COUNT = 0;
        }
        sprite_clean();
        arrow_y-=8;
        print(">", arrow_x, arrow_y);
        LETTER_COUNT = 0;
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

    print(">", arrow_x, arrow_y);
    LETTER_COUNT = 0;

    SHOW_SPRITES;
}

/* setup the background for the opening screen. */
void setup_bkg(void)
{
    HIDE_WIN;
    HIDE_BKG;

    /* setup bkg */
    set_bkg_data(0, 89, ship_tiles);
    set_bkg_tiles(0,0,32,32,open_screen);
    scroll_bkg(96,0);

    SHOW_BKG;

    DISPLAY_ON;
}
