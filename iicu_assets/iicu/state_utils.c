#include "state_utils.h"
void initialize_iicu_state(sdl_screen_object_t *obj_sdl){
    // --- initialize the network state
    obj_sdl->iicu_state.network_last_update=0x00;
    obj_sdl->iicu_state.network_is_up=0x00;
    // --- initialize the broker state
    obj_sdl->iicu_state.broker_last_update=0x00;
    obj_sdl->iicu_state.broker_is_up=0x00;
    // --- initialize the keyboard state
    obj_sdl->iicu_state.keyboard_last_update=0x00;
    obj_sdl->iicu_state.keyboard_is_up=0x00;
    // --- initialize the controller state
    obj_sdl->iicu_state.controller_last_update=0x00;
    obj_sdl->iicu_state.controller_is_up=0x00;
    // --- update
    update_iicu_state(obj_sdl);
}
void initialize_iicu_scene(sdl_screen_object_t *obj_sdl){
    // --- initialize interface states
	obj_sdl->iicu_state.scene_id=0x00;
	obj_sdl->iicu_state.scene_count=0x00;
    // --- create item zero
    fabric_iicu_scene(obj_sdl);
}
void update_iicu_state(sdl_screen_object_t *obj_sdl){
    double d_time;
    double c_time= (double) time(NULL);
    // --- update network state
    d_time = c_time-obj_sdl->iicu_state.network_last_update;
    if(obj_sdl->iicu_state.network_last_update==0x00 || d_time > STATE_NETWORK_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : network\n");
        if(test_network_by_ping()!=STATE_STATUS_UP){
            obj_sdl->iicu_state.network_is_up=0x00;
        } else {
            obj_sdl->iicu_state.network_is_up=0xFF;
        }
        obj_sdl->iicu_state.network_last_update=(double)time(NULL);
    }
    // --- update broker state
    d_time = c_time-obj_sdl->iicu_state.broker_last_update;
    if(obj_sdl->iicu_state.broker_last_update==0x00 || d_time > STATE_BROKER_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : broker\n");
        if(test_network_by_ping()!=STATE_STATUS_UP){
            obj_sdl->iicu_state.broker_is_up=0x00;
        } else {
            obj_sdl->iicu_state.broker_is_up=0xFF;
        }
        obj_sdl->iicu_state.broker_last_update=(double)time(NULL);
    }
    // --- update keyboard state
    d_time = c_time-obj_sdl->iicu_state.keyboard_last_update;
    if(obj_sdl->iicu_state.keyboard_last_update==0x00 || d_time > STATE_KEYBOARD_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : keyboard\n");
        if(test_keyboard()!=STATE_STATUS_UP){
            obj_sdl->iicu_state.keyboard_is_up=0x00;
        } else {
            obj_sdl->iicu_state.keyboard_is_up=0xFF;
        }
        obj_sdl->iicu_state.keyboard_last_update=(double)time(NULL);
    }
    // --- update controller state
    d_time = c_time-obj_sdl->iicu_state.controller_last_update;
    if(obj_sdl->iicu_state.controller_last_update==0x00 || d_time > STATE_CONTROLLER_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : controller\n");
        if(test_controller()!=STATE_STATUS_UP){
            obj_sdl->iicu_state.controller_is_up=0x00;
        } else {
            obj_sdl->iicu_state.controller_is_up=0xFF;
        }
        obj_sdl->iicu_state.controller_last_update=(double)time(NULL);
    }
}
