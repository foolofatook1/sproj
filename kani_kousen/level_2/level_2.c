#include "level_2.h"
#include "crab_catch.h"
#include "../assets/level_assets/level_assets.h"
#include "../text/text.h"
#include "../battle/battle.h"

UINT8 talking = 1;
UINT8 moving = 1;
UINT8 left = 0;
UINT8 screen_x = 95;

void level_2_ctrl(void)
{
    wait_vbl_done();
    level_2_bkg_start();
    /* something odd is happening between these two functions */
    wait_vbl_done();
    l2_scene_1();
    while(talking > 0)
    {
        wait_vbl_done();
        joypad_check_l2_scene_1();
    }
    fisherman_walk_away();
    while(moving)
    {
        wait_vbl_done();
        hero_walk(); 
        pos_check_shit_pot();
    }
    deck_enter();
    deck_enter_intro_scene();
    moving = 1;
    while(moving)
    {
        wait_vbl_done();
        hero_scroll_walk();
        pos_check_deck();
        if(screen_x <= 0)
            moving = 0;
    }
    asakawa_enters_deck();
    crab_catch_ctrl();
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

    delay(2000);
    print("chapter 2\0", 48, 64);
    print("  lost\0", 48, 80);
    print(" at sea\0", 48, 96);
    for(i = 0; i < LETTER_COUNT; ++i)
        set_sprite_prop(i,1);
    delay(2500);
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
    delay(1000);
    HIDE_SPRITES;
    delay(500);
    SHOW_SPRITES;
    delay(500);
    HIDE_SPRITES;
    delay(500);
    SHOW_SPRITES;
    delay(800);

    sprite_clean();
    LETTER_COUNT = 0;
    print("we have to\0", 48, 75);
    print("get\0", 72, 91);
    print("to work!\0", 56, 107);
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
    set_bkg_tiles(0,0,20,18,shit_pot);
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
    /* hero_pos[1][0]-SPRITE_WIDTH+5) */
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

void joypad_check_l2_scene_1(void)
{
    if(joypad() & J_A)
        l2_scene_1_fisherman_enter();
}

void l2_scene_1_fisherman_enter(void)
{
    ++talking;
    if(talking == 3)
    {
        sprite_clean();
        LETTER_COUNT = 0;
        print("fisherman:\0", 24, 32);
        print("you'll\0", 24, 48);
        print("need these\0", 24, 64);
    }
    if(talking == 4)
    {
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
    }
    if(talking == 5)
    {
        sprite_clean();
        LETTER_COUNT = 0;
        DISPLAY_OFF;
        bkg_clean();
        DISPLAY_ON;
        print("fisherman:\0", 24, 32);
        print("now let's\0", 24, 48);
        print("get going!\0", 24, 64);
    }
    if(talking == 6)
        talking = 0;
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
        --hero_posy;
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
        ++hero_posy;
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
        --hero_posx;
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
        ++hero_posx;
    }
    /*if(check_items())
    {*/
        /* set things back to normal */
      /*  DISPLAY_OFF;
        set_bkg_data(0,4,blank_screen_tiles);
        set_bkg_tiles(0,0,20,18,shit_pot);
        hide_sprites();
        sprite_clean();
        LETTER_COUNT = 0;
        SPRITES_8x16;
        set_sprite_data(0, 4, hero_walk_down);
        set_sprite_tile(0, 0);
        set_sprite_tile(1, 2);*/
        /* make sure sprites aren't flipped */
        /*set_sprite_prop(0, S_FLIPX&0x0);
        set_sprite_prop(1, S_FLIPX&0x0);
        move_sprite(0, hero_posx, hero_posy);
        move_sprite(1, hero_posx+sprite_width, hero_posy);
        DISPLAY_ON;
    }*/
}

