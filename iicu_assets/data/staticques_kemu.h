#ifndef __STATICQUES_KEMU__
#define __STATICQUES_KEMU__
#include "../config/general_config.h"
typedef struct __iicu_staticques_kemu {
    __cwcn_type_t alliu_latest;
    __cwcn_type_t alliu_mean;
    __cwcn_type_t alliu_std;
}__iicu_staticques_t;
__iicu_staticques_t *staticques_fabric();
void destroy_staticques(__iicu_staticques_t *_kemu);
void update_iicu_staticques(__iicu_staticques_t *_kemu);
#endif