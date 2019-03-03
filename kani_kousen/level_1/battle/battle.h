#include <gb/gb.h>
#include <stdio.h>
#include <stdlib.h>
#include <rand.h>
#include <gb/drawing.h>

#include "../../text/text.c"

#include "../../assets/sprites/asakawa_front_idle.c"
#include "../../assets/sprites/hero_back_idle.c"
#include "../assets/blank_screen.c"
#include "../assets/blank_screen_tiles.c"

//void fight_ctrl(void);
void fight(void);
void sprite_setup(UINT8, unsigned char*, UINT8, unsigned char*);


#define PUNCH 1
#define SHOOT 5
