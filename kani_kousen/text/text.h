#include <gb/gb.h>
#include <stdio.h>

#include "assets/chain_border.c"
#include "assets/font.c"
#include "assets/chain_border_tiles.c"
 #include "assets/small_chain_border.c"  // dash this out to play pt. 1

/**
 * prints array of characters; max size = 10
 * arr = array of characters
 * x = x position
 * y = y position
 * print_ln = what number line is being printed
 * print_ln starts at 0
 */
void print(char* arr, UINT8 x, UINT8 y) NONBANKED;
void battle_print(char* arr, UINT8 x, UINT8 y) NONBANKED; // dash for pt.1


/**
 * Clears the bkg and sets up text box for next 
 * set of dialogue. 
 */
void bkg_clean(void) NONBANKED;
void battle_bkg_clean(void) NONBANKED; // dash for pt. 1


/**
 * Clears all the old sprites. 
 */
void sprite_clean(void) NONBANKED;


/**
 * move the screen off screen
 * so they're not in the way.
 */
void hide_sprites(void) NONBANKED;


char chars[40] = "abcdefghijklmnopqrstuvwxyz0123456789.,;/";
UINT8 i;
UINT8 j;
UINT8 cushion;
UINT8 LETTER_COUNT = 0;
