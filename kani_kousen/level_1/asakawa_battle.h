#ifndef ASAKAWA_BATTLE_INCLUDE
#define ASAKAWA_BATTLE_INCLUDE

#include <gb/gb.h>

void asakawa_battle_ctrl(void);
void asakawa_battle_check(void);
void show_fighter_stats(void);

//extern UINT8 SPRITE_WIDTH;

extern UINT8 BATTLE_CHOICE;
extern UINT8 FIGHT_CHOICE;
extern UINT8 RUN_CHOICE;
extern UINT8 ITEM_CHOICE;
extern UINT8 FIGHTING;

extern UINT8 STATE;

#endif /* ASAKAWA_BATTLE_INCLUDE */
