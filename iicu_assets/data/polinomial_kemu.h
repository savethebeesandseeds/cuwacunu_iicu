#ifndef __POLINOMIAL_KEMU__
#define __POLINOMIAL_KEMU__
#include "../config/general_config.h"
#include "../config/threads_config.h"
#include "../data/kemu_utils.h"
#include "../data/mewaajacune_utils.h"
#include "../config/polinomial_config.h"
typedef struct __polinomial{
    ___cwcn_bool_t __pl_blrk_has_computed; // to know if pl is empty
    __iicu_mewaajacune_t *__pl_mewaajacune;
}__iicu_polinomial_t;
__iicu_polinomial_t *polinomial_fabric();
void destroy_polinomial(__iicu_polinomial_t *_polinomial);
void *polinomial_launcher(void *_pl_thread_order);
#endif

