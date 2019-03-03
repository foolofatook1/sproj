/* battle functions */
#include "battle.h"

void asakawa_battle_ctrl(void);
void battle_menu(void);
void battle_toggle_up(void);
void battle_doggle_down(void);
void asakawa_battle_check(void);
void show_sprites(void);
void battle_nav(void);
void fight_opt(void);
void item_opt(void);
void run(void);
void show_items(void);
void show_fighter_stats(void);
void back(void);


#define SPRITE_WIDTH 8

#define BATTLE_OPT  0
#define FIGHT_OPT   1
#define RUN         2
#define ITEM_OPT    3
#define FIGHTING    4


UINT8 hero_pos[2][2];
UINT8 asakawa_pos[2][2];

UINT8 arrow_x = 18;
UINT8 arrow_y = 32;

UINT8 state = BATTLE_OPT;
