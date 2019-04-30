/**
 * level_assets.c
 *
 * Initializes variables needed 
 * for all levels {1..3}
 */

#include "level_assets.h"
#include "../../level_2/level_2.h"
#include "../../text/text.h"

UINT8 sprite_width = 8;

UINT8 talking = 1;
UINT8 slept = 0;
UINT8 talked = 0;
UINT8 revolt = 0;
UINT8 REVOLUTION_1 = 0;
UINT8 REVOLUTION_2 = 0;
UINT8 striking = 0;
UINT8 appeared = 0;
UINT8 crabs_to_catch = 1;
UINT8 health_loss = 0;

UINT8 anim_1 = 32;
UINT8 anim_2 = 34;

UINT8 hero_posx = 200;
UINT8 hero_posy = 200;
UINT8 fisherman_posx = 200;
UINT8 fisherman_posy = 200;
UINT8 fisherman2_posx = 200;
UINT8 fisherman2_posy = 200;
UINT8 miner_posx = 200;
UINT8 miner_posy = 200;
UINT8 student_posx = 200;
UINT8 student_posy = 200;
UINT8 student2_posx = 200;
UINT8 student2_posy = 200;
UINT8 asakawa_posx = 200;
UINT8 asakawa_posy = 200;
UINT8 bed_posx = 200;
UINT8 bed_posy = 200;

UINT8 hero_hp = 10;
UINT16 asakawa_hp = 100;
