#include "broker_thread.h"
void *IICU_broker_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[%s cuwacunu %s:] : start : IICU_broker_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    while(0xFF){
        fprintf(stdout,"[%s cuwacunu %s:] step broker thread--- ... ---\n",COLOR_CUWACUNU,COLOR_REGULAR);
        Uint32 start_time = SDL_GetTicks();
        update_mewaajacune_broker((__iicu_wikimyei_t *)_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*BROKER_THREAD_PERIOD)){
            SDL_Delay((1000*BROKER_THREAD_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    pthread_exit(NULL);
    fprintf(stdout,"[%s cuwacunu %s:] : end : IICU_broker_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
}

___cwcn_bool_t symbol_kline_broker_update_needed(__iicu_wikimyei_t *_iicu_wikimyei, int _idx_scene, int _idx_kline){
    double c_time= (double) time(NULL);
    double d_time = c_time-get_state(_iicu_wikimyei)->kline_last_update[_idx_scene][_idx_kline];
    if(get_state(_iicu_wikimyei)->kline_last_update[_idx_scene][_idx_kline]==0x00 || d_time > BROKER_CANDLE_PERIODS[_idx_kline]){
        return 0x01;
    } else {
        return 0x00;
    }
}
void update_mewaajacune_broker(__iicu_wikimyei_t *_iicu_wikimyei){
    int test_index_kline;
    for(int idx_kline=0x00;idx_kline<BROKER_CANDLE_N_INTERVALS;idx_kline++){ // all intervals per symbol
        for(int idx_symb=0x00;idx_symb<MAX_IICU_SCENES;idx_symb++){ // all symbols
            if(symbol_kline_broker_update_needed(_iicu_wikimyei,gcsid(_iicu_wikimyei),gcklid(_iicu_wikimyei))){ // give priority to the active item
                update_mewaajacune_item(_iicu_wikimyei, IICU_SCENES_SYMBOLS[gcsid(_iicu_wikimyei)], BROKER_CANDLE_INTERVALS[gcklid(_iicu_wikimyei)]);
            }
            beseech_nijcyota(_iicu_wikimyei);
            test_index_kline=giicn(_iicu_wikimyei)->jkimyei_klines_index;
            release_nijcyota(_iicu_wikimyei);
            if(symbol_kline_broker_update_needed(_iicu_wikimyei,idx_symb,test_index_kline)){ // give priority to policy needs
                update_mewaajacune_item(_iicu_wikimyei, IICU_SCENES_SYMBOLS[idx_symb], BROKER_CANDLE_INTERVALS[test_index_kline]);
            }
            update_mewaajacune_item(_iicu_wikimyei, IICU_SCENES_SYMBOLS[idx_symb], BROKER_CANDLE_INTERVALS[idx_kline]);
        }
    }
}
void update_mewaajacune_item(__iicu_wikimyei_t *_iicu_wikimyei, char *symbol, char *interval){
    int idx_kline=-1;
    int idx_scene=-1;
    for(int ctx_kline=0x00;ctx_kline<BROKER_CANDLE_N_INTERVALS;ctx_kline++){
        if(strcmp(BROKER_CANDLE_INTERVALS[ctx_kline], interval)==0){idx_kline=ctx_kline;break;}
    }
    for(int ctx_symb=0x00;ctx_symb<MAX_IICU_SCENES;ctx_symb++){ // all scenes
        if(strcmp(IICU_SCENES_SYMBOLS[ctx_symb],symbol)==0){idx_scene=ctx_symb;break;}
    }
    if(idx_kline!=-1 && idx_scene!=-1){
        // --- --- --- 
        beseech_current_nijcyota(_iicu_wikimyei);
        int _alliu_index=giicn(_iicu_wikimyei)->alliu_index;
        release_current_nijcyota(_iicu_wikimyei);
        // --- --- --- 
        if(symbol_kline_broker_update_needed(_iicu_wikimyei, idx_scene, idx_kline)){
            // --- temporal mewaajacune
            __iicu_mewaajacune_t *tmp_mewaajacune=mewaajacune_fabric();
            __cwcn_type_t tmp_mean=0x00;
            __cwcn_type_t tmp_std=0x00;
            // --- update temporal mewaajacune
            populate_alliu_with_klines(tmp_mewaajacune, _alliu_index, symbol, interval);
            tmp_mean=mean_alliu_in_load(tmp_mewaajacune, _alliu_index);
            tmp_std=std_alliu_in_load(tmp_mewaajacune, _alliu_index);
            get_state(_iicu_wikimyei)->kline_last_update[idx_scene][idx_kline]=(double) time(NULL);
            // --- safely update desired mewaajacune
            beseech_mewaajacune(_iicu_wikimyei, idx_scene, idx_kline);
            rebase_mewaajacune(get_mewaajacune(_iicu_wikimyei, idx_scene, idx_kline),tmp_mewaajacune);
            release_mewaajacune(_iicu_wikimyei, idx_scene, idx_kline);
            // --- safely destoy temporal mewaajacune
            destroy_mewaajacune(tmp_mewaajacune);
            // --- safely update desired staticques
            beseech_staticques(_iicu_wikimyei, idx_scene);
            get_staticques(_iicu_wikimyei, idx_scene)->__alliu_mean[idx_kline]=tmp_mean;
            get_staticques(_iicu_wikimyei, idx_scene)->__alliu_std[idx_kline]=tmp_std;
            release_staticques(_iicu_wikimyei, idx_scene);
        }
    } else {
        if(idx_kline==-1){fprintf(stderr,"[ERROR:] on function update_mewaajacune_broker_interval_symbol : cound't find CANDLE INTERVAL %s...\n", interval);}
        if(idx_scene==-1){fprintf(stderr,"[ERROR:] on function update_mewaajacune_broker_interval_symbol : cound't find SYMBOL %s...\n",symbol);}
        assert(0x00);
    }
}