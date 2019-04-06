#include "level_3.h"
#include "../text/text.h"
#include "../level_1/asakawa_battle.h"
#include "../battle/battle.h"
#include "../level_1/level_1.h"
#include "../level_2/level_2.h"
#include "../level_2/crab_catch.h"
#include "../assets/level_assets/level_assets.h"
#include "../start_up/start_up.h"

void level_3_ctrl(void)
{
    option = LEVEL_3;
    GOT_INFO = 0;
    DISPLAY_OFF;
    clear_screen();
    delay(500);
    sprite_clean();
    LETTER_COUNT = 0;
    print("chapter 3\0", 48, 56);
    print("rxvxlxtxxn\0", 44, 72);
    DISPLAY_ON;
    delay(1000);
    DISPLAY_OFF;
    shit_pot_setup();
    shit_pot_sprites();
    DISPLAY_ON;
    moving = 1;
    while(!striking)
    {
        while(moving)
        {
            option = LEVEL_3;
            hero_walk();
            pos_check_shit_pot();
            if(conv_check())
                break;
        }
        if(!striking)
            leaves_shit_pot();
    }
    delay(1000);
    DISPLAY_OFF;
    sprite_clean();
    LETTER_COUNT = 0;
    shit_pot_setup();
    shit_pot_sprites();
    DISPLAY_ON;
    
    /* asakawa shooting */
    anim_1 = 32;
    anim_2 = 34;
    asakawa_posx = 75;
    asakawa_posy = 65;
    set_sprite_data(32, 32, asakawa_air_shot);
    set_sprite_tile(14, anim_1);
    set_sprite_tile(15, anim_2);
    move_sprite(14, asakawa_posx, asakawa_posy);
    move_sprite(15, asakawa_posx+sprite_width, asakawa_posy);
    for(i = 0; i < 7; ++i)
    {
        set_sprite_tile(14, anim_1+=4);
        set_sprite_tile(15, anim_2+=4);
        delay(500);
    }
    delay(500);
    DISPLAY_OFF;
    bkg_clean();
    sprite_clean();
    LETTER_COUNT = 0;
    DISPLAY_ON;
    print("asakawa:\0", 24, 32);
    print("i've heard\0", 24, 48);
    print("talk of a\0", 24, 64);
    print("strike!\0", 24, 80);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("show me\0", 24, 48);
    print("your\0", 24, 64);
    print("leaders!\0", 24, 80);
    delay(1000);
    DISPLAY_OFF;
    clear_screen();
    sprite_clean();
    LETTER_COUNT = 0;
    print("fight\0", 64, 32);
    print("asakawa\0", 56, 48);
    DISPLAY_ON;
    ENEMY = 0;
    ITEMS = 2;
    HERO_HP = 50;
    ASAKAWA_HP = 200; /* this will later go back down to 100 */
    start_hp = 50;
    asakawa_battle_ctrl();
    /* third time around can increase HERO_HP to 100 */
    clear_screen();
    sprite_clean();
    LETTER_COUNT = 0;
    print("made it!\0", 24, 32);
    /**
     * Now we need to:
     *  1) have battle with asakawa and imperial army
     *  2) lose battle
     *  3) have another battle with different tactic
     *  4) win battle
     */
}

void leaves_shit_pot(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
    asakawa_enters_deck();
    asakawa_before_work();
    crab_catch_ctrl();
    asakawa_enters_deck();
    asakawa_after_work();
    delay(500);
    DISPLAY_OFF;
    shit_pot_setup();
    shit_pot_sprites();
    delay(500);
    DISPLAY_ON;

    moving = 1;
    GOT_INFO = 0;
    SLEPT = 0;
    caught_crabs = 0;
}
