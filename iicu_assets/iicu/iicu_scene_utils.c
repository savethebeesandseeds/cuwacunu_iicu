#include "iicu_scene_utils.h"
// ---------- SCENE --- --- --- --- --- --- --- 
void fabric_iicu_scene(__iicu_scene_struct_t *_iicu_scene){
	// --- --- --- NIJCYOTA
	_iicu_scene->nijcyota=nijcyota_fabric();
	// --- --- --- MEWAAJACUNE
	_iicu_scene->mewaajacune=mewaajacune_fabric();	
}
void fabric_all_iicu_scenes(__iicu_wikimyei_t *_iicu_wikimyei){
	if(_iicu_wikimyei->iicu_state.scene_count!=0 || _iicu_wikimyei->iicu_state.scene_id!=0){
		fprintf(stderr,"ERROR :: fabric_all_iicu_scenes :: request failed\n");
		assert(0x00);
	}
	while(_iicu_wikimyei->iicu_state.scene_count<MAX_IICU_SCENES){
		// --- --- --- 
		_iicu_wikimyei->iicu_state.scene_id=_iicu_wikimyei->iicu_state.scene_count;
		// --- --- --- 
		fabric_iicu_scene(giics(_iicu_wikimyei));
		// --- --- --- 
		_iicu_wikimyei->iicu_state.scene_count++;
		// --- --- ---
	}
	_iicu_wikimyei->iicu_state.scene_id=0x00;
	strcpy(_iicu_wikimyei->iicu_state.scene_symbol,IICU_SCENES_SYMBOLS[_iicu_wikimyei->iicu_state.scene_id]);
}
void update_current_iicu_scene(__iicu_wikimyei_t *_iicu_wikimyei){
	update_iicu_mewaajacune(giicm(_iicu_wikimyei));
	// #FIXME put into update_iicu_nijcyota
    giicn(_iicu_wikimyei)->orbital_angle=mean_alliu_in_load( \
		giicm(_iicu_wikimyei), giicn(_iicu_wikimyei)->alliu_index); // update nijcyota
    update_iicu_nicjyota(giicn(_iicu_wikimyei));
}
void refresh_iicu_scene(__iicu_scene_struct_t *_iicu_scene){
	// #FIXME add ...
    // fprintf(stdout,"[WARNING:] refresh_iicu_scene is call empty\n");
}
void refresh_current_iicu_scene(__iicu_wikimyei_t *_iicu_wikimyei){
	refresh_iicu_scene(giics(_iicu_wikimyei));
}
void destroy_iicu_scene(__iicu_scene_struct_t *_iicu_scene){ // #FIXME fix fixed size of scenes, rather allocate memory
	refresh_iicu_scene(_iicu_scene);
	destroy_mewaajacune(_iicu_scene->mewaajacune);
	free(_iicu_scene->nijcyota);
}
void destroy_all_iicu_scenes(__iicu_wikimyei_t *_iicu_wikimyei){
	_iicu_wikimyei->iicu_state.scene_id=_iicu_wikimyei->iicu_state.scene_count-0x01;
	while(_iicu_wikimyei->iicu_state.scene_count!=0x00){
		destroy_iicu_scene(giics(_iicu_wikimyei));
		_iicu_wikimyei->iicu_state.scene_count-=0x01;
		_iicu_wikimyei->iicu_state.scene_id-=0x01;
	}
	assert(_iicu_wikimyei->iicu_state.scene_count==0x00);
	assert(_iicu_wikimyei->iicu_state.scene_id==0x00);
}


void iicu_scene_go_up(__iicu_wikimyei_t *_iicu_wikimyei){
	if(_iicu_wikimyei->iicu_state.scene_id<_iicu_wikimyei->iicu_state.scene_count-0x01){
		_iicu_wikimyei->iicu_state.scene_id++;
	} else {
		_iicu_wikimyei->iicu_state.scene_id=0x00;
	}
	strcpy(_iicu_wikimyei->iicu_state.scene_symbol,IICU_SCENES_SYMBOLS[_iicu_wikimyei->iicu_state.scene_id]);
}
void iicu_scene_go_down(__iicu_wikimyei_t *_iicu_wikimyei){
	if(_iicu_wikimyei->iicu_state.scene_id>0x00){
		_iicu_wikimyei->iicu_state.scene_id--;
	} else {
		_iicu_wikimyei->iicu_state.scene_id=_iicu_wikimyei->iicu_state.scene_count-0x01;
	}
	strcpy(_iicu_wikimyei->iicu_state.scene_symbol,IICU_SCENES_SYMBOLS[_iicu_wikimyei->iicu_state.scene_id]);
}