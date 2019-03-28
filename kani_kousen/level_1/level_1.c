#include "level_1.h"
#include "../assets/level_assets/level_assets.h"
#include "asakawa_battle.h"
#include "../text/text.h"
#include "../assets/sprite_palette.h"

/* scene 1 variables */
UINT8 text_count = 0;
/* scene 2 variables */
UINT8 start_animate = 0;
UINT8 l1_scene_2 = 0;
/* scene 3 variables */
UINT8 l1_scene_3_anim = 0;
UINT8 l1_scene_3_stop = 0;

UINT8 hero_pos[2][2];
UINT8 fisherman_pos[2][2];
UINT8 miner_pos[2][2];
UINT8 student_pos[2][2];
UINT8 asakawa_pos[2][2];

UINT8 sprite_width = 8;

UINT8 anim_1 = 32;
UINT8 anim_2 = 34;

/* The big control function */
void level_1_ctrl(void) 
{
    wait_vbl_done();
/*    level_1_bkg_start();
    while(start_animate == 0)
    {
        joypad_check_l1_scene_1();
        wait_vbl_done();
    }
    i = 0; // helping with animation
    while(enter_miner() == 0)
    {
        animate();
        enter_miner();
        wait_vbl_done();
    }
    sprite_clean();
    LETTER_COUNT = 0;
    miner_intro_setup();
    while(l1_scene_2 == 0)
    {
        joypad_check_l1_scene_2();
        wait_vbl_done();
    }
    l1_scene_3_setup();
    while(l1_scene_3_anim < 3)
    {
        l1_scene_3_animate();
        wait_vbl_done();
    }
    l1_scene_3_text_setup();
    while(l1_scene_3_stop == 0)
    {
        joypad_check_l1_scene_3();
        wait_vbl_done();
    }*/
    asakawa_battle_ctrl();
}

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
    sprite_clean();
    LETTER_COUNT = 0;
    /* opening screen */
    print("chapter 1\0", 48, 64);
    print("welcome to\0", 44, 80);
    print("hell\0", 68, 96);
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;

    DISPLAY_OFF;
    HIDE_WIN;
    HIDE_BKG;
    HIDE_SPRITES;

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    /* setting up first set of text */
    bkg_clean();
    print("fisherman:\0", 24, 32);
    print("we're all\0", 24, 48);
    print("goin' to\0", 24, 64);
    print("hell!\0", 24, 80);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("fisherman:\0", 24, 32);
    print("you hear!?\0", 24, 48);
}

void joypad_check_l1_scene_1(void) 
{
    if(joypad() & J_A)
        l1_scene_1();
}

void l1_scene_1(void) 
{
    delay(100);
    ++text_count;
    delay(100);
    if(text_count == 1)
    {
        sprite_clean();
        LETTER_COUNT = 0;
        bkg_clean();
        print("fisherman:\0", 24, 32);
        print("4 months\0", 24, 48);
        print("on\0", 24, 64);
        delay(1000);
        sprite_clean();
        LETTER_COUNT = 0;
        print("fisherman:\0", 24, 32);
        print("kamchatkas\0", 24, 48);
        print("northern\0", 24, 64);
        print("waters.\0", 24, 80);
    }
    if(text_count == 2)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("fisherman:\0", 24, 32);
        print("it would\0", 24, 48);
        print("be a cold\0", 24, 64);
        print("death\0", 24, 80);
        print("indeed...\0", 24, 96);
    }
    if(text_count == 3)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("fisherman:\0", 24, 32);
        print("i see we\0", 24, 48);
        print("have a\0", 24, 64);
        print("quiet\0", 24, 80);
        print("one.\0", 24, 96);
    }
    if(text_count == 4)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("fisherman:\0", 24, 32);
        print("c'mon\0", 24, 48);
        print("i'll take\0", 24, 64);
        print("you down\0", 24, 80);
        delay(1000);
        sprite_clean();
        LETTER_COUNT = 0;
        print("fisherman:\0", 24, 32);
        print("to the\0", 24, 48);
        print("shit pot.\0", 24, 64);
    }
    if(text_count == 5)
    {
        DISPLAY_OFF;

        /* center on the door */
        set_bkg_data(0,4,blank_screen_tiles);
        set_bkg_tiles(0,0,20,18,shit_pot);
        DISPLAY_ON;
        HIDE_SPRITES;/* this turns sprites off */
        sprite_clean();
        hide_sprites();
        LETTER_COUNT = 0;
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

    /* make correct color for characters */
    /*for(i = 0; i < 4; ++i)
        set_sprite_prop(i,2); */

    delay(400); /* a pause before appearing at door */
    SHOW_SPRITES;
    start_animate = 1;
}

