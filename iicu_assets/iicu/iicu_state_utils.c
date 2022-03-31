#include "iicu_state_utils.h"
/*
    ---------- STATE --- --- --- --- --- --- ---
*/
__iicu_state_struct_t *fabric_iicu_state(__iicu_wikimyei_t *_iicu_wikimyei){
    __iicu_state_struct_t *new_iicu_state=malloc(sizeof(__iicu_state_struct_t));
    new_iicu_state->__req_itsaave=0x00;
    new_iicu_state->__jk_thread_order=malloc(INTERNAL_NUM_THREADS*sizeof(__jkimyei_thread_order_t *));
    new_iicu_state->__rg_thread_order=malloc(INTERNAL_NUM_THREADS*sizeof(__regressive_thread_order_t *));
    new_iicu_state->__pl_thread_order=malloc(INTERNAL_NUM_THREADS*sizeof(__polinomial_thread_order_t *));
    new_iicu_state->__sq_thread_order=malloc(INTERNAL_NUM_THREADS*sizeof(__staticques_thread_order_t *));
    new_iicu_state->__it_thread_order=malloc(MAX_IICU_ITSAAVES*sizeof(__itsaave_thread_order_t *));
    for(int temp_idx=0x00;temp_idx<INTERNAL_NUM_THREADS;temp_idx++){ // #OK multiple malloc seems ok #FIXME not it does not
        new_iicu_state->__jk_thread_order[temp_idx]=malloc(sizeof(__jkimyei_thread_order_t));
        new_iicu_state->__rg_thread_order[temp_idx]=malloc(sizeof(__regressive_thread_order_t));
        new_iicu_state->__pl_thread_order[temp_idx]=malloc(sizeof(__polinomial_thread_order_t));
        new_iicu_state->__sq_thread_order[temp_idx]=malloc(sizeof(__staticques_thread_order_t));
    }
    for(int temp_idx=0x00;temp_idx<MAX_IICU_ITSAAVES;temp_idx++){
        new_iicu_state->__it_thread_order[temp_idx]=malloc(sizeof(__itsaave_thread_order_t));
    }
    initialize_iicu_state(new_iicu_state,_iicu_wikimyei);
    return new_iicu_state;
}
void destroy_iicu_state(__iicu_state_struct_t *_iicu_state){
    kill_iicu_state(_iicu_state);
    for(int temp_idx=0x00;temp_idx<INTERNAL_NUM_THREADS;temp_idx++){
        free(_iicu_state->__jk_thread_order[temp_idx]);
        free(_iicu_state->__rg_thread_order[temp_idx]);
        free(_iicu_state->__pl_thread_order[temp_idx]);
        free(_iicu_state->__sq_thread_order[temp_idx]);
    }
    for(int temp_idx=0x00;temp_idx<MAX_IICU_ITSAAVES;temp_idx++){
        free(_iicu_state->__it_thread_order[temp_idx]);
    }
    free(_iicu_state->__jk_thread_order);
    free(_iicu_state->__rg_thread_order);
    free(_iicu_state->__pl_thread_order);
    free(_iicu_state->__sq_thread_order);
    free(_iicu_state->__it_thread_order);
    free(_iicu_state);
}
void initialize_iicu_state(__iicu_state_struct_t *_iicu_state,__iicu_wikimyei_t *_iicu_wikimyei){
    // --- initialize the in_use states
    _iicu_state->nijcyota_in_use=0x00;
    _iicu_state->wk_itsaave_in_use=0x00;
    for(int bsi_idx=0x00;bsi_idx<MAX_IICU_SCENES;bsi_idx++){
        _iicu_state->jkimyei_in_use[bsi_idx]=0x00;
        _iicu_state->scene_itsaave_in_use[bsi_idx]=0x00;
        for(int bki_idx=0x00;bki_idx<BROKER_CANDLE_N_INTERVALS;bki_idx++){
            _iicu_state->mewaajacune_in_use[bsi_idx][bki_idx]=0x00;
            _iicu_state->regressive_in_use[bsi_idx][bki_idx]=0x00;
            _iicu_state->polinomial_in_use[bsi_idx][bki_idx]=0x00;
            _iicu_state->staticques_in_use[bsi_idx][bki_idx]=0x00;
        }
    }
    // --- initialize the threads_states
    for(int temp_idx=0x00;temp_idx<INTERNAL_NUM_THREADS;temp_idx++){
        ((__jkimyei_thread_order_t*)_iicu_state->__jk_thread_order[temp_idx])->__jk_thead_is_bussy=0x00;
        ((__jkimyei_thread_order_t*)_iicu_state->__jk_thread_order[temp_idx])->__ref_iicu_wikimyei=_iicu_wikimyei;

        ((__regressive_thread_order_t*)_iicu_state->__rg_thread_order[temp_idx])->__rg_thead_is_bussy=0x00;
        ((__regressive_thread_order_t*)_iicu_state->__rg_thread_order[temp_idx])->__ref_iicu_wikimyei=_iicu_wikimyei;

        ((__polinomial_thread_order_t*)_iicu_state->__pl_thread_order[temp_idx])->__pl_thead_is_bussy=0x00;
        ((__polinomial_thread_order_t*)_iicu_state->__pl_thread_order[temp_idx])->__ref_iicu_wikimyei=_iicu_wikimyei;

        ((__staticques_thread_order_t*)_iicu_state->__sq_thread_order[temp_idx])->__sq_thead_is_bussy=0x00;
        ((__staticques_thread_order_t*)_iicu_state->__sq_thread_order[temp_idx])->__ref_iicu_wikimyei=_iicu_wikimyei;
    }
    for(int temp_idx=0x00;temp_idx<MAX_IICU_ITSAAVES;temp_idx++){
        ((__itsaave_thread_order_t*)_iicu_state->__it_thread_order[temp_idx])->__it_thead_is_bussy=0x00;
        ((__itsaave_thread_order_t*)_iicu_state->__it_thread_order[temp_idx])->__it_policy_is_bussy=0x00;
        ((__itsaave_thread_order_t*)_iicu_state->__it_thread_order[temp_idx])->__ref_iicu_wikimyei=_iicu_wikimyei;
    }
    // _iicu_state->kline_id[scene_idx]; // initialized in fabric_all_iicu_scenes()
    // --- initialize the network state
    _iicu_state->network_last_update=0x00;
    _iicu_state->network_is_up=0x00;
    // --- initialize the broker state
    _iicu_state->broker_last_update=0x00;
    _iicu_state->broker_is_up=0x00;
    // --- initialize the keyboard state
    _iicu_state->keyboard_last_update=0x00;
    _iicu_state->keyboard_is_up=0x00;
    // --- initialize the controller state
    _iicu_state->controller_last_update=0x00;
    _iicu_state->controller_is_up=0x00;
    // --- initialize the scene
    _iicu_state->scene_id=0x00;
	_iicu_state->scene_count=0x00;
    // --- initialize the fps
    _iicu_state->fps=0x00;
    // --- initialize the textures
	SDL_Surface *network_surface = IMG_Load(STATE_PANEL_WIFI);
    SDL_Surface *broker_surface = IMG_Load(STATE_PANEL_BROKER);
    SDL_Surface *keyboard_surface = IMG_Load(STATE_PANEL_KEYBOARD);
    SDL_Surface *controller_surface = IMG_Load(STATE_PANEL_CONTROLLER);
    _iicu_state->network_texture = SDL_CreateTextureFromSurface(_iicu_wikimyei->__obj_sdl->renderer,network_surface);
    _iicu_state->broker_texture = SDL_CreateTextureFromSurface(_iicu_wikimyei->__obj_sdl->renderer,broker_surface);
    _iicu_state->keyboard_texture = SDL_CreateTextureFromSurface(_iicu_wikimyei->__obj_sdl->renderer,keyboard_surface);
    _iicu_state->controller_texture = SDL_CreateTextureFromSurface(_iicu_wikimyei->__obj_sdl->renderer,controller_surface);
    SDL_FreeSurface(network_surface);
    SDL_FreeSurface(broker_surface);
    SDL_FreeSurface(keyboard_surface);
    SDL_FreeSurface(controller_surface);
}
void kill_iicu_state(__iicu_state_struct_t *_iicu_state){
    SDL_DestroyTexture(_iicu_state->network_texture);
    SDL_DestroyTexture(_iicu_state->broker_texture);
    SDL_DestroyTexture(_iicu_state->keyboard_texture);
    SDL_DestroyTexture(_iicu_state->controller_texture);
}
void update_iicu_state(__iicu_wikimyei_t *_iicu_wikimyei){
    double d_time;
    double c_time= (double) time(NULL);
    // --- update network state
    d_time = c_time-get_state(_iicu_wikimyei)->network_last_update;
    if(get_state(_iicu_wikimyei)->network_last_update==0x00 || d_time > STATE_NETWORK_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : network\n");
        if(test_network_by_ping()!=STATE_STATUS_UP){
            get_state(_iicu_wikimyei)->network_is_up=0x00;
        } else {
            get_state(_iicu_wikimyei)->network_is_up=0xFF;
        }
        get_state(_iicu_wikimyei)->network_last_update=(double)time(NULL);
    }
    // --- update broker state
    d_time = c_time-get_state(_iicu_wikimyei)->broker_last_update;
    if(get_state(_iicu_wikimyei)->broker_last_update==0x00 || d_time > STATE_BROKER_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : broker\n");
        if(test_network_by_ping()!=STATE_STATUS_UP){
            get_state(_iicu_wikimyei)->broker_is_up=0x00;
        } else {
            get_state(_iicu_wikimyei)->broker_is_up=0xFF;
        }
        get_state(_iicu_wikimyei)->broker_last_update=(double)time(NULL);
    }
    // --- update keyboard state
    d_time = c_time-get_state(_iicu_wikimyei)->keyboard_last_update;
    if(get_state(_iicu_wikimyei)->keyboard_last_update==0x00 || d_time > STATE_KEYBOARD_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : keyboard\n");
        if(test_keyboard()!=STATE_STATUS_UP){
            get_state(_iicu_wikimyei)->keyboard_is_up=0x00;
        } else {
            get_state(_iicu_wikimyei)->keyboard_is_up=0xFF;
        }
        get_state(_iicu_wikimyei)->keyboard_last_update=(double)time(NULL);
    }
    // --- update controller state
    d_time = c_time-get_state(_iicu_wikimyei)->controller_last_update;
    if(get_state(_iicu_wikimyei)->controller_last_update==0x00 || d_time > STATE_CONTROLLER_UPDATE_PERIOD){
        fprintf(stdout,"[cuwacunu:] update_iicu_state : controller\n");
        if(test_controller()!=STATE_STATUS_UP){
            get_state(_iicu_wikimyei)->controller_is_up=0x00;
        } else {
            get_state(_iicu_wikimyei)->controller_is_up=0xFF;
        }
        get_state(_iicu_wikimyei)->controller_last_update=(double)time(NULL);
    }
}

