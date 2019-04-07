#include "level_1.h"
#include "../assets/level_assets/level_assets.h"
#include "../battle/battle.h"
#include "asakawa_battle.h"
#include "../text/text.h"
#include "../start_up/start_up.h"
#include "../assets/sprite_palette.h"

/* scene 3 variables */
UINT8 l1_scene_3_anim = 0;

/* The big control function */
void level_1_ctrl(void) 
{
    wait_vbl_done();
    level_1_bkg_start();
    l1_scene_1();
    i = 0; // helping with animation
    while(enter_miner() == 0)
    {
        enter_miner();
        wait_vbl_done();
    }
    sprite_clean();
    LETTER_COUNT = 0;
    miner_intro_setup();
    miner_intro();
    l1_scene_3_setup();
    while(l1_scene_3_anim < 3)
    {
        l1_scene_3_animate();
        wait_vbl_done();
    }
    l1_scene_3_text_setup();
    l1_scene_3();
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
    delay(500);
}

void l1_scene_1(void) 
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
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("fisherman:\0", 24, 32);
    print("it would\0", 24, 48);
    print("be a cold\0", 24, 64);
    print("death\0", 24, 80);
    print("indeed...\0", 24, 96);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("fisherman:\0", 24, 32);
    print("i see we\0", 24, 48);
    print("have a\0", 24, 64);
    print("quiet\0", 24, 80);
    print("one.\0", 24, 96);
    delay(1000);
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
    delay(1000);
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

int level_1_sprite_setup(void) 
{
    /* hero on screen at door */
    hero_posx = 70;
    hero_posy = 65;

    /* fisherman on screen at door */
    fisherman_posx = 86;
    fisherman_posy = 65;

    /* miner positioning for the coming scene */
    miner_posx = 150;
    miner_posy = 100;

    SPRITES_8x16;
    /* hero */
    set_sprite_data(0, 8, hero_front_idle);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    /* fisherman */
    set_sprite_data(8, 8, fisherman_front_idle);
    set_sprite_tile(2, 8);
    set_sprite_tile(3, 8);
    set_sprite_prop(3, S_FLIPX);

    /* miner */
    set_sprite_data(16, 8, miner_walk_left);

    /* display the hero */
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    /* display the fisherman */
    move_sprite(2, fisherman_posx, fisherman_posy);
    move_sprite(3, fisherman_posx+sprite_width, fisherman_posy);

    delay(400); /* a pause before appearing at door */
    SHOW_SPRITES;
}

/**
 * SCENE 2
 */
int enter_miner(void) 
{
    UINT8 step_x = 4;
    UINT8 step_y = 0;

    if(miner_posx <= 80) /* if we are far enough to the left */
    {
        step_y = 4;
        step_x = 0;
        set_sprite_data(16, 8, miner_walk_up); 
        if(miner_posy <= 90)
        {
            step_y = 0;
            set_sprite_data(16, 8, miner_idle_back);
            delay(100);

            return 1; /* we're done */
        }

        miner_posx -= step_x;
        miner_posy -= step_y;

        set_sprite_tile(4, 16+((i&0x1)*4));
        set_sprite_tile(5, 18+((i&0x1)*4));

        move_sprite(4, miner_posx, miner_posy);
        move_sprite(5, miner_posx+sprite_width, miner_posy);
        delay(80);
    }

    /* start by walking left */
    miner_posx -= step_x;
    miner_posy -= step_y;

    set_sprite_tile(4, 16+((i&0x1)*4));
    set_sprite_tile(5, 18+((i&0x1)*4));
    move_sprite(4, miner_posx, miner_posy);
    move_sprite(5, miner_posx+sprite_width, miner_posy);
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

    sprite_clean();
    LETTER_COUNT = 0;
    print("miner:\0", 24, 32);
    print("i come\0", 24, 48);
    print("from the\0", 24, 64);
    print("yubari\0", 24, 80);
    print("coal\0", 24, 96);
    print("mines.\0", 24, 112);
    delay(1000);
}

