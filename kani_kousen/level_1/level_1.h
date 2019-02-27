/** 
 * for later:
 * consider trying to make the text box a small window that
 * overlaps the bkg. This can be used to make who's in 
 * dialogue with who more clear.
 */
//#include <gb/gb.h>
//#include <stdio.h>

/* giving mem banking a try */
//#include "asakawa_battle.c"

/* text things */
#include "../text/text.c"

/* level 1 opening screen */
#include "assets/level_1_screen_tiles.c"
#include "assets/level_1_screen.c"

/* shit pot assets */
#include "assets/shit_pot_tiles.c" 
#include "assets/shit_pot.c"

/* starting sprites */
/* hero */
#include "../assets/sprites/hero_front_idle.c"
#include "../assets/sprites/hero_idle_back.c"
/* fisherman */
#include "../assets/sprites/fisherman_front_idle.c"
#include "../assets/sprites/fisherman_idle_back.c"
/* miner */
#include "../assets/sprites/miner_walk_left.c"
#include "../assets/sprites/miner_walk_up.c"
#include "../assets/sprites/miner_idle_back.c"
/* student */
#include "../assets/sprites/student_idle_back.c"
/* asakawa */
#include "../assets/sprites/asakawa_front_idle.c"
#include "../assets/sprites/asakawa_air_shot.c"



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


/* scene 1 variables */
UINT8 text_count = 0;
/* scene 2 variables */
UINT8 start_animate = 0;
UINT8 scene_2 = 0;
/* scene 3 variables */
UINT8 scene_3_anim = 0;
UINT8 scene_3_stop = 0;

UINT8 hero_pos[2][2];
UINT8 fisherman_pos[2][2];
UINT8 miner_pos[2][2];
UINT8 student_pos[2][2];
UINT8 asakawa_pos[2][2];

UINT8 sprite_width = 8;
