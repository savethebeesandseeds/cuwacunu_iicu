#include "iicu_wikimyei.h"

__iicu_wikimyei_t *iicu_wikimyei_fabric(){
    fprintf(stdout,"[cuwacunu:] : start : iicu_wikimyei_fabric()\n");
    fprintf(stdout,"[cuwacunu:] : 0 : iicu_wikimyei_fabric()\n");
    __iicu_wikimyei_t *new_iicu_wikimyei=malloc(sizeof(__iicu_wikimyei_t));
    fprintf(stdout,"[cuwacunu:] : 1 : iicu_wikimyei_fabric()\n");
    new_iicu_wikimyei->obj_sdl=malloc(sizeof(__sdl_screen_object_t));
    fprintf(stdout,"[cuwacunu:] : 2 : iicu_wikimyei_fabric()\n");
    initialize_sdl_object(new_iicu_wikimyei->obj_sdl); // must first initialize obj_sdl
    fprintf(stdout,"[cuwacunu:] : 3 : iicu_wikimyei_fabric()\n");
    initialize_iicu_state(new_iicu_wikimyei); // then initialize state
    fprintf(stdout,"[cuwacunu:] : 4 : iicu_wikimyei_fabric()\n");
    fabric_all_iicu_scenes(new_iicu_wikimyei); // and tird scenes
    fprintf(stdout,"[cuwacunu:] : 5 : iicu_wikimyei_fabric()\n");
    fprintf(stdout,"[cuwacunu:] : start : iicu_wikimyei_fabric()\n");
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
	BESEECH (meaning: solicit access urgently)
*/
void beseech_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index,int _kline_index){
    // fprintf(stdout,"request to beseech_mewaajacune...\n");
    Uint32 beseech_ctx=0x00;
    while(_iicu_wikimyei->iicu_state.mewaajacune_in_use[_scene_index][_kline_index]){
        SDL_Delay(BESEECH_TIMEOUT);
        beseech_ctx++;
        if(beseech_ctx>BESEECH_MAX_RETRY){
            fprintf(stderr,"%s [ERROR] beseech_mewaajacune index scene:[%d]:kline:[%d] exceed maxima timeout...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            fprintf(stderr,"%s [beseech_mewaajacune] index scene:[%d]:kline:[%d] forcing release...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            break;
        }
    } // wait mewaajacune to release
	_iicu_wikimyei->iicu_state.mewaajacune_in_use[_scene_index][_kline_index]=0x01;
}
void release_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index){
    // fprintf(stdout,"request to release_mewaajacune...\n");
    _iicu_wikimyei->iicu_state.mewaajacune_in_use[_scene_index][_kline_index]=0x00;
}
void beseech_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei){
    beseech_mewaajacune(_iicu_wikimyei,gcsid(_iicu_wikimyei),gckid(_iicu_wikimyei));
}
void release_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"request to release_current_mewaajacune...\n");
    release_mewaajacune(_iicu_wikimyei,gcsid(_iicu_wikimyei),gckid(_iicu_wikimyei));
}


void beseech_kemu(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index,int _kline_index){
    // fprintf(stdout,"request to beseech_kemu...\n");
    Uint32 beseech_ctx=0x00;
    while(_iicu_wikimyei->iicu_state.kemu_in_use[_scene_index][_kline_index]){
        SDL_Delay(BESEECH_TIMEOUT);
        beseech_ctx++;
        if(beseech_ctx>BESEECH_MAX_RETRY){
            fprintf(stderr,"%s [ERROR] beseech_kemu index scene:[%d]:kline:[%d] exceed maxima timeout...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            fprintf(stderr,"%s [beseech_kemu] index scene:[%d]:kline:[%d] forcing release...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            break;
        }
    } // wait kemu to release
	_iicu_wikimyei->iicu_state.kemu_in_use[_scene_index][_kline_index]=0x01;
}
void release_kemu(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index){
    // fprintf(stdout,"request to release_kemu...\n");
    _iicu_wikimyei->iicu_state.kemu_in_use[_scene_index][_kline_index]=0x00;
}
void beseech_current_kemu(__iicu_wikimyei_t *_iicu_wikimyei){
    beseech_kemu(_iicu_wikimyei,gcsid(_iicu_wikimyei),gckid(_iicu_wikimyei));
}
void release_current_kemu(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"request to release_current_kemu...\n");
    release_kemu(_iicu_wikimyei,gcsid(_iicu_wikimyei),gckid(_iicu_wikimyei));
}

void beseech_all(__iicu_wikimyei_t *_iicu_wikimyei){
    for(int scene_idx; scene_idx<MAX_IICU_SCENES;scene_idx++){
        for(int kline_idx; kline_idx<BROKER_CANDLE_N_INTERVALS;kline_idx++){
            beseech_mewaajacune(_iicu_wikimyei, scene_idx, kline_idx);
            beseech_kemu(_iicu_wikimyei, scene_idx, kline_idx);
        }
    }
}
void release_all(__iicu_wikimyei_t *_iicu_wikimyei){
    for(int scene_idx; scene_idx<MAX_IICU_SCENES;scene_idx++){
        for(int kline_idx; kline_idx<BROKER_CANDLE_N_INTERVALS;kline_idx++){
            release_mewaajacune(_iicu_wikimyei, scene_idx, kline_idx);
            release_kemu(_iicu_wikimyei, scene_idx, kline_idx);
        }
    }
}
/*
	HANDLERS
*/
__iicu_scene_struct_t *get_current_scene(__iicu_wikimyei_t *_iicu_wikimyei){
    return &_iicu_wikimyei->iicu_scene[gcsid(_iicu_wikimyei)];
}
__iicu_scene_struct_t *giics(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_scene(_iicu_wikimyei);
}
__iicu_nijcyota_t *get_current_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei){
    return _iicu_wikimyei->iicu_scene[gcsid(_iicu_wikimyei)].nijcyota;
}
__iicu_nijcyota_t *giicn(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_nijcyota(_iicu_wikimyei);
}
__iicu_mewaajacune_t *get_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id){
    return _iicu_wikimyei->iicu_scene[_scene_id].mewaajacune[_kline_id];
}
__iicu_mewaajacune_t *get_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_mewaajacune(_iicu_wikimyei, 
        gcsid(_iicu_wikimyei),
        gckid(_iicu_wikimyei));
}
__iicu_mewaajacune_t *giicm(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_mewaajacune(_iicu_wikimyei);
}
__iicu_kemu_t *get_kemu(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id){
    return _iicu_wikimyei->iicu_scene[_scene_id].kemu[_kline_id];
}
__iicu_kemu_t *get_current_kemu(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_kemu(_iicu_wikimyei, 
        gcsid(_iicu_wikimyei),
        gckid(_iicu_wikimyei));
}
__iicu_kemu_t *giick(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_kemu(_iicu_wikimyei);
}