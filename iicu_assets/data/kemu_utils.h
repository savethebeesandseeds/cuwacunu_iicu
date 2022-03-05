#ifndef __KEMU_UTILS__
#define __KEMU_UTILS__
#include "../config/general_config.h"
#include "../config/states_config.h"
#include "../config/broker_config.h"
#include "../data/mewaajacune_utils.h"
//------------- KEMU ------------ ------------
typedef struct __iicu_kemu {
    __cwcn_type_t alliu_latest;
    __cwcn_type_t alliu_mean;
    __cwcn_type_t alliu_std;
}__iicu_kemu_t;
//------------- KEMU FUNKS ------------ ------
__iicu_kemu_t *kemu_fabric();
void destroy_kemu(__iicu_kemu_t *_kemu);
void update_iicu_kemu(__iicu_kemu_t *_kemu);
#endif