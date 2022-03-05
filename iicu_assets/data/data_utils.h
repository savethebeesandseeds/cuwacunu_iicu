#ifndef __DATA_UTILS__
#define __DATA_UTILS__
#include "stdio.h"
#include "../data/mewaajacune_utils.h"
#include "../communications/broker_api.h"
void test_populate_alliu(__iicu_mewaajacune_t *_mewaajacune);
void populate_alliu_with_klines(__iicu_mewaajacune_t *_mewaajacune, int _alliu_index, char *symbol, char *interval);
__cwcn_type_t request_latest_alliu(char *symbol);
#endif