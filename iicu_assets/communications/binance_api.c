#include "binance_api.h"
void get_price_ticker(bnc_price_tick_t *payload,char *symbol){
    char target_url[256];
    snprintf(target_url,256,"%s%s?symbol=%s",BINANCE_BASE_URL,BINANCE_TICKER_PRICE,symbol);
    curl_string_t responce=get_request(target_url);
    int ref = interpret_rest_code(responce.res_code);
    payload->symbol=symbol;
    printf("request : [%d] : %s\n",ref,responce.ptr);
    payload->price=1234.0;
}
int test_network_by_ping(){
    char target_url[256];
    snprintf(target_url,256,"%s%s",BINANCE_BASE_URL,BINANCE_PING);
    return test_conectivity(target_url);
}