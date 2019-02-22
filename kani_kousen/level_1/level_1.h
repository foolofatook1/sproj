/* text things */
#include "../text/text.c"

/* level 1 opening screen */
#include "assets/level_1_screen_tiles.c"
#include "assets/level_1_screen.c"

/* shit pot assets */
#include "assets/shit_pot_tiles.c" 
#include "assets/shit_pot.c"

/* starting sprites */
/* hero */
#include "../assets/sprites/hero_front_idle.c"
#include "../assets/sprites/hero_idle_back.c"
/* fisherman */
#include "../assets/sprites/fisherman_front_idle.c"
#include "../assets/sprites/fisherman_idle_back.c"
/* miner */
#include "../assets/sprites/miner_walk_left.c"
#include "../assets/sprites/miner_walk_up.c"
#include "../assets/sprites/miner_idle_back.c"
/* student */
#include "../assets/sprites/student_idle_back.c"


void level_1_ctrl(void);
void level_1_bkg_start(void);
int level_1_sprite_setup(void);
void joypad_check_scene_1(void);
void joypad_check_scene_2(void);
void scene_1(void);
void animate(void);
int enter_miner(void);
void miner_intro_setup(void);
int miner_intro(void);
void scene_3_setup(void);
void scene_3_animate(void);

/* scene 1 variables */
UINT8 text_count = 0;
/* scene 2 variables */
UINT8 start_animate = 0;
UINT8 scene_2 = 0;
/* scene 3 variables */
UINT8 scene_3_anim = 0;

UINT8 hero_pos[2][2];
UINT8 fisherman_pos[2][2];
UINT8 miner_pos[2][2];
UINT8 student_pos[2][2];

UINT8 sprite_width = 8;

/**
 * SCENE 1
 */

/* setup the background for the opening screen. */
void level_1_bkg_start(void) 
{
    DISPLAY_OFF;
    HIDE_WIN;
    HIDE_BKG;

    HIDE_SPRITES;

    /* setup bkg */
    set_bkg_data(0, 40, level_1_screen_tiles);
    set_bkg_tiles(0,0,20,18,level_1_screen);

    scroll_bkg(-96,0);

    SHOW_BKG;
    DISPLAY_ON;

    delay(1000);

    DISPLAY_OFF;
    HIDE_WIN;
    SHOW_SPRITES;
    SHOW_BKG;

    /* setting up first set of text */
    print("we're all\0", 24, 32);
    print("goin' to\0", 24, 48);
    print("hell!\0", 24, 64);
    print("you hear!?\0", 24, 80);
    LETTER_COUNT = 0;
    DISPLAY_ON;
}

void joypad_check_scene_1(void) 
{
    if(joypad() & J_A)
    {
        scene_1();
    }
}

void scene_1(void) 
{
    delay(100);
    ++text_count;
    delay(100);
    if(text_count == 1)
    {
        DISPLAY_OFF;

        bkg_clean();
        sprite_clean();

        print("4 months\0", 24, 32);
        print("on\0", 24, 48);
        print("kamchatkas\0", 24, 64);
        print("northern\0", 24, 80);
        print("waters.\0", 24, 96);
        LETTER_COUNT = 0;        
        DISPLAY_ON;
    }
    if(text_count == 2)

    {
        DISPLAY_OFF;

        bkg_clean();
        sprite_clean();

        print("it would be", 24, 32);
        print("a cold", 24, 48);
        print("death", 24, 64);
        print("indeed...", 24, 80);
        LETTER_COUNT = 0;

        DISPLAY_ON;
    }
    if(text_count == 3)
    {
        DISPLAY_OFF;

        bkg_clean();
        sprite_clean();

        print("i see we", 24, 32);
        print("have a", 24, 48);
        print("quiet", 24, 64);
        print("one.", 24, 80);
        LETTER_COUNT = 0; 

        DISPLAY_ON;
    }
    if(text_count == 4)
    {
        DISPLAY_OFF;

        bkg_clean();
        sprite_clean();

        print("c'mon i'll", 24, 32);
        print("take you", 24, 48);
        print("down to", 24, 64);
        print("the", 24, 80);
        print("shit pot.", 24, 96);
        LETTER_COUNT = 0; 

        DISPLAY_ON;
    }
    if(text_count == 5)
    {
        DISPLAY_OFF;
        scroll_bkg(40,0);

        /* center on the door */
        set_bkg_data(0,16,shit_pot_tiles);
        set_bkg_tiles(0,0,32,32,shit_pot);
        DISPLAY_ON;
        HIDE_SPRITES;/* this turns sprites off */
        hide_sprites();/* this moves them to lower corner of screen */
        level_1_sprite_setup();
    }
}

