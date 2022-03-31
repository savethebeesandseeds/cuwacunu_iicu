#include "iicu_wikimyei.h"

__iicu_wikimyei_t *iicu_wikimyei_fabric(){
    fprintf(stdout,"[cuwacunu:] : start : iicu_wikimyei_fabric()\n");
    __iicu_wikimyei_t *new_iicu_wikimyei=malloc(sizeof(__iicu_wikimyei_t));
    new_iicu_wikimyei->__obj_sdl=fabric_obj_sdl(); // must first initialize obj_sdl
    new_iicu_wikimyei->__iicu_state=fabric_iicu_state(new_iicu_wikimyei);
    fabric_all_iicu_scenes(new_iicu_wikimyei); // and tird scenes
    new_iicu_wikimyei->__wk_tsaave=itsaave_fabric(NULL);
    fprintf(stdout,"[cuwacunu:] : end : iicu_wikimyei_fabric()\n");
    return new_iicu_wikimyei;
}
void destroy_iicu_wikimyei(__iicu_wikimyei_t *_iicu_wikimyei){
    destroy_all_iicu_scenes(_iicu_wikimyei);
    destroy_iicu_state(get_state(_iicu_wikimyei));
	destroy_obj_sdl(_iicu_wikimyei->__obj_sdl);
    destroy_itsaave(_iicu_wikimyei->__wk_tsaave);
    free(_iicu_wikimyei);
}
/*
	BESEECH (meaning: solicit access urgently)
*/
void beseech_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index,int _kline_index){
    // fprintf(stdout,"request to beseech_mewaajacune...\n");
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->mewaajacune_in_use[_scene_index][_kline_index]){
        SDL_Delay((Uint32)((((__cwcn_type_t)BESEECH_TIMEOUT))*max_min_res_rand(2.0, 0.5, 200)));
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

void beseech_scene_itsaave(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index){
    // fprintf(stdout,"request to beseech_scene_itsaave...\n");
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->scene_itsaave_in_use[_scene_index]){
        SDL_Delay((Uint32)((((__cwcn_type_t)BESEECH_TIMEOUT))*max_min_res_rand(2.0, 0.5, 200)));
        beseech_ctx++;
        if(beseech_ctx>BESEECH_MAX_RETRY){
            fprintf(stderr,"%s [ERROR] beseech_scene_itsaave index scene:[%d] exceed maxima timeout...%s\n",COLOR_DANGER,_scene_index,COLOR_REGULAR);
            fprintf(stderr,"%s [beseech_scene_itsaave] index scene:[%d] forcing release...%s\n",COLOR_DANGER,_scene_index,COLOR_REGULAR);
            break;
        }
    } // wait kemu to release
	get_state(_iicu_wikimyei)->scene_itsaave_in_use[_scene_index]=0x01;
}
void release_scene_itsaave(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index){
    get_state(_iicu_wikimyei)->scene_itsaave_in_use[_scene_index]=0x00;
}

void beseech_wk_itsaave(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"request to beseech_wk_itsaave...\n");
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->wk_itsaave_in_use){
        SDL_Delay((Uint32)((((__cwcn_type_t)BESEECH_TIMEOUT))*max_min_res_rand(2.0, 0.5, 200)));
        beseech_ctx++;
        if(beseech_ctx>BESEECH_MAX_RETRY){
            fprintf(stderr,"%s [ERROR] beseech_wk_itsaave exceed maxima timeout...%s\n",COLOR_DANGER,COLOR_REGULAR);
            fprintf(stderr,"%s [beseech_wk_itsaave] forcing release...%s\n",COLOR_DANGER,COLOR_REGULAR);
            break;
        }
    } // wait kemu to release
	get_state(_iicu_wikimyei)->wk_itsaave_in_use=0x01;
}
void release_wk_itsaave(__iicu_wikimyei_t *_iicu_wikimyei){
	get_state(_iicu_wikimyei)->wk_itsaave_in_use=0x00;
}

