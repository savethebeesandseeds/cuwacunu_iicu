#include <stdio.h>
#include <curl/curl.h>
#include <regex.h>
#include "../iicu_assets/communications/curl_utils.h"
#include "../iicu_assets/communications/broker_api.h"
int main(void){
    // --- --- --- --- --- --- --- --- --- 
    char *symbol="BTCUSDT";
    // --- --- --- --- --- --- --- --- --- 
    bnc_price_tick_t price_payload={};
    get_price_ticker(&price_payload, symbol);
    printf("RESULT: %f\n",price_payload.price);
    // --- --- --- --- --- --- --- --- --- 
    // bnc_klines_t klines_payload={};
    // char *klines_interval="1m";
    // get_klines(&klines_payload, symbol, klines_interval);
    // --- --- --- --- --- --- --- --- --- 
    return 0;
    // --- --- --- --- --- --- --- --- --- 
}