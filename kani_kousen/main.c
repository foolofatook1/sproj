#include "main.h"

void main(void)
{
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
