#include "polinomial_kemu.h"
#include "../iicu/iicu_wikimyei.h"
__iicu_polinomial_t *polinomial_fabric(){
    // fprintf(stdout,"[%s cuwacunu: %s] polinomial_fabric() \n",COLOR_CUWACUNU,COLOR_REGULAR);
    __iicu_polinomial_t *new_polinomial = malloc(sizeof(__iicu_polinomial_t));
    return new_polinomial;
}
void destroy_polinomial(__iicu_polinomial_t *_polinomial){
    // fprintf(stdout,"[%s cuwacunu: %s] destory_polinomial() \n",COLOR_CUWACUNU,COLOR_REGULAR);
    free(_polinomial);
}
void *polinomial_launcher(void *_pl_thread_order){
    #ifdef __POLINOMIAL_THREAD_FORCE_CORE
    cpu_set_t cpuset;
    int cpu = __POLINOMIAL_THREAD_FORCE_CORE;
    CPU_ZERO(&cpuset);
    CPU_SET(cpu,&cpuset);
    #endif
    switch(((__polinomial_thread_order_t*)_pl_thread_order)->__pl_type){
    case PL_KIKE_METHOD:
        // #FIXME add
        fprintf(stdout,"%s[WARNING:] empty action in polinomial_launcher PL_KIKE_METHOD%s\n",COLOR_WARNING,COLOR_REGULAR);
        break;
    default:
        fprintf(stderr,"[%s cuwacunu: %s]%sERROR, not understood polinomial type configured in polinomial thread order%s\n",COLOR_CUWACUNU,COLOR_REGULAR,COLOR_DANGER,COLOR_REGULAR);
        break;
    }
    pthread_exit(NULL);
}