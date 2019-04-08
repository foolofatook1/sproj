#include "level_2.h"
#include <stdio.h>
#include <stdlib.h>
#include "crab_catch.h"
#include "../assets/level_assets/level_assets.h"
#include "../text/text.h"
#include "../battle/battle.h"
#include "../start_up/start_up.h"
#include "../level_3/level_3.h"
#include "crab_catch.h"

/* save this for later when checking collisions with sprites */
UINT8 arr_size = 9;
UINT8 sprite_positions[] = {
    48, 64,
    64, 64,
    148,124,
    132, 64,
    16, 132,
    80,112 /* fisherman2_posx & fisherman2_posy */
};

UINT8 GOT_INFO = 0;
UINT8 talking = 1;
UINT8 moving = 1;
UINT8 left = 0;
UINT8 screen_x = 95;

void level_2_ctrl(void)
{
    wait_vbl_done();
    level_2_bkg_start();
    l2_scene_1();
    talking = 1;
    wait_vbl_done();
    l2_scene_1_fisherman_enter(); 
    fisherman_walk_away();
    while(moving)
    {
        option = LEVEL_2;
        wait_vbl_done();
        hero_walk(); 
        pos_check_shit_pot();
    }
    while(option != LEVEL_3 && option != GAME_OVER)
    {
        GOT_INFO = 0;
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
        if(option != LEVEL_3)
        {
            while(moving && option != LEVEL_3)
            {
                option = LEVEL_2;
                hero_walk();
                pos_check_shit_pot();
                if(conv_check())
                    break;
            }
        }
        caught_crabs = 0;
    }
    option = LEVEL_3;
}

void level_2_bkg_start(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
    HIDE_SPRITES;
    HIDE_BKG;

    set_sprite_palette(0, 3, sprite_palette);
    /* load the black clear screen */
    set_bkg_tiles(0,0,20,18, black_screen);

    SHOW_SPRITES;
    SHOW_BKG;

    print("chapter 2\0", 48, 64);
    print("  lost\0", 48, 80);
    print(" at sea\0", 48, 96);
    for(i = 0; i < LETTER_COUNT; ++i)
        set_sprite_prop(i,1);
    delay(1000);
}

void shit_pot_setup(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
    hide_sprites();
    set_bkg_data(0, 4, blank_screen_tiles);
    set_bkg_tiles(0,0,20,18,shit_pot);
}

void shit_pot_sprites(void)
{
    hero_posx = 80;
    hero_posy = 80;
    student_posx = 48;
    student_posy = 64;
    fisherman_posx = 64;
    fisherman_posy = 64;
    fisherman2_posx = 80;
    fisherman2_posy = 112;
    student2_posx = 148;
    student2_posy = 124;
    miner_posx = 132;
    miner_posy = 64;
    bed_posx = 16;
    bed_posy = 132;

    SPRITES_8x16;
    set_sprite_data(0, 8, hero_front_idle);
    set_sprite_data(8, 4, student_front_idle);
    set_sprite_data(12, 4, fisherman_front_idle);
    set_sprite_data(16, 4, miner_front_idle);
    set_sprite_data(20, 4, bed);
    /* hero */
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    /* student */
    set_sprite_tile(2, 8);
    set_sprite_tile(3, 8);
    set_sprite_prop(3, S_FLIPX);
    move_sprite(2, student_posx, student_posy);
    move_sprite(3, student_posx+sprite_width, student_posy);
    /* student2 */
    set_sprite_tile(4, 8);
    set_sprite_tile(5, 8);
    set_sprite_prop(5, S_FLIPX);
    move_sprite(4, student2_posx, student2_posy);
    move_sprite(5, student2_posx+sprite_width, student2_posy);
    /* fisherman */
    set_sprite_tile(6, 12);
    set_sprite_tile(7, 12);
    set_sprite_prop(7, S_FLIPX);
    move_sprite(6, fisherman_posx, fisherman_posy);
    move_sprite(7, fisherman_posx+sprite_width, fisherman_posy);
    /* miner */
    set_sprite_tile(8, 16);
    set_sprite_tile(9, 16);
    set_sprite_prop(9, S_FLIPX);
    move_sprite(8, miner_posx, miner_posy);
    move_sprite(9, miner_posx+sprite_width, miner_posy);
    /* bed */
    set_sprite_tile(10, 20);
    set_sprite_tile(11, 22);
    move_sprite(10, bed_posx, bed_posy);
    move_sprite(11, bed_posx+sprite_width, bed_posy);

    if(((option == LEVEL_3) && (GOT_INFO) && (SLEPT)) || APPEARED)
    {
        /* fisherman2 */
        set_sprite_tile(12, 12);
        set_sprite_tile(13, 12);
        set_sprite_prop(13, S_FLIPX);
        move_sprite(12, fisherman2_posx, fisherman2_posy);
        move_sprite(13, fisherman2_posx+sprite_width, fisherman2_posy);
        APPEARED = 1;
        arr_size += 2;
    }

}

