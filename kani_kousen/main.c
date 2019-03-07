#ifndef GBDK_INCLUDE
#define GBDK_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#endif

#include "start_up/start_up.h"
#include "level_1/level_1.h"

//UINT8 action;

void main(void)
{
 //   ENABLE_RAM_MBC1;
  //  SWITCH_4_32_MODE_MBC1;

    /* this poses the OPTIONS: START, NEW GAME, and QUIT. */
    opening();
    if(option == START)           /* Did you choose START? */
    {
        level_1_ctrl();
    }
    if(option == QUIT)            /* Do you not want to play at all? */
    {
        display_off();
    }
}    
