#include "main.h"

void main(void)
{
//    ENABLE_RAM_MBC1;
 //   SWITCH_4_32_MODE_MBC1;
    
    /* this poses the OPTIONS: START, NEW GAME, and QUIT. */
  //  SWITCH_ROM_MBC1(2);
    opening();
    if(option == START)           /* Did you choose START? */
    {
//        SWITCH_ROM_MBC1(1);
        level_1_ctrl();
    }
    if(option == QUIT)            /* Do you not want to play at all? */
    {
        display_off();
    }
}    
