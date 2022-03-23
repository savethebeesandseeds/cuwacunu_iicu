#include "broker_thread.h"
void *IICU_broker_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[cuwacunu:] : start : IICU_broker_thread()\n");
    while(0xFF){
        fprintf(stdout,"[cuwacunu:] step broker thread--- ... ---\n");
        Uint32 start_time = SDL_GetTicks();
        update_kemu_broker((__iicu_wikimyei_t *)_iicu_wikimyei);
        update_mewaajacune_broker((__iicu_wikimyei_t *)_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*BROKER_THREAD_PERIOD)){
            SDL_Delay((1000*BROKER_THREAD_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    pthread_exit(NULL);
    fprintf(stdout,"[cuwacunu:] : end : IICU_broker_thread()\n");
}

void update_kemu_broker(__iicu_wikimyei_t *_iicu_wikimyei){
    __cwcn_type_t symbol_latest_alliu=0x00;
    for(int idx_symb=0x00;idx_symb<MAX_IICU_SCENES;idx_symb++){ // all symbols
        symbol_latest_alliu=(__cwcn_type_t) request_latest_alliu(IICU_SCENES_SYMBOLS[idx_symb]);
        for(int idx_kline=0;idx_kline<BROKER_CANDLE_N_INTERVALS;idx_kline++){ // all intervals per symbol
            beseech_staticques(_iicu_wikimyei,idx_symb,idx_kline);
            get_staticques(_iicu_wikimyei,idx_symb,idx_kline)->__alliu_latest=symbol_latest_alliu;
            release_staticques(_iicu_wikimyei,idx_symb,idx_kline);
        }
    }
}
void update_mewaajacune_broker(__iicu_wikimyei_t *_iicu_wikimyei){
    for(int idx_symb=0x00;idx_symb<MAX_IICU_SCENES;idx_symb++){ // all symbols
        update_mewaajacune_broker_symbol(_iicu_wikimyei, IICU_SCENES_SYMBOLS[idx_symb]);
    }
}
void update_mewaajacune_broker_symbol(__iicu_wikimyei_t *_iicu_wikimyei, char *symbol){
    for(int idx_interval=0;idx_interval<BROKER_CANDLE_N_INTERVALS;idx_interval++){ // all intervals per symbol
        update_mewaajacune_broker_symbol_interval(_iicu_wikimyei, symbol, BROKER_CANDLE_INTERVALS[idx_interval]);
    }
}
void update_mewaajacune_broker_symbol_interval(__iicu_wikimyei_t *_iicu_wikimyei, char *symbol, char *interval){
    int idx_kline=-1;
    for(int idx_interval=0;idx_interval<BROKER_CANDLE_N_INTERVALS;idx_interval++){
        if(strcmp(BROKER_CANDLE_INTERVALS[idx_interval],interval)==0){idx_kline=idx_interval;break;}
    }
    int idx_scene=-1;
    for(int idx_symbol=0;idx_symbol<MAX_IICU_SCENES;idx_symbol++){ // all scenes
        if(strcmp(IICU_SCENES_SYMBOLS[idx_symbol],symbol)==0){idx_scene=idx_symbol;break;}
    }
    if(idx_kline!=-1 && idx_scene!=-1){
        int _alliu_index=giicn(_iicu_wikimyei)->alliu_index;
        double d_time;
        double c_time= (double) time(NULL);
        #ifdef __UPDATE_ONLY_ACTIVE_BROKER_SYMBOL_INTERVAL__
        if(idx_scene!=gcsid(_iicu_wikimyei)){return;}
        #endif
        d_time = c_time-get_state(_iicu_wikimyei)->kline_last_update[idx_scene][idx_kline];
        if(get_state(_iicu_wikimyei)->kline_last_update[idx_scene][idx_kline]==0x00 || d_time > BROKER_CANDLE_PERIODS[idx_kline]){
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
            beseech_mewaajacune(_iicu_wikimyei,idx_scene,idx_kline);
            rebase_mewaajacune(get_mewaajacune(_iicu_wikimyei, idx_scene, idx_kline),tmp_mewaajacune);
            release_mewaajacune(_iicu_wikimyei,idx_scene,idx_kline);
            destroy_mewaajacune(tmp_mewaajacune);
            // --- safely update desired staticques
            beseech_staticques(_iicu_wikimyei,idx_scene,idx_kline);
            get_staticques(_iicu_wikimyei, idx_scene, idx_kline)->__alliu_mean=tmp_mean;
            get_staticques(_iicu_wikimyei, idx_scene, idx_kline)->__alliu_std=tmp_std;
            release_staticques(_iicu_wikimyei,idx_scene,idx_kline);
        }
    } else {
        if(idx_kline==-1){fprintf(stderr,"[ERROR:] on function update_mewaajacune_broker_symbol_interval : cound't find CANDLE INTERVAL %s...\n",interval);}
        if(idx_scene==-1){fprintf(stderr,"[ERROR:] on function update_mewaajacune_broker_symbol_interval : cound't find SYMBOL %s...\n",symbol);}
        assert(0x00);
    }
}