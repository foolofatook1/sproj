#ifndef GBDK_INCLUDE
#define GBDK_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#endif


#include "../text/text.h"

/*#ifndef START_UP_ASSETS
#define START_UP_ASSETS

 background tiles and sprite 
#include "../text/assets/blank_screen_tiles.h"
#include "../text/assets/blank_screen.h"

#endif*/

#ifndef START_UP_INCLUDE
#define START_UP_INCLUDE

/* functions */
extern void setup_bkg(void);
extern void start_up(void);
extern int check_pos(void);
extern void opening(void);

/* positions of the arrow */
extern UINT8 START_POS;
extern UINT8 NEW_GAME_POS;
extern UINT8 QUIT_POS;

/* actions that can be taken and returned */
extern UINT8 NOTHING;
extern UINT8 START;
extern UINT8 NEW_GAME;
extern UINT8 QUIT;

/* arrow sprite coordinates */
extern UINT8 arrow_x;
extern UINT8 arrow_y;


/* option chosen */
extern UINT8 option;

/* chosen decision */
extern UINT8 choice;

#endif