UINT8 sprite_collide_shit_pot(UINT8 *sprite_pos)
{
    for(i = 0; i < arr_size; i+=2)
    {
        if((hero_posx < (sprite_pos[i]+sprite_width)) &&
                ((hero_posx+sprite_width) > sprite_pos[i]) &&
                (hero_posy < (sprite_pos[i+1]+sprite_width)) &&
                ((hero_posy+sprite_width) > sprite_pos[i+1]))
        {
            hero_posx = sprite_pos[i]-8;
            hero_posy = sprite_pos[i+1]+8;
            move_sprite(0, hero_posx, hero_posy);
            move_sprite(1, hero_posx+sprite_width, hero_posy);
            return sprite_pos[i];
        }
    }
    return 0;
}

UINT8 conv_check(void)
{
    UINT8 sprite;
    UINT8 old_hero_posx;
    UINT8 old_hero_posy;
    if((sprite=sprite_collide_shit_pot(sprite_positions)) > 0)
    {

        /* student in top left corner */
        if(sprite == student_posx || sprite == fisherman_posx)
        {
            bkg_clean();
            old_hero_posx = hero_posx;
            old_hero_posy = hero_posy;
            if(!revolt)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                hide_sprites();
                print("workers:\0", 24, 32);
                print("you hear!?\0", 24, 48);
                delay(1000);
                if(option == LEVEL_2)
                {
                    sprite_clean();
                    LETTER_COUNT = 0;
                    print("workers:\0", 24, 32);
                    print("a fishing\0", 24, 48);
                    print("boat was\0", 24, 64);
                    print("lost!\0", 24, 80);
                    delay(1000);
                    sprite_clean();
                    LETTER_COUNT = 0;
                    print("workers:\0", 24, 32);
                    print("damn that\0", 24, 48);
                    print("asakawa!\0", 24, 64);
                    GOT_INFO = 1;
                }
            }
            if(revolt)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                hide_sprites();
                print("workers:\0", 24, 32);
                print("keep us\0",24, 48);
                print("out of it!\0", 24, 64);
                /*print("to do with\0", 24, 80);
                print("this!\0", 24, 96);*/
            }
        }
        /* student in bottom right corner */
        else if(sprite == student2_posx)
        {
            bkg_clean();
            old_hero_posx = hero_posx;
            old_hero_posy = hero_posy;
            if(!revolt)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                hide_sprites();
                print("student:\0", 24, 32);
                print("i don't\0", 24, 48);
                print("want to\0", 24, 64);
                print("die in\0", 24, 80);
                print("kamchatka\0", 24, 96);
                print("...\0",24,112);
            }
            if(revolt)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                hide_sprites();
                print("student:\0", 24, 32);
                print("i'm too\0", 24, 48);
                print("weak!\0", 24, 64);
            }
        } 
        else if(sprite == miner_posx)
        {
            bkg_clean();
            old_hero_posx = hero_posx;
            old_hero_posy = hero_posy;
            if(option == LEVEL_2)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                hide_sprites();
                print("miner:\0", 24, 32);
                print("it was the\0", 24, 48);
                print("same at\0", 24, 64);
                print("the mines!\0", 24, 80);
            }
            if(option == LEVEL_3 && !revolt)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                hide_sprites();
                print("miner:\0", 24, 32);
                print("you hear!?\0", 24, 48);
                delay(500);
                sprite_clean();
                LETTER_COUNT = 0;
                print("miner:\0", 24, 32);
                print("the boat's\0", 24, 48);
                print("back!\0", 24, 64);
                GOT_INFO = 1;
            }
            else if(option == LEVEL_3 && revolt)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                print("miner:\0", 24, 32);
                print("of course\0", 24, 48);
                print("i'll join\0", 24, 64);
                print("the fight!\0", 24, 80);
                talked = 1;
            }
        }
        else if(sprite == bed_posx)
        {
            sprite_clean();
            LETTER_COUNT = 0;
            hide_sprites();
            set_bkg_data(0, 4, blank_screen_tiles);
            set_bkg_tiles(0, 0, 20, 18, black_screen);
            print("sleeping\0", 56, 56);
            for(i = 0; i < LETTER_COUNT+3; ++i)
                set_sprite_prop(i, 1);
            delay(500);
            print(".\0", 75, 72);
            delay(500);
            print(".\0", 84, 72);
            delay(500);
            print(".\0", 92, 72);
            delay(800);
            sprite_clean();
            LETTER_COUNT = 0;
            print("press a\0", 56, 88);
            print("to wake\0", 56, 104);
            for(i = 0; i < LETTER_COUNT; ++i)
                set_sprite_prop(i, 1);
            SLEPT = 1;
            if(option == LEVEL_2 && (!GOT_INFO));
            else if((option == LEVEL_2) && (GOT_INFO))
            {
                clear_screen();
                sprite_clean();
                LETTER_COUNT = 0;
                print("next\0", 24, 32);
                option = LEVEL_3;
                return 1;
            }
        }
        else if((sprite == fisherman2_posx) && (APPEARED))
        {
            bkg_clean();
            old_hero_posx = hero_posx;
            old_hero_posy = hero_posy;
            if(!revolt)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("we were\0", 24, 48);
                print("lost at\0", 24, 64);
                print("sea,\0", 24, 80);
                delay(1300);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("we washed\0", 24, 48);
                print("ashore in\0", 24, 64);
                print("russia!\0", 24, 80);
                delay(1300);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("those\0", 24, 48);
                print("russkies\0", 24, 64);
                print("are on to\0",24, 80);
                print("something.\0", 24, 96);
                delay(1300);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("they\0", 24, 48);
                print("talked to\0",24, 64);
                print("us about\0", 24, 80);
                print("rxvxlxtxxn\0", 24, 96);
                delay(1300);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0",24, 32);
                print("we should\0", 24, 48);
                print("organize\0", 24, 64);
                print("too!\0", 24, 80);
                delay(1300);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("me, you,\0", 24, 48);
                print("and a\0",24, 64);
                print("couple\0",24, 80);
                print("others!\0", 24, 96);
                delay(1300);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("we could\0", 24, 48);
                print("organize\0", 24, 64);
                print("the crew!\0", 24, 80);
                delay(1300);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("what d'you\0", 24, 48);
                print("think?\0", 24, 64);
                delay(1000);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0",24, 32);
                print("will you\0", 24, 48);
                print("join us?\0", 24, 64);
                print("a yes!\0", 24, 88);
                print("b no...\0", 24, 104);
                REVOLUTION_1 = 1;
            }
            if(revolt && !talked)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("there's\0", 24, 48);
                print("not enough\0", 24, 64);
                print("talk to\0", 24, 80);
                delay(800);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("strike yet.\0", 24, 48);
                print("keep\0", 24, 64);
                print("talking\0", 24, 80);
            }
            if(revolt && talked)
                REVOLUTION_1 = 1;

            if(talked)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("we've got\0", 24, 48);
                print("the\0", 24, 64);
                print("numbers!\0", 24, 80);
                delay(1000);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("without\0", 24, 48);
                print("us\0", 24, 64);
                delay(800);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("ships\0", 24, 48);
                print("wouldn't\0", 24, 64);
                print("budge.\0", 24, 80);
                delay(800);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("without\0", 24, 48);
                print("us,\0", 24, 64);
                delay(500);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0", 24, 32);
                print("the rich\0", 24, 48);
                print("wouldn't\0", 24, 64);
                print("make a\0", 24, 80);
                print("dime!\0", 24, 96);
                delay(1000);
                sprite_clean();
                LETTER_COUNT = 0;
                print("fisherman:\0",24, 32);
                print("let's give\0", 24, 48);
                print("'em hell\0", 24, 64);
                print("together!\0", 24, 80);
                delay(1000);
                striking = 1;
                REVOLUTION_1 = 1;
            }
        }
        /* double check that we didn't mistakenly collide */
        for(i = 0; i < 12; i+=2)
        {
            if(sprite_positions[i] == sprite)
            {
                talking = 1;
                break;
            }
            else
                talking = 0;
        }
        while(talking)
        {
            if(!REVOLUTION_1)
            {
                if(joypad() & J_A)
                {
                    shit_pot_setup();
                    shit_pot_sprites();
                    hero_posx = old_hero_posx;
                    hero_posy = old_hero_posy;
                    move_sprite(0, hero_posx, hero_posy);
                    move_sprite(1, hero_posx+sprite_width, hero_posy);
                    talking = 0;
                }
            }
            if(REVOLUTION_1) /* prompt for revolution 1 */
            {
                if(joypad() & J_A)
                {
                    REVOLUTION_1 = 0;
                    health_loss = 0;
                    crabs_to_catch = 1;
                    if(revolt && talked)
                        return 1;
                    if(!revolt)
                    {
                        sprite_clean();
                        LETTER_COUNT = 0;
                        print("fisherman:\0", 24, 32);
                        print("good!\0", 24, 48);
                        delay(500);
                        sprite_clean();
                        LETTER_COUNT = 0;
                        print("fisherman:\0", 24, 32);
                        print("go see who\0", 24, 48);
                        print("can help!\0", 24, 64);
                        delay(1000);
                        revolt = 1;
                    }
                }
                if(joypad() & J_B)
                {
                    sprite_clean();
                    LETTER_COUNT = 0;
                    print("fisherman:\0", 24, 32);
                    print("that's too\0", 24, 48);
                    print("bad...\0", 24, 64);
                    revolt = 0;
                    option = LEVEL_3;
                    REVOLUTION_1 = 0;
                    ++health_loss;
                    crabs_to_catch+=2;
                    delay(500);
                    REVOLUTION_1 = 0;
                }
            }
        }
    }
    return 0;
}

