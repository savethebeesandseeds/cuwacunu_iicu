#include "iicu_scene_utils.h"
// ---------- SCENE --- --- --- --- --- --- --- 
void fabric_iicu_scene(__iicu_scene_struct_t *_iicu_scene){
	// --- --- --- NIJCYOTA
	_iicu_scene->nijcyota=nijcyota_fabric();
	// --- --- --- MEWAAJACUNE
	for(int m_idx=0;m_idx<BROKER_CANDLE_N_INTERVALS;m_idx++){
		_iicu_scene->mewaajacune[m_idx]=mewaajacune_fabric();
		_iicu_scene->kemu[m_idx]=kemu_fabric();
	}
}
void fabric_all_iicu_scenes(__iicu_wikimyei_t *_iicu_wikimyei){
	if(_iicu_wikimyei->iicu_state.scene_count!=0 || gcsid(_iicu_wikimyei)!=0){
		fprintf(stderr,"ERROR :: fabric_all_iicu_scenes :: request failed\n");
		assert(0x00);
	}
	while(_iicu_wikimyei->iicu_state.scene_count<MAX_IICU_SCENES){
		// --- --- --- 
		_iicu_wikimyei->iicu_state.scene_id=_iicu_wikimyei->iicu_state.scene_count;
		// --- --- --- 
		fabric_iicu_scene(giics(_iicu_wikimyei));
		// --- --- --- 
		for(int idx_interval=0;idx_interval<BROKER_CANDLE_N_INTERVALS;idx_interval++){
			_iicu_wikimyei->iicu_state.kline_last_update[_iicu_wikimyei->iicu_state.scene_count][idx_interval]=0x00;
		}
		_iicu_wikimyei->iicu_state.kline_id[_iicu_wikimyei->iicu_state.scene_count]=0x00;
		// --- --- ---
		_iicu_wikimyei->iicu_state.scene_count++;
	}
	_iicu_wikimyei->iicu_state.scene_id=0x00;
	strcpy(_iicu_wikimyei->iicu_state.scene_symbol,IICU_SCENES_SYMBOLS[gcsid(_iicu_wikimyei)]);
}
void update_current_iicu_scene(__iicu_wikimyei_t *_iicu_wikimyei){
	beseech_current_mewaajacune(_iicu_wikimyei);
	update_iicu_mewaajacune(giicm(_iicu_wikimyei));	
	release_current_mewaajacune(_iicu_wikimyei);

    update_iicu_nicjyota(giicn(_iicu_wikimyei)); // #FIXME add beseech nijcyota
	
	beseech_current_kemu(_iicu_wikimyei);
    update_iicu_kemu(giick(_iicu_wikimyei));
	release_current_kemu(_iicu_wikimyei);
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
	for(int m_idx=0;m_idx<BROKER_CANDLE_N_INTERVALS;m_idx++){
		destroy_mewaajacune(_iicu_scene->mewaajacune[m_idx]);
		destroy_kemu(_iicu_scene->kemu[m_idx]);
	}
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
	assert(gcsid(_iicu_wikimyei)==0x00);
}


void iicu_scene_go_up(__iicu_wikimyei_t *_iicu_wikimyei){
	if(gcsid(_iicu_wikimyei)<_iicu_wikimyei->iicu_state.scene_count-0x01){
		_iicu_wikimyei->iicu_state.scene_id++;
	} else {
		_iicu_wikimyei->iicu_state.scene_id=0x00;
	}
	strcpy(_iicu_wikimyei->iicu_state.scene_symbol,IICU_SCENES_SYMBOLS[gcsid(_iicu_wikimyei)]);
}
void iicu_scene_go_down(__iicu_wikimyei_t *_iicu_wikimyei){
	if(gcsid(_iicu_wikimyei)>0x00){
		_iicu_wikimyei->iicu_state.scene_id--;
	} else {
		_iicu_wikimyei->iicu_state.scene_id=_iicu_wikimyei->iicu_state.scene_count-0x01;
	}
	strcpy(_iicu_wikimyei->iicu_state.scene_symbol,IICU_SCENES_SYMBOLS[gcsid(_iicu_wikimyei)]);
}

void iicu_klines_increse(__iicu_wikimyei_t *_iicu_wikimyei){
	if(gckid(_iicu_wikimyei)<BROKER_CANDLE_N_INTERVALS-0x01){
		_iicu_wikimyei->iicu_state.kline_id[gcsid(_iicu_wikimyei)]++;
	} else {
		_iicu_wikimyei->iicu_state.kline_id[gcsid(_iicu_wikimyei)]=0x00;
	}
	#ifdef __COORDINATE_ALL_KLINES_IN_SCENES__
	for(int scene_idx=0x00;scene_idx<MAX_IICU_SCENES;scene_idx++){
		_iicu_wikimyei->iicu_state.kline_id[scene_idx]=_iicu_wikimyei->iicu_state.kline_id[gcsid(_iicu_wikimyei)];
	}
	#endif
}
void iicu_klines_decrese(__iicu_wikimyei_t *_iicu_wikimyei){
	if(gckid(_iicu_wikimyei)>0x00){
		_iicu_wikimyei->iicu_state.kline_id[gcsid(_iicu_wikimyei)]--;
	} else {
		_iicu_wikimyei->iicu_state.kline_id[gcsid(_iicu_wikimyei)]=BROKER_CANDLE_N_INTERVALS-0x01;
	}
	#ifdef __COORDINATE_ALL_KLINES_IN_SCENES__
	for(int scene_idx=0x00;scene_idx<MAX_IICU_SCENES;scene_idx++){
		_iicu_wikimyei->iicu_state.kline_id[scene_idx]=_iicu_wikimyei->iicu_state.kline_id[gcsid(_iicu_wikimyei)];
	}
	#endif
}