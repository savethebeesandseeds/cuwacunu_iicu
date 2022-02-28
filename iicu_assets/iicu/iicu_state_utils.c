#include "iicu_state_utils.h"

/*
    ---------- STATE --- --- --- --- --- --- ---
*/
void initialize_iicu_state(__iicu_wikimyei_t *_iicu_wikimyei){
    // --- initialize the network state
    _iicu_wikimyei->iicu_state.network_last_update=0x00;
    _iicu_wikimyei->iicu_state.network_is_up=0x00;
    // --- initialize the broker state
    _iicu_wikimyei->iicu_state.broker_last_update=0x00;
    _iicu_wikimyei->iicu_state.broker_is_up=0x00;
    // --- initialize the keyboard state
    _iicu_wikimyei->iicu_state.keyboard_last_update=0x00;
    _iicu_wikimyei->iicu_state.keyboard_is_up=0x00;
    // --- initialize the controller state
    _iicu_wikimyei->iicu_state.controller_last_update=0x00;
    _iicu_wikimyei->iicu_state.controller_is_up=0x00;
    // --- initialize the scene
    _iicu_wikimyei->iicu_state.scene_id=0x00;
	_iicu_wikimyei->iicu_state.scene_count=0x00;
    // --- initialize the fps
    _iicu_wikimyei->iicu_state.fps=0x00;
    // --- initialize the textures
	SDL_Surface *network_surface = IMG_Load(STATE_PANEL_WIFI);
    SDL_Surface *broker_surface = IMG_Load(STATE_PANEL_BROKER);
    SDL_Surface *keyboard_surface = IMG_Load(STATE_PANEL_KEYBOARD);
    SDL_Surface *controller_surface = IMG_Load(STATE_PANEL_CONTROLLER);
    _iicu_wikimyei->iicu_state.network_texture = SDL_CreateTextureFromSurface(_iicu_wikimyei->obj_sdl->renderer,network_surface);
    _iicu_wikimyei->iicu_state.broker_texture = SDL_CreateTextureFromSurface(_iicu_wikimyei->obj_sdl->renderer,broker_surface);
    _iicu_wikimyei->iicu_state.keyboard_texture = SDL_CreateTextureFromSurface(_iicu_wikimyei->obj_sdl->renderer,keyboard_surface);
    _iicu_wikimyei->iicu_state.controller_texture = SDL_CreateTextureFromSurface(_iicu_wikimyei->obj_sdl->renderer,controller_surface);
    SDL_FreeSurface(network_surface);
    SDL_FreeSurface(broker_surface);
    SDL_FreeSurface(broker_surface);
    SDL_FreeSurface(controller_surface);
}
void destroy_iicu_state(__iicu_wikimyei_t *_iicu_wikimyei){
    SDL_DestroyTexture(_iicu_wikimyei->iicu_state.network_texture);
    SDL_DestroyTexture(_iicu_wikimyei->iicu_state.broker_texture);
    SDL_DestroyTexture(_iicu_wikimyei->iicu_state.keyboard_texture);
    SDL_DestroyTexture(_iicu_wikimyei->iicu_state.controller_texture);
}
void update_iicu_state(__iicu_wikimyei_t *_iicu_wikimyei){
    double d_time;
    double c_time= (double) time(NULL);
    // --- update network state
    d_time = c_time-_iicu_wikimyei->iicu_state.network_last_update;
    if(_iicu_wikimyei->iicu_state.network_last_update==0x00 || d_time > STATE_NETWORK_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : network\n");
        if(test_network_by_ping()!=STATE_STATUS_UP){
            _iicu_wikimyei->iicu_state.network_is_up=0x00;
        } else {
            _iicu_wikimyei->iicu_state.network_is_up=0xFF;
        }
        _iicu_wikimyei->iicu_state.network_last_update=(double)time(NULL);
    }
    // --- update broker state
    d_time = c_time-_iicu_wikimyei->iicu_state.broker_last_update;
    if(_iicu_wikimyei->iicu_state.broker_last_update==0x00 || d_time > STATE_BROKER_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : broker\n");
        if(test_network_by_ping()!=STATE_STATUS_UP){
            _iicu_wikimyei->iicu_state.broker_is_up=0x00;
        } else {
            _iicu_wikimyei->iicu_state.broker_is_up=0xFF;
        }
        _iicu_wikimyei->iicu_state.broker_last_update=(double)time(NULL);
    }
    // --- update keyboard state
    d_time = c_time-_iicu_wikimyei->iicu_state.keyboard_last_update;
    if(_iicu_wikimyei->iicu_state.keyboard_last_update==0x00 || d_time > STATE_KEYBOARD_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : keyboard\n");
        if(test_keyboard()!=STATE_STATUS_UP){
            _iicu_wikimyei->iicu_state.keyboard_is_up=0x00;
        } else {
            _iicu_wikimyei->iicu_state.keyboard_is_up=0xFF;
        }
        _iicu_wikimyei->iicu_state.keyboard_last_update=(double)time(NULL);
    }
    // --- update controller state
    d_time = c_time-_iicu_wikimyei->iicu_state.controller_last_update;
    if(_iicu_wikimyei->iicu_state.controller_last_update==0x00 || d_time > STATE_CONTROLLER_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : controller\n");
        if(test_controller()!=STATE_STATUS_UP){
            _iicu_wikimyei->iicu_state.controller_is_up=0x00;
        } else {
            _iicu_wikimyei->iicu_state.controller_is_up=0xFF;
        }
        _iicu_wikimyei->iicu_state.controller_last_update=(double)time(NULL);
    }
}