int level_1_sprite_setup(void) 
{
    /* hero on screen at door */
    /* left half */
    hero_pos[0][0] = 70; 
    hero_pos[0][1] = 65;
    /* right half */
    hero_pos[1][0] = hero_pos[0][0]+sprite_width; 
    hero_pos[1][1] = hero_pos[0][1];

    /* fisherman on screen at door */
    /* left half */
    fisherman_pos[0][0] = 86;
    fisherman_pos[0][1] = 65;
    /* right half */
    fisherman_pos[1][0] = fisherman_pos[0][0]+sprite_width;
    fisherman_pos[1][1] = fisherman_pos[0][1];

    /* miner positioning for the coming scene */
    /* left half */
    miner_pos[0][0] = 150;
    miner_pos[0][1] = 100;
    /* right half */
    miner_pos[1][0] = miner_pos[0][0]+sprite_width;
    miner_pos[1][1] = miner_pos[0][1];

    SPRITES_8x16;
    /* hero */
    set_sprite_data(0, 8, hero_front_idle);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    /* fisherman */
    set_sprite_data(8, 8, fisherman_front_idle);
    set_sprite_tile(2, 8);
    set_sprite_tile(3, 10);

    /* miner */
    set_sprite_data(16, 8, miner_walk_left);

    /* display the hero */
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    /* display the fisherman */
    move_sprite(2, fisherman_pos[0][0], fisherman_pos[0][1]);
    move_sprite(3, fisherman_pos[1][0], fisherman_pos[1][1]);

    delay(400); /* a pause before appearing at door */
    SHOW_SPRITES;
    start_animate = 1;
}

/* a helper function to animate the sprites when they appear */
void animate(void) 
{
    set_sprite_tile(0, 4);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    set_sprite_tile(1, 6);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);

    set_sprite_tile(2, 12);
    move_sprite(2, fisherman_pos[0][0], fisherman_pos[0][1]); 
    set_sprite_tile(3, 14);
    move_sprite(3, fisherman_pos[1][0], fisherman_pos[1][1]);
    delay(100);

    set_sprite_tile(0, 0);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    set_sprite_tile(1, 2);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);

    set_sprite_tile(2, 8);
    move_sprite(2, fisherman_pos[0][0], fisherman_pos[0][1]);
    set_sprite_tile(3, 10);
    move_sprite(3, fisherman_pos[1][0], fisherman_pos[1][1]);
    delay(100);
}


/**
 * SCENE 2
 */
void joypad_check_scene_2(void)
{
    if(joypad() & J_A)
    {
        miner_intro();
    }
}

