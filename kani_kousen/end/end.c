/**
 * end.c
 *
 * THE END
 */

#include <gb/gb.h>
#include "../text/text.h"
#include "../assets/level_assets/level_assets.h"
#include "../battle/battle.h"
#include "../assets/sh_tiles.h"
#include "../assets/sickle_hammer.h"

void ending(void)
{
    sprite_clean(0);
    LETTER_COUNT = 0;
    bkg_clean();
    delay(500);
    talking = 1;
    print("THE\nPROLETARO\nHAVE\nNOTHING\nTOiLOSE", 24, 32);
    while(talking)
    {
        if(joypad() & J_A)
        {
            ++talking;
            delay(200);
            if(talking == 2)
            {
                sprite_clean(0);
                LETTER_COUNT = 0;
                print("BUTiTHEIR\nCHAINSe", 24, 32);
            }
            delay(1000);
            clear_screen();
            delay(100);
            bkg_clean();
            delay(100);
            clear_screen();
            delay(100);
            bkg_clean();
            delay(100);
            clear_screen();
            delay(2000);
            sprite_clean(0);
            LETTER_COUNT = 0;
            print("KANI\nKOUSEN", 60, 96);
            set_bkg_data(0, 18, sh_tiles);
            set_bkg_tiles(0, 0, 20, 18, sickle_hammer);
            break;
        }
    }
}
