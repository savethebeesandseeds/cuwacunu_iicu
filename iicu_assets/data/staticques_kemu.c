#include "staticques_kemu.h"
#include "../iicu/iicu_wikimyei.h"
__iicu_staticques_t *staticques_fabric(){
    // fprintf(stdout,"[%s cuwacunu: %s] staticques_fabric() \n",COLOR_CUWACUNU,COLOR_REGULAR);
    __iicu_staticques_t *new_staticques = malloc(sizeof(__iicu_staticques_t));
    for(int idx_kline=0x00;idx_kline<BROKER_CANDLE_N_INTERVALS;idx_kline++){
        new_staticques->__alliu_mean[idx_kline]=0x00;
        new_staticques->__alliu_std[idx_kline]=0x00;
    }
    assert(ALLIU_SIZE==0x01); // alliu asigments are not vectorized
    new_staticques->__alliu_latest=0x00;
    return new_staticques;
}
void destroy_staticques(__iicu_staticques_t *_staticques){
    // fprintf(stdout,"[%s cuwacunu: %s] destory_kemu() \n",COLOR_CUWACUNU,COLOR_REGULAR);
    free(_staticques);
}
void *staticques_launcher(void *_sq_thread_order){
    #ifdef __STATICQUES_THREAD_FORCE_CORE
    cpu_set_t cpuset;
    int cpu = __STATICQUES_THREAD_FORCE_CORE;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu,&cpuset);
    #endif
    // --- --- --- --- --- 
    ((__staticques_thread_order_t*)_sq_thread_order)->__sq_thead_is_bussy=0x01;
    // --- --- --- --- --- 
    int c_scene_id=((__staticques_thread_order_t*)_sq_thread_order)->__scene_id;
    // --- --- --- --- --- 
    switch(((__staticques_thread_order_t*)_sq_thread_order)->__sq_type){
    case FIRST_ORDER_STATISTICS:
        // --- --- --- --- 
        fprintf(stdout,"[%sWARNING:%s] empty action in staticques_launcher FIRST_ORDER_STATISTICS : [%s]\n",COLOR_WARNING,COLOR_REGULAR,IICU_SCENES_SYMBOLS[c_scene_id]);
        // --- --- --- --- 
        break;
        // --- --- --- --- 
    case FIRST_ORDER_AUTOREGRESSION: // FIXME add
        fprintf(stdout,"[%sWARNING:%s] empty action in staticques_launcher FIRST_ORDER_AUTOREGRESSION : [%s]\n",COLOR_WARNING,COLOR_REGULAR,IICU_SCENES_SYMBOLS[c_scene_id]);
        break;
    default:
        fprintf(stderr,"[%s cuwacunu: %s]%sERROR, not understood staticques type configured in staticques thread order%s\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_DANGER,COLOR_REGULAR);
        break;
    }
    // __std, __mean, __last, are updated in broker thread
    // __iicu_staticques_t *c_staticques=
    // #FIXME add.
    // #FIXME add the frist order autocorrelation to see if there is a pattern in the data
    // -- --- --- 
    ((__staticques_thread_order_t*)_sq_thread_order)->__sq_thead_is_bussy=0x00;
    // -- --- --- 
    pthread_exit(NULL);
}

___cwcn_bool_t staticques_is_ready(__iicu_staticques_t *_staticques){
    return _staticques->__alliu_latest!=0x00;
}