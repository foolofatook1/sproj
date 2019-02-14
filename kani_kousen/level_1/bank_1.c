/**
 * This is currently problematic. This is taking up too much memory.
 * I may find that I can use Memory banking here though. 
 * Worth double checking 
 */
#include "assets/text/text_5_level_1.c"  /* fifth text box */

int text_count_2;

int miner_intro(void) NONBANKED
{
    if(joypad() & J_A)
    {
        delay(100);
        text_count++;
        delay(100);
    }
    set_bkg_tiles(0,0,20,18,text_4_level_1);
    DISPLAY_ON;
    if(text_count == 1)
    {
        DISPLAY_OFF;
        set_bkg_tiles(0,0,20,18,text_5_level_1);
        DISPLAY_ON;
        return 1;    
    }

    return 0;
}
