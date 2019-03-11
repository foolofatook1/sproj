#include "level_1.h"

/* scene 1 variables */
UINT8 text_count = 0;
/* scene 2 variables */
UINT8 start_animate = 0;
UINT8 scene_2 = 0;
/* scene 3 variables */
UINT8 scene_3_anim = 0;
UINT8 scene_3_stop = 0;

UINT8 hero_pos[2][2];
UINT8 fisherman_pos[2][2];
UINT8 miner_pos[2][2];
UINT8 student_pos[2][2];
UINT8 asakawa_pos[2][2];

UINT8 sprite_width = 8;

/* The big control function */
void level_1_ctrl(void) 
{
    wait_vbl_done();
    level_1_bkg_start();
    while(start_animate == 0)
    {
        joypad_check_scene_1();
        wait_vbl_done();
    }
    while(enter_miner() == 0)
    {
        animate();
        enter_miner();
        wait_vbl_done();
    }
    miner_intro_setup();
    while(scene_2 == 0)
    {
        joypad_check_scene_2();
        wait_vbl_done();
    }
    scene_3_setup();
    while(scene_3_anim < 3)
    {
        scene_3_animate();
        wait_vbl_done();
    }
    scene_3_text_setup();
    while(scene_3_stop == 0)
    {
        joypad_check_scene_3();
        wait_vbl_done();
    }
    //SWITCH_ROM_MBC1(1);
//    asakawa_battle1_setup();*/

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

    /* opening screen */
    sprite_clean();
    print("chapter 1", 48, 64);
    print("welcome to", 44, 80);
    print("hell", 68, 96);
    LETTER_COUNT = 0;

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    delay(1000);

    DISPLAY_OFF;
    HIDE_WIN;
    HIDE_BKG;

    /* setting up first set of text */
    bkg_clean();
    sprite_clean();
    print("we're all", 24, 32);
    print("goin' to", 24, 48);
    print("hell!", 24, 64);
    print("you hear!?", 24, 80);
    LETTER_COUNT = 0;

    SHOW_BKG;
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
        bkg_clean();
        sprite_clean();
        print("4 months\0", 24, 32);
        print("on\0", 24, 48);
        print("kamchatkas\0", 24, 64);
        print("northern\0", 24, 80);
        print("waters.\0", 24, 96);
        LETTER_COUNT = 0;        
    }
    if(text_count == 2)
    {
        bkg_clean();
        sprite_clean();

        print("it would be", 24, 32);
        print("a cold", 24, 48);
        print("death", 24, 64);
        print("indeed...", 24, 80);
        LETTER_COUNT = 0;
    }
    if(text_count == 3)
    {
        bkg_clean();
        sprite_clean();

        print("i see we", 24, 32);
        print("have a", 24, 48);
        print("quiet", 24, 64);
        print("one.", 24, 80);
        LETTER_COUNT = 0; 
    }
    if(text_count == 4)
    {
        bkg_clean();
        sprite_clean();

        print("c'mon i'll", 24, 32);
        print("take you", 24, 48);
        print("down to", 24, 64);
        print("the", 24, 80);
        print("shit pot.", 24, 96);
        LETTER_COUNT = 0; 
    }
    if(text_count == 5)
    {
        DISPLAY_OFF;

        /* center on the door */
        set_bkg_data(0,4,blank_screen_tiles);
        set_bkg_tiles(0,0,20,18,shit_pot);
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

    bkg_clean();
    sprite_clean();

    SHOW_BKG;
    /* just adding this for a second */
    //set_win_data(0, 10, chain_border_tiles);
    //shet_win_tiles(0, 10, 20, 18, small_chain_border);
    //SHOW_WIN;
    SHOW_SPRITES;
    DISPLAY_ON;

    text_count = 0;

    print("i come", 24, 32);
    print("from the", 24, 48);
    print("yubari", 24, 64);
    print("coal", 24, 80);
    print("mines.", 24, 96);
    LETTER_COUNT = 0;
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

        print("worked", 24, 32);
        print("there for", 24, 48);
        print("seven", 24, 64);
        print("years.", 24, 80);
        LETTER_COUNT = 0;

        DISPLAY_ON;
    }
    if(text_count == 2)
    {
        bkg_clean();
        sprite_clean();

        print("a miner,", 24, 32);
        print("huh?", 24, 48);
        LETTER_COUNT = 0;
    }
    if(text_count == 3)
    {
        bkg_clean();
        sprite_clean();

        print("must've", 24, 32);
        print("been no", 24, 48);
        print("money in", 24, 64);
        print("mining?", 24, 80);
        LETTER_COUNT = 0;
    }
    if(text_count == 4)
    {
        bkg_clean();
        sprite_clean();

        print("...there\0", 24, 32);
        print("was an\0", 24, 48);
        print("explosion\0", 24, 64);
        print("...\0", 24, 80);
        print("from the\0", 24, 96);
        print("gas...\0", 24, 112);
        LETTER_COUNT = 0;
    }
    if(text_count == 5)
    {
        bkg_clean();
        sprite_clean();

        print("good lives\0", 24, 32);
        print("were lost\0", 24, 48);
        print("that can't\0", 24, 64);
        print("be\0", 24, 80);
        print("returned\0", 24, 96);
        print("...\0", 24, 112);
        LETTER_COUNT = 0;
    }
    if(text_count == 6)
    {
        bkg_clean();
        sprite_clean();

        print("we better\0", 24, 32);
        print("go!\0", 24, 48);
        print("i think\0", 24, 64);
        print("i hear\0", 24, 80);
        print("asakawa\0", 24, 96);
        print("coming!\0", 24, 112);
        LETTER_COUNT = 0;
    }
    if(text_count == 7)
    {
        bkg_clean();
        sprite_clean();

        print("who's that\0", 24, 32);
        print("???\0", 24, 48);
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
void scene_3_animate(void)
{
    ++scene_3_anim;
    /* hero */
    set_sprite_tile(0, 4);
    set_sprite_tile(1, 6);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    set_sprite_tile(0, 0);
    set_sprite_tile(1, 2);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    /* fisherman */
    set_sprite_tile(2, 12);
    set_sprite_tile(3, 14);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    set_sprite_tile(2, 8);
    set_sprite_tile(3, 10);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    /* miner */ 
    set_sprite_tile(4, 20);
    set_sprite_tile(5, 22);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    set_sprite_tile(4, 16);
    set_sprite_tile(5, 18);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    /* student */ 
    set_sprite_tile(6, 28);
    set_sprite_tile(7, 30);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    set_sprite_tile(6, 24);
    set_sprite_tile(7, 26);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
    /* asakawa */ 
    set_sprite_tile(8, 36);
    set_sprite_tile(9, 38);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(400);
    set_sprite_tile(8, 32);
    set_sprite_tile(9, 34);
    move_sprite(0, hero_pos[0][0], hero_pos[0][1]);
    move_sprite(1, hero_pos[1][0], hero_pos[1][1]);
    delay(100);
}
/* scene_3 dialogue setup first */
void scene_3_text_setup(void)
{
    DISPLAY_OFF;
    hide_sprites();
    bkg_clean();
    text_count = 0; // just making sure that this is zero
    DISPLAY_ON;

    print("listen up", 24, 32);
    print("you", 24, 48);
    print("maggots!", 24, 64);
    LETTER_COUNT = 0;

}

/* asakawa give his message */
void joypad_check_scene_3(void) 
{
    if(joypad() & J_A)
    {
        scene_3();
    }
}

/* asakawa's message */
void scene_3(void)
{
    delay(100);
    ++text_count;
    delay(100);

    if(text_count == 1)
    {
        bkg_clean();
        sprite_clean();
        print("needless", 24, 32);
        print("to say,", 24, 48);
        LETTER_COUNT = 0;
    }
    if(text_count == 2)
    {
        bkg_clean();
        sprite_clean();
        print("this ship", 24, 32);
        print("is not", 24, 48);
        print("a simple", 24, 64);
        print("source of", 24, 80);
        print("income!", 24, 96);
        LETTER_COUNT = 0;
    }
    if(text_count == 3)
    {
        bkg_clean();
        sprite_clean();
        print("but rather", 24, 32);
        print("of the", 24, 48);
        print("utmost", 24, 64);
        print("concern", 24, 80);
        LETTER_COUNT = 0;
    }
    if(text_count == 4)
    {
        bkg_clean();
        sprite_clean();
        print("for our", 24, 32);
        print("nation!", 24, 48);
        LETTER_COUNT = 0;
    }
    if(text_count == 5)
    {
        bkg_clean();
        sprite_clean();
        print("as", 24, 32);
        print("peoples", 24, 48);
        print("of", 24, 64);
        print("imperial", 24, 80);
        print("japan,", 24, 96);
        LETTER_COUNT = 0;
    }
    if(text_count == 6)
    {
        bkg_clean();
        sprite_clean();
        print("we are", 24, 32);
        print("proud", 24, 48);
        print("rivals", 24, 64);
        print("of russia!", 24, 80);
        LETTER_COUNT = 0;
    }
    if(text_count == 7)
    {
        bkg_clean();
        sprite_clean();
        print("that is", 24, 32);
        print("why you", 24, 48);
        print("fisherman", 24, 64);
        print("are not", 24, 80);
        LETTER_COUNT = 0;
    }
    if(text_count == 8)
    {
        bkg_clean();
        sprite_clean();
        print("only", 24, 32);
        print("canning", 24, 48);
        print("crabs,", 24, 64);
        LETTER_COUNT = 0;
    }
    if(text_count == 9)
    {
        bkg_clean();
        sprite_clean();
        print("but", 24, 32);
        print("salmon and", 24, 48);
        print("tuna", 24, 64);
        print("as well!", 24, 80);
        LETTER_COUNT = 0;
    }
    if(text_count == 10)
    {
        bkg_clean();
        sprite_clean();
        print("as a", 24, 32);
        print("nation of", 24, 48);
        print("excellence", 24, 64);
        print("...", 24, 80);
        LETTER_COUNT = 0;
    }
    if(text_count == 11)
    {
        bkg_clean();
        sprite_clean();
        print("we are", 24, 32);
        print("unmatched", 24, 48);
        print("when", 24, 64);
        print("compared", 24, 80);
        print("to others!", 24, 96);
        LETTER_COUNT = 0;
    }
    if(text_count == 12)
    {
        bkg_clean();
        sprite_clean();
        print("from the", 24, 32);
        print("crowd", 24, 48);
        print("someone", 24, 64);
        print("murmurs,", 24, 80);
        LETTER_COUNT = 0;
    }
    if(text_count == 13)
    {
        bkg_clean();
        sprite_clean();
        print("that's", 24, 32);
        print("a little", 24, 48);
        print("exagerated", 24, 64);
        print("don't you", 24, 80);
        print("think?", 24, 96);
        LETTER_COUNT = 0;
    }
    if(text_count == 14)
    {
        scene_3_setup();
        asakawa_shoots_anim();

        DISPLAY_OFF;
        bkg_clean();
        sprite_clean();
        DISPLAY_ON;

        print("this kind", 24, 32);
        print("of talk is", 24, 48);
        print("not", 24, 64);
        print("tolerable!", 24, 80);
        LETTER_COUNT = 0;
    }
    if(text_count == 15)
    {
        bkg_clean();
        sprite_clean();
        print("this", 24, 32);
        print("attitude", 24, 48);
        print("is not", 24, 64);
        print("only", 24, 80);
        print("mutinous,", 24, 96);
        LETTER_COUNT = 0;
    }
    if(text_count == 16)
    {
        bkg_clean();
        sprite_clean();
        print("but will", 24, 32);
        print("be", 24, 48);
        print("considered", 24, 64);
        print("treason as", 24, 80);
        print("well!", 24, 96);
        LETTER_COUNT = 0;
    }
    if(text_count == 17)
    {
        bkg_clean();
        sprite_clean();
        print("this job", 24, 32);
        print("is within", 24, 48);
        print("the realm", 24, 64);
        LETTER_COUNT = 0;
     }
     if(text_count == 18)
     {
         bkg_clean();
         sprite_clean();
         print("of", 24, 32);
         print("'national", 24, 48);
         print("policy!'", 24, 64);
         LETTER_COUNT = 0;
         delay(500);
         /* Battle prompt */
         DISPLAY_OFF;
         bkg_clean();
         sprite_clean();
         print("fight", 64, 32);
         print("asakawa", 56, 48);
         LETTER_COUNT = 0;
         DISPLAY_ON;
         delay(100);
         DISPLAY_OFF;
         delay(100);
         DISPLAY_ON;
         delay(100);
         DISPLAY_OFF;
         delay(100);
         DISPLAY_ON;
         LETTER_COUNT = 0;
         scene_3_stop = 1;
     }
}

void asakawa_shoots_anim(void)
{
    /* asakawa shooting setup */
    set_sprite_data(32, 32, asakawa_air_shot);
    set_sprite_tile(8, 32);
    set_sprite_tile(9, 34);
    move_sprite(8, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(9, asakawa_pos[1][0], asakawa_pos[1][1]);
    delay(500);
    /* asakawa reveals gun */
    set_sprite_tile(8, 36);
    set_sprite_tile(9, 38);
    move_sprite(8, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(9, asakawa_pos[1][0], asakawa_pos[1][1]);
    delay(500);
    /* asakawa raises gun */
    set_sprite_tile(8, 40);
    set_sprite_tile(9, 42);
    move_sprite(8, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(9, asakawa_pos[1][0], asakawa_pos[1][1]);
    delay(500);
    /* gun fires (takes 3 changes) */
    set_sprite_tile(8, 44);
    set_sprite_tile(9, 46);
    move_sprite(8, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(9, asakawa_pos[1][0], asakawa_pos[1][1]);
    delay(300);
    set_sprite_tile(8, 48);
    set_sprite_tile(9, 50);
    move_sprite(8, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(9, asakawa_pos[1][0], asakawa_pos[1][1]);
    delay(300);
    set_sprite_tile(8, 52);
    set_sprite_tile(9, 54);
    move_sprite(8, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(9, asakawa_pos[1][0], asakawa_pos[1][1]);
    delay(300);
    /* post gun firing */
    set_sprite_tile(8, 56);
    set_sprite_tile(9, 58);
    move_sprite(8, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(9, asakawa_pos[1][0], asakawa_pos[1][1]);
    delay(500); 
    /* lowers gun */
    set_sprite_tile(8, 60);
    set_sprite_tile(9, 62);
    move_sprite(8, asakawa_pos[0][0], asakawa_pos[0][1]);
    move_sprite(9, asakawa_pos[1][0], asakawa_pos[1][1]);
    delay(800);
}
