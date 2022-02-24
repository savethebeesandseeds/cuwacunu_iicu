#include <stdio.h>
#include <curl/curl.h>
#include <regex.h>
#include "../iicu_assets/communications/curl_utils.h"
#include "../iicu_assets/communications/broker_api.h"
int main(void){
    bnc_price_tick_t *payload;
    char *symbol="BTCUSDT";
    get_price_ticker(payload, symbol);
    printf("RESULT: %f\n",payload->price);
    return 0;
}