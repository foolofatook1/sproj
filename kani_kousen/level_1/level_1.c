/**
 * level_1.c
 */

#include "level_1.h"
#include "../assets/level_assets/level_assets.h"
#include "../battle/battle.h"
#include "asakawa_battle.h"
#include "../text/text.h"
#include "../start_up/start_up.h"
#include "../assets/sprite_palette.h"
#include "../assets/bkg_palette.h"
#include "../assets/sprite_palette.h"

/* scene 3 variables */
UINT8 l1_scene_3_anim = 0;
UINT16 dt = 1500;

/* The big control function */
void level_1_ctrl(void) 
{   /** this is a test **/
    set_bkg_palette(0, 1, bkg_palette);
    // set sprite properties 
    set_sprite_palette(0, 2, sprite_palette);
    /** the test ends here **/

    wait_vbl_done();
    level_1_bkg_start();
    l1_scene_1();
    i = 0; // helping with animation
    while(enter_miner() == 0)
    {
        enter_miner();
        wait_vbl_done();
    }
    sprite_clean(0);
    LETTER_COUNT = 0;
    miner_intro_setup();
    miner_intro();
    l1_scene_3_anim = 0;
    l1_scene_3_setup();
    while(l1_scene_3_anim < 3)
    {
        l1_scene_3_animate();
        wait_vbl_done();
    }
    l1_scene_3_text_setup();
    l1_scene_3();
    enemy = 0;
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
    sprite_clean(0);
    LETTER_COUNT = 0;
    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;
    /* opening screen */
    print("CHAPTERi\\\nWELCOME\nTOiHELL\0", 48, 64);
    delay(dt);
    sprite_clean(0);
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
    fisherman();
    print("WEkREiALL\nGOINkiTO\nHELLl\0", 24, 48);
    delay(dt);
    sprite_clean(10);
    LETTER_COUNT = 10;
    you_hear();
    delay(dt);
}

void l1_scene_1(void) 
{
    while(talking)
    {
        if(joypad() & J_A)
        {
            ++talking;
            delay(200);
            if(talking == 2)
            {
                sprite_clean(10);
                LETTER_COUNT = 10;
                print("_iMONTHS\nON\0", 24, 48);
            }
            if(talking == 3)
            {
                sprite_clean(10);
                LETTER_COUNT = 10;
                print("KAMCHATKAS\nNORTHERN\nWATERSe\0", 24, 48);
            }
            if(talking == 4)
            {
                sprite_clean(10);
                LETTER_COUNT = 10;
                print("ITiWOULD\nBEiAiCOLD\nDEATH\neee\0", 24, 48);
            }
            if(talking == 5)
            {
                sprite_clean(10);
                LETTER_COUNT = 10;
                print("IiSEEiWE\nHAVEiA\nQUIETiONEe\0", 24, 48);
            }
            if(talking == 6)
            {
                sprite_clean(10);
                LETTER_COUNT = 10;
                print("CkMON\nIkLLiTAKE\nYOUiDOWN\0", 24, 48);
            }
            if(talking == 7)
            {
                sprite_clean(10);
                LETTER_COUNT = 10;
                print("TOiTHE\nSHITiPOTe\0", 24, 48);
            }
            if(talking == 8)
            {
                DISPLAY_OFF;
                // center on the door 
                set_bkg_data(0,4,blank_screen_tiles);
                set_bkg_tiles(0,0,20,18,shit_pot);
                DISPLAY_ON;
                HIDE_SPRITES;// this turns sprites off 
                sprite_clean(0);
                hide_sprites();
                LETTER_COUNT = 0;
                level_1_sprite_setup();
                break;
            }
        }
    }
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

    miner();
    print("IiCOME\nFROMiTHE\nYUBARI\nCOAL\nMINESe\0", 24, 48);
    
}

