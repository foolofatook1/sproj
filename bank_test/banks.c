#include <stdio.h>
#include <gb/gb.h>

#include "text.h"

void battle_menu(void) NONBANKED;
UINT8 m;
UWORD n[1];
void main(void)
{
    wait_vbl_done();

    ENABLE_RAM_MBC1;
    SWITCH_4_32_MODE_MBC1;

    DISPLAY_OFF;
    HIDE_BKG;
    HIDE_SPRITES;
    HIDE_WIN;


    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

//    for(m = 0; m < 5; ++m)
 //   {
  //      itoa(m, n);
   //     puts(n);
        delay(1000);
        SWITCH_RAM_MBC1(2);
        //SWITCH_ROM_MBC1(2);
        set_bkg_data(0, 10, chain_border_tiles);
        set_bkg_tiles(0,0,20,18,small_chain_border);
       // battle_bkg_clean();
        delay(1000);
    //    battle_menu();

}

void battle_menu(void) NONBANKED
{
    /* setup the bkg */
    set_bkg_data(0,10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18,small_chain_border);

    sprite_clean();
    hide_sprites();
    /* selection menu */
    battle_print(" fight", 18, 32);
    battle_print(" defend", 18, 48);
    battle_print(" run", 18, 64);
    battle_print(" item", 18, 80);
}
