#ifndef __BROKER_THREAD__
#define __BROKER_THREAD__
#include "../config/general_config.h"
#include "../config/threads_config.h"
#include "../config/broker_config.h"
#include "../config/sdl_config.h"
#include "../iicu/iicu_wikimyei.h"
void *IICU_broker_thread(void *_iicu_wikimyei);
void update_kemu_broker(__iicu_wikimyei_t *_iicu_wikimyei);
void update_mewaajacune_broker(__iicu_wikimyei_t *_iicu_wikimyei);
void update_mewaajacune_broker_symbol(__iicu_wikimyei_t *_iicu_wikimyei, char *symbol);
void update_mewaajacune_broker_symbol_interval(__iicu_wikimyei_t *_iicu_wikimyei, char *symbol, char *interval);
#endif