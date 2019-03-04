#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <rand.h>
#include <gb/drawing.h>

//#include "../../text/text.c"
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

UINT8 ASAKAWA_HP = 100;

UINT8 HERO_HP = 10;
UWORD h_hp[4];

#define PUNCH 1
#define DEFEND 2 
#define SHOOT 5

#define PUNCH_LOC 32

UINT8 choice = 0;
UINT8 enemy_choice = 0;

/* a stepping variable for character animations */
UINT8 y = 72;
/* another animation counter */
UINT8 a = 0;
