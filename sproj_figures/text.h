#ifndef TEXT_INCLUDE
#define TEXT_INCLUDE

#include <gb/gb.h>

#include "font.h"
#include "chain_border_tiles.h"
#include "blank_screen_tiles.h"

/**
 * prints array of characters; max size = 10
 * arr = array of characters
 * x = x position
 * y = y position
 * print_ln = what number line is being printed
 * print_ln starts at 0
 */
//void fancy_print(char* arr, UINT8 x, UINT8 y, UINT8 clean);
void print(char* arr, UINT8 x, UINT8 y);
void battle_print(char* arr, UINT8 x, UINT8 y); // dash for pt.1


/**
 * Clears the bkg and sets up text box for next 
 * set of dialogue. 
 */
void bkg_clean(void); 
void battle_bkg_clean(void); // dash for pt. 1

/** 
 * some catch phrases 
 */
void damn_that_asakawa(void);
void you_hear(void);
/**
 * character titles 
 */
void asakawa(void);
void fisherman(void);
void workers(void);
void student(void);
void miner(void);

/**
 * Clears all the old sprites. 
 */
void sprite_clean(UINT8);


/**
 * move the screen off screen
 * so they're not in the way.
 */
void hide_sprites(void);

extern unsigned char *ints;
extern UINT8 i;
extern UINT8 j;
extern UINT8 cushion;
extern UINT8 LETTER_COUNT;
extern UINT8 arrow_x;
extern UINT8 arrow_y;

extern UINT8 MAX_SPRITES;

//extern unsigned char speech[];

#endif /* TEXT_INCLUDE */
