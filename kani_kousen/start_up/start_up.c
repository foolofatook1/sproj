#include "start_up.h"
#include "../text/text.h"

/* positions of the arrow */
UINT8 START_POS = 72;
UINT8 NEW_GAME_POS = 80;
UINT8 QUIT_POS = 88;

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
    arrow_x = 72;
    arrow_y = 72;
    
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
    /* sprite 0 is the '>' */
    delay(100);
    if(joypad() & J_DOWN)
    {
        if(arrow_y > QUIT_POS-8)
        {
            arrow_y = START_POS-8;
            move_sprite(0, arrow_x, arrow_y);
        }
        arrow_y+=8;
        move_sprite(0, arrow_x, arrow_y);
    }

    if(joypad() & J_UP)
    {
        if(arrow_y < START_POS+8)
        {
            arrow_y = QUIT_POS+8; /* actual location of QUIT */
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

/* setup the background for the opening screen. */
void setup_bkg(void)
{
    HIDE_WIN;
    HIDE_BKG;

    set_bkg_data(0,4,blank_screen_tiles); 
    set_bkg_tiles(0,0,20,18,blank_screen);

    /* setup bkg */
    print(">start\0", 72, 72);
    print(" new game\0", 72, 80);
    print(" quit\0", 72, 88);

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
}