/**
 * Should probably make hero_pos and fisherman_pos 
 * global at some point.
 */
void l2_scene_1(void)
{
    /* waking up the hero */
    sprite_clean();
    LETTER_COUNT = 0;
    delay(500);
    print("wake up!\0", 56, 75);
    for(i = 0; i < LETTER_COUNT; ++i)
        set_sprite_prop(i,1);
    delay(800);
    // reset sprite properties
    for(i = 0; i < LETTER_COUNT; ++i)
        set_sprite_prop(i, 1);
    /* start the next part */
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    hide_sprites();

    hero_posx = 80;
    hero_posy = 75;
    fisherman_posx = 160;
    fisherman_posy = 75;

    /* reset sprite properties back to normal */
    for(i = 0; i < MAX_SPRITES; ++i)
        set_sprite_prop(i, 0);
    /* hero lying down in shit pot */
    shit_pot_setup();
    SPRITES_8x16;
    set_sprite_data(0, 4, hero_lie_down);
    set_sprite_data(4, 4, hero_front_idle);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    move_sprite(0, hero_posx, hero_posy);//80, 75);
    move_sprite(1, hero_posx+sprite_width, hero_posy);//88, 75);
    /* hero stands up */
    delay(500);
    set_sprite_tile(0, 4);
    set_sprite_tile(1, 6);
    /* setting up fisherman data for his walk in */
    set_sprite_data(8, 8, fisherman_walk_side);
    set_sprite_tile(2, 8);
    set_sprite_tile(3, 10);
    /** 
     * enter fisherman (the -5 adds a little extra distance) 
     * i = 160 is the right side of the screen.
     */
    for(i = 0; fisherman_posx > 95; ++i)
    {
        delay(50);
        move_sprite(2, fisherman_posx, fisherman_posy);
        move_sprite(3, fisherman_posx+sprite_width, fisherman_posy);
        set_sprite_tile(2, (8+(4*(0x1&i))));
        set_sprite_tile(3, (10+(4*(0x1&i))));
        --fisherman_posx;
    }
    set_sprite_data(0, 4, hero_walk_sideways);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);

    delay(500);
    DISPLAY_OFF;
    bkg_clean();
    DISPLAY_ON;
    sprite_clean();
    LETTER_COUNT = 0;
    print("fisherman:\0", 24, 32);
    print("we've got\0", 24, 48);
    print("to get to\0", 24, 64);
    print("work!\0", 24, 80);
}