/* setting up the miners dialogue / introduction */
int miner_intro(void)
{
    DISPLAY_ON;
    talking = 1;
    while(talking)
    {
        if(joypad() & J_A)
        {
            ++talking;
            delay(200);
            if(talking == 2)
            {
                sprite_clean(6);
                LETTER_COUNT = 6;
                print("WORKED\nTHEREiFOR\nSEVEN\nYEARSe\0", 24, 48);
            }
            if(talking == 3)
            {
                sprite_clean(0);
                LETTER_COUNT = 0;
                fisherman();
                print("AiMINERf\nHUHn\0", 24, 48);
            }
            if(talking == 4)
            {
                sprite_clean(10);
                LETTER_COUNT = 10;
                print("MUSTkVE\nBEENiNO\nMONEYiIN\nMININGn", 24, 48);
            }
            if(talking == 5)
            {
                sprite_clean(0);
                LETTER_COUNT = 0;
                miner();
                print("eeeTHERE\nWASiAN\nEXPLOSION\0", 24, 48);
            }
            if(talking == 6)
            {
                sprite_clean(6);
                LETTER_COUNT = 6;
                print("eee\nFROMiTHE\nGASeee\0", 24, 48);
            }
            if(talking == 7)
            {
                sprite_clean(6);
                LETTER_COUNT= 6;
                print("GOODiLIVES\nWEREiLOST\0", 24, 48);
            }
            if(talking == 8)
            {
                sprite_clean(6);
                LETTER_COUNT = 6;
                print("THATiCANkT\nBE\nRETURNED\neee\0", 24, 48);
            }
            if(talking == 9)
            {
                sprite_clean(0);
                LETTER_COUNT = 0;
                fisherman();
                print("WEiBETTER\nGOl\0", 24, 48);
            }
            if(talking == 10)
            {
                sprite_clean(10);
                LETTER_COUNT = 10;
                print("IiTHINK\nIiHEAR\nASAKAWA\nCOMINGl\0", 24, 48);
            }
            if(talking == 11)
            {
                sprite_clean(0);
                LETTER_COUNT = 0;
                miner();
                print("WHOkSiTHAT\nn\0", 24, 48);
            }
            if(talking == 12)
                print("FISHERMANg\nTHE\nMANAGERl\0", 24, 80);
            if(talking == 13)
                break;
        }
    }
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
    sprite_clean(0);
    LETTER_COUNT = 0;
    asakawa();
    print("LISTENiUP\nYOU\nMAGGOTSl\0", 24, 48);
}

/* asakawa's message */
void l1_scene_3(void)
{
    talking = 1;
    while(talking)
    {
        if(joypad() & J_A)
        {
            ++talking;
            delay(200);
            if(talking == 2)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("NEEDLESS\nTOiSAYf\0", 24, 48);
            }
            if(talking == 3)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("THISiSHIP\nISiOFiTHE", 24, 48);
            }
            if(talking == 4)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("UTMOST\nCONCERN\0", 24, 48);
            }
            if(talking == 5)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("AS\nPEOPLES\nOF\nIMPERIAL\nJAPANf\0", 24, 48);
            }
            if(talking == 6)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("WEiARE\nPROUD\nRIVALS\nOFiRUSSIAl\0",24, 48);
            }
            if(talking == 7)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("THEREkSiAN\nIMPERIAL\nSHIP\0", 24, 48);
            }
            if(talking == 8)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("TO\nPROTECTiUS\0", 24, 48);
            }
            if(talking == 9)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("ASiA\nNATIONiOF\nEXCELLENCE\0", 24, 48);
            }
            if(talking == 10)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("WEiARE\nUNMATCHED\0", 24, 48);
            }
            if(talking == 11)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("WHEN\nCOMPARED\nTOiOTHERSl\0", 24, 48);
            }
            if(talking == 12)
            {
                sprite_clean(0);
                LETTER_COUNT = 0;
                print("FROMiTHE\nCROWD\nSOMEONE\nMURMURSf\0", 24, 32);
            }
            if(talking == 13)
            {
                sprite_clean(0);
                LETTER_COUNT = 0;
                print("THATkS\nEXAGERATED\neee\0", 24, 32);
            }
            if(talking == 14)
            {
                sprite_clean(0);
                LETTER_COUNT = 0;
                l1_scene_3_setup();
                asakawa_shoots_anim();
                DISPLAY_OFF;
                bkg_clean();
                hide_sprites();
                DISPLAY_ON;
                asakawa();
                print("THISiKIND\nOFiTALKiIS\0", 24, 48);
            }
            if(talking == 15)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("NOT\nTOLERABLE\0", 24, 48);
            }
            if(talking == 16)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("THIS\nATTITUDE\nIS\nMUTINOUSf\0", 24, 48);
            }
            if(talking == 17)
            {
                sprite_clean(8);
                LETTER_COUNT = 8;
                print("ANDiWILL\nBE\nCONSIDERED\nTREASONl\0", 24, 48);
            }
            if(talking == 18)
            {
                sprite_clean(0);
                LETTER_COUNT = 0;
                // Battle prompt 
                DISPLAY_OFF;
                clear_screen();
                print("FIGHT\0", 64, 32);
                print("ASAKAWA\0", 56, 48);
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
                break;
            }
        }
    }
}

void asakawa_shoots_anim(void)
{
    set_sprite_data(32, 32, asakawa_air_shot);
    anim_1 = 32;
    anim_2 = 34;
    /* asakawa shooting setup */
    for(i = 0; i < 7; ++i)
    {
        set_sprite_tile(8, anim_1+=4);
        set_sprite_tile(9, anim_2+=4);
        delay(500);
    }
    delay(500);
}
