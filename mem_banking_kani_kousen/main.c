#include "main.h"

void main(void)
{
//    ENABLE_RAM_MBC1;
//    SWITCH_4_32_MODE_MBC1;

    /* this poses the OPTIONS: START, NEW GAME, and QUIT. */
    opening();
    /* Did you choose START? */
    if(option == START)
    {
        /* level 1 control */
        level_1_ctrl();
    }
    /* if you've gotten as far as level 2 */
    if(option == LEVEL_2)
    {
  /*      sprite_clean();
        LETTER_COUNT = 0;
        clear_screen();
        print("off to 2\0", 24, 32);
        delay(1000);*/
 //       SWITCH_ROM_MBC1(1);
        /* level 2 control */
        //bank_test();
        level_2_ctrl();
    }
    if(option == GAME_OVER)
    {
        /* for when you die in game */
        game_over_screen();
    }
    /* Do you not want to play at all? */
    if(option == QUIT)
    {
        display_off();
    }
}    
