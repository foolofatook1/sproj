#include "start_up.h"
#include "../text/text.h"
#include "../battle/battle.h"
#include "../assets/sprite_palette.h"
#include "../assets/bkg_palette.h"
#include "../assets/sickle_hammer.h"
#include "../assets/kani_kousen_palette.h"

/* positions of the arrow */
/*UINT8 START_POS = 72;
UINT8 NEW_GAME_POS = 80;
UINT8 QUIT_POS = 88;*/

/* actions that can be taken and returned */
UINT8 GAME_OVER = 0;
//UINT8 NOTHING = 0;
UINT8 START = 1;
UINT8 LEVEL_2 = 2;
UINT8 LEVEL_3 = 3;
UINT8 NEW_GAME = 4;
UINT8 QUIT = 5;

/* option chosen */
UINT8 option;

/* chosen decision */
UINT8 choice = 0;

void opening(void)
{
    DISPLAY_OFF;
    set_bkg_palette(0, 1, bkg_palette);
    set_sprite_palette(0, 2, sprite_palette);

//    clear_screen();
    sick_ham();
    print("PRESSiA\0", 54, 72);
    print("TOiSTART\0",52, 88);
    for(i = 0; i < LETTER_COUNT; ++i)
        set_sprite_prop(i, 0);
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
    while(1)
    {
        if(joypad() & J_A)
        {
            option = START;
            break;
        }
    }
}

void sick_ham(void)
{
    set_bkg_data(0, 28, kani_kousen_palette);
    set_bkg_tiles(0, 0, 20, 18, sickle_hammer);
}