int enter_miner(void) 
{
    UINT8 step_x = 4;
    UINT8 step_y = 0;

    if(miner_pos[0][0] <= 80) /* if we are far enough to the left */
    {
        step_y = 4;
        step_x = 0;
        set_sprite_data(16, 8, miner_walk_up); 
        if(miner_pos[0][1] <= 90) /* stop walking */
        {
            step_y = 0;
            set_sprite_data(16, 8, miner_idle_back);
            delay(100);

            return 1; /* we're done */
        }

        miner_pos[0][0] -= step_x;
        miner_pos[0][1] -= step_y;
        miner_pos[1][0] -= step_x;
        miner_pos[1][1] -= step_y;

        set_sprite_tile(4, 16);
        move_sprite(4, miner_pos[0][0], miner_pos[0][1]);
        set_sprite_tile(5, 18);
        move_sprite(5, miner_pos[1][0], miner_pos[1][1]);
        delay(140);

        miner_pos[0][0] -= step_x;
        miner_pos[0][1] -= step_y;
        miner_pos[1][0] -= step_x;
        miner_pos[1][1] -= step_y;

        set_sprite_tile(4, 20);
        move_sprite(4, miner_pos[0][0], miner_pos[0][1]);
        set_sprite_tile(5, 22);
        move_sprite(5, miner_pos[1][0], miner_pos[1][1]);
    }

    /* start by walking left */
    miner_pos[0][0] -= step_x;
    miner_pos[0][1] -= step_y;
    miner_pos[1][0] -= step_x;
    miner_pos[1][1] -= step_y;

    set_sprite_tile(4, 16);
    move_sprite(4, miner_pos[0][0], miner_pos[0][1]);
    set_sprite_tile(5, 18);
    move_sprite(5, miner_pos[1][0], miner_pos[1][1]);
    delay(140);

    miner_pos[0][0] -= step_x;
    miner_pos[0][1] -= step_y;
    miner_pos[1][0] -= step_x;
    miner_pos[1][1] -= step_y;

    set_sprite_tile(4, 20);
    move_sprite(4, miner_pos[0][0], miner_pos[0][1]);
    set_sprite_tile(5, 22);
    move_sprite(5, miner_pos[1][0], miner_pos[1][1]);

    return 0;
}

/* setting up the miners dialogue / introduction */
void miner_intro_setup(void)
{
    DISPLAY_OFF;
    HIDE_SPRITES;
    HIDE_WIN;
    HIDE_BKG;

    scroll_bkg(-40,0);

    bkg_clean();
    sprite_clean();

    print("i come\0", 24, 32);
    print("from the\0", 24, 48);
    print("yubari\0", 24, 64);
    print("coal\0", 24, 80);
    print("mines.\0", 24, 96);
    LETTER_COUNT = 0;

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
    text_count = 0;
}

/* setting up the miners dialogue / introduction */
int miner_intro(void)
{
    delay(100);
    ++text_count;
    delay(100);

    if(text_count == 1)
    {
        DISPLAY_OFF;

        bkg_clean();
        sprite_clean();

        print("worked\0", 24, 32);
        print("there for\0", 24, 48);
        print("seven\0", 24, 64);
        print("years.\0", 24, 80);
        LETTER_COUNT = 0;

        DISPLAY_ON;
    }
    if(text_count == 2)
    {
        DISPLAY_OFF;

        bkg_clean();
        sprite_clean();

        print("a miner,\0", 24, 32);
        print("huh?\0", 24, 48);
        LETTER_COUNT = 0;

        DISPLAY_ON;

    }
    if(text_count == 3)
    {
        DISPLAY_OFF;

        bkg_clean();
        sprite_clean();

        print("must've\0", 24, 32);
        print("been no\0", 24, 48);
        print("money in\0", 24, 64);
        print("mining?\0", 24, 80);
        LETTER_COUNT = 0;

        DISPLAY_ON;
    }
    if(text_count == 4)
    {
        DISPLAY_OFF;

        bkg_clean();
        sprite_clean();

        print("...there\0", 24, 32);
        print("was an\0", 24, 48);
        print("explosion\0", 24, 64);
        print("...\0", 24, 80);
        print("from the\0", 24, 96);
        print("gas...\0", 24, 112);
        LETTER_COUNT = 0;

        DISPLAY_ON;
    }
    if(text_count == 5)
    {
        DISPLAY_OFF;

        bkg_clean();
        sprite_clean();

        print("good lives\0", 24, 32);
        print("were lost\0", 24, 48);
        print("that can't\0", 24, 64);
        print("be\0", 24, 80);
        print("returned\0", 24, 96);
        print("...\0", 24, 112);
        LETTER_COUNT = 0;

        DISPLAY_ON;
    }
    if(text_count == 6)
    {
        DISPLAY_OFF;

        bkg_clean();
        sprite_clean();

        print("we better\0", 24, 32);
        print("go!\0", 24, 48);
        print("i think\0", 24, 64);
        print("i hear\0", 24, 80);
        print("asakawa\0", 24, 96);
        print("coming!\0", 24, 112);
        LETTER_COUNT = 0;

        DISPLAY_ON;
    }
    if(text_count == 7)
    {
        DISPLAY_OFF;

        bkg_clean();
        sprite_clean();

        print("who's that\0", 24, 32);
        print("???\0", 24, 48);

        DISPLAY_ON;
    }
    if(text_count == 8)
    {
        print("the\0", 24, 64);
        print("manager!\0", 24, 80);
        LETTER_COUNT = 0;
    } 
    if(text_count == 9)
        scene_2 = 1;
}

