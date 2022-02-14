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
void update_iicu_state(sdl_screen_object_t *obj_sdl){
    // --- update network state
    if((double)(clock()-obj_sdl->iicu_state.network_last_update) / CLOCKS_PER_SEC < STATE_NETWORK_UPDATE_PERIOD){
        if(test_network_by_ping()!=STATE_STATUS_UP){
            obj_sdl->iicu_state.network_is_up=0x00;
        } else {
            obj_sdl->iicu_state.network_is_up=0xFF;
        }
        obj_sdl->iicu_state.network_last_update=clock();
    }
    // --- update broker state
    if((double)(clock()-obj_sdl->iicu_state.broker_last_update) / CLOCKS_PER_SEC < STATE_BROKER_UPDATE_PERIOD){
        if(test_network_by_ping()!=STATE_STATUS_UP){
            obj_sdl->iicu_state.broker_is_up=0x00;
        } else {
            obj_sdl->iicu_state.broker_is_up=0xFF;
        }
        obj_sdl->iicu_state.broker_last_update=clock();
    }
    // --- update keyboard state
    if((double)(clock()-obj_sdl->iicu_state.keyboard_last_update) / CLOCKS_PER_SEC < STATE_KEYBOARD_UPDATE_PERIOD){
        if(test_keyboard()!=STATE_STATUS_UP){
            obj_sdl->iicu_state.keyboard_is_up=0x00;
        } else {
            obj_sdl->iicu_state.keyboard_is_up=0xFF;
        }
        obj_sdl->iicu_state.keyboard_last_update=clock();
    }
    // --- update controller state
    if((double)(clock()-obj_sdl->iicu_state.controller_last_update) / CLOCKS_PER_SEC < STATE_CONTROLLER_UPDATE_PERIOD){
        if(test_controller()!=STATE_STATUS_UP){
            obj_sdl->iicu_state.controller_is_up=0x00;
        } else {
            obj_sdl->iicu_state.controller_is_up=0xFF;
        }
        obj_sdl->iicu_state.controller_last_update=clock();
    }
}