/*void joypad_check_l2_scene_1(void)
{
    if(joypad() & J_A)
        l2_scene_1_fisherman_enter();
}*/

void l2_scene_1_fisherman_enter(void)
{
    //++talking;
    //if(talking == 3)
    //{
        delay(1000);
        sprite_clean();
        LETTER_COUNT = 0;
        print("fisherman:\0", 24, 32);
        print("you'll\0", 24, 48);
        print("need these\0", 24, 64);
    //}
    //if(talking == 4)
    //{
        delay(1000);
        sprite_clean();
        LETTER_COUNT = 0;
        DISPLAY_OFF;
        set_bkg_tiles(0,0,20,18,blank_screen);
        DISPLAY_ON;
        print("you\0", 72, 32);
        print("acquire a\0", 48, 48);
        print("club and\0", 52, 64);
        print("fishing\0", 56, 80);
        print("net\0", 72, 96);
        ITEMS += 2;
    /*}
    if(talking == 5)
    {*/
    delay(1000);
        sprite_clean();
        LETTER_COUNT = 0;
        DISPLAY_OFF;
        bkg_clean();
        DISPLAY_ON;
        print("fisherman:\0", 24, 32);
        print("now let's\0", 24, 48);
        print("get going!\0", 24, 64);
    while(talking)
    {
        if(joypad() & J_A)
            talking = 0;
    }
}

