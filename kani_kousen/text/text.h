#ifndef TEXT_INCLUDE
#define TEXT_INCLUDE

#include <stdio.h>
#include <gb/gb.h>

#include "assets/chain_border.h"
#include "assets/font.h"
#include "assets/chain_border_tiles.h"
#include "assets/blank_screen_tiles.h"
#include "assets/blank_screen.h"
//#include "assets/small_chain_border.h"  // dash this out to play pt. 1

/**
 * prints array of characters; max size = 10
 * arr = array of characters
 * x = x position
 * y = y position
 * print_ln = what number line is being printed
 * print_ln starts at 0
 */
void print(char* arr, UINT8 x, UINT8 y);
//void battle_print(char* arr, UINT8 x, UINT8 y); // dash for pt.1


/**
 * Clears the bkg and sets up text box for next 
 * set of dialogue. 
 */
void bkg_clean(void); 
void battle_bkg_clean(void); // dash for pt. 1


/**
 * Clears all the old sprites. 
 */
void sprite_clean(void);


/**
 * move the screen off screen
 * so they're not in the way.
 */
void hide_sprites(void);

extern char *chars;
extern UINT8 i;
extern UINT8 j;
extern UINT8 cushion;
extern UINT8 LETTER_COUNT;
extern UINT8 arrow_x;
extern UINT8 arrow_y;

#endif /* TEXT_INCLUDE */
