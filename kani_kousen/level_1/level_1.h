/* text things */
#include "../text/text.c"

/* level 1 opening screen */
#include "assets/level_1_screen_tiles.c"
#include "assets/level_1_screen.c"

/* shit pot assets */
#include "assets/shit_pot_tiles.c" 
#include "assets/shit_pot.c"

/* starting sprites */
#include "../assets/sprites/hero_front_idle.c"
#include "../assets/sprites/fisherman_front_idle.c"
#include "../assets/sprites/miner_walk_left.c"
#include "../assets/sprites/miner_walk_up.c"
#include "../assets/sprites/miner_idle_back.c"


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


UINT8 text_count = 0;
UINT8 start_animate = 0;
UINT8 scene_2 = 0;

UINT8 hero_pos[2][2];
UINT8 fisherman_pos[2][2];
UINT8 miner_pos[2][2];

UINT8 sprite_width = 8;