/* a helper function to animate the sprites when they appear */
void animate(void) 
{
    set_sprite_tile(0, 4);
    set_sprite_tile(1, 6);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);

    set_sprite_tile(2, 12);
    set_sprite_tile(3, 14);
    move_sprite(2, fisherman_pos[0][0], fisherman_pos[0][1]); 
    move_sprite(3, fisherman_pos[1][0], fisherman_pos[1][1]);
    delay(100);

    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);

    set_sprite_tile(2, 8);
    set_sprite_tile(3, 10);
    move_sprite(2, fisherman_pos[0][0], fisherman_pos[0][1]);
    move_sprite(3, fisherman_pos[1][0], fisherman_pos[1][1]);
    delay(100);
}


/**
 * SCENE 2
 */
void joypad_check_l1_scene_2(void)
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

        set_sprite_tile(4, 16+((i&0x1)*4));
        set_sprite_tile(5, 18+((i&0x1)*4));
        
        /* make sure miner is correct colors */
        //set_sprite_prop(4,2);
        //set_sprite_prop(5,2);

        move_sprite(4, miner_pos[0][0], miner_pos[0][1]);
        move_sprite(5, miner_pos[1][0], miner_pos[1][1]);
        delay(80);
    }

    /* start by walking left */
    miner_pos[0][0] -= step_x;
    miner_pos[0][1] -= step_y;
    miner_pos[1][0] -= step_x;
    miner_pos[1][1] -= step_y;

    set_sprite_tile(4, 16+((i&0x1)*4));
    set_sprite_tile(5, 18+((i&0x1)*4));
    move_sprite(4, miner_pos[0][0], miner_pos[0][1]);
    move_sprite(5, miner_pos[1][0], miner_pos[1][1]);
    delay(80);

    ++i;

    return 0;
}

/* setting up the miners dialogue / introduction */
void miner_intro_setup(void)
{
    DISPLAY_OFF;
    HIDE_SPRITES;
    HIDE_WIN;
    HIDE_BKG;

    bkg_clean();

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    text_count = 0;

    sprite_clean();
    LETTER_COUNT = 0;
    print("miner:\0", 24, 32);
    print("i come\0", 24, 48);
    print("from the\0", 24, 64);
    print("yubari\0", 24, 80);
    print("coal\0", 24, 96);
    print("mines.\0", 24, 112);
}

/* setting up the miners dialogue / introduction */
int miner_intro(void)
{
    delay(100);
    ++text_count;
    delay(100);

    if(text_count == 1)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("miner:\0", 24, 32);
        print("worked\0", 24, 48);
        print("there for\0", 24, 64);
        print("seven\0", 24, 80);
        print("years.\0", 24, 96);

        DISPLAY_ON;
    }
    if(text_count == 2)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("fisherman:\0", 24, 32);
        print("a miner,\0", 24, 48);
        print("huh?\0", 24, 64);
    }
    if(text_count == 3)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("fisherman:\0", 24, 32);
        print("must've\0", 24, 48);
        print("been no\0", 24, 64);
        print("money in\0", 24, 80);
        print("mining?\0", 24, 96);
    }
    if(text_count == 4)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("miner:\0", 24, 32);
        print("...there\0", 24, 48);
        print("was an\0", 24, 64);
        print("explosion\0", 24, 80);
        delay(1000);
        sprite_clean();
        LETTER_COUNT = 0;
        print("miner:\0", 24, 32);
        print("...\0", 24, 48);
        print("from the\0", 24, 64);
        print("gas...\0", 24, 80);
    }
    if(text_count == 5)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("miner:\0", 24, 32);
        print("good lives\0", 24, 48);
        print("were lost\0", 24, 64);
        delay(1000);
        sprite_clean();
        LETTER_COUNT = 0;
        print("miner:\0", 24, 32);
        print("that can't\0", 24, 48);
        print("be\0", 24, 64);
        print("returned\0", 24, 80);
        print("...\0", 24, 96);
    }
    if(text_count == 6)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("fisherman:\0", 24, 32);
        print("we better\0", 24, 48);
        print("go!\0", 24, 64);
        delay(1000);
        sprite_clean();
        LETTER_COUNT = 0;
        print("fisherman:\0", 24, 32);
        print("i think\0", 24, 48);
        print("i hear\0", 24, 64);
        print("asakawa\0", 24, 80);
        print("coming!\0", 24, 96);
    }
    if(text_count == 7)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("miner:\0", 24, 32);
        print("who's that\0", 24, 48);
        print("???\0", 24, 64);
    }
    if(text_count == 8)
    {
        print("fisherman:\0", 24, 80);
        print("the\0", 24, 96);
        print("manager!\0", 24, 112);
    } 
    if(text_count == 9)
        l1_scene_2 = 1;
}

