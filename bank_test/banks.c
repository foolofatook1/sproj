#include "bank2.h"
#ifndef GBDK_INCLUDE
#define GBDK_INCLUDE

#include <stdio.h>
#include <gb/gb.h>

#endif

#include "assets/chain_border_tiles.c"
#include "assets/small_chain_border.c"
#include "assets/font.c"
#include "assets/chain_border.c"


extern void hello(void);
extern UINT8 arrow_x;
extern UINT8 arrow_y;

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

    SWITCH_ROM_MBC1(2);
    hello();

}
