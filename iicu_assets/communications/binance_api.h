#ifndef __BINANCE_API__
#define __BINANCE_API__
typedef struct bnc_price_tick {
    char *symbol;
    float price;
} bnc_price_tick_t;
#include "curl_utils.h"
void get_price_ticker(bnc_price_tick_t *payload,char *symbol);
#endif