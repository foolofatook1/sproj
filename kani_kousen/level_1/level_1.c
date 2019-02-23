#include "level_1.h"


/* The big control function */
void level_1_ctrl(void) 
{
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
    asakawa_battle1_setup();
}
