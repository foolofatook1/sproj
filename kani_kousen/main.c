#include "main.h"

void main(void)
{
//    SAVE = 1;
/*    while(SAVE >= 0)
    {*/
        /* this poses the OPTIONS: START, NEW GAME, and QUIT. */
        opening();
        /* level 1 control */
        if(option == START)// || SAVE == 1)
            level_1_ctrl();
        /* if you've gotten as far as level 2 */
        if(option == LEVEL_2)// || SAVE == 2)
            level_2_ctrl();
        /* if you've gotten as far as level 3 */
        if(option == LEVEL_3)// || SAVE == 3)
            level_3_ctrl();
        /* for when you die in game */
        if(option == GAME_OVER)
            game_over_screen();
        /* Do you not want to play at all? */
    //}    
}
