#ifndef BATTLE_INCLUDE
#define BATTLE_INCLUDE

#include <gb/gb.h>

void show_fighter_stats(void);

void battle_menu(void);
void battle_toggle_up(void);
void battle_toggle_down(void);
void battle_toggle_ctrl(void);
void battle_nav(void);
void fight_opt(void);
void item_opt(void);
void choose_item_toggle(void);
void run(void);
void back(void);

void fight_config(void);
void fight(UINT8*, UINT8*);
void npc_fight(void);

void hero_fight(void);
void hero_fight_anim(void);
void hero_defend_anim(void);
void enemy_fight_anim(void);
void enemy_defend_anim(void);

void damage(UINT8*);
void enemy_damage(UINT8*);
void lower_hp(UINT8*, UINT8, UINT8*);

void sprite_setup(UINT8, unsigned char*, 
                  UINT8, unsigned char*);
void choice_handler(UINT8);

void clear_screen(void);

//void game_over_screen(void);

extern UINT8 ENEMY;
extern UINT8 BATTLE_NUM;

extern UINT8 PUNCH;
extern UINT8 NET;
extern UINT8 CLUB;
extern UINT8 DEFEND;
extern UINT8 SHOOT;
extern UINT8 CLAW;
extern UINT8 KING_CLAW;

extern UINT8 PUNCH_LOC;

/* what do i do about this stuff? */
extern UINT8 start_hp;

extern UWORD *h_hp;
extern UWORD *e_hp;

//extern UINT8 choice;
extern UINT8 enemy_choice;

extern UWORD seed;

/* a stepping variable for character animations */
extern UINT8 y;
extern UINT8 enemy_y;
/* another animation counter */
extern UINT8 a;

extern UINT8 arrow_x;
extern UINT8 arrow_y;

extern UBYTE npc_act;
extern UBYTE npc_acc;

extern UBYTE hero_acc;

extern UBYTE first_fighter;

extern UINT8 ITEM;
extern UINT8 ITEMS;
extern UINT8 CHOSEN_ITEM;
extern UINT8 CHOOSING;

extern UINT8 BATTLE_CHOICE;
extern UINT8 FIGHT_CHOICE;
extern UINT8 RUN_CHOICE;
extern UINT8 ITEM_CHOICE;
extern UINT8 FIGHTING;
extern UINT8 DEAD;
extern UINT8 BATTLE_WIN;

extern UINT8 STATE;
#endif /* BATTLE_INCLUDE */
