#include "iicu_scene_utils.h"
// ---------- SCENE --- --- --- --- --- --- --- 
__iicu_scene_struct_t *iicu_scene_fabric(){
	__iicu_scene_struct_t *new_scene=malloc(sizeof(__iicu_scene_struct_t));
	// --- --- --- JKIMYEI
	new_scene->__iicu_jkimyei=jkimyei_fabric();
	// --- --- --- ITSAAVE
	new_scene->__scene_itsaave=itsaave_fabric(new_scene->__iicu_jkimyei->__jk_inteligent_order_policy);
	// --- --- --- NIJCYOTA
	new_scene->__nijcyota=nijcyota_fabric();
	// --- --- --- MEWAAJACUNE
	for(int m_idx=0x00;m_idx<BROKER_CANDLE_N_INTERVALS;m_idx++){
		new_scene->__mewaajacune[m_idx]=mewaajacune_fabric();
		new_scene->__iicu_regressive[m_idx]=regressive_fabric();
		new_scene->__iicu_polinomial[m_idx]=polinomial_fabric();
	}
	// --- --- --- STATICQUES
	new_scene->__iicu_staticques=staticques_fabric();
	return new_scene;
}
void fabric_all_iicu_scenes(__iicu_wikimyei_t *_iicu_wikimyei){
	if(get_state(_iicu_wikimyei)->scene_count!=0 || gcsid(_iicu_wikimyei)!=0){
		fprintf(stderr,"ERROR :: fabric_all_iicu_scenes :: fabric request failed\n");
		assert(0x00);
	}
	while(get_state(_iicu_wikimyei)->scene_count<MAX_IICU_SCENES){
		// --- --- --- 
		get_state(_iicu_wikimyei)->scene_id=get_state(_iicu_wikimyei)->scene_count;
		// --- --- --- 
		_iicu_wikimyei->__iicu_scene[get_state(_iicu_wikimyei)->scene_count]=iicu_scene_fabric();
		// --- --- --- 
		for(int idx_interval=0x00;idx_interval<BROKER_CANDLE_N_INTERVALS;idx_interval++){
			get_state(_iicu_wikimyei)->kline_last_update[get_state(_iicu_wikimyei)->scene_count][idx_interval]=0x00;
		}
		get_state(_iicu_wikimyei)->kline_id[get_state(_iicu_wikimyei)->scene_count]=0x00;
		// --- --- ---
		get_state(_iicu_wikimyei)->scene_count++;
	}
	get_state(_iicu_wikimyei)->scene_id=0x00;
	strcpy(get_state(_iicu_wikimyei)->scene_symbol,IICU_SCENES_SYMBOLS[gcsid(_iicu_wikimyei)]);
}
void update_current_iicu_scene(__iicu_wikimyei_t *_iicu_wikimyei){
	beseech_current_mewaajacune(_iicu_wikimyei);
	update_iicu_mewaajacune(giicm(_iicu_wikimyei));	
	release_current_mewaajacune(_iicu_wikimyei);

	beseech_current_nijcyota(_iicu_wikimyei);
    update_iicu_nicjyota(giicn(_iicu_wikimyei));
	release_current_nijcyota(_iicu_wikimyei);
	
}
void refresh_iicu_scene(__iicu_scene_struct_t *_iicu_scene){
	// #FIXME add ...
    // fprintf(stdout,"[WARNING:] refresh_iicu_scene is call empty\n");
}
void refresh_current_iicu_scene(__iicu_wikimyei_t *_iicu_wikimyei){
	refresh_iicu_scene(giics(_iicu_wikimyei));
}
void destroy_iicu_scene(__iicu_scene_struct_t *_iicu_scene){ // #FIXME fix fixed size of scenes, rather allocate memory
	refresh_iicu_scene(_iicu_scene); // #FIXME is refresh enough?
	for(int m_idx=0x00;m_idx<BROKER_CANDLE_N_INTERVALS;m_idx++){
		destroy_mewaajacune(_iicu_scene->__mewaajacune[m_idx]);
		destroy_regressive(_iicu_scene->__iicu_regressive[m_idx]);
		destroy_polinomial(_iicu_scene->__iicu_polinomial[m_idx]);
	}
	destroy_staticques(_iicu_scene->__iicu_staticques);
	destroy_jkimyei(_iicu_scene->__iicu_jkimyei);
	destroy_nijcyota(_iicu_scene->__nijcyota);
	destroy_itsaave(_iicu_scene->__scene_itsaave);
	free(_iicu_scene);
}
void destroy_all_iicu_scenes(__iicu_wikimyei_t *_iicu_wikimyei){
	get_state(_iicu_wikimyei)->scene_id=get_state(_iicu_wikimyei)->scene_count-0x01;
	while(get_state(_iicu_wikimyei)->scene_count!=0x00){
		destroy_iicu_scene(giics(_iicu_wikimyei));
		get_state(_iicu_wikimyei)->scene_count-=0x01;
		get_state(_iicu_wikimyei)->scene_id-=0x01;
	}
	assert(get_state(_iicu_wikimyei)->scene_count==0x00);
	assert(gcsid(_iicu_wikimyei)==0x00);
}


