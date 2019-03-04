#include "text.h"

char chars[40] = "abcdefghijklmnopqrstuvwxyz0123456789.,;/";
UINT8 i;
UINT8 j;
UINT8 cushion;
UINT8 LETTER_COUNT = 0;

void print(char *arr, UINT8 x, UINT8 y)
{
    SPRITES_8x8;

    set_sprite_data(0, 46, font);

    set_bkg_data(0, 10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18, chain_border);

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

void bkg_clean(void)
{
    set_bkg_data(0, 10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18,chain_border);
}

void sprite_clean(void)
{
    for(i = 0; i < 100; ++i)
    {
        set_sprite_tile(i, 40);
    }
}

void hide_sprites(void)
{
    for(i = 0; i < 100; ++i)
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
