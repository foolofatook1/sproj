#ifndef LEVEL_2_INCLUDE
#define LEVEL_2_INCLUDE

#include <gb/gb.h>
#include <gb/cgb.h>

#include "../level_1/assets/shit_pot.h"
#include "../text/assets/black_screen.h"

#include "../assets/sprite_palette.h"
#include "../assets/bkg_palette.h"

#include "../assets/sprites/hero_lie_down.h"
#include "../assets/sprites/hero_walk_sideways.h"
#include "../assets/sprites/hero_front_idle.h"
#include "../assets/sprites/hero_walk_up.h"
#include "../assets/sprites/hero_walk_down.h"

#include "../assets/sprites/fisherman_walk_sideways.h"
#include "../assets/sprites/fisherman_walk_up.h"
#include "../assets/sprites/fisherman_front_idle.h"

#include "../assets/sprites/miner_front_idle.h"
#include "../assets/sprites/student_front_idle.h"

#include "../assets/sprites/asakawa_walk_sideways.h"
#include "../assets/sprites/bed.h"

#include "../assets/bkgs/deck.h"

void level_2_ctrl(void);
void level_2_bkg_start(void);

void l2_scene_1(void);

void joypad_check_l2_scene_1(void);
void l2_scene_1_fisherman_enter(void);
void fisherman_walk_away(void);

void hero_walk(void);

void asakawa_enters_deck(void);
void asakawa_before_work(void);
void asakawa_after_work(void);

void shit_pot_setup(void);
void shit_pot_sprites(void);
UINT8 sprite_collide_shit_pot(UINT8*);
UINT8 conv_check(void);
void pos_check_shit_pot(void);
void pos_check_deck(void);


extern UINT8 talking;
extern UINT8 moving;
extern UINT8 left;

extern UINT8 sprite_positions[];
extern UINT8 arr_size;

extern UINT8 screen_x;
extern UINT8 GOT_INFO;

#endif /* LEVEL_2_INCLUDE */
