/**
 * main.c
 */

#include "main.h"

void main(void)
{
    /* this poses the OPTIONS: START, NEW GAME, and QUIT. */
    opening();
    /* if you've gotten as far as level 1 */
    if(option == START)
        level_1_ctrl();
    /* if you've gotten as far as level 2 */
    if(option == LEVEL_2)
        level_2_ctrl();
    if(option == LEVEL_3)
        level_3_ctrl();
}    
