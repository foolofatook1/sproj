//#include <gb/gb.h>
//#include <stdio.h>

/* background tiles and sprite */
#include "assets/ship_tiles.c"
#include "assets/open_screen.c"


/* functions */
void setup_sprite(void);
void setup_bkg(void);
//void start_up(void);
void start_up(void);
int check_pos(void);
void opening(void);

/* positions of the arrow */
#define START_POS 56
#define NEW_GAME_POS 64
#define QUIT_POS 72

/* actions that can be taken and returned */
#define NOTHING 	0
#define START		1
#define	NEW_GAME 	2
#define QUIT		3

/* arrow sprite coordinates */
UINT8 arrow_x = 72;
UINT8 arrow_y = 56;


/* option chosen */
UINT8 option;

/* chosen decision */
UINT8 choice = NOTHING;
