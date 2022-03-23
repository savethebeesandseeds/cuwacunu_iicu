#ifndef __IICU_JKIMYEI__
#define __IICU_JKIMYEI__
#include "../config/general_config.h"
#include "../config/jkimyei_config.h"
#include "../config/states_config.h"
#include "../config/broker_config.h"
#include "../data/mewaajacune_utils.h"
#include "../config/nijcyota_utils.h"
#include "../data/kemu_utils.h"
#define POLICY_BASE_INVESTMENT (__cwcn_type_t) 1.0 // #FIXME put in nijcyota
typedef struct __inteligent_order_policy{
    __cwcn_type_t __order_margin_up; // (in [%]) how much porcentaje to margin up
    __cwcn_type_t __order_margin_down; // (in [%]) how much porcentaje to margin down
    __cwcn_type_t __base_margin_investment; // (in [%]) how much to invest
    __cwcn_type_t __policy_total_reward;
} __inteligent_order_policy_t;
typedef struct __iicu_jkimyei{
    ___cwcn_bool_t __jk_policy_has_computed; // to know if jk is empty
    __iicu_mewaajacune_t *__jk_mewaajacune;
    __inteligent_order_policy_t *__jk_inteligent_order_policy;
} __iicu_jkimyei_t;
// --- --- --- --- 
__inteligent_order_policy_t *policy_fabric();
__inteligent_order_policy_t *policy_clone_fabric(__inteligent_order_policy_t *src_iicu_policy);
void rebase_policy(__inteligent_order_policy_t *dest_iicu_policy, __inteligent_order_policy_t *src_iicu_policy);
void destroy_jkimyei(__iicu_jkimyei_t *_iicu_jkimyei);

__iicu_jkimyei_t *jkimyei_fabric();
__iicu_jkimyei_t *jkimyei_clone_fabric(__iicu_jkimyei_t *src_iicu_jkimyei);
void rebase_jkimyei(__iicu_jkimyei_t *dest_iicu_jkimyei, __iicu_jkimyei_t *src_iicu_jkimyei);
void destroy_policy(__inteligent_order_policy_t *_iicu_policy);

void run_policy_on_mewaajacunwe(__iicu_jkimyei_t *_iicu_jkimyei);
void monte_carlo_random_search(__iicu_jkimyei_t *_iicu_jkimyei);

void *jkimyei_launcher(void *_jk_thread_order);
void plot_policy(__inteligent_order_policy_t *_iicu_policy);

#endif