#ifndef GBDK_INCLUDE
#define GBDK_INCLUDE

#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#endif

/**
 * Things needed for start_up
 */
#ifndef START_UP_ASSETS
#define START_UP_ASSETS

#include "start_up/assets/ship_tiles.c"
#include "start_up/assets/open_screen.c"

#endif

#ifndef START_UP_INCLUDE
#define START_UP_INCLUDE

extern void setup_sprite(void);
extern void setup_bkg(void);
extern void start_up(void);
extern int check_pos(void);
extern void opening(void);
extern UINT8 START_POS;
extern UINT8 NEW_GAME_POS;
extern UINT8 QUIT_POS;
extern UINT8 NOTHING;
extern UINT8 START;
extern UINT8 NEW_GAME;
extern UINT8 QUIT;


extern UINT8 xx;
extern UINT8 yy;
extern UINT8 option;
extern UINT8 choice;

#endif

/**
 * Things needed for text
 */
#ifndef TEXT_ASSETS
#define TEXT_ASSETS

#include "text/assets/chain_border.c"
#include "text/assets/font.c"
#include "text/assets/chain_border_tiles.c"

#endif

#ifndef TEXT_INCLUDE
#define TEXT_INCLUDE

extern void print(char* arr, UINT8 x, UINT8 y) NONBANKED;
extern void bkg_clean(void) NONBANKED;
extern void sprite_clean(void) NONBANKED;
extern void hide_sprites(void) NONBANKED;
extern char *chars;
extern UINT8 i;
extern UINT8 j;
extern UINT8 cushion;
extern UINT8 LETTER_COUNT;

#endif

/**
 * Things needed for level_1
 */

#ifndef LEVEL_1_ASSETS
#define LEVEL_1_ASSETS

#include "level_1/assets/level_1_screen_tiles.c"
#include "level_1/assets/level_1_screen.c"
#include "level_1/assets/shit_pot_tiles.c" 
#include "level_1/assets/shit_pot.c"
#include "assets/sprites/hero_front_idle.c"
#include "assets/sprites/hero_back_idle.c"
#include "assets/sprites/fisherman_front_idle.c"
#include "assets/sprites/fisherman_idle_back.c"
#include "assets/sprites/miner_walk_left.c"
#include "assets/sprites/miner_walk_up.c"
#include "assets/sprites/miner_idle_back.c"
#include "assets/sprites/student_idle_back.c"
#include "assets/sprites/asakawa_front_idle.c"
#include "assets/sprites/asakawa_air_shot.c"

#endif

#ifndef LEVEL_1_INCLUDE
#define LEVEL_1_INCLUDE

extern void level_1_ctrl(void);
extern void level_1_bkg_start(void);
extern int level_1_sprite_setup(void);
extern void joypad_check_scene_1(void);
extern void joypad_check_scene_2(void);
extern void scene_1(void);
extern void animate(void);
extern int enter_miner(void);
extern void miner_intro_setup(void);
extern int miner_intro(void);
extern void scene_3_setup(void);
extern void scene_3_animate(void);
extern void scene_3_text_setup(void);
extern void joypad_check_scene_3(void);
extern void scene_3(void);
extern void asakawa_shoots_anim(void);
extern void asakawa_battle1_setup(void);
extern UINT8 text_count;
extern UINT8 start_animate;
extern UINT8 scene_2;
extern UINT8 scene_3_anim;
extern UINT8 scene_3_stop;
extern UINT8 **hero_pos;
extern UINT8 **fisherman_pos;
extern UINT8 **miner_pos;
extern UINT8 **student_pos;
extern UINT8 **asakawa_pos;
extern UINT8 sprite_width;

#endif 

//#include "start_up/start_up.h"
//#include "text/text.h"
//#include "level_1/level_1.h"
