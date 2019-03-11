#ifndef GBDK_INCLUDE
#define GBDK_INCLUDe

#include <gb/gb.h>
#include <stdio.h>

#endif

/* battle functions */
#include "battle.h"

#include "../../text/text.h"

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

extern UINT8 arrow_x;
extern UINT8 arrow_y;

extern UINT8 state;
