#include "assets/chain_border.c"
#include "assets/chain_border_tiles.c"
#include "assets/font.c"

#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h>
#include <gb/drawing.h>

/**
 * prints array of characters; max size = 10
 * arr = array of characters
 * x = x position
 * y = y position
 * print_ln = what number line is being printed
 * print_ln starts at 0
 */
void print(char* arr, UINT8 x, UINT8 y, UINT8 print_ln);

char chars[40] = "abcdefghijklmnopqrstuvwxyz0123456789.,;:";
UINT8 i;
UINT8 j;

void main(void)
{

    wait_vbl_done();
    HIDE_WIN;
    HIDE_BKG;
    DISPLAY_OFF;

    set_bkg_data(0, 10, chain_border_tiles);
    set_bkg_tiles(0,0,20,18, chain_border);

    set_sprite_data(0, 46, font);
    print("\"we're all\"", 40, 32, 0);
    print("goin'\0", 40, 48, 1);
    print("to hell!\"\0", 40, 64, 2);
    //print("you hear?\0", 40, 80, 3);

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
}

/**
 * Only takes a string of size 10.
 */
void print(char *arr, UINT8 x, UINT8 y, UINT8 print_ln)
{
    print_ln*=10;
    

    for(i=0; arr[i] != '\0'; ++i)
    {
        for(j=0; j < 48; ++j)
        {
            if(arr[i] == ' ')
                break;
            if(arr[i] == '\'')
            {
                set_sprite_tile((i+print_ln), 42);
                move_sprite((i+print_ln), x, y);
            }
            if(arr[i] == '!')
            {
                set_sprite_tile((i+print_ln), 43);
                move_sprite((i+print_ln), x, y);
            }
            if(arr[i] == '"')
            {
                set_sprite_tile((i+print_ln), 44);
                move_sprite((i+print_ln), x, y);
            }
            if(arr[i] == '?')
            {
                set_sprite_tile((i+print_ln), 45);
                move_sprite((i+print_ln), x, y);
            }
            if(arr[i] == chars[j])
            {
                set_sprite_tile((i+print_ln), j);
                move_sprite((i+print_ln), x, y);
            }
        }
        x+=8;
    }
}
