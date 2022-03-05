#ifndef __BROKER_API__
#define __BROKER_API__
#include <string.h>
#include <stdlib.h>
#include "curl_utils.h"
#include "../config/broker_config.h"
typedef struct bnc_price_tick {
    char *symbol;
    float price;
} bnc_price_tick_t;

typedef struct item_kline {
    long int open_time;
    double open;
    double high;
    double low;
    double close;
    double volume;
    long int close_time;
    double quote_asset_volume;
    long int number_of_trades;
    double taker_by_base_asset_volume;
    double taker_by_quote_asset_volume;
    double ignore;
} item_kline_t;
typedef struct bnc_klines {
    int klines_count;
    char *symbol;
    char *interval;
    item_kline_t klines[KLINES_N_LIMIT];
} bnc_klines_t;
void get_price_ticker(bnc_price_tick_t *payload,char *symbol);
void get_klines(bnc_klines_t *payload,char *symbol,char *interval);
int test_network_by_ping();
#endif