/**
 * SCENE 3
 */
/**
 * first make a line of workers 
 * with backs to the door 
 */
void scene_3_setup(void)
{
    HIDE_WIN;
    HIDE_BKG;
    HIDE_SPRITES;
    DISPLAY_OFF;

    /* scroll the screen back after dialogue */
    scroll_bkg(40, 0);

    /* set bkg up */
    set_bkg_data(0,16,shit_pot_tiles);
    set_bkg_tiles(0,0,32,32,shit_pot);

    /* hide unused sprites first */
    hide_sprites();

    /* hero back faced to the screen */
    /* left half */
    hero_pos[0][0] = 100; 
    hero_pos[0][1] = 100;
    /* right half */
    hero_pos[1][0] = hero_pos[0][0]+sprite_width; 
    hero_pos[1][1] = hero_pos[0][1];

    /* fisherman back faced to the screen */
    /* left half */
    fisherman_pos[0][0] = 120;
    fisherman_pos[0][1] = 100;
    /* right half */
    fisherman_pos[1][0] = fisherman_pos[0][0]+sprite_width;
    fisherman_pos[1][1] = fisherman_pos[0][1];

    /* miner back faced to the screen */
    /* left half */
    miner_pos[0][0] = 80;
    miner_pos[0][1] = 100;
    /* right half */
    miner_pos[1][0] = miner_pos[0][0]+sprite_width;
    miner_pos[1][1] = miner_pos[0][1];

    /* student back faced to the screen */
    /* left half */
    student_pos[0][0] = 60;
    student_pos[0][1] = 100;
    /* right half */
    student_pos[1][0] = student_pos[0][0]+sprite_width;
    student_pos[1][1] = student_pos[0][1];

    SPRITES_8x16;
    /* hero */
    set_sprite_data(0, 8, hero_idle_back); 
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    /* fisherman */
    set_sprite_data(8, 8, fisherman_idle_back); 
    set_sprite_tile(2, 8);
    set_sprite_tile(3, 10);
    /* miner */
    set_sprite_data(16, 8, miner_idle_back); 
    set_sprite_tile(4, 16);
    set_sprite_tile(5, 18);
    /* student */
    set_sprite_data(24, 8, student_idle_back);
    set_sprite_tile(6, 24);
    set_sprite_tile(7, 26);

    /* display the hero */
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    /* display the fisherman */
    move_sprite(2, fisherman_pos[0][0], fisherman_pos[0][1]);
    move_sprite(3, fisherman_pos[1][0], fisherman_pos[1][1]);
    /* display the miner */
    move_sprite(4, miner_pos[0][0], miner_pos[0][1]);
    move_sprite(5, miner_pos[1][0], miner_pos[1][1]);
    /* display the student */
    move_sprite(6, student_pos[0][0], student_pos[0][1]);
    move_sprite(7, student_pos[1][0], student_pos[1][1]);


    delay(400); /* a pause before appearing at door */
    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;
}
/* asakawa appears in door way */
/* asakawa give his message */
