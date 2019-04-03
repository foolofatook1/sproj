/** 
 * for later:
 * consider trying to make the text box a small window that
 * overlaps the bkg. This can be used to make who's in 
 * dialogue with who more clear.
 */

/* text things */
#ifndef LEVEL_1_INCLUDE
#define LEVEL_1_INCLUDE

#include <gb/gb.h>

/* shit pot assets */
#include "assets/shit_pot.h"

/* starting sprites */
/* hero */
#include "../assets/sprites/hero_front_idle.h"
#include "../assets/sprites/hero_back_idle.h"
/* fisherman */
#include "../assets/sprites/fisherman_front_idle.h"
#include "../assets/sprites/fisherman_idle_back.h"
/* miner */
#include "../assets/sprites/miner_walk_left.h"
#include "../assets/sprites/miner_walk_up.h"
#include "../assets/sprites/miner_idle_back.h"
/* student */
#include "../assets/sprites/student_idle_back.h"
/* asakawa */
#include "../assets/sprites/asakawa_front_idle.h"
#include "../assets/sprites/asakawa_air_shot.h"

void level_1_ctrl(void);
void level_1_bkg_start(void);
int level_1_sprite_setup(void);
void joypad_check_l1_scene_1(void);
void joypad_check_l1_scene_2(void);
void l1_scene_1(void);
void animate(void);
int enter_miner(void);
void miner_intro_setup(void);
int miner_intro(void);
void l1_scene_3_setup(void);
void l1_scene_3_animate(void);
void l1_scene_3_text_setup(void);
void joypad_check_l1_scene_3(void);
void l1_scene_3(void);
void asakawa_shoots_anim(void);
void asakawa_battle1_setup(void);


/* scene 1 variables */
//extern UINT8 text_count;
/* scene 2 variables */
//extern UINT8 start_animate;
extern UINT8 l1_scene_2;
/* scene 3 variables */
extern UINT8 l1_scene_3_anim;
extern UINT8 l1_scene_3_stop;

/*extern UINT8 **hero_pos;
extern UINT8 **fisherman_pos;
extern UINT8 **miner_pos;
extern UINT8 **student_pos;
extern UINT8 **asakawa_pos;

extern UINT8 sprite_width;*/

#endif /* LEVEL_1_INCLUDE */
