#include "iicu_wikimyei.h"

__iicu_wikimyei_t *iicu_wikimyei_fabric(){
    fprintf(stdout,"[cuwacunu:] : start : iicu_wikimyei_fabric()\n");
    __iicu_wikimyei_t *new_iicu_wikimyei=malloc(sizeof(__iicu_wikimyei_t));
    new_iicu_wikimyei->__obj_sdl=fabric_obj_sdl(); // must first initialize obj_sdl
    new_iicu_wikimyei->__iicu_state=fabric_iicu_state(new_iicu_wikimyei);
    fabric_all_iicu_scenes(new_iicu_wikimyei); // and tird scenes
    // #FIXME add fabric_all_iicu_jkimyeis or get rid of fabric_all_iicu_scenes (non trivial!)
    for(int scene_idx; scene_idx<MAX_IICU_SCENES;scene_idx++){ // four initialize the jkimyeis
        new_iicu_wikimyei->__iicu_jkimyei[scene_idx]=jkimyei_fabric();
    }
    fprintf(stdout,"[cuwacunu:] : start : iicu_wikimyei_fabric()\n");
    return new_iicu_wikimyei;
}
void destroy_iicu_wikimyei(__iicu_wikimyei_t *_iicu_wikimyei){
    for(int scene_idx; scene_idx<MAX_IICU_SCENES;scene_idx++){
        destroy_jkimyei(get_jkimyei(_iicu_wikimyei,scene_idx));
    }
    destroy_all_iicu_scenes(_iicu_wikimyei);
    destroy_iicu_state(get_state(_iicu_wikimyei));
	destroy_obj_sdl(_iicu_wikimyei->__obj_sdl);
    free(_iicu_wikimyei);
}
/*
	BESEECH (meaning: solicit access urgently)
*/
void beseech_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index,int _kline_index){
    // fprintf(stdout,"request to beseech_mewaajacune...\n");
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->mewaajacune_in_use[_scene_index][_kline_index]){
        SDL_Delay(BESEECH_TIMEOUT);
        beseech_ctx++;
        if(beseech_ctx>BESEECH_MAX_RETRY){
            fprintf(stderr,"%s [ERROR] beseech_mewaajacune index scene:[%d]:kline:[%d] exceed maxima timeout...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            fprintf(stderr,"%s [beseech_mewaajacune] index scene:[%d]:kline:[%d] forcing release...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            break;
        }
    } // wait mewaajacune to release
	get_state(_iicu_wikimyei)->mewaajacune_in_use[_scene_index][_kline_index]=0x01;
}
void release_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index){
    // fprintf(stdout,"request to release_mewaajacune...\n");
    get_state(_iicu_wikimyei)->mewaajacune_in_use[_scene_index][_kline_index]=0x00;
}
void beseech_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei){
    beseech_mewaajacune(_iicu_wikimyei,gcsid(_iicu_wikimyei),gcklid(_iicu_wikimyei));
}
void release_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"request to release_current_mewaajacune...\n");
    release_mewaajacune(_iicu_wikimyei,gcsid(_iicu_wikimyei),gcklid(_iicu_wikimyei));
}

void beseech_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index){
    // fprintf(stdout,"request to beseech_jkimyei...\n");
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->jkimyei_in_use[_scene_index]){
        SDL_Delay(BESEECH_TIMEOUT);
        beseech_ctx++;
        if(beseech_ctx>BESEECH_MAX_RETRY){
            fprintf(stderr,"%s [ERROR] beseech_jkimyei index scene:[%d] exceed maxima timeout...%s\n",COLOR_DANGER,_scene_index,COLOR_REGULAR);
            fprintf(stderr,"%s [beseech_jkimyei] index scene:[%d] forcing release...%s\n",COLOR_DANGER,_scene_index,COLOR_REGULAR);
            break;
        }
    } // wait kemu to release
	get_state(_iicu_wikimyei)->jkimyei_in_use[_scene_index]=0x01;
}
void release_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index){
    get_state(_iicu_wikimyei)->jkimyei_in_use[_scene_index]=0x00;
}
void beseech_current_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei){
    beseech_jkimyei(_iicu_wikimyei,gcsid(_iicu_wikimyei));
}
void release_current_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei){
    release_jkimyei(_iicu_wikimyei,gcsid(_iicu_wikimyei));
}