void fisherman_walk_away(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
    hide_sprites();
    set_bkg_data(0, 4, blank_screen_tiles);
    set_bkg_tiles(0,0,20,18,shit_pot);

    /* setting up fisherman data for his walk in */
    SPRITES_8x16;
    set_sprite_data(0, 4, hero_walk_sideways);
    set_sprite_data(4, 4, fisherman_walk_up);

    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    set_sprite_tile(2, 4);
    set_sprite_tile(3, 6);


    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    move_sprite(2, fisherman_posx, fisherman_posy);
    move_sprite(3, fisherman_posx+sprite_width, fisherman_posy);

    /** 
     * enter fisherman (the -5 adds a little extra distance) 
     * i = 160 is the right side of the screen.
     */
    /* hero_pos[1][0]-SPRITE_WIDTH+5) */
    for(i = 0; fisherman_posy > 50; ++i)
    {
        delay(50);
        if(i&0x1)
        {
            set_sprite_prop(2, S_FLIPX);
            set_sprite_prop(3, S_FLIPX);
            move_sprite(2, fisherman_posx+sprite_width, fisherman_posy);
            move_sprite(3, fisherman_posx, fisherman_posy);
        }
        else 
        {
            set_sprite_prop(2, S_FLIPX&0x0);
            set_sprite_prop(3, S_FLIPX&0x0);
            move_sprite(2, fisherman_posx, fisherman_posy);
            move_sprite(3, fisherman_posx+sprite_width, fisherman_posy);
        }
        --fisherman_posy;
    }
    /* fisherman disappears */
    fisherman_posx = 200;
    fisherman_posy = 200;
    move_sprite(2, fisherman_posx, fisherman_posy);
    move_sprite(3, fisherman_posx, fisherman_posy);
}

