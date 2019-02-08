#include "assets/font.c"

UINT8 length(UWORD*);
void print(UWORD*, UINT8, UINT8);
void text_put(void);//UINT8, UINT8);

//UWORD *string;
UINT8 size;


/**
 * Returns the size of given word.
 */
UINT8 length(UWORD *words)
{
	UINT8 count;
	for(count = 0; words[count] != 'd'; count++){
		printf("letter: %c count: %d\n", words[count], count);
	}

	return count+1;
}


void print(UWORD *words, UINT8 x, UINT8 y)
{
	SPRITES_8x8;

	size = length(words);
	printf("size: %d", size);
	/*string[size] = *words;*/

	set_sprite_data(0, size, font);

	//text_put(x, y);
}

/* Check to see what values are string is. */
void text_put(void)//UINT8 x_, UINT8 y_)
{
	char string[12] = "hello world";

	UINT8 x = 15;
	UINT8 y = 90;

	UINT8 i;
	for(i = 0; i < size; ++i)
	{
		/*if(string[i] == 'a')
		  if(string[i] == 'b')
		  if(string[i] == 'c')*/
		if(string[i] == 'd')
		{
			set_sprite_tile(0, 3);
			move_sprite(0, x, y++);
		}
		if(string[i] == 'e')
		{
			set_sprite_tile(1, 4);
			move_sprite(1, 16, 90);
		}
		/*if(string[i] == 'f')
		  if(string[i] == 'g')*/
		if(string[i] == 'h')
		{
			set_sprite_tile(2, 7);
			move_sprite(2, 17, 90);
		}
		/*if(string[i] == 'i')
		  if(string[i] == 'j')
		  if(string[i] == 'k')*/
		if(string[i] == 'l')
		{
			set_sprite_tile(3, 11);
			move_sprite(3, 18, 90);
		}
		/*if(string[i] == 'm')
		  if(string[i] == 'n')*/
		if(string[i] == 'o')
		{
			set_sprite_tile(4, 14);
			move_sprite(4, 19, 90);
		}
		/*if(string[i] == 'p')
		  if(string[i] == 'q')*/
		if(string[i] == 'r')
		{
			set_sprite_tile(5, 17);
			move_sprite(5, x, y++);
		} 
		/*if(string[i] == 's')
		  if(string[i] == 't')
		  if(string[i] == 'u')
		  if(string[i] == 'v')*/
		if(string[i] == 'w')
		{
			set_sprite_tile(6, 22);
			move_sprite(6, x, y++);
		} 
		/*if(string[i] == 'x')
		  if(string[i] == 'y')
		  if(string[i] == 'z')
		  if(string[i] == '0')
		  if(string[i] == '1')
		  if(string[i] == '2')
		  if(string[i] == '3')
		  if(string[i] == '4')
		  if(string[i] == '5')
		  if(string[i] == '6')
		  if(string[i] == '7')
		  if(string[i] == '8')
		  if(string[i] == '9')
		  if(string[i] == '.')
		  if(string[i] == ',')
		  if(string[i] == ';')
		  if(string[i] == ':')
		  if(string[i] == ' ')
		  if(string[i] == ' ')
		  if(string[i] == ''')
		  if(string[i] == '"')
		  if(string[i] == '?')*/
	}
}
