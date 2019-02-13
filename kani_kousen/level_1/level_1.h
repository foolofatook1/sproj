/* start level 1 screen tiles */
#include "assets/level_1_screen_tiles.c"
#include "assets/level_1_screen.c"


/* text boxes */
#include "assets/text/font.c" /* text tiles */
#include "assets/text/text_1_level_1.c" /* first text box */
#include "assets/text/text_2_level_1.c" /* second text box */
#include "assets/text/text_3_level_1.c" /* third text box */

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
void level_1_sprite_setup(void);
void joypad_check(void);
void scene_1(void);
void animate(void);
void enter_miner(void);

UINT8 text_count = 0;
UINT8 start_animate = 0;

UINT8 hero_pos[2][2];
UINT8 fisherman_pos[2][2];
UINT8 miner_pos[2][2];

UINT8 sprite_width = 8;