void beseech_regressive(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index,int _kline_index){
    // fprintf(stdout,"request to beseech_regressive...\n");
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->regressive_in_use[_scene_index][_kline_index]){
        SDL_Delay(BESEECH_TIMEOUT);
        beseech_ctx++;
        if(beseech_ctx>BESEECH_MAX_RETRY){
            fprintf(stderr,"%s [ERROR] beseech_regressive index scene:[%d]:kline:[%d] exceed maxima timeout...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            fprintf(stderr,"%s [beseech_regressive] index scene:[%d]:kline:[%d] forcing release...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            break;
        }
    } // wait regressive to release
	get_state(_iicu_wikimyei)->regressive_in_use[_scene_index][_kline_index]=0x01;
}
void release_regressive(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index){
    // fprintf(stdout,"request to release_regressive...\n");
    get_state(_iicu_wikimyei)->regressive_in_use[_scene_index][_kline_index]=0x00;
}
void beseech_current_regressive(__iicu_wikimyei_t *_iicu_wikimyei){
    beseech_regressive(_iicu_wikimyei,gcsid(_iicu_wikimyei),gcklid(_iicu_wikimyei));
}
void release_current_regressive(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"request to release_current_regressive...\n");
    release_regressive(_iicu_wikimyei,gcsid(_iicu_wikimyei),gcklid(_iicu_wikimyei));
}

void beseech_polinomial(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index,int _kline_index){
    // fprintf(stdout,"request to beseech_polinomial...\n");
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->polinomial_in_use[_scene_index][_kline_index]){
        SDL_Delay(BESEECH_TIMEOUT);
        beseech_ctx++;
        if(beseech_ctx>BESEECH_MAX_RETRY){
            fprintf(stderr,"%s [ERROR] beseech_polinomial index scene:[%d]:kline:[%d] exceed maxima timeout...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            fprintf(stderr,"%s [beseech_polinomial] index scene:[%d]:kline:[%d] forcing release...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            break;
        }
    } // wait polinomial to release
	get_state(_iicu_wikimyei)->polinomial_in_use[_scene_index][_kline_index]=0x01;
}
void release_polinomial(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index){
    // fprintf(stdout,"request to release_polinomial...\n");
    get_state(_iicu_wikimyei)->polinomial_in_use[_scene_index][_kline_index]=0x00;
}
void beseech_current_polinomial(__iicu_wikimyei_t *_iicu_wikimyei){
    beseech_polinomial(_iicu_wikimyei,gcsid(_iicu_wikimyei),gcklid(_iicu_wikimyei));
}
void release_current_polinomial(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"request to release_current_polinomial...\n");
    release_polinomial(_iicu_wikimyei,gcsid(_iicu_wikimyei),gcklid(_iicu_wikimyei));
}

void beseech_staticques(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index,int _kline_index){
    // fprintf(stdout,"request to beseech_staticques...\n");
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->staticques_in_use[_scene_index][_kline_index]){
        SDL_Delay(BESEECH_TIMEOUT);
        beseech_ctx++;
        if(beseech_ctx>BESEECH_MAX_RETRY){
            fprintf(stderr,"%s [ERROR] beseech_staticques index scene:[%d]:kline:[%d] exceed maxima timeout...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            fprintf(stderr,"%s [beseech_staticques] index scene:[%d]:kline:[%d] forcing release...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
            break;
        }
    } // wait staticques to release
	get_state(_iicu_wikimyei)->staticques_in_use[_scene_index][_kline_index]=0x01;
}
void release_staticques(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index){
    // fprintf(stdout,"request to release_staticques...\n");
    get_state(_iicu_wikimyei)->staticques_in_use[_scene_index][_kline_index]=0x00;
}
void beseech_current_staticques(__iicu_wikimyei_t *_iicu_wikimyei){
    beseech_staticques(_iicu_wikimyei,gcsid(_iicu_wikimyei),gcklid(_iicu_wikimyei));
}
void release_current_staticques(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"request to release_current_staticques...\n");
    release_staticques(_iicu_wikimyei,gcsid(_iicu_wikimyei),gcklid(_iicu_wikimyei));
}


void beseech_current_all(__iicu_wikimyei_t *_iicu_wikimyei){
    beseech_current_jkimyei(_iicu_wikimyei);
    beseech_current_mewaajacune(_iicu_wikimyei);
    beseech_current_staticques(_iicu_wikimyei);
    beseech_current_regressive(_iicu_wikimyei);
    beseech_current_polinomial(_iicu_wikimyei);
}
void release_current_all(__iicu_wikimyei_t *_iicu_wikimyei){
    release_current_jkimyei(_iicu_wikimyei);
    release_current_mewaajacune(_iicu_wikimyei);
    release_current_staticques(_iicu_wikimyei);
    release_current_regressive(_iicu_wikimyei);
    release_current_polinomial(_iicu_wikimyei);
}
void beseech_all(__iicu_wikimyei_t *_iicu_wikimyei){
    for(int scene_idx; scene_idx<MAX_IICU_SCENES;scene_idx++){
        beseech_jkimyei(_iicu_wikimyei,scene_idx);
        for(int kline_idx; kline_idx<BROKER_CANDLE_N_INTERVALS;kline_idx++){
            beseech_mewaajacune(_iicu_wikimyei, scene_idx, kline_idx);
            beseech_staticques(_iicu_wikimyei, scene_idx, kline_idx);
            beseech_regressive(_iicu_wikimyei, scene_idx, kline_idx);
            beseech_polinomial(_iicu_wikimyei, scene_idx, kline_idx);
        }
    }
}
void release_all(__iicu_wikimyei_t *_iicu_wikimyei){
    for(int scene_idx; scene_idx<MAX_IICU_SCENES;scene_idx++){
        release_jkimyei(_iicu_wikimyei,scene_idx);
        for(int kline_idx; kline_idx<BROKER_CANDLE_N_INTERVALS;kline_idx++){
            release_mewaajacune(_iicu_wikimyei, scene_idx, kline_idx);
            release_staticques(_iicu_wikimyei, scene_idx, kline_idx);
            release_regressive(_iicu_wikimyei, scene_idx, kline_idx);
            release_polinomial(_iicu_wikimyei, scene_idx, kline_idx);
        }
    }
}
/*
	HANDLERS
*/
__iicu_scene_struct_t *get_current_scene(__iicu_wikimyei_t *_iicu_wikimyei){
    return _iicu_wikimyei->__iicu_scene[gcsid(_iicu_wikimyei)];
}
__iicu_scene_struct_t *giics(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_scene(_iicu_wikimyei);
}


