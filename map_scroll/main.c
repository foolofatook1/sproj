#include <stdio.h>
#include <stdlib.h>
#include <gb/gb.h> #include <gb/drawing.h>

#include "second_map.c"
#include "second_map_tiles.c"

#define MapSizeX 40
#define MapSizeY 32

#define Width  20 /* 166 pixels divided by 8 */
#define Height 18 /* 144 pixels divided by 8 */

void bkg(void)
{
	wait_vbl_done();
	disable_interrupts();
	DISPLAY_OFF;
	HIDE_SPRITES;
	HIDE_WIN;
	HIDE_BKG;

	set_bkg_data(0,6,second_map_tiles);
	set_bkg_tiles(0,0,40,32,second_map);

}

void walk(void)
{
	/* Down */
	if(joypad() & J_DOWN)
		scroll_bkg(0,1);

	/* Up */
	if(joypad() & J_UP)
		scroll_bkg(0,-1);

	/* Left */
	if(joypad() & J_LEFT)
		scroll_bkg(-1,0);

	/* Right */
	if(joypad() & J_RIGHT)
		scroll_bkg(1,0);

}

void main(void)
{
	UBYTE scrollX = 0;
	UBYTE scrollY = 0;
	BYTE x = 0;
	BYTE y = 0;
	UBYTE tempa = 0;
	UBYTE tempb = 0;
	UWORD counter = 0;
	UBYTE i = 0;

	wait_vbl_done();
	disable_interrupts();
	DISPLAY_OFF;
	HIDE_SPRITES;
	HIDE_WIN;
	HIDE_BKG;

	set_bkg_data(0,6,second_map_tiles);

	//for(tempa = 0; tempa != MapSizeX; tempa++)
	//{
	//	set_bkg_tiles(0, tempa, 40, 1, &(second_map+counter));
	//	counter = counter + MapSizeX;
	//}
	set_bkg_tiles(0,0,MapSizeX,MapSizeY+100,second_map);
	SHOW_BKG;
	DISPLAY_ON;
	while(1)
	{
		wait_vbl_done();
		i = joypad();
		if((i & J_LEFT) && (scrollX != 0))
		{
			scroll_bkg(-1,0);
			x--; /* x increments by 1 for every pixel it moves */
		}
		if((i & J_RIGHT) && (scrollX <= 10))
		{
			scroll_bkg(1,0);
			x++; /* x increments by 1 for every pixel it moves */
		}
		if(i & J_UP)
		{
			scroll_bkg(0,-1);
			y--;
		}
		if(i & J_DOWN)
		{
			scroll_bkg(0,1);
			y++;
		}
		if(x == 8)
		{
			scrollX++;
			x = 0;
			set_bkg_tiles(0,0,MapSizeX,MapSizeY,second_map+scrollX);
			/*counter = scrollX+Width;
			  tempb = counter % MapSizeY;
			  for(tempa = 0; tempa != Height; tempa++)
			  {
			  set_bkg_tiles(tempb, tempa, 1, 1, second_map+counter);
			  counter += MapSizeX;
			  }*/
		}
		if(x == -8)
		{
			scrollX--;
			x = 0;
			set_bkg_tiles(0,0,MapSizeX,MapSizeY,second_map+scrollX);
			/*counter = scrollX+Width;
			  tempb = counter % MapSizeY;
			  for(tempa = 0; tempa != 18; tempa++)
			  {
			  set_bkg_tiles(tempb, tempa, 1, 1, second_map+counter);
			  counter = counter + MapSizeX;
			  }*/
		}
		/*		if(y == 8)
				{
				scrollY++;
				y = 0;
				set_bkg_tiles(0,scrollY,MapSizeX,MapSizeY,second_map);
				}
				if(y == -8)
				{
				scrollY--;
				y = 0;
				set_bkg_tiles(0,scrollY,MapSizeX,MapSizeY,second_map);
				}*/
	}
}
