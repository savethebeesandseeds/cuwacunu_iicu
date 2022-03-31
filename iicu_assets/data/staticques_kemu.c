#include "staticques_kemu.h"
#include "../iicu/iicu_wikimyei.h"
__iicu_staticques_t *staticques_fabric(){
    // fprintf(stdout,"[cuwacunu:] staticques_fabric() \n");
    __iicu_staticques_t *new_staticques = malloc(sizeof(__iicu_staticques_t));
    assert(ALLIU_SIZE==0x01); // alliu asigments are not vectorized
    new_staticques->__alliu_latest=0x00;
    new_staticques->__alliu_mean=0x00;
    new_staticques->__alliu_std=0x00;
    return new_staticques;
}
void destroy_staticques(__iicu_staticques_t *_staticques){
    // fprintf(stdout,"[cuwacunu:] destory_kemu() \n");
    free(_staticques);
}
void *staticques_launcher(void *_sq_thread_order){
    switch(((__staticques_thread_order_t*)_sq_thread_order)->__sq_type){
    case FIRST_ORDER_STATISTICS:
        // FIXME add
        fprintf(stdout,"%s[WARNING:] empty action in staticques_launcher FIRST_ORDER_STATISTICS%s\n",COLOR_WARNING,COLOR_REGULAR);
        break;
    case FIRST_ORDER_AUTOREGRESSION:
        // FIXME add
        fprintf(stdout,"%s[WARNING:] empty action in staticques_launcher FIRST_ORDER_AUTOREGRESSION%s\n",COLOR_WARNING,COLOR_REGULAR);
        break;
    default:
        fprintf(stderr,"[cuwacunu:]%sERROR, not understood staticques type configured in staticques thread order%s\n",COLOR_DANGER,COLOR_REGULAR);
        break;
    }
    // __std, __mean, __last, are updated in broker thread
    // __iicu_staticques_t *c_staticques=
    // #FIXME add.
    // #FIXME add the frist order autocorrelation to see if there is a pattern in the data
    pthread_exit(NULL);
}