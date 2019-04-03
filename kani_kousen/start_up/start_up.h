#ifndef START_UP_INCLUDE
#define START_UP_INCLUDE

#include <gb/gb.h>

/* functions */
void setup_bkg(void);
void start_up(void);
int check_pos(void);
void opening(void);

/* positions of the arrow */
extern UINT8 START_POS;
extern UINT8 NEW_GAME_POS;
extern UINT8 QUIT_POS;
/* this is if you die */
extern UINT8 GAME_OVER;

/* actions that can be taken and returned */
extern UINT8 NOTHING;
extern UINT8 START;
extern UINT8 LEVEL_2;
extern UINT8 LEVEL_3;
extern UINT8 NEW_GAME;
extern UINT8 QUIT;
extern UINT8 GAME_OVER;

/* arrow sprite coordinates */
//extern UINT8 arrow_x;
//extern UINT8 arrow_y;

/* option chosen */
extern UINT8 option;

/* chosen decision */
extern UINT8 choice;

#endif /* START_UP_INCLUDE */