void beseech_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index){
    // fprintf(stdout,"request to beseech_jkimyei...\n");
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->jkimyei_in_use[_scene_index]){
        SDL_Delay((Uint32)((((__cwcn_type_t)BESEECH_TIMEOUT))*max_min_res_rand(2.0, 0.5, 200)));
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

void beseech_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei){
    // fprintf(stdout,"request to beseech_nijcyota...\n");
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->nijcyota_in_use){
        SDL_Delay((Uint32)((((__cwcn_type_t)BESEECH_TIMEOUT))*max_min_res_rand(2.0, 0.5, 200)));
        beseech_ctx++;
        if(beseech_ctx>BESEECH_MAX_RETRY){
            fprintf(stderr,"%s [ERROR] beseech_nijcyota exceed maxima timeout...%s\n",COLOR_DANGER,COLOR_REGULAR);
            fprintf(stderr,"%s [beseech_nijcyota] forcing release...%s\n",COLOR_DANGER,COLOR_REGULAR);
            break;
        }
    } // wait kemu to release
	get_state(_iicu_wikimyei)->nijcyota_in_use=0x01;
}
void release_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei){
	get_state(_iicu_wikimyei)->nijcyota_in_use=0x00;
}
void beseech_current_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei){
    beseech_nijcyota(_iicu_wikimyei);
}
void release_current_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei){
	release_nijcyota(_iicu_wikimyei);
}

