#include "text.h"
#include <stdio.h>
#include <stdlib.h>

/*unsigned char speech[] = "it's the\n beriberi.\n * damn that\n asakawa!\n * nobody's\n * on our * side,\n * except
 * our\n * own selves.\n * they were\n wrong,\n * we were\n wrong!\n * we all\n should\n have acted\n together! *
 * there'd be\n no one to\n work if\n they took\n * us all\n away! * well let's\n do it\n again,\n * one more\n
 * time!\0";*/

//unsigned char ints[] = "0123456789.,:/";
UINT8 i;
UINT8 j;
UINT8 cushion;
UINT8 LETTER_COUNT = 0;
/* MAX number of sprites that can be on screen at once */
UINT8 MAX_SPRITES = 40; 

UINT8 START_X = 0;

/* hide arrow off screen */
UINT8 arrow_x = 200; 
UINT8 arrow_y = 200;

/**
 * 0 = [    . = e
 * 1 = \    , = f
 * 2 = ]    : = g
 * 3 = ^    / = h
 * 4 = _   ' '= i
 * 5 = `    > = j
 * 6 = a    ' = k
 * 7 = b    ! = l
 * 8 = c    " = m
 * 9 = d    ? = n
 *
 * {A...Z} = {A...Z}
 */
void print(char *arr, UINT8 x, UINT8 y)
{
    SPRITES_8x8;
    cushion = LETTER_COUNT;
    set_sprite_data(0, 46, font);
    START_X = x;
    for(i = 0; arr[i] != '\0'; i++)
    {
        if(arr[i] == '\n')
        {
            y+=16;
            x=START_X;
            continue;
        }
        else
        {
            set_sprite_tile((i+cushion), (arr[i]-65));
            move_sprite((i+cushion), x, y);
            ++LETTER_COUNT;
            x+=8;
        }
    }
}

/*void fancy_print(char *arr, UINT8 x, UINT8 y, UINT8 clean) 
  {
  SPRITES_8x8;
  cushion = LETTER_COUNT;
  set_sprite_data(0, 46, font);
  START_X = x;
  for(i = 0; arr[i] != '\0'; ++i)
  {
  if(arr[i] == '\n')
  {
  y+=16;
  x=START_X-8;
  }
  if(arr[i] == '{')
  {
  delay(1000);
  sprite_clean(clean);
  LETTER_COUNT = clean;
  }
  set_sprite_tile((i+cushion), (arr[i]-65));
  move_sprite((i+cushion), x, y);
  ++LETTER_COUNT;
  x+=8;
  }
  }*/

void bkg_clean(void)
{
    set_bkg_data(0, 10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18,chain_border);
}

void sprite_clean(UINT8 start) 
{
    /**
     * could also try making this letter 
     * count instead of MAX SPRITES 
     */
    for(i = start; i < MAX_SPRITES; ++i)
    {
        set_sprite_tile(i, 40);
        set_sprite_prop(i, S_FLIPX&0x0);
    }
}

void hide_sprites(void) 
{
    for(i = 0; i < MAX_SPRITES; ++i)
    {
        move_sprite(i, 250, 250);
    }
}

/* special text settings for battles */
void battle_print(char *arr, UINT8 x, UINT8 y) 
{
    SPRITES_8x8;

    set_sprite_data(0, 46, font);

    set_bkg_data(0, 10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18, small_chain_border);

    cushion = LETTER_COUNT;

    for(i = 0; arr[i] != '\0'; ++i)
    {
        set_sprite_tile((i+cushion), (arr[i]-65));
        move_sprite((i+cushion), x, y);
        ++LETTER_COUNT;
        x+=8;
    }
}

void damn_that_asakawa(void)
{
    sprite_clean(8);
    LETTER_COUNT = 8;
    print("DAMNiTHAT\nASAKAWA\0", 24, 48);
}

void you_hear(void)
{
    print("YOUiHEARln\0", 24, 48);
}

/**
 * labels for the different 
 * characters when they talk 
 */
void asakawa(void)
{
    print("ASAKAWAg\0", 24, 32);
}

void fisherman(void)
{
    print("FISHERMANg\0", 24, 32);
}

void student(void)
{
    print("STUDENTg\0", 24, 32);
}

void miner(void)
{
    print("MINERg\0", 24, 32);
}

void workers(void)
{
    print("WORKERSg\0", 24, 32);
}

void battle_bkg_clean(void)
{
    set_bkg_data(0, 10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18,small_chain_border);
}
