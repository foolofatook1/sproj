#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#include "assets/chain_border_tiles.c"
#include "assets/text_box.c"
#include "assets/font.c"

/**
 * prints array of characters; max size = 10
 * arr = array of characters
 * x = x position
 * y = y position
 * print_ln = what number line is being printed
 * print_ln starts at 0
 */
void print(char* arr, UINT8 x, UINT8 y, UINT8 print_ln);

char chars[55] = "abcdefghijklmnopqrstuvwxyz0123456789.,;:  ;!'\"?";
UINT8 i;
UINT8 j;

void main(void)
{

    wait_vbl_done();
    HIDE_WIN;
    SHOW_BKG;
    DISPLAY_OFF;

    set_bkg_data(0, 7, chain_border_tiles);
    set_bkg_tiles(0,0,20,18, text_box);

    
    set_sprite_data(0, 46, font);
    print("hello world", 24, 32, 0);
    print("how are you?", 24, 48, 1);
    print("wtf is going", 24, 64, 2);
    print("on?", 24, 80, 3);

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
}

void print(char *arr, UINT8 x, UINT8 y, UINT8 print_ln)
{
    print_ln*=10;

    for(i=0; i < 13; ++i)
    {
        for(j=0; j < 55; ++j)
        {
            if(arr[i] == ' ')
                continue;
            if(arr[i] == chars[j])
            {
                set_sprite_tile((i+print_ln), j);
                move_sprite((i+print_ln), x, y);
            }
        }
        x+=8;
    }
}