void hero_scroll_walk(void)
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
        if((hero_posx+screen_x+hero_posy)&0x1)
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
        --hero_posy;

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
        if((hero_posx+screen_x+hero_posy)&0x1)
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
        ++hero_posy;
    }
    if(joypad() & J_LEFT)
    {
        set_sprite_data(0, 8, hero_walk_sideways);
        if(!left)
        {
            set_sprite_prop(0, S_FLIPX);
            set_sprite_prop(1, S_FLIPX);
        }
        if((hero_posx+screen_x+hero_posy)&0x1)
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
        if((hero_posx > 72 || screen_x <= 0) && 
                hero_posx+screen_x >= 16)
            --hero_posx;
        if(hero_posx <= 72 && screen_x > 0)
            move_bkg(--screen_x, 0);
    }
    if(joypad() & J_RIGHT)
    {
        set_sprite_data(0, 8, hero_walk_sideways);
        /* make sure the sprites aren't flipped */
        set_sprite_prop(0, S_FLIPX&0x0);
        set_sprite_prop(1, S_FLIPX&0x0);
        if((hero_posx+screen_x+hero_posy)&0x1)
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
        if((hero_posx < 86 || screen_x+160 >= 255) && 
                hero_posx+sprite_width+screen_x <= 250)
            ++hero_posx;
        if(hero_posx >= 86 && (screen_x+160) < 255)
            move_bkg(++screen_x, 0);
    }
    /*if(check_items())
    {*/
        /* set things back to normal */
      /*  DISPLAY_OFF;
        set_bkg_data(0,4,blank_screen_tiles);
        set_bkg_tiles(0,0,32,18,deck);
        move_bkg(screen_x, 0);
        hide_sprites();
        sprite_clean();
        LETTER_COUNT = 0;
        SPRITES_8x16;
        set_sprite_data(0, 4, hero_walk_down);
        set_sprite_tile(0, 0);
        set_sprite_tile(1, 2);*/
        /* make sure sprites aren't flipped */
        /*set_sprite_prop(0, S_FLIPX&0x0);
        set_sprite_prop(1, S_FLIPX&0x0);
        move_sprite(0, hero_posx, hero_posy);
        move_sprite(1, hero_posx+sprite_width, hero_posy);
        DISPLAY_ON;
    }*/
}

void deck_enter(void)
{
    DISPLAY_OFF;
    set_bkg_data(0, 4, blank_screen_tiles);        
    set_bkg_tiles(0, 0, 32, 18, deck);
    move_bkg(screen_x, 0);
    HIDE_SPRITES;

    hero_posx = 140;
    hero_posy = 128;

    set_sprite_data(0, 8, hero_walk_sideways);
    set_sprite_tile(0, 2);
    set_sprite_tile(1, 0);
    set_sprite_prop(0, S_FLIPX);
    set_sprite_prop(1, S_FLIPX);
    move_sprite(0, hero_posx, hero_posy); 
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    SHOW_SPRITES;
    DISPLAY_ON;
}

