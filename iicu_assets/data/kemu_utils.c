#include "kemu_utils.h"
__iicu_kemu_t *kemu_fabric(){
    // fprintf(stdout,"[cuwacunu:] kemu_fabric() \n");
    __iicu_kemu_t *new_kemu = malloc(sizeof(__iicu_kemu_t));
    return new_kemu;
}
void destroy_kemu(__iicu_kemu_t *_kemu){
    // fprintf(stdout,"[cuwacunu:] destory_kemu() \n");
    free(_kemu);
}
void update_iicu_kemu(__iicu_kemu_t *_kemu){
    // #FIXME add.
}