
#include "text/text.h"
#include "level_1/level_1.h"
#include "start_up/start_up.h"

#ifndef GBDK_INCLUDE
#define GBDK_INCLUDE

#include <gb/gb.h>
#include <gb/drawing.h>

#endif

#ifndef START_UP_INCLUDE
#define START_UP_INCLUDE

void setup_bkg(void);
void start_up(void);
int check_pos(void);
void opening(void);
extern UINT8 START_POS;
extern UINT8 NEW_GAME_POS;
extern UINT8 QUIT_POS;
extern UINT8 NOTHING;
extern UINT8 START;
extern UINT8 NEW_GAME;
extern UINT8 QUIT;

extern UINT8 arrow_x;
extern UINT8 arrow_y;
extern UINT8 option;
extern UINT8 choice;

#endif

/**
 * Things needed for text
 */
#ifndef TEXT_ASSETS
#define TEXT_ASSETS

#include "text/assets/chain_border_tiles.h"
#include "text/assets/chain_border.h"
#include "text/assets/font.h"
#include "text/assets/blank_screen.h"
#include "text/assets/blank_screen_tiles.h"

#endif

#ifndef TEXT_INCLUDE
#define TEXT_INCLUDE

void print(char* arr, UINT8 x, UINT8 y);
void bkg_clean(void);
void sprite_clean(void);
void hide_sprites(void);
char *chars;
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

#include "level_1/assets/shit_pot.h"
#include "assets/sprites/hero_front_idle.h"
#include "assets/sprites/hero_back_idle.h"
#include "assets/sprites/fisherman_front_idle.h"
#include "assets/sprites/fisherman_idle_back.h"
#include "assets/sprites/miner_walk_left.h"
#include "assets/sprites/miner_walk_up.h"
#include "assets/sprites/miner_idle_back.h"
#include "assets/sprites/student_idle_back.h"
#include "assets/sprites/asakawa_front_idle.h"
#include "assets/sprites/asakawa_air_shot.h"

#endif

#ifndef LEVEL_1_INCLUDE
#define LEVEL_1_INCLUDE

void level_1_ctrl(void);
void level_1_bkg_start(void);
int level_1_sprite_setup(void);
void joypad_check_scene_1(void);
void joypad_check_scene_2(void);
void scene_1(void);
void animate(void);
int enter_miner(void);
void miner_intro_setup(void);
int miner_intro(void);
void scene_3_setup(void);
void scene_3_animate(void);
void scene_3_text_setup(void);
void joypad_check_scene_3(void);
void scene_3(void);
void asakawa_shoots_anim(void);
void asakawa_battle1_setup(void);
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