void deck_enter_intro_scene(void)
{
    /* make sure the hero is facing left */
    set_sprite_data(0, 8, hero_walk_sideways);
    set_sprite_tile(0,2);
    set_sprite_tile(1,0);
    set_sprite_prop(0, S_FLIPX);
    set_sprite_prop(1, S_FLIPX);
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);

    fisherman_posx = 8;
    fisherman_posy = 128;
    set_sprite_data(8, 8, fisherman_walk_side);

    /* init fisherman */
    for(i = 2; i < 7; i+=2)
    {
        set_sprite_tile(i, 10);
        set_sprite_tile(i+1, 8);
        set_sprite_prop(i, S_FLIPX);
        set_sprite_prop(i+1, S_FLIPX);
        move_sprite(i, fisherman_posx, fisherman_posy);
        move_sprite(i+1, fisherman_posx+sprite_width, fisherman_posy);
        fisherman_posx += 20;
    }
    /* have to reset the fisherman's position */
    fisherman_posx -= 60;
    delay(500);
    /* fisherman walk in */
    while(fisherman_posx+40 <= 120)
    {
        delay(50);
        for(i = 2; i < 7; i+=2)
        {
            set_sprite_tile(i, 10+(4*(fisherman_posx&0x1)));
            set_sprite_tile(i+1, 8+(4*(fisherman_posx&0x1)));
        }
        ++fisherman_posx;
        move_sprite(2, fisherman_posx, fisherman_posy);
        move_sprite(3, fisherman_posx+sprite_width, fisherman_posy);
        move_sprite(4, fisherman_posx+20, fisherman_posy);
        move_sprite(5, fisherman_posx+20+sprite_width, fisherman_posy);
        move_sprite(6, fisherman_posx+40, fisherman_posy);
        move_sprite(7, fisherman_posx+40+sprite_width, fisherman_posy);
    }
    DISPLAY_OFF;
    bkg_clean();
    move_bkg(0, 0);
    DISPLAY_ON;
    sprite_clean();
    LETTER_COUNT = 0;
    print("fishermen:\0", 24, 32);
    print("follow us!\0", 24, 48);
    talking = 1;
    while(talking)
    {
        if(joypad() & J_A)
            talking = 0;
    }
    DISPLAY_OFF;
    hide_sprites();
    sprite_clean();
    LETTER_COUNT = 0;
    set_bkg_data(0, 4, blank_screen_tiles);        
    set_bkg_tiles(0, 0, 32, 18, deck);
    move_bkg(95, 0);
    DISPLAY_ON;

    SPRITES_8x16;
    set_sprite_data(0, 8, hero_walk_sideways);
    set_sprite_tile(0,2);
    set_sprite_tile(1,0);
    set_sprite_prop(0, S_FLIPX);
    set_sprite_prop(1, S_FLIPX);
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    set_sprite_data(8, 8, fisherman_walk_side);
    /* init fisherman */
    for(i = 2; i < 7; i+=2)
    {
        set_sprite_tile(i, 8);
        set_sprite_tile(i+1, 10);
        move_sprite(i, fisherman_posx, fisherman_posy);
        move_sprite(i+1, fisherman_posx+sprite_width, fisherman_posy);
        fisherman_posx-=20;
    }
    fisherman_posx += 60;
    delay(500);
    while(fisherman_posx+60 >= 16)
    {
        delay(50);
        for(i = 2; i < 7; i+=2)
        {
            set_sprite_tile(i, 8+(4*(fisherman_posx&0x1)));
            set_sprite_tile(i+1, 10+(4*(fisherman_posx&0x1)));
        }
        --fisherman_posx;
        move_sprite(2, fisherman_posx, fisherman_posy);
        move_sprite(3, fisherman_posx+sprite_width, fisherman_posy);
        move_sprite(4, fisherman_posx-20, fisherman_posy);
        move_sprite(5, fisherman_posx-20+sprite_width, fisherman_posy);
        move_sprite(6, fisherman_posx-40, fisherman_posy);
        move_sprite(7, fisherman_posx-40+sprite_width, fisherman_posy);
    }
}

void asakawa_enters_deck(void)
{
    sprite_clean();
    LETTER_COUNT = 0;
    set_sprite_data(0, 8, hero_walk_sideways);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    set_sprite_prop(0, S_FLIPX&0x0);
    set_sprite_prop(1, S_FLIPX&0x0);
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);

    fisherman_posx = 48;
    fisherman_posy = 128;
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

void pos_check_shit_pot(void)
{

    if(hero_posy <= 56)
    {
        hero_posy = 56;
        if(hero_posx >= 48 && hero_posx <= 108)
            moving = 0;
    }
    if(hero_posx <= 8)
        hero_posx = 8;
    if(hero_posy >= 144)
        hero_posy = 144;
    if(hero_posx >= 152)
        hero_posx = 152;
}

void pos_check_deck(void)
{
    if(hero_posy <= 116)
        hero_posy = 116;
    if(hero_posy >= 144)
        hero_posy = 144;
}
