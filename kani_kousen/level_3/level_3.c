#include "level_3.h"
#include "../text/text.h"
#include "../battle/battle.h"

void level_3_ctrl(void)
{
    clear_screen();
    delay(500);
    sprite_clean();
    LETTER_COUNT = 0;
    print("hello!\0", 24, 32);
    print("you're in\0", 24, 48);
    print("level 3!\0", 24, 64);
}
