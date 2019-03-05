#ifndef GBDK_INCLUDE
#define GBDK_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#endif

#ifndef TEXT_ASSETS_INCLUDE
#define TEXT_ASSETS_INCLUDE

#include "assets/chain_border.c"
#include "assets/font.c"
#include "assets/chain_border_tiles.c"
#include "assets/small_chain_border.c"  // dash this out to play pt. 1

#endif

#ifndef TEXT_INCLUDE
#define TEXT_INCLUDE

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


extern char *chars;
extern UINT8 i;
extern UINT8 j;
extern UINT8 cushion;
extern UINT8 LETTER_COUNT;

#endif
