#ifndef GBDK_INCLUDE
#define GBDK_INCLUDE

#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <rand.h>
#include <gb/drawing.h>

#endif

#include "../../text/text.h"

#include "../../assets/sprites/asakawa_front_idle.c"
#include "../../assets/sprites/hero_back_idle.c"
#include "../assets/blank_screen.c"
#include "../assets/blank_screen_tiles.c"

//void fight_ctrl(void);
extern void npc_fight(UINT8*);

extern void hero_fight(UINT8*, UINT8*);
extern void hero_fight_anim(void);
extern void hero_defend_anim(void);

extern void sprite_setup(UINT8, unsigned char*, 
                  UINT8, unsigned char*);
extern void choice_handler(UINT8);

extern void clear_screen(void);

extern UINT8 PUNCH;
extern UINT8 DEFEND;
extern UINT8 SHOOT;

extern UINT8 PUNCH_LOC;

/* what do i do about this stuff? */
extern UINT8 ASAKAWA_HP;
extern UINT8 HERO_HP;

extern UWORD *h_hp;

extern UINT8 choice;
extern UINT8 enemy_choice;

/* a stepping variable for character animations */
extern UINT8 y;
/* another animation counter */
extern UINT8 a;