/* setting up the miners dialogue / introduction */
int miner_intro(void)
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
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("fisherman:\0", 24, 32);
    print("a miner,\0", 24, 48);
    print("huh?\0", 24, 64);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("fisherman:\0", 24, 32);
    print("must've\0", 24, 48);
    print("been no\0", 24, 64);
    print("money in\0", 24, 80);
    print("mining?\0", 24, 96);
    delay(1000);
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
    delay(1000);
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
    delay(1000);
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
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("miner:\0", 24, 32);
    print("who's that\0", 24, 48);
    print("???\0", 24, 64);
    delay(1000);
    print("fisherman:\0", 24, 80);
    print("the\0", 24, 96);
    print("manager!\0", 24, 112);
    delay(1000);
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
    hero_posx = 100;
    hero_posy = 100;

    /* fisherman back faced to the screen */
    fisherman_posx = 120;
    fisherman_posy = 100;

    /* miner back faced to the screen */
    miner_posx = 80;
    miner_posy = 100;

    /* student back faced to the screen */
    student_posx = 60;
    student_posy = 100;

    /* asakawa front in doorway */
    asakawa_posx = 75;
    asakawa_posy = 65;

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
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    /* display the fisherman */
    move_sprite(2, fisherman_posx, fisherman_posy);
    move_sprite(3, fisherman_posx+sprite_width, fisherman_posy);
    /* display the miner */
    move_sprite(4, miner_posx, miner_posy);
    move_sprite(5, miner_posx+sprite_width, miner_posy);
    /* display the student */
    move_sprite(6, student_posx, student_posy);
    move_sprite(7, student_posx+sprite_width, student_posy);

    delay(400); /* a pause before appearing at door */
    SHOW_SPRITES;
    SHOW_BKG;
    DISPLAY_ON;

    /* after a little wait, asakawa appears in door way */
    delay(400);
    move_sprite(8, asakawa_posx, asakawa_posy);
    move_sprite(9, asakawa_posx+sprite_width, asakawa_posy);
}

/* brief animation for scene 3 */
void l1_scene_3_animate(void)
{
    ++l1_scene_3_anim;
    /* hero */
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    /* fisherman */
    set_sprite_tile(2, 8);
    set_sprite_tile(3, 10);
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    /* miner */ 
    set_sprite_tile(4, 16);
    set_sprite_tile(5, 18);
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    /* student */ 
    set_sprite_tile(6, 24);
    set_sprite_tile(7, 26);
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    /* asakawa */ 
    set_sprite_tile(8, 36-((l1_scene_3_anim&0x1)*4));
    set_sprite_tile(9, 38-((l1_scene_3_anim&0x1)*4));
    move_sprite(0, hero_posx, hero_posy);
    move_sprite(1, hero_posx+sprite_width, hero_posy);
    delay(500);
}
/* scene_3 dialogue setup first */
void l1_scene_3_text_setup(void)
{
    DISPLAY_OFF;
    hide_sprites();
    bkg_clean();
    DISPLAY_ON;
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("listen up\0", 24, 48);
    print("you\0", 24, 64);
    print("maggots!\0", 24, 80);
    delay(1000);
}

/* asakawa's message */
void l1_scene_3(void)
{
    bkg_clean();
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("needless\0", 24, 48);
    print("to say,\0", 24, 64);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("this ship\0", 24, 48);
    print("is of the\0", 24, 64);
    print("utmost\0", 24, 80);
    print("concern\0", 24, 96);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("for our\0", 24, 48);
    print("nation!\0", 24, 64);
    delay(500);
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("as\0", 24, 48);
    print("peoples\0", 24, 64);
    print("of\0", 24, 80);
    print("imperial\0", 24, 96);
    print("japan,\0", 24, 112);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("we are\0", 24, 48);
    print("proud\0", 24, 64);
    print("rivals\0", 24, 80);
    print("of russia!\0", 24, 96);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("there is an\0", 24, 48);
    print("imperial\0", 24, 64);
    print("ship\0", 24, 80);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("to\0", 24, 48);
    print("protect us\0", 24, 64);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("as a\0", 24, 48);
    print("nation of\0", 24, 64);
    print("excellence\0", 24, 80);
    delay(1000);
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
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("from the\0", 24, 32);
    print("crowd\0", 24, 48);
    print("someone\0", 24, 64);
    print("murmurs,\0", 24, 80);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("that's\0", 24, 32);
    print("a little\0", 24, 48);
    print("exagerated\0", 24, 64);
    print("don't you\0", 24, 80);
    print("think?\0", 24, 96);
    delay(1000);
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
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("this\0", 24, 48);
    print("attitude\0", 24, 64);
    print("is\0", 24, 80);
    print("mutinous,\0", 24, 94);
    delay(1000);
    sprite_clean();
    LETTER_COUNT = 0;
    print("asakawa:\0", 24, 32);
    print("and will\0", 24, 48);
    print("be\0", 24, 64);
    print("considered\0", 24, 80);
    print("treason!\0", 24, 96);
    delay(1000);
    /* Battle prompt */
    DISPLAY_OFF;
    //set_bkg_data(0,4, blank_screen_tiles);
    //set_bkg_tiles(0,0,20,18,blank_screen);
    clear_screen();
    sprite_clean();
    LETTER_COUNT = 0;
    print("fight\0", 64, 32);
    print("asakawa\0", 56, 48);
    DISPLAY_ON;
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
    delay(500);
}
