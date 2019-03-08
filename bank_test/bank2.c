#include "bank2.h"

void hello(void)
{
    while(1)
    {
            print("hello world", arrow_x, arrow_y);
            arrow_y+=16;
            delay(500);
            bkg_clean();
            sprite_clean();
            if(arrow_y >= 134)
                arrow_y = 32;
    }
}
