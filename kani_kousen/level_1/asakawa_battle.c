#include <gb/gb.h>
#include <stdio.h>

//#include "../text/text.c"
//#include "assets/small_chain_border.c"

void asakawa_battle1_setup(void)
{
    DISPLAY_OFF;
    HIDE_BKG;
    HIDE_SPRITES;
   
 //   set_win_data(0,10,chain_border_tiles);
  //  set_win_tiles(0,8,20,18,small_chain_border);
    
    SHOW_WIN;
    DISPLAY_ON;

}