__iicu_nijcyota_t *get_current_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei){
    return _iicu_wikimyei->__iicu_scene[gcsid(_iicu_wikimyei)]->nijcyota;
}
__iicu_nijcyota_t *giicn(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_nijcyota(_iicu_wikimyei);
}



__iicu_mewaajacune_t *get_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id){
    return _iicu_wikimyei->__iicu_scene[_scene_id]->mewaajacune[_kline_id];
}
__iicu_mewaajacune_t *get_current_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_mewaajacune(_iicu_wikimyei, 
        gcsid(_iicu_wikimyei),
        gcklid(_iicu_wikimyei));
}
__iicu_mewaajacune_t *giicm(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_mewaajacune(_iicu_wikimyei);
}


__iicu_jkimyei_t *get_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id){
    return _iicu_wikimyei->__iicu_jkimyei[_scene_id];
}
__iicu_jkimyei_t *get_current_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME always the same jkimyei
    return get_jkimyei(_iicu_wikimyei,gcsid(_iicu_wikimyei));
}
__iicu_jkimyei_t *giicjk(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_jkimyei(_iicu_wikimyei);
}


__iicu_regressive_t *get_regressive(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id){
    return _iicu_wikimyei->__iicu_scene[_scene_id]->__iicu_regressive[_kline_id];
}
__iicu_regressive_t *get_current_regressive(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_regressive(_iicu_wikimyei, 
        gcsid(_iicu_wikimyei),
        gcklid(_iicu_wikimyei));
}
__iicu_regressive_t *giicrg(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_staticques(_iicu_wikimyei);
}


__iicu_polinomial_t *get_polinomial(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id){
    return _iicu_wikimyei->__iicu_scene[_scene_id]->__iicu_polinomial[_kline_id];
}
__iicu_polinomial_t *get_current_polinomial(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_polinomial(_iicu_wikimyei, 
        gcsid(_iicu_wikimyei),
        gcklid(_iicu_wikimyei));
}
__iicu_polinomial_t *giicpl(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_staticques(_iicu_wikimyei);
}


__iicu_staticques_t *get_staticques(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id){
    return _iicu_wikimyei->__iicu_scene[_scene_id]->__iicu_staticques[_kline_id];
}
__iicu_staticques_t *get_current_staticques(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_staticques(_iicu_wikimyei, 
        gcsid(_iicu_wikimyei),
        gcklid(_iicu_wikimyei));
}
__iicu_staticques_t *giicsq(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_staticques(_iicu_wikimyei);
}

__iicu_state_struct_t *get_state(__iicu_wikimyei_t *_iicu_wikimyei){
    return _iicu_wikimyei->__iicu_state;
}

__jkimyei_thread_order_t *get_jk_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _jk_id){
    return ((__jkimyei_thread_order_t*)get_state(_iicu_wikimyei)->__jk_thread_order[_jk_id]);
}

__iicu_regressive_thread_order_t *get_rg_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _rg_id){
    return ((__iicu_regressive_thread_order_t*)get_state(_iicu_wikimyei)->__rg_thread_order[_rg_id]);
}

__iicu_polinomial_thread_order_t *get_pl_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _pl_id){
    return ((__iicu_polinomial_thread_order_t*)get_state(_iicu_wikimyei)->__pl_thread_order[_pl_id]);
}

int get_current_scene_id(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_state(_iicu_wikimyei)->scene_id;
}
int gcsid(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_scene_id(_iicu_wikimyei);
}
int get_current_kline_id(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_state(_iicu_wikimyei)->kline_id[gcsid(_iicu_wikimyei)];
}
int gcklid(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_kline_id(_iicu_wikimyei);
}
