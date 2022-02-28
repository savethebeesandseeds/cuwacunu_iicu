#include "iicu_wikimyei.h"

__iicu_wikimyei_t *iicu_wikimyei_fabric(){
    __iicu_wikimyei_t *new_iicu_wikimyei=malloc(sizeof(__iicu_wikimyei_t));
    new_iicu_wikimyei->obj_sdl=malloc(sizeof(__sdl_screen_object_t));
    initialize_sdl_object(new_iicu_wikimyei->obj_sdl); // must first initialize obj_sdl
    initialize_iicu_state(new_iicu_wikimyei); // then initialize state
    fabric_all_iicu_scenes(new_iicu_wikimyei); // and tird scenes
    return new_iicu_wikimyei;
}
void destroy_iicu_wikimyei(__iicu_wikimyei_t *_iicu_wikimyei){
    destroy_all_iicu_scenes(_iicu_wikimyei);
    destroy_iicu_state(_iicu_wikimyei);
	kill_sdl_object(_iicu_wikimyei->obj_sdl);
    free(_iicu_wikimyei->obj_sdl);
    free(_iicu_wikimyei);
}
/*
	HANDLERS
*/
__iicu_scene_struct_t *get_current_scene(__iicu_wikimyei_t *_iicu_wikimyei){
    return &_iicu_wikimyei->iicu_scene[_iicu_wikimyei->iicu_state.scene_id];
}
__iicu_scene_struct_t *giics(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_scene(_iicu_wikimyei);
}
__iicu_nijcyota_t *get_current_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei){
    return _iicu_wikimyei->iicu_scene[_iicu_wikimyei->iicu_state.scene_id].nijcyota;
}
__iicu_nijcyota_t *giicn(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_nijcyota(_iicu_wikimyei);
}
__iicu_mewaajacune_t *get_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei){
    return _iicu_wikimyei->iicu_scene[_iicu_wikimyei->iicu_state.scene_id].mewaajacune;
}
__iicu_mewaajacune_t *giicm(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_mewaajacune(_iicu_wikimyei);
}