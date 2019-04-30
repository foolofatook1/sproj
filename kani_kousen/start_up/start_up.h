#ifndef START_UP_INCLUDE
#define START_UP_INCLUDE

#include <gb/gb.h>

/* functions */
void opening(void);

/* actions that can be taken and returned */
extern UINT8 START;
extern UINT8 LEVEL_2;
extern UINT8 LEVEL_3;
extern UINT8 NEW_GAME;
extern UINT8 QUIT;
extern UINT8 GAME_OVER;

/* option chosen */
extern UINT8 option;

/* chosen decision */
extern UINT8 choice;

#endif /* START_UP_INCLUDE */
