#include "staticques_kemu.h"

__iicu_staticques_t *staticques_fabric(){
    // fprintf(stdout,"[cuwacunu:] staticques_fabric() \n");
    __iicu_staticques_t *new_kemu = malloc(sizeof(__iicu_staticques_t));
    return new_kemu;
}
void destroy_staticques(__iicu_staticques_t *_staticques){
    // fprintf(stdout,"[cuwacunu:] destory_kemu() \n");
    free(_staticques);
}
void update_iicu_staticques(__iicu_staticques_t *_staticques){
    // #FIXME add.
    ...
    // #FIXME add the frist order autocorrelation to see if there is a pattern in the data
}