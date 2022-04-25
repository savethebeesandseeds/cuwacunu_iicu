#ifndef __BROKER_THREAD__
#define __BROKER_THREAD__
#include "../config/general_config.h"
#include "../config/threads_config.h"
#include "../config/broker_config.h"
#include "../config/sdl_config.h"
#include "../iicu/iicu_wikimyei.h"
void *IICU_broker_thread(void *_iicu_wikimyei);
#endif