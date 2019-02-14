#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#include "start_up/start_up.c"
#include "level_1/level_1.c"

UINT8 action;

void main(void)
{
    ENABLE_RAM_MBC1;
    SWITCH_4_32_MODE_MBC1;

    SWITCH_RAM_MBC1(0);
    /* this poses the OPTIONS: START, NEW GAME, and QUIT. */
    opening();
    if(option == START)           /* Did you choose START? */
    {
        SWITCH_RAM_MBC1(1);
        level_1_ctrl();
    }
    if(option == QUIT)            /* Do you not want to play at all? */
    {
        display_off();
    }
}    
