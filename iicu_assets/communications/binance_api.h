#ifndef __BINANCE_API__
#define __BINANCE_API__
typedef struct bnc_price_tick {
    char *symbol;
    float price;
} bnc_price_tick_t;
#include <string.h>
#include "curl_utils.h"
#include "../config/binance_config.h"
void get_price_ticker(bnc_price_tick_t *payload,char *symbol);
int test_network_by_ping();
#endif