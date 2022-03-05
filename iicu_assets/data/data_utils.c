#include "data_utils.h"
void test_populate_alliu(__iicu_mewaajacune_t *_mewaajacune){
    __cwcn_type_t rand_float;
    kill_load(_mewaajacune);
    // --- --- --- --- · --- --- --- --- populate coordinate list
    for(int x_position=0;x_position<64;x_position++){
        rand_float=(__cwcn_type_t)rand()/(__cwcn_type_t)RAND_MAX*((__cwcn_type_t)64);
        yield_next_trayectory(_mewaajacune);
        glti(_mewaajacune)->__alliu_state[0]=rand_float;
        // glti(_mewaajacune)->__alliu_state[0]=sin(2*2*3.141592/64*((__cwcn_type_t)x_position+1));
        // glti(_mewaajacune)->__alliu_state[0]=(__cwcn_type_t)x_position;
        // fprintf(stdout,"glti(_mewaajacune)->__alliu_state[0]:%f\n",glti(_mewaajacune)->__alliu_state[0]);
    }
    load_to_start(_mewaajacune);
}
void populate_alliu_with_klines(__iicu_mewaajacune_t *_mewaajacune, int _alliu_index, char *symbol, char *interval){
    bnc_klines_t klines_payload={};    
    get_klines(&klines_payload, symbol, interval);
    kill_load(_mewaajacune);
    // --- --- --- --- · --- --- --- --- populate coordinate list
    for(int x_position=0;x_position<klines_payload.klines_count;x_position++){
        yield_next_trayectory(_mewaajacune);
        #if defined(MEWAAJACUNE_LOAD_CLOSE_KLINES_DATA)
        glti(_mewaajacune)->__alliu_timestamp=(time_t)(((__cwcn_type_t)klines_payload.klines[x_position].close_time)/((__cwcn_type_t)1000.0));
        glti(_mewaajacune)->__alliu_state[_alliu_index]=(__cwcn_type_t)klines_payload.klines[x_position].close;
        #elif defined(MEWAAJACUNE_LOAD_OPEN_KLINES_DATA)
        glti(_mewaajacune)->__alliu_timestamp=(time_t)(((__cwcn_type_t)klines_payload.klines[x_position].open_time)/((__cwcn_type_t)1000.0));
        glti(_mewaajacune)->__alliu_state[_alliu_index]=(__cwcn_type_t)klines_payload.klines[x_position].open;
        #endif
    }
    load_to_start(_mewaajacune);
}
__cwcn_type_t request_latest_alliu(char *symbol){
    // --- --- --- --- · --- --- --- --- request_latest_alliu
    bnc_price_tick_t price_payload={};
    get_price_ticker(&price_payload,symbol);
    return (__cwcn_type_t)price_payload.price;
}