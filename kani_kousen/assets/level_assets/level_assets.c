#include "level_assets.h"
#include "../../level_2/level_2.h"
#include "../../text/text.h"

//UINT8 text_count = 0;
//UINT8 start_animate = 0;
UINT8 sprite_width = 8;
//UINT16 dt = 1500; // delay time

UINT8 SAVE = 0;

UINT8 SLEPT = 0;
UINT8 talked = 0;
UINT8 revolt = 0;
UINT8 REVOLUTION_1 = 0;
UINT8 REVOLUTION_2 = 0;
UINT8 striking = 0;
UINT8 APPEARED = 0;
UINT8 crabs_to_catch = 1;
UINT8 health_loss = 0;

UINT8 anim_1 = 32;
UINT8 anim_2 = 34;

UINT8 hero_posx = 200;
UINT8 hero_posy = 200;
UINT8 fisherman_posx = 200;
UINT8 fisherman_posy = 200;
UINT8 fisherman2_posx = 200;
UINT8 fisherman2_posy = 200;
UINT8 miner_posx = 200;
UINT8 miner_posy = 200;
UINT8 student_posx = 200;
UINT8 student_posy = 200;
UINT8 student2_posx = 200;
UINT8 student2_posy = 200;
UINT8 asakawa_posx = 200;
UINT8 asakawa_posy = 200;
UINT8 bed_posx = 200;
UINT8 bed_posy = 200;

UINT8 HERO_HP = 10;
UINT16 ASAKAWA_HP = 100;

//UINT8 sprite_positions[8];

/*UINT8 check_items(void)
{
    if(joypad() & J_B)
    {
        if(screen_x != 0)
            move_bkg(0, 0);
        wait_vbl_done();
        DISPLAY_OFF;;
        set_bkg_tiles(0,0,20,18,blank_screen);
        sprite_clean();
        LETTER_COUNT = 0;
        battle_print("items:\0", 24, 32);
        battle_print("club\0", 24, 64);
        battle_print("net\0", 24, 80);
        DISPLAY_ON;
        delay(1000);
        return 1;
    }
    return 0;
}*/