void hero_walk(void)
{
    /**
     * need: hero_walk down
     */
    if(joypad() & J_UP)
    {
        set_sprite_data(0, 4, hero_walk_up);
        set_sprite_tile(0, 0);
        set_sprite_tile(1, 2);
        /* make sure sprites aren't flipped */
        set_sprite_prop(0, S_FLIPX&0x0);
        set_sprite_prop(1, S_FLIPX&0x0);
        move_sprite(0, hero_posx, hero_posy);
        move_sprite(1, hero_posx+sprite_width, hero_posy);
        if((hero_posy+hero_posx)&0x1)
        {
            set_sprite_prop(0, S_FLIPX);
            set_sprite_prop(1, S_FLIPX);
            move_sprite(0, hero_posx+sprite_width, hero_posy);
            move_sprite(1, hero_posx, hero_posy);
        }
        else
        {
            set_sprite_prop(0, S_FLIPX&0x0);
            set_sprite_prop(1, S_FLIPX&0x0);
            move_sprite(0, hero_posx, hero_posy);
            move_sprite(1, hero_posx+sprite_width, hero_posy);
        }
        left = 0;
        delay(50);
        hero_posy-=3;
    }
    if(joypad() & J_DOWN)
    {
        set_sprite_data(0, 4, hero_walk_down);
        set_sprite_tile(0, 0);
        set_sprite_tile(1, 2);
        /* make sure sprites aren't flipped */
        set_sprite_prop(0, S_FLIPX&0x0);
        set_sprite_prop(1, S_FLIPX&0x0);
        move_sprite(0, hero_posx, hero_posy);
        move_sprite(1, hero_posx+sprite_width, hero_posy);
        if((hero_posx+hero_posy)&0x1)
        {
            set_sprite_prop(0, S_FLIPX);
            set_sprite_prop(1, S_FLIPX);
            move_sprite(0, hero_posx+sprite_width, hero_posy);
            move_sprite(1, hero_posx, hero_posy);
        }
        else
        {
            set_sprite_prop(0, S_FLIPX&0x0);
            set_sprite_prop(1, S_FLIPY&0x0);
            move_sprite(0, hero_posx, hero_posy);
            move_sprite(1, hero_posx+sprite_width, hero_posy);
        }
        left = 0;
        delay(50);
        hero_posy+=3;
    }
    if(joypad() & J_LEFT)
    {
        set_sprite_data(0, 8, hero_walk_sideways);
        if(!left)
        {
            set_sprite_prop(0, S_FLIPX);
            set_sprite_prop(1, S_FLIPX);
        }
        if((hero_posx+hero_posy)&0x1)
        {
            set_sprite_tile(0, 4);
            set_sprite_tile(1, 6);
        }
        else
        {
            set_sprite_tile(0, 0);
            set_sprite_tile(1, 2);
        }
        move_sprite(0, hero_posx+sprite_width, hero_posy);
        move_sprite(1, hero_posx, hero_posy);
        left = 1;
        delay(50);
        hero_posx-=3;
    }
    if(joypad() & J_RIGHT)
    {
        set_sprite_data(0, 8, hero_walk_sideways);
        /* make sure the sprites aren't flipped */
        set_sprite_prop(0, S_FLIPX&0x0);
        set_sprite_prop(1, S_FLIPX&0x0);
        if((hero_posx+hero_posy)&0x1)
        {
            set_sprite_tile(0, 4);
            set_sprite_tile(1, 6);
        }
        else
        {
            set_sprite_tile(0, 0);
            set_sprite_tile(1, 2);
        }
        move_sprite(0, hero_posx, hero_posy);
        move_sprite(1, hero_posx+sprite_width, hero_posy);
        left = 0;
        delay(50);
        hero_posx+=3;
    }
}

