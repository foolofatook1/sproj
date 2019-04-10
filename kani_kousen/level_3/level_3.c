#include "level_3.h"
#include "../text/text.h"
#include "../level_1/asakawa_battle.h"
#include "../battle/battle.h"
#include "../level_1/level_1.h"
#include "../level_2/level_2.h"
#include "../level_2/crab_catch.h"
#include "../assets/level_assets/level_assets.h"
#include "../start_up/start_up.h"
#include "../assets/sprites/student_lie_down.h"

void level_3_ctrl(void)
{
    option = LEVEL_3;
    GOT_INFO = 0;
    DISPLAY_OFF;
    clear_screen();
    delay(500);
    sprite_clean(0);
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
        option = LEVEL_3;
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
   // revolt = 1; // this is just for running tests;
    //STATE = FIGHT_CHOICE;
    delay(1000);
    DISPLAY_OFF;
    sprite_clean(0);
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
    STATE = BATTLE_CHOICE; // this is for tests
    delay(500);
    DISPLAY_OFF;
    bkg_clean();
    sprite_clean(0);
    LETTER_COUNT = 0;
    DISPLAY_ON;
    print("asakawa:\0", 24, 32);
    print("i've heard\0", 24, 48);
    print("talk of a\0", 24, 64);
    print("strike!\0", 24, 80);
    delay(1000);
    sprite_clean(8);
    LETTER_COUNT = 8;
    asakawa();
    print("show me\0", 24, 48);
    print("your\0", 24, 64);
    print("leaders!\0", 24, 80);
    delay(1000);
    DISPLAY_OFF;
    clear_screen();
    sprite_clean(0);
    LETTER_COUNT = 0;
    print("fight\0", 64, 32);
    print("asakawa\0", 56, 48);
    DISPLAY_ON;
    ENEMY = 0;
    ITEMS = 2;
    HERO_HP = 50;
    ASAKAWA_HP = 200; /* this will later go back down to 100 */
    start_hp = 50;

    sprite_clean(0);
    LETTER_COUNT = 0;
    STATE = BATTLE_CHOICE;
    option = LEVEL_3;

    /** 
     * battle mechanics are working. 
     * the bkg screen is just looking
     * a bit scrambled for some reason. 
     */

    asakawa_battle_ctrl();
    
    STATE = BATTLE_CHOICE;
    option = LEVEL_3;

    /* for some reason this is ending way too soon */

    bkg_clean();
    sprite_clean(0);
    LETTER_COUNT = 0;
    asakawa();
    print("now take\0", 24, 48);
    print("them away!\0", 24, 64);
    delay(800);
    DISPLAY_OFF;
    set_bkg_data(0, 4, blank_screen_tiles);
    set_bkg_tiles(0, 0, 20, 18, black_screen);
    DISPLAY_ON;
    delay(500);
    DISPLAY_OFF;
    SPRITES_8x16;
    shit_pot_setup();
    shit_pot_sprites();

    team_battle_show();

    set_sprite_data(24, 4, student_lie_down);
    set_sprite_tile(4, 24);
    set_sprite_tile(5, 26);
    move_sprite(4, student2_posx, student2_posy);
    move_sprite(5, student2_posx+sprite_width, student2_posy);
    DISPLAY_ON;


    /** 
     * the bug that's ruining the battle 
     * menu display is in here.
     */
    delay(1000);
    bkg_clean();
    sprite_clean(0);
    LETTER_COUNT = 0;
    workers();
    print("it's the\0", 24, 48);
    print("beriberi.\0", 24, 64);
    delay(1000);
    sprite_clean(8);
    LETTER_COUNT = 8;
    damn_that_asakawa();
    delay(1000);
    sprite_clean(8);
    LETTER_COUNT = 8;
    print("nobody's\0", 24, 48);
    print("on our\0", 24, 64);
    print("side,\0", 24, 80);
    delay(1000);
    sprite_clean(8);
    LETTER_COUNT = 8;
    print("except our\0", 24, 48);
    print("own selves.\0", 24, 64);
    delay(1000);
    sprite_clean(8);
    LETTER_COUNT = 8;
    print("we all\0", 24, 48);
    print("should've\0", 24, 64);
    print("acted\0", 24, 80);
    print("together!\0", 24, 96);
    delay(1000);
    sprite_clean(8);
    LETTER_COUNT = 8;
    print("there'd be\0", 24, 48);
    print("no one to\0", 24, 64);
    print("work\0", 24, 80);
    delay(1000);
    sprite_clean(8);
    LETTER_COUNT= 8;
    print("if\0", 24, 48);
    print("they took\0", 24, 64);
    print("us all!\0", 24, 80);
    delay(1000);
    sprite_clean(8);
    LETTER_COUNT = 8;
    print("let's\0", 24, 48);
    print("do it\0", 24, 64);
    print("again,\0", 24, 80);
    delay(1000);
    sprite_clean(8);
    LETTER_COUNT = 8;
    print("one more\0", 24, 48);
    print("time!\0", 24, 64);

    REVOLUTION_2 = 1;
    ENEMY = 0;
    ITEMS = 2;
    HERO_HP = 100;
    ASAKAWA_HP = 100; /* this will later go back down to 100 */
    start_hp = 100;
    option = LEVEL_3;
    STATE = BATTLE_CHOICE;
    
    asakawa_battle_ctrl();
    
    //STATE = BATTLE_CHOICE;
    //option = LEVEL_3;



    /* third time around can increase HERO_HP to 100 */
/*    clear_screen();
    sprite_clean();
    LETTER_COUNT = 0;
    print("made it!\0", 24, 32);*/
    /**
     *  Q: what incites the coming battle?
     *  1) have another battle with different tactic
     *  2) win battle
     */
}

void team_battle_show(void)
{
    hero_posx = 200;
    hero_posy = 200;
    fisherman2_posx = 200;
    fisherman2_posy = 200;
    miner_posx = 200;
    miner_posy = 200;
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    move_sprite(8, miner_posx, miner_posy);
    move_sprite(9, miner_posx+sprite_width, miner_posy);
    move_sprite(12, fisherman2_posx, fisherman2_posy);
    move_sprite(13, fisherman2_posx+sprite_width, fisherman2_posy);
    fisherman_posy = student2_posy-20;
    student_posy = fisherman_posy;
    fisherman_posx = student2_posx;
    student_posx = student2_posx-20;
    move_sprite(2, student_posx, student_posy);
    move_sprite(3, student_posx+sprite_width, student_posy);
    move_sprite(6, fisherman_posx, fisherman_posy);
    move_sprite(7, fisherman_posx+sprite_width, fisherman_posy);
}

void leaves_shit_pot(void)
{
    sprite_clean(0);
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
