#include "binance_api.h"
void get_price_ticker(bnc_price_tick_t *payload,char *symbol){
    char *target_url="http://api.binance.com/api/v3/ticker/price?symbol=BTCUSDT";
    curl_string_t responce=get_request(target_url);
    int ref = interpret_rest_code(responce.res_code);
    payload->symbol=symbol;
    printf("request: %s\n",responce.ptr);
    payload->price=1234.0;
}