void asakawa_enters_deck(void)
{
    hero_posx = 80;
    hero_posy = 116;
    sprite_clean();
    LETTER_COUNT = 0;
    hide_sprites();
    set_bkg_data(0,4,blank_screen_tiles);
    set_bkg_tiles(0,0,32,18,deck);
    SPRITES_8x16;
    set_sprite_data(0, 8, hero_walk_sideways);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    set_sprite_prop(0, S_FLIPX&0x0);
    set_sprite_prop(1, S_FLIPX&0x0);
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);

    fisherman_posx = 48;
    fisherman_posy = 128;

    set_sprite_data(8, 8, fisherman_walk_side);
    for(i = 2; i < 7; i+=2)
    {
        set_sprite_tile(i, 10);
        set_sprite_tile(i+1, 8);
        set_sprite_prop(i, S_FLIPX);
        set_sprite_prop(i+1, S_FLIPX);
    }
    move_sprite(2, fisherman_posx, fisherman_posy);
    move_sprite(3, fisherman_posx+sprite_width, fisherman_posy);
    move_sprite(4, fisherman_posx-20, fisherman_posy);
    move_sprite(5, fisherman_posx-20+sprite_width, fisherman_posy);
    move_sprite(6, fisherman_posx-40, fisherman_posy);
    move_sprite(7, fisherman_posx-40+sprite_width, fisherman_posy);

    /* asakawa */
    asakawa_posx = 156;
    asakawa_posy = 116;
    set_sprite_data(16, 8, asakawa_walk_side);
    set_sprite_tile(8, 16);
    set_sprite_tile(9, 18);
    move_sprite(8, asakawa_posx, asakawa_posy);
    move_sprite(9, asakawa_posx+sprite_width, asakawa_posy);
    while(asakawa_posx > 120)
    {
        delay(50);
        --asakawa_posx;
        set_sprite_tile(8, 16+(4*(asakawa_posx&0x1)));
        set_sprite_tile(9, 18+(4*(asakawa_posx&0x1)));
        move_sprite(8, asakawa_posx, asakawa_posy);
        move_sprite(9, asakawa_posx+sprite_width, asakawa_posy);
    }
    delay(500);
}

void asakawa_before_work(void)
{
    DISPLAY_OFF;
    bkg_clean();
    sprite_clean();
    LETTER_COUNT = 0;
    DISPLAY_ON;
    talking = 1;
    print("asakawa:\0", 24, 32);
    print("get these\0", 24, 48);
    print("crabs\0", 24, 64);
    print("ready to\0", 24, 80);
    print("can!\0", 24, 96);
    /* asakawa's instructions on how to play */
    while(talking)
    {
        if(joypad() & J_A)
        {
            ++talking;
            if(talking == 2)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                print("asakawa:\0", 24, 32);
                print("catch them\0", 24, 48);
                print("with your\0", 24, 64);
                print("net!\0", 24, 80);
            }
            if(talking == 3)
            {
                sprite_clean();
                LETTER_COUNT = 0;
                print("asakawa:\0", 24, 32);
                print("then bash\0", 24, 48);
                print("their\0", 24, 64);
                print("shells\0", 24, 80);
                print("with the\0", 24, 96);
                print("club!\0", 24, 112);
            }
            if(talking == 4)
                talking = 0;
        }
    }
}

void asakawa_after_work(void)
{
    DISPLAY_OFF;
    bkg_clean();
    sprite_clean();
    LETTER_COUNT = 0;
    DISPLAY_ON;
    print("asakawa:\0", 24, 32);
    print("now back\0", 24, 48);
    print("down to\0", 24, 64);
    print("the shit\0", 24, 80);
    print("pot!\0", 24, 96);
    delay(1000);
}

void pos_check_shit_pot(void)
{
    if(hero_posy <= 56)
    {
        hero_posy = 56;
        if(hero_posx >= 48 && hero_posx <= 108)
        {
            if(revolt)
            {
                hero_posy = 56;
                hero_posx = hero_posx;
            }
            else
                moving = 0;
        }
    }
    if(hero_posx <= 8)
        hero_posx = 8;
    if(hero_posy >= 144)
        hero_posy = 144;
    if(hero_posx >= 152)
        hero_posx = 152;
}

/*void pos_check_deck(void)
{
    if(hero_posy <= 116)
        hero_posy = 116;
    if(hero_posy >= 144)
        hero_posy = 144;
}*/
