#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#include "start_up/start_up.c"
#include "level_1/level_1.c"

UINT8 action;

void main(void)
{
   /* this poses the OPTIONS: START, NEW GAME, and QUIT. */
   opening();
   if(option == START)          /* Did you choose START? */
   {
        level_1_bkg_start();
   }
   if(option == QUIT)           /* Do you not want to play at all? */
   {
       display_off();
   }
}    
