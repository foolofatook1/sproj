#include "level_2.h"
#include "../assets/level_assets/level_assets.h"
#include "../text/text.h"
#include "../battle/battle.h"

UINT8 talking = 1;
UINT8 moving = 1;
UINT8 left = -1;

void level_2_ctrl(void)
{
    wait_vbl_done();
    /*    level_2_bkg_start();*/
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
    }
    deck_walk();
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
    delay(800);
    print("wake up!\0", 56, 75);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    delay(500);
    print("wake up!\0", 56, 75);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    delay(500);
    print("wake up!\0", 56, 75);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("we have to\0", 48, 75);
    print("get\0", 72, 91);
    print("to work!\0", 56, 107);
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
        if(left)
        {
            set_sprite_prop(0, S_FLIPX&0x0);
            set_sprite_prop(1, S_FLIPX&0x0);
            move_sprite(0, hero_posx, hero_posy);
            move_sprite(1, hero_posx+sprite_width, hero_posy);
        }
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
        left = -1;
        delay(50);
        --hero_posy;
        if(hero_posy <= 56)
        {
            hero_posy = 56;
            if(hero_posx >= 48 && hero_posx <= 108)
                moving = 0;
        }
    }
    if(joypad() & J_DOWN)
    {
        set_sprite_data(0, 4, hero_walk_down);
        set_sprite_tile(0, 0);
        set_sprite_tile(1, 2);
        if(left)
        {
            set_sprite_prop(0, S_FLIPX&0x0);
            set_sprite_prop(1, S_FLIPX&0x0);
            move_sprite(0, hero_posx, hero_posy);
            move_sprite(1, hero_posx+sprite_width, hero_posy);
            left = -1;
        }
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
        left = -1;
        delay(50);
        ++hero_posy;
        if(hero_posy >= 144)
            hero_posy = 144;
    }
    if(joypad() & J_LEFT)
    {
        set_sprite_data(0, 8, hero_walk_sideways);
        if(left == -1)
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
        if(hero_posx <= 8)
            hero_posx = 8;
    }
    if(joypad() & J_RIGHT)
    {
        set_sprite_data(0, 8, hero_walk_sideways);
        if(left)
        {
            set_sprite_prop(0, S_FLIPX&0x0);
            set_sprite_prop(1, S_FLIPX&0x0);
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
        move_sprite(0, hero_posx, hero_posy);
        move_sprite(1, hero_posx+sprite_width, hero_posy);
        left = -1;
        delay(50);
        ++hero_posx;
        if(hero_posx >= 152)
            hero_posx = 152;
    }
}

void deck_walk(void)
{
    DISPLAY_OFF;
    set_bkg_data(0, 4, blank_screen_tiles);        
    set_bkg_tiles(0, 0, 32, 18, deck);
    scroll_bkg(96, 0);
    HIDE_SPRITES;
    hero_posx = 148;
    hero_posy = 120;
    move_sprite(0, hero_posx, hero_posy); 
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    SHOW_SPRITES;
    DISPLAY_ON;
}
