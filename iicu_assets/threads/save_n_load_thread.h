#ifndef __SAVE_n_LOAD_THREAD__
#define __SAVE_n_LOAD_THREAD__
#include "../communications/regular_key_file.h"
#include "../encription/rcsi.h"
#include "../config/general_config.h"
#include "../config/threads_config.h"
#include "../config/itsaave_config.h"
void *IICU_save_n_load_thread(void *_iicu_wikimyei);
#include "../iicu/iicu_wikimyei.h"
#include "../iicu/iicu_loops.h"
void load_itsaave_from_state_backup(__iicu_wikimyei_t *_iicu_wikimyei);
void save_itsaave_from_state_backup(__iicu_wikimyei_t *_iicu_wikimyei);
#endif