void iicu_scene_go_up(__iicu_wikimyei_t *_iicu_wikimyei){
	beseech_all(_iicu_wikimyei);
	if(gcsid(_iicu_wikimyei)<get_state(_iicu_wikimyei)->scene_count-0x01){
		get_state(_iicu_wikimyei)->scene_id++;
	} else {
		get_state(_iicu_wikimyei)->scene_id=0x00;
	}
	strcpy(get_state(_iicu_wikimyei)->scene_symbol,IICU_SCENES_SYMBOLS[gcsid(_iicu_wikimyei)]);
	release_all(_iicu_wikimyei);
}
void iicu_scene_go_down(__iicu_wikimyei_t *_iicu_wikimyei){
	beseech_all(_iicu_wikimyei);
	if(gcsid(_iicu_wikimyei)>0x00){
		get_state(_iicu_wikimyei)->scene_id--;
	} else {
		get_state(_iicu_wikimyei)->scene_id=get_state(_iicu_wikimyei)->scene_count-0x01;
	}
	strcpy(get_state(_iicu_wikimyei)->scene_symbol,IICU_SCENES_SYMBOLS[gcsid(_iicu_wikimyei)]);
	release_all(_iicu_wikimyei);
}

void iicu_klines_increse(__iicu_wikimyei_t *_iicu_wikimyei){
	beseech_all(_iicu_wikimyei);
	if(gcklid(_iicu_wikimyei)<BROKER_CANDLE_N_INTERVALS-0x01){
		get_state(_iicu_wikimyei)->kline_id[gcsid(_iicu_wikimyei)]++;
	} else {
		get_state(_iicu_wikimyei)->kline_id[gcsid(_iicu_wikimyei)]=0x00;
	}
	#ifdef __COORDINATE_ALL_KLINES_IN_SCENES__
	for(int scene_idx=0x00;scene_idx<MAX_IICU_SCENES;scene_idx++){
		get_state(_iicu_wikimyei)->kline_id[scene_idx]=get_state(_iicu_wikimyei)->kline_id[gcsid(_iicu_wikimyei)];
	}
	#endif
	release_all(_iicu_wikimyei);
}
void iicu_klines_decrese(__iicu_wikimyei_t *_iicu_wikimyei){
	beseech_all(_iicu_wikimyei);
	if(gcklid(_iicu_wikimyei)>0x00){
		get_state(_iicu_wikimyei)->kline_id[gcsid(_iicu_wikimyei)]--;
	} else {
		get_state(_iicu_wikimyei)->kline_id[gcsid(_iicu_wikimyei)]=BROKER_CANDLE_N_INTERVALS-0x01;
	}
	#ifdef __COORDINATE_ALL_KLINES_IN_SCENES__
	for(int scene_idx=0x00;scene_idx<MAX_IICU_SCENES;scene_idx++){
		get_state(_iicu_wikimyei)->kline_id[scene_idx]=get_state(_iicu_wikimyei)->kline_id[gcsid(_iicu_wikimyei)];
	}
	#endif
	release_all(_iicu_wikimyei);
}