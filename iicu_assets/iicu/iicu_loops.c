#include "iicu_loops.h"

void iicu_scene_loop(__iicu_wikimyei_t *_iicu_wikimyei){     
    // fprintf(stdout,"[cuwacunu:] : start : iicu_scene_loop()\n");
_iicu_wikimyei->iicu_state.interface_id=IICU_SCREEN_PANEL_STATE_ID;
    // // --- --- --- --- · --- --- --- --- UPDATE 
        update_current_iicu_scene(_iicu_wikimyei);
    step_sdl_object(_iicu_wikimyei->obj_sdl);
    refresh_current_iicu_scene(_iicu_wikimyei);
        render_state_panel(_iicu_wikimyei);
        render_scene_panel(_iicu_wikimyei);
    draw_sdl_object(_iicu_wikimyei->obj_sdl);
        #ifndef __cwcn_CLOCK_THREAD__
        miss_or_catch_sdl_event(_iicu_wikimyei);
        #else
        wait_for_sdl_event(_iicu_wikimyei); //handle_sdl_event(_iicu_wikimyei);
        #endif
    // fprintf(stdout,"[cuwacunu:] : end   : iicu_scene_loop()\n");
}

void loading_loop(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"[cuwacunu:] : start : loading_loop()\n");
_iicu_wikimyei->iicu_state.interface_id=LOADING_STATE_ID;
    step_sdl_object(_iicu_wikimyei->obj_sdl);
        render_loading(_iicu_wikimyei);
    draw_sdl_object(_iicu_wikimyei->obj_sdl);
        update_iicu_state(_iicu_wikimyei);
    // fprintf(stdout,"[cuwacunu:] : end   : loading_loop()\n");
}

void home_loop(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"[cuwacunu:] : start : home_loop()\n");
_iicu_wikimyei->iicu_state.interface_id=HOME_STATE_ID;
    step_sdl_object(_iicu_wikimyei->obj_sdl);
        // render_state_panel(_iicu_wikimyei);
        render_home(_iicu_wikimyei->obj_sdl);
    draw_sdl_object(_iicu_wikimyei->obj_sdl);
        // handle_sdl_event(_iicu_wikimyei);
        wait_for_sdl_event(_iicu_wikimyei);
    // fprintf(stdout,"[cuwacunu:] : end   : home_loop()\n");
}
