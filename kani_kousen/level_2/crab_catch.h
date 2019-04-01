#ifndef CRAB_CATCH_INCLUDE
#define CRAB_CATCH_INCLUDE

#include <gb/gb.h>
#include "../assets/sprites/norm_crab.h"
#include "../assets/sprites/king_crab.h"

void crab_catch_ctrl(void);
void crab_catch_setup(void);

extern UINT8 crab;
extern UINT8 CRAB_HP;
extern UINT8 CRAB_CAUGHT;

#endif /* CRAB_CATCH_INCLUDE */
