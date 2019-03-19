#ifndef BATTLE_INCLUDE
#define BATTLE_INCLUDE

#include <gb/gb.h>

#include "../assets/sprites/asakawa_front_idle.h"
#include "../assets/sprites/hero_back_idle.h"

void battle_menu(void);
void battle_toggle_up(void);
void battle_toggle_down(void);
void battle_nav(void);
void fight_opt(void);
void item_opt(void);
void run(void);
void back(void);

//void fight_ctrl(void);
void fight_config(void);
void fight(UINT8*, UINT8*);
void npc_fight(void);

void hero_fight(UINT8*);
void hero_fight_anim(void);
void hero_defend_anim(void);

void damage(UINT8*);

void sprite_setup(UINT8, unsigned char*, 
                  UINT8, unsigned char*);
void choice_handler(UINT8);

void clear_screen(void);

extern UINT8 PUNCH;
extern UINT8 DEFEND;
extern UINT8 SHOOT;

extern UINT8 PUNCH_LOC;

/* what do i do about this stuff? */
extern UINT8 ASAKAWA_HP;
extern UINT8 HERO_HP;

extern UWORD *h_hp;

//extern UINT8 choice;
extern UINT8 enemy_choice;

extern UWORD seed;

/* a stepping variable for character animations */
extern UINT8 y;
/* another animation counter */
extern UINT8 a;

extern UINT8 arrow_x;
extern UINT8 arrow_y;

extern UBYTE npc_act;
extern UBYTE npc_acc;

extern UBYTE hero_acc;

extern UBYTE first_fighter;
#endif /* BATTLE_INCLUDE */
