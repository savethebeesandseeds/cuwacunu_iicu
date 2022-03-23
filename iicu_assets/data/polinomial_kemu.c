#include "polinomial_kemu.h"
#include "../iicu/iicu_wikimyei.h"
__iicu_polinomial_t *polinomial_fabric(){
    // fprintf(stdout,"[cuwacunu:] polinomial_fabric() \n");
    __iicu_polinomial_t *new_polinomial = malloc(sizeof(__iicu_polinomial_t));
    return new_polinomial;
}
void destroy_polinomial(__iicu_polinomial_t *_polinomial){
    // fprintf(stdout,"[cuwacunu:] destory_polinomial() \n");
    free(_polinomial);
}
void *polinomial_launcher(void *_pl_thread_order){
    switch(((__polinomial_thread_order_t*)_pl_thread_order)->__pl_type){
    case PL_KIKE_METHOD:
        // #FIXME add
        fprintf(stdout,"%s[WARNING:] empty action in polinomial_launcher PL_KIKE_METHOD%s\n",COLOR_WARNING,COLOR_REGULAR);
        break;
    default:
        fprintf(stderr,"[cuwacunu:]%sERROR, not understood polinomial type configured in polinomial thread order%s\n",COLOR_DANGER,COLOR_REGULAR);
        break;
    }
    pthread_exit(NULL);
}