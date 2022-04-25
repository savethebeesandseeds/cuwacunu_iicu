#ifndef __STATICQUES_KEMU__
#define __STATICQUES_KEMU__
#include "../config/general_config.h"
#include "../config/threads_config.h"
#include "../data/kemu_utils.h"
#include "../data/mewaajacune_utils.h"
#include "../config/staticques_config.h"
typedef struct __iicu_staticques_kemu {
    __cwcn_type_t __alliu_latest;
    __cwcn_type_t __alliu_mean[BROKER_CANDLE_N_INTERVALS];
    __cwcn_type_t __alliu_std[BROKER_CANDLE_N_INTERVALS];
}__iicu_staticques_t;
__iicu_staticques_t *staticques_fabric();
void destroy_staticques(__iicu_staticques_t *_staticques);
void *staticques_launcher(void *_sq_thread_order);
___cwcn_bool_t staticques_is_ready(__iicu_staticques_t *_staticques);
#endif