/**
 * SCENE 3
 */
/**
 * first make a line of workers 
 * with backs to the door 
 */
void l1_scene_3_setup(void)
{
    HIDE_WIN;
    HIDE_BKG;
    HIDE_SPRITES;
    DISPLAY_OFF;

    /* set bkg up */
    set_bkg_data(0,4,blank_screen_tiles);
    set_bkg_tiles(0,0,20,18,shit_pot);

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

    /* asakawa front in doorway */
    /* left half */
    asakawa_pos[0][0] = 75;
    asakawa_pos[0][1] = 65;
    asakawa_pos[1][0] = asakawa_pos[0][0]+sprite_width;
    asakawa_pos[1][1] = asakawa_pos[0][1];

    SPRITES_8x16;
    /* hero */
    set_sprite_data(0, 8, hero_back_idle); 
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
    /* asakawa */
    set_sprite_data(32, 8, asakawa_front_idle);
    set_sprite_tile(8, 32);
    set_sprite_tile(9, 34);

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

    /* after a little wait, asakawa appears in door way */
    delay(400);
    move_sprite(8, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(9, asakawa_pos[1][0], asakawa_pos[1][1]);
}

/* brief animation for scene 3 */
void l1_scene_3_animate(void)
{
    ++l1_scene_3_anim;

    /* hero */
    set_sprite_tile(0, 4-((l1_scene_3_anim&0x1)*4));
    set_sprite_tile(1, 6-((l1_scene_3_anim&0x1)*4));
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    /* fisherman */
    set_sprite_tile(2, 12-((l1_scene_3_anim&0x1)*4));
    set_sprite_tile(3, 14-((l1_scene_3_anim&0x1)*4));
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    /* miner */ 
    set_sprite_tile(4, 20-((l1_scene_3_anim&0x1)*4));
    set_sprite_tile(5, 22-((l1_scene_3_anim&0x1)*4));
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    /* student */ 
    set_sprite_tile(6, 28-((l1_scene_3_anim&0x1)*4));
    set_sprite_tile(7, 30-((l1_scene_3_anim&0x1)*4));
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    /* asakawa */ 
    set_sprite_tile(8, 36-((l1_scene_3_anim&0x1)*4));
    set_sprite_tile(9, 38-((l1_scene_3_anim&0x1)*4));
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(400);
}
/* scene_3 dialogue setup first */
void l1_scene_3_text_setup(void)
{
    DISPLAY_OFF;
    hide_sprites();
    bkg_clean();
    text_count = 0; // just making sure that this is zero
    DISPLAY_ON;
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("listen up\0", 24, 48);
    print("you\0", 24, 64);
    print("maggots!\0", 24, 80);

}

/* asakawa give his message */
void joypad_check_l1_scene_3(void) 
{
    if(joypad() & J_A)
    {
        l1_scene_3();
    }
}

/* asakawa's message */
void l1_scene_3(void)
{
    delay(100);
    ++text_count;
    delay(100);

    if(text_count == 1)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("needless\0", 24, 48);
        print("to say,\0", 24, 64);
    }
    if(text_count == 2)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("this ship\0", 24, 48);
        print("is no\0", 24, 64);
        delay(1000);
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("simple\0", 24, 48);
        print("source of\0", 24, 64);
        print("income!\0", 24, 80);
    }
    if(text_count == 3)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("but rather\0", 24, 48);
        print("of the\0", 24, 64);
        print("utmost\0", 24, 80);
        print("concern\0", 24, 96);
    }
    if(text_count == 4)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("for our\0", 24, 48);
        print("nation!\0", 24, 64);
    }
    if(text_count == 5)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("as\0", 24, 48);
        print("peoples\0", 24, 64);
        print("of\0", 24, 80);
        print("imperial\0", 24, 96);
        print("japan,\0", 24, 112);
    }
    if(text_count == 6)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("we are\0", 24, 48);
        print("proud\0", 24, 64);
        print("rivals\0", 24, 80);
        print("of russia!\0", 24, 96);
    }
    if(text_count == 7)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("that is\0", 24, 48);
        print("why you\0", 24, 64);
        print("fisherman\0", 24, 80);
        print("are not\0", 24, 96);
    }
    if(text_count == 8)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("only\0", 24, 48);
        print("canning\0", 24, 64);
        print("crabs,\0", 24, 80);
    }
    if(text_count == 9)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("but\0", 24, 48);
        print("salmon and\0", 24, 64);
        print("tuna\0", 24, 80);
        print("as well!\0", 24, 96);
    }
    if(text_count == 10)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("as a\0", 24, 48);
        print("nation of\0", 24, 64);
        print("excellence\0", 24, 80);
        print("...", 24, 96);
    }
    if(text_count == 11)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("we are\0", 24, 48);
        print("unmatched\0", 24, 64);
        delay(1000);
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("when\0", 24, 48);
        print("compared\0", 24, 64);
        print("to others!\0", 24, 80);
    }
    if(text_count == 12)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("from the\0", 24, 32);
        print("crowd\0", 24, 48);
        print("someone\0", 24, 64);
        print("murmurs,\0", 24, 80);
    }
    if(text_count == 13)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("that's\0", 24, 32);
        print("a little\0", 24, 48);
        print("exagerated\0", 24, 64);
        print("don't you\0", 24, 80);
        print("think?\0", 24, 96);
    }
    if(text_count == 14)
    {
        l1_scene_3_setup();
        asakawa_shoots_anim();

        DISPLAY_OFF;
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        DISPLAY_ON;

        print("asakawa:\0", 24, 32);
        print("this kind\0", 24, 48);
        print("of talk is\0", 24, 64);
        print("not\0", 24, 80);
        print("tolerable!\0", 24, 96);
    }
    if(text_count == 15)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("this\0", 24, 48);
        print("attitude\0", 24, 64);
        print("is not\0", 24, 80);
        print("only\0", 24, 96);
        print("mutinous,\0", 24, 112);
    }
    if(text_count == 16)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("but will\0", 24, 48);
        print("be\0", 24, 64);
        print("considered\0", 24, 80);
        delay(1000);
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("treason as\0", 24, 48);
        print("well!\0", 24, 64);
    }
    if(text_count == 17)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("this job\0", 24, 48);
        print("is within\0", 24, 64);
        print("the realm\0", 24, 80);
    }
    if(text_count == 18)
    {
        bkg_clean();
        sprite_clean();
        LETTER_COUNT = 0;
        print("asakawa:\0", 24, 32);
        print("of\0", 24, 48);
        print("'national\0", 24, 64);
        print("policy!'\0", 24, 80);
        delay(1000);
        /* Battle prompt */
        DISPLAY_OFF;
        set_bkg_data(0,4, blank_screen_tiles);
        set_bkg_tiles(0,0,20,18,blank_screen);
        sprite_clean();
        LETTER_COUNT = 0;
        print("fight\0", 64, 32);
        print("asakawa\0", 56, 48);

        DISPLAY_ON;
        delay(100);
        DISPLAY_OFF;
        delay(100);
        DISPLAY_ON;
        delay(100);
        DISPLAY_OFF;
        delay(100);
        DISPLAY_ON;
        delay(300);
        sprite_clean();
        LETTER_COUNT = 0;
        l1_scene_3_stop = 1;
    }
}

void asakawa_shoots_anim(void)
{
    set_sprite_data(32, 32, asakawa_air_shot);
    /* asakawa shooting setup */
    for(i = 0; i < 7; ++i)
    {
        set_sprite_tile(8, anim_1+=4);
        set_sprite_tile(9, anim_2+=4);
        delay(500);
    }
    delay(800);
}
