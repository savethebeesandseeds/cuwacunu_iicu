#include "data_utils.h"
void test_populate_alliu(__iicu_mewaajacune_t *_mewaajacune){
    __cwcn_type_t rand_float;
    kill_load(_mewaajacune);
    // --- --- --- --- · --- --- --- --- populate coordinate list
    for(int data_x=0;data_x<64;data_x++){
        rand_float=(__cwcn_type_t)rand()/(__cwcn_type_t)RAND_MAX*((__cwcn_type_t)64);
        yield_next_trayectory(_mewaajacune);
        glti(_mewaajacune)->__alliu_state[0]=rand_float;
        // glti(_mewaajacune)->__alliu_state[0]=sin(2*2*3.141592/64*((__cwcn_type_t)data_x+1));
        // glti(_mewaajacune)->__alliu_state[0]=(__cwcn_type_t)data_x;
        // fprintf(stdout,"glti(_mewaajacune)->__alliu_state[0]:%f\n",glti(_mewaajacune)->__alliu_state[0]);
    }
}