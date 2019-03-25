#include "main.h"

void main(void)
{
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
        /* level 2 control */
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
