#include <gb/gb.h>
#include <gb/cgb.h>
#include "level_2.h"
#include "../text/text.h"
#include "../battle/battle.h"
#include "../assets/sprite_palette.h"
#include "../assets/bkg_palette.h"

/*UWORD bkg_palette[] = 
{
    RGB_BLACK, 0, 0, 0
};*/

void level_2_ctrl(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
    HIDE_SPRITES;
    HIDE_BKG;

    set_sprite_palette(0, 3, sprite_palette);

    print("hello!", 65, 75);
    for(i = 0; i < LETTER_COUNT; ++i)
        set_sprite_prop(i,1);

    set_bkg_data(0, 4, blank_screen_tiles);
    set_bkg_tiles(0,0,20,18, black_screen);

    SHOW_SPRITES;
    SHOW_BKG;
}
