#include "text.h"
#include <stdio.h>
#include <stdlib.h>

char chars[40] = "abcdefghijklmnopqrstuvwxyz0123456789.,:/";
//char ints[] = "0123456789.,:/";
UINT8 i;
UINT8 j;
UINT8 cushion;
UINT8 LETTER_COUNT = 0;
/* MAX number of sprites that can be on screen at once */
UINT8 MAX_SPRITES = 40; 

/* hide arrow off screen */
UINT8 arrow_x = 200; 
UINT8 arrow_y = 200;

void print(char *arr, UINT8 x, UINT8 y) 
{
    SPRITES_8x8;
    cushion = LETTER_COUNT;
    set_sprite_data(0, 46, font);
    /*for(i = 0; arr[i] != '\0'; ++i)
      {
    // check for integers 
    for(j = 0; j < 14; ++j)
    {
    if(ints[j] == arr[i])
    {
    set_sprite_tile((i+cushion), (26+j));
    move_sprite((i+cushion), x, y);
    continue;
    }
    }
    if(arr[i] == ' ')
    {
    set_sprite_tile((i+cushion), 40);
    move_sprite((i+cushion), x, y);
    }
    if(arr[i] == '>')
    {
    set_sprite_tile((i+cushion), 41);
    move_sprite((i+cushion), x, y);
    }
    if(arr[i] == '\'')
    {
    set_sprite_tile((i+cushion), 42);
    move_sprite((i+cushion), x, y);
    }
    if(arr[i] == '!')
    {
    set_sprite_tile((i+cushion), 43);
    move_sprite((i+cushion), x, y);
    }
    if(arr[i] == '"')
    {
    set_sprite_tile((i+cushion), 44);
    move_sprite((i+cushion), x, y);
    }
    if(arr[i] == '?')
    {
    set_sprite_tile((i+cushion), 45);
    move_sprite((i+cushion), x, y);
    }
    else
    {
    set_sprite_tile((i+cushion), (arr[i]-97));
    move_sprite((i+cushion), x, y);
    }
    ++LETTER_COUNT;
    x+=8;
    }*/


    for(i=0; arr[i] != '\0'; ++i)
    {
        for(j=0; j < 48; ++j)
        {
            if(arr[i] == ' ')
                break;
            if(arr[i] == '>')
            {
                set_sprite_tile((i+cushion), 41);
                move_sprite((i+cushion), x, y);
            }
            if(arr[i] == '\'')
            {
                set_sprite_tile((i+cushion), 42);
                move_sprite((i+cushion), x, y);
            }
            if(arr[i] == '!')
            {
                set_sprite_tile((i+cushion), 43);
                move_sprite((i+cushion), x, y);
            }
            if(arr[i] == '"')
            {
                set_sprite_tile((i+cushion), 44);
                move_sprite((i+cushion), x, y);
            }
            if(arr[i] == '?')
            {
                set_sprite_tile((i+cushion), 45);
                move_sprite((i+cushion), x, y);
            }
            if(arr[i] == chars[j])
            {
                set_sprite_tile((i+cushion), j);
                move_sprite((i+cushion), x, y);
            }
        }
        ++LETTER_COUNT;
        x+=8;
    }
}

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
    for(i=0; arr[i] != '\0'; ++i)
    {
        for(j=0; j < 48; ++j)
        {
            if(arr[i] == ' ')
                break;
            if(arr[i] == '>')
            {
                set_sprite_tile((i+cushion), 41);
                move_sprite((i+cushion), x, y);
            }
            if(arr[i] == '\'')
            {
                set_sprite_tile((i+cushion), 42);
                move_sprite((i+cushion), x, y);
            }
            if(arr[i] == '!')
            {
                set_sprite_tile((i+cushion), 43);
                move_sprite((i+cushion), x, y);
            }
            if(arr[i] == '"')
            {
                set_sprite_tile((i+cushion), 44);
                move_sprite((i+cushion), x, y);
            }
            if(arr[i] == '?')
            {
                set_sprite_tile((i+cushion), 45);
                move_sprite((i+cushion), x, y);
            }
            if(arr[i] == chars[j])
            {
                set_sprite_tile((i+cushion), j);
                move_sprite((i+cushion), x, y);
            }
        }
        ++LETTER_COUNT;
        x+=8;
    }
}

void battle_bkg_clean(void)
{
    set_bkg_data(0, 10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18,small_chain_border);
}
