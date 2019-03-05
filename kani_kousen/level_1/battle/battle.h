#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <rand.h>
#include <gb/drawing.h>

#include "../../text/text.h"

#include "../../assets/sprites/asakawa_front_idle.c"
#include "../../assets/sprites/hero_back_idle.c"
#include "../assets/blank_screen.c"
#include "../assets/blank_screen_tiles.c"

//void fight_ctrl(void);
void npc_fight(UINT8*);//,UINT8*);

void hero_fight(UINT8*, UINT8*);
void hero_fight_anim(void);
void hero_defend_anim(void);

void sprite_setup(UINT8, unsigned char*, UINT8, unsigned char*);
void choice_handler(UINT8);

void clear_screen(void);

#define PUNCH 1
#define DEFEND 2 
#define SHOOT 5

#define PUNCH_LOC 32

/* what do i do about this stuff? */
UINT8 ASAKAWA_HP = 100;
UINT8 HERO_HP = 10;

UWORD h_hp[4];

extern UINT8 choice;
extern UINT8 enemy_choice;

/* a stepping variable for character animations */
extern UINT8 y;
/* another animation counter */
extern UINT8 a;
