#ifndef __BROKER_THREAD__
#define __BROKER_THREAD__
#include "../config/general_config.h"
#include "../config/threads_config.h"
#include "../config/broker_config.h"
#include "../config/sdl_config.h"
#include "../iicu/iicu_wikimyei.h"
void *IICU_broker_thread(void *_iicu_wikimyei);
___cwcn_bool_t symbol_kline_broker_update_needed(__iicu_wikimyei_t *_iicu_wikimyei, int _idx_scene, int _idx_kline);
void update_mewaajacune_broker(__iicu_wikimyei_t *_iicu_wikimyei);
void update_mewaajacune_item(__iicu_wikimyei_t *_iicu_wikimyei, char *symbol, char *interval);
#endif