void beseech_regressive(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index,int _kline_index){
    // fprintf(stdout,"request to beseech_regressive...\n");
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->regressive_in_use[_scene_index][_kline_index]){
        SDL_Delay((Uint32)((((__cwcn_type_t)BESEECH_TIMEOUT))*max_min_res_rand(2.0, 0.5, 200)));
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
        SDL_Delay((Uint32)((((__cwcn_type_t)BESEECH_TIMEOUT))*max_min_res_rand(2.0, 0.5, 200)));
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

void beseech_staticques(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_index, int _kline_index){
    // fprintf(stderr,"%s beseech_staticques index scene:[%d]:kline:[%d]...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
    Uint32 beseech_ctx=0x00;
    while(get_state(_iicu_wikimyei)->staticques_in_use[_scene_index][_kline_index]){
        SDL_Delay((Uint32)((((__cwcn_type_t)BESEECH_TIMEOUT))*max_min_res_rand(2.0, 0.5, 200)));
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
    // fprintf(stderr,"%s release_staticques index scene:[%d]:kline:[%d]...%s\n",COLOR_DANGER,_scene_index,_kline_index,COLOR_REGULAR);
    get_state(_iicu_wikimyei)->staticques_in_use[_scene_index][_kline_index]=0x00;
}
void beseech_current_staticques(__iicu_wikimyei_t *_iicu_wikimyei){
    beseech_staticques(_iicu_wikimyei,gcsid(_iicu_wikimyei),gcklid(_iicu_wikimyei));
}
void release_current_staticques(__iicu_wikimyei_t *_iicu_wikimyei){
    release_staticques(_iicu_wikimyei,gcsid(_iicu_wikimyei),gcklid(_iicu_wikimyei));
}

void beseech_current_all(__iicu_wikimyei_t *_iicu_wikimyei){
    // #FIXME missing tsaave
    beseech_wk_itsaave(_iicu_wikimyei);
    beseech_scene_itsaave(_iicu_wikimyei,gcsid(_iicu_wikimyei));
    beseech_current_nijcyota(_iicu_wikimyei);
    beseech_current_jkimyei(_iicu_wikimyei);
    beseech_current_mewaajacune(_iicu_wikimyei);
    beseech_current_staticques(_iicu_wikimyei);
    beseech_current_regressive(_iicu_wikimyei);
    beseech_current_polinomial(_iicu_wikimyei);
}
void release_current_all(__iicu_wikimyei_t *_iicu_wikimyei){
    // #FIXME missing tsaave
    release_wk_itsaave(_iicu_wikimyei);
    release_scene_itsaave(_iicu_wikimyei,gcsid(_iicu_wikimyei));
    release_current_nijcyota(_iicu_wikimyei);
    release_current_jkimyei(_iicu_wikimyei);
    release_current_mewaajacune(_iicu_wikimyei);
    release_current_staticques(_iicu_wikimyei);
    release_current_regressive(_iicu_wikimyei);
    release_current_polinomial(_iicu_wikimyei);
}
void beseech_all(__iicu_wikimyei_t *_iicu_wikimyei){
    beseech_current_nijcyota(_iicu_wikimyei);
    beseech_wk_itsaave(_iicu_wikimyei);
    for(int scene_idx=0x00; scene_idx<MAX_IICU_SCENES;scene_idx++){
        beseech_jkimyei(_iicu_wikimyei,scene_idx);
        beseech_scene_itsaave(_iicu_wikimyei, scene_idx);
        for(int kline_idx=0x00; kline_idx<BROKER_CANDLE_N_INTERVALS;kline_idx++){
            beseech_mewaajacune(_iicu_wikimyei, scene_idx, kline_idx);
            beseech_staticques(_iicu_wikimyei, scene_idx, kline_idx);
            beseech_regressive(_iicu_wikimyei, scene_idx, kline_idx);
            beseech_polinomial(_iicu_wikimyei, scene_idx, kline_idx);
        }
    }
}
void release_all(__iicu_wikimyei_t *_iicu_wikimyei){
    release_current_nijcyota(_iicu_wikimyei);
    release_wk_itsaave(_iicu_wikimyei);
    for(int scene_idx=0x00; scene_idx<MAX_IICU_SCENES;scene_idx++){
        release_jkimyei(_iicu_wikimyei,scene_idx);
        release_scene_itsaave(_iicu_wikimyei, scene_idx);
        for(int kline_idx=0x00; kline_idx<BROKER_CANDLE_N_INTERVALS;kline_idx++){
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

__iicu_scene_struct_t *get_scene(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id){
    // if(get_state(_iicu_wikimyei)->scene_in_use[_scene_id]!=0x01){ // not beseech
    //     fprintf(stderr,"[%sERROR:%s] scene access on get_scene() was not beseech.\n",COLOR_DANGER,COLOR_REGULAR);
        // #ifndef LOWFORCE_BEESECH
        // return NULL;
        // #endif
    // }
    return _iicu_wikimyei->__iicu_scene[_scene_id];
}
__iicu_scene_struct_t *get_current_scene(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_scene(_iicu_wikimyei, gcsid(_iicu_wikimyei));
}
__iicu_scene_struct_t *giics(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_scene(_iicu_wikimyei);
}

__iicu_itsaave_t *get_wk_itsaave(__iicu_wikimyei_t *_iicu_wikimyei){
    if(get_state(_iicu_wikimyei)->wk_itsaave_in_use!=0x01){ // not beseech
        fprintf(stderr,"[%sERROR:%s] itsaave access on get_wk_itsaave() was not beseech.\n",COLOR_DANGER,COLOR_REGULAR);
        #ifndef LOWFORCE_BEESECH
        return NULL;
        #endif
    }
    return _iicu_wikimyei->__wk_tsaave;
}
__iicu_itsaave_t *get_scene_itsaave(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id){
    if(get_state(_iicu_wikimyei)->scene_itsaave_in_use[_scene_id]!=0x01){ // not beseech
        fprintf(stderr,"[%sERROR:%s] itsaave access on get_scene_itsaave() was not beseech.\n",COLOR_DANGER,COLOR_REGULAR);
        #ifndef LOWFORCE_BEESECH
        return NULL;
        #endif
    }
    return get_scene(_iicu_wikimyei, _scene_id)->__scene_itsaave;
}

__iicu_nijcyota_t *get_current_nijcyota(__iicu_wikimyei_t *_iicu_wikimyei){
    if(get_state(_iicu_wikimyei)->nijcyota_in_use!=0x01){ // not beseech
        fprintf(stderr,"[%sERROR:%s] nijcyota access on get_current_nijcyota() was not beseech.\n",COLOR_DANGER,COLOR_REGULAR);
        #ifndef LOWFORCE_BEESECH
        return NULL;
        #endif
    }
    return _iicu_wikimyei->__iicu_scene[gcsid(_iicu_wikimyei)]->__nijcyota;
}
__iicu_nijcyota_t *giicn(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_nijcyota(_iicu_wikimyei);
}



__iicu_mewaajacune_t *get_mewaajacune(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id){
    if(get_state(_iicu_wikimyei)->mewaajacune_in_use[_scene_id][_kline_id]!=0x01){
        fprintf(stderr,"[%sERROR:%s] mewaajacune access on get_mewaajacune() was not beseech.\n",COLOR_DANGER,COLOR_REGULAR);
        #ifndef LOWFORCE_BEESECH
        return NULL;
        #endif
    }
    return _iicu_wikimyei->__iicu_scene[_scene_id]->__mewaajacune[_kline_id];
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
    if(get_state(_iicu_wikimyei)->jkimyei_in_use[_scene_id]!=0x01){
        fprintf(stderr,"[%sERROR:%s] jkimyei access on get_jkimyei() was not beseech.\n",COLOR_DANGER,COLOR_REGULAR);
        #ifndef LOWFORCE_BEESECH
        return NULL;
        #endif
    }
    return get_scene(_iicu_wikimyei,_scene_id)->__iicu_jkimyei;
}
__iicu_jkimyei_t *get_current_jkimyei(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME always the same jkimyei
    return get_jkimyei(_iicu_wikimyei,gcsid(_iicu_wikimyei));
}
__iicu_jkimyei_t *giicjk(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_jkimyei(_iicu_wikimyei);
}


__iicu_regressive_t *get_regressive(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id){
    if(get_state(_iicu_wikimyei)->regressive_in_use[_scene_id][_kline_id]!=0x01){
        fprintf(stderr,"[%sERROR:%s] regressive access on get_regressive() was not beseech.\n",COLOR_DANGER,COLOR_REGULAR);
        #ifndef LOWFORCE_BEESECH
        return NULL;
        #endif
    }
    return _iicu_wikimyei->__iicu_scene[_scene_id]->__iicu_regressive[_kline_id];
}
__iicu_regressive_t *get_current_regressive(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_regressive(_iicu_wikimyei, 
        gcsid(_iicu_wikimyei),
        gcklid(_iicu_wikimyei));
}
__iicu_regressive_t *giicrg(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_regressive(_iicu_wikimyei);
}


__iicu_polinomial_t *get_polinomial(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id){
    if(get_state(_iicu_wikimyei)->polinomial_in_use[_scene_id][_kline_id]!=0x01){
        fprintf(stderr,"[%sERROR:%s] polinomial access on get_polinomial() was not beseech.\n",COLOR_DANGER,COLOR_REGULAR);
        #ifndef LOWFORCE_BEESECH
        return NULL;
        #endif
    }
    return _iicu_wikimyei->__iicu_scene[_scene_id]->__iicu_polinomial[_kline_id];
}
__iicu_polinomial_t *get_current_polinomial(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_polinomial(_iicu_wikimyei, 
        gcsid(_iicu_wikimyei),
        gcklid(_iicu_wikimyei));
}
__iicu_polinomial_t *giicpl(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_polinomial(_iicu_wikimyei);
}


__iicu_staticques_t *get_staticques(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id,int _kline_id){
    if(get_state(_iicu_wikimyei)->staticques_in_use[_scene_id][_kline_id]!=0x01){
        fprintf(stderr,"[%sERROR:%s] staticques access on get_staticques() was not beseech.\n",COLOR_DANGER,COLOR_REGULAR);
        #ifndef LOWFORCE_BEESECH
        return NULL;
        #endif
    }
    return _iicu_wikimyei->__iicu_scene[_scene_id]->__iicu_staticques[_kline_id];
}
__iicu_staticques_t *get_current_staticques(__iicu_wikimyei_t *_iicu_wikimyei){ // #FIXME not in use
    return get_staticques(_iicu_wikimyei, 
        gcsid(_iicu_wikimyei),
        gcklid(_iicu_wikimyei));
}
__iicu_staticques_t *giicsq(__iicu_wikimyei_t *_iicu_wikimyei){
    return get_current_staticques(_iicu_wikimyei);
}

__iicu_state_struct_t *get_state(__iicu_wikimyei_t *_iicu_wikimyei){
    // if(get_state(_iicu_wikimyei)->state_in_use[_scene_id][_kline_id]!=0x01){
    //     fprintf(stderr,"[%sERROR:%s] state access on get_state() was not beseech.\n",COLOR_DANGER,COLOR_REGULAR);
    #ifndef LOWFORCE_BEESECH
    //     return NULL;
    #endif
    // }
    return _iicu_wikimyei->__iicu_state;
}

__jkimyei_thread_order_t *get_jk_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _jk_id){
    return ((__jkimyei_thread_order_t*)get_state(_iicu_wikimyei)->__jk_thread_order[_jk_id]);
}

__regressive_thread_order_t *get_rg_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _rg_id){
    return ((__regressive_thread_order_t*)get_state(_iicu_wikimyei)->__rg_thread_order[_rg_id]);
}

__polinomial_thread_order_t *get_pl_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _pl_id){
    return ((__polinomial_thread_order_t*)get_state(_iicu_wikimyei)->__pl_thread_order[_pl_id]);
}
__staticques_thread_order_t *get_sq_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _sq_id){
    return ((__staticques_thread_order_t*)get_state(_iicu_wikimyei)->__sq_thread_order[_sq_id]);
}
__itsaave_thread_order_t *get_it_thread_order(__iicu_wikimyei_t *_iicu_wikimyei, int _it_id){
    return ((__itsaave_thread_order_t*)get_state(_iicu_wikimyei)->__it_thread_order[_it_id]);
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

void wait_scene_kline_load(__iicu_wikimyei_t *_iicu_wikimyei, int _scene_id, int _kline_id){
    int wait_ctx=0x00;
    while(get_state(_iicu_wikimyei)->kline_last_update[_scene_id][_kline_id]==0x00){
        SDL_Delay(1500);
        wait_ctx++;
        if(wait_ctx>1000){
            fprintf(stderr,"%s [ERROR] wait_scene_kline_load index scene:[%d]: kline:[%d] exceed maxima timeout...%s\n",COLOR_DANGER,_scene_id,_kline_id,COLOR_REGULAR);
            break;
        }
    }
}