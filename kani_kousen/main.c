#include "main.h"

void main(void)
{
    //    ENABLE_RAM_MBC1;
    //    SWITCH_4_32_MODE_MBC1;
    /*while(SAVE >= 0)
    {*/
        /* this poses the OPTIONS: START, NEW GAME, and QUIT. */
        opening();
        /* if you've gotten as far as level 1 */
        if(option == START)// || SAVE == 1)
        {
            level_1_ctrl();
        }
        /* if you've gotten as far as level 2 */
        if(option == LEVEL_2)// || SAVE == 2)
        {
            level_2_ctrl();
        }
        if(option == LEVEL_3)// || SAVE == 3)
        {
            level_3_ctrl();
        }
/*        if(option == GAME_OVER)
        {
             for when you die in game */
          /*  game_over_screen();
        }*/
        /* Do you not want to play at all? */
/*        if(option == QUIT)
        {
            display_off();
        }
    }*/
}    
