#include <gb/drawing.h>
#include <rand.h>
#include "music.h"

/* My Functions. */
void wall_check(UINT8*, UINT8*);
void add_vect(UINT8*, UINT8*, UINT8*, UINT8*);
void bounce(UINT8*, UINT8*, UINT8*, UINT8*, UINT8*, UINT8*);

/*  originally caused enemy to speed up. */
void level_change(void);
void init_enem(void);


void enemy_move (int, UINT8*, UINT8*, UINT8*, UINT8*, UINT8*, UINT8*);
UINT8 score(UINT8*, UINT8*, UINT8*, UINT8*, UINT8*);

void PRINT_MESSAGE(int x, int y, char *c);

UINT8 collision_check(UINT8* x1, UINT8* y1, UINT8 w1, UINT8 h1,
        UINT8* x2, UINT8* y2, UINT8 w2, UINT8 h2);

#define MAX_ENEMY 2

/* Counter for enemies. Starts at 1 enemy. */
int enemy_count = 1;
/* A list of enemies */
int enemies[MAX_ENEMY][2];

UINT8* incr = 1;

int i = 0;
int j = 0;

/* seed for random number generator. */
UINT16 t;

/**
 * Check if two rectangels from x1,y1, and extending out h1, h2,
 * overlap with another, x2, y2, and extending out w2, h2
 */
UINT8 collision_check(UINT8* x1,UINT8* y1,UINT8 w1,UINT8 h1, 
        UINT8* x2,UINT8* y2,UINT8 w2,UINT8 h2)
{
    if((*x1 < ((*x2)+(w2))) && (((*x1)+(w1)) > *x2) 
            && (*y1 < ((h2)+(*y2))) && (((*y1)+(h1)) > *y2))
    {
        collide_sound();
        return 1;
    }
    else
    {
        return 0;
    }
}

void PRINT_MESSAGE(int x, int y, char *c)
{
    gotogxy(x, y);
    gprintf(c);
}

UINT8 score(UINT8* x, UINT8* y, UINT8* x1, UINT8* y1, UINT8* s)
{
    if(collision_check(x, y, 8, 8, x1, y1, 8, 8) == 1)
        *s -= 1;

    return *s;
}



void enemy_move(int sprite, UINT8* enemyx, UINT8* enemyy, UINT8* playerx, 
        UINT8* playery, UINT8* velx, UINT8* vely)
{
    bounce(enemyx, enemyy, playerx, playery, velx, vely);
    move_sprite(sprite, *enemyx, *enemyy);
    /* this would attempt to speed up a sprite. */
    /*add_vect(x, y, incr, incr);*/
}

void init_enem(void)
{
    /* enter enemies! */
    initrand(time(&t));
    //for(j = enemy_count; j < enemy_count+1; ++j)
    //{

        enemies[enemy_count][0] = (rand()%60);
        enemies[enemy_count][1] = 40;
       /* gotogxy(3, 5);
        gprintf("j: %d", j);*/
    //}
}

void level_change(void)
{       /* clocks per ms */
    if (clock() % 300 == 5)/*/ ((CLOCKS_PER_SEC)*1000)) % 6 == 5)*/
    {
        if(enemy_count <= MAX_ENEMY)
        {
            ++enemy_count;
            init_enem();
            /*gotogxy(3, 3);
            gprintf("Enemy count: %d", enemy_count);*/
        }
        if(enemy_count > MAX_ENEMY)
            enemy_count = MAX_ENEMY;
    }
}

/* Add two vectors. */
void add_vect(UINT8* x, UINT8* y, UINT8* x1, UINT8* y1) 
{
    *x += *x1;
    *y += *y1;
}


/* Are we hitting a wall? */
void wall_check(UINT8 *x, UINT8 *y)
{
    /* left wall */
    if(*x < 24)
        *x = 24;

    /* right wall */
    if(*x > 144)
        *x = 144;

    /* top wall */
    if(*y < 32)
        *y = 32;

    /* bottom wall */
    if(*y > 136)
        *y = 136;
}

/* BOUNCE OFF THE EVERYTHING! */
void bounce(UINT8* x, UINT8* y, UINT8* x1, UINT8* y1,
        UINT8* velx, UINT8* vely)
{
    /* bounce off player */
    if(collision_check(x, y, 8, 8, x1, y1, 8, 8) == 1)
    {
        *velx *= -1;
        *vely *= -1;
    }

    *x += (*velx);
    *y += (*vely);
    /* left wall. */
    if(*x >= 24)
        *velx *= -1;

    /* right wall */
    if(*x <= 144)
        *velx *= -1;

    /* top wall */
    if(*y <=32)
        *vely *= -1;

    /* bottom wall */
    if(*y >= 136)
        *vely *= -1;
}
