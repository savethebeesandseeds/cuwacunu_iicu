#include "iicu_loops.h"

void iicu_scene_loop(sdl_screen_object_t *obj_sdl){        
    fprintf(stdout,"[cuwacunu:] : start : iicu_scene_screen()\n");
    obj_sdl->iicu_state.interface_id=IICU_SCREEN_PANEL_STATE_ID;
// Uint32 start_time = SDL_GetTicks();
        update_iicu_state(obj_sdl);
    step_sdl_object(obj_sdl);
    refresh_current_iicu_scene(obj_sdl);
        render_state_panel(obj_sdl);
        render_iicu_scene(obj_sdl);
    draw_sdl_object(obj_sdl);
        wait_for_sdl_event(obj_sdl); //handle_sdl_event(obj_sdl);
// if((SDL_GetTicks()-start_time)<(1000*CLOCK_THREAD_PERIOD)){
//     SDL_Delay((1000*CLOCK_THREAD_PERIOD)-(SDL_GetTicks()-start_time));
// }
    fprintf(stdout,"[cuwacunu:] : end   : iicu_scene_screen()\n");
}

void loading_loop(sdl_screen_object_t *obj_sdl){
    fprintf(stdout,"[cuwacunu:] : start : loading_loop()\n");
    obj_sdl->iicu_state.interface_id=LOADING_STATE_ID;
    step_sdl_object(obj_sdl);
        render_loading(obj_sdl);
    draw_sdl_object(obj_sdl);
    fprintf(stdout,"[cuwacunu:] : end   : loading_loop()\n");
}

void home_loop(sdl_screen_object_t *obj_sdl){
    fprintf(stdout,"[cuwacunu:] : start : home_loop()\n");
    obj_sdl->iicu_state.interface_id=HOME_STATE_ID;
        update_iicu_state(obj_sdl);
    step_sdl_object(obj_sdl);
        render_state_panel(obj_sdl);
        render_home(obj_sdl);
    draw_sdl_object(obj_sdl);
        // handle_sdl_event(obj_sdl);
        wait_for_sdl_event(obj_sdl);
    fprintf(stdout,"[cuwacunu:] : end   : home_loop()\n");
}
