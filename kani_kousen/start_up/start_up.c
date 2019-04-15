#include "start_up.h"
#include "../text/text.h"
#include "../battle/battle.h"
#include "../assets/sprite_palette.h"
#include "../assets/bkg_palette.h"
#include "../assets/level_assets/level_assets.h"

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
    // set bkg property
    set_bkg_palette(0, 1, bkg_palette);
    // set sprite properties 
    set_sprite_palette(0, 2, sprite_palette);

    sprite_clean(0);
    LETTER_COUNT = 0;
    clear_screen();
    print("PRESSiA\0", 56, 54);
    print("TOiSTART\0", 52, 70);
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
            SAVE = 1;
            break;
        }
    }
}
