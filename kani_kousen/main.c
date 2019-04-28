#include "main.h"

void main(void)
{
//    play:
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

  /*  while(1)
    {
        if(joypad() & J_A)
        {
            option = 0;
            STATE = BATTLE_CHOICE;
            HERO_HP = 10;
            ASAKAWA_HP = 100;
            ENEMY = 0;
            break;
        }
    }*/
 //   goto play;
}    
