#include "../iicu/iicu_wikimyei.h"
#include "broker_api.h"

void get_price_ticker(bnc_price_tick_t *payload,char *symbol){
    // #FIXME this method is functional but deprecated (crashes on long usage sessions)
    char target_url[256];
    snprintf(target_url,256,"%s%s?symbol=%s",BROKER_BASE_URL,BROKER_TICKER_PRICE,symbol);
    curl_string_t responce=get_request(target_url);
    int ref = interpret_rest_code(responce.res_code);
    assert(ref==0x01);
    payload->symbol=symbol;
    fprintf(stdout,"get_price_ticker : request : [%d] : %s : %s\n",ref,target_url,responce.ptr);
    char *ch;
    char filter_str[64];
    snprintf(filter_str,256,"},{\"symbol:%sprice",symbol);
    char *saveptr;
    ch=strtok_r(responce.ptr, filter_str,&saveptr);
    // fprintf(stdout," :: %s\n",ch);
    if(ch!=NULL){payload->price=strtof(ch,NULL);
    } else {payload->price=0.0;}
    free_curl_string(&responce);
}

void print_kline(bnc_klines_t *payload, int payload_idx){
    fprintf(stdout,"--- --- %d/%d --- --- \n",payload_idx+1,payload->klines_count);
    fprintf(stdout,"open_time: %ld\n",payload->klines[payload_idx].open_time);
    fprintf(stdout,"open: %f\n",payload->klines[payload_idx].open);
    fprintf(stdout,"high: %f\n",payload->klines[payload_idx].high);
    fprintf(stdout,"low: %f\n",payload->klines[payload_idx].low);
    fprintf(stdout,"close: %f\n",payload->klines[payload_idx].close);
    fprintf(stdout,"volume: %f\n",payload->klines[payload_idx].volume);
    fprintf(stdout,"close_time: %ld\n",payload->klines[payload_idx].close_time);
    fprintf(stdout,"quote_asset_volume: %f\n",payload->klines[payload_idx].quote_asset_volume);
    fprintf(stdout,"number_of_trades: %ld\n",payload->klines[payload_idx].number_of_trades);
    fprintf(stdout,"taker_by_base_asset_volume: %f\n",payload->klines[payload_idx].taker_by_base_asset_volume);
    fprintf(stdout,"taker_by_quote_asset_volume: %f\n",payload->klines[payload_idx].taker_by_quote_asset_volume);
    fprintf(stdout,"ignore: %f\n",payload->klines[payload_idx].ignore);
}
void get_klines(bnc_klines_t *payload,char *symbol,char *interval){
    char target_url[256];
    snprintf(target_url,256,"%s%s?symbol=%s&interval=%s&limit=%d",BROKER_BASE_URL,BROKER_KLINES,symbol,interval,KLINES_N_LIMIT);
    // fprintf(stdout,"%s\n",target_url);
    curl_string_t responce=get_request(target_url);
    int ref = interpret_rest_code(responce.res_code);
    assert(ref==0x01);
    payload->symbol=symbol;
    payload->interval=interval;
    fprintf(stdout,"request : [%d] : %s : ...\n",ref,target_url); //,responce.ptr
    char *ch;
    payload->klines_count=0;
    // --- --- --- DEBUG porpouses
    // char dbug_fle_nme[64];
    // sprintf(dbug_fle_nme,"debug_klines_%s_%s.txt",symbol,interval);
    // FILE *debug_file=fopen(dbug_fle_nme,"w");
    // if(debug_file==NULL){
    //     fprintf(stderr,"[%s ERROR: %s] debugging klines found null file.\n",COLOR_DANGER,COLOR_REGULAR);
    //     exit(-1);
    // }
    // --- --- --- 
    char *saveptr;
    ch=strtok_r(responce.ptr, "],[\"",&saveptr);
    while(ch!=NULL){ // capture data into the klines structure
        payload->klines[payload->klines_count].open_time=strtol(ch,NULL,10);
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines[payload->klines_count].open=strtof(ch,NULL);}else{break;}
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines[payload->klines_count].high=strtof(ch,NULL);}else{break;}
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines[payload->klines_count].low=strtof(ch,NULL);}else{break;}
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines[payload->klines_count].close=strtof(ch,NULL);}else{break;}
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines[payload->klines_count].volume=strtof(ch,NULL);}else{break;}
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines[payload->klines_count].close_time=strtol(ch,NULL,10);}else{break;}
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines[payload->klines_count].quote_asset_volume=strtof(ch,NULL);}else{break;}
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines[payload->klines_count].number_of_trades=strtol(ch,NULL,10);}else{break;}
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines[payload->klines_count].taker_by_base_asset_volume=strtof(ch,NULL);}else{break;}
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines[payload->klines_count].taker_by_quote_asset_volume=strtof(ch,NULL);}else{break;}
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines[payload->klines_count].ignore=strtof(ch,NULL);}else{break;}
        ch=strtok_r(NULL,"],[\"",&saveptr);if(ch!=NULL){payload->klines_count++;}else{break;}
    }
    // if(strcmp(symbol,"BTCUSDT")==0 && strcmp(interval,"1m")==0){
    //     fprintf(stdout,"%s : %s :: ",symbol,interval);
    //     for(int payload_idx=0;payload_idx<payload->klines_count;payload_idx++){print_kline(payload, payload_idx);}
    // }
    // for(int payload_idx=0;payload_idx<payload->klines_count;payload_idx++){print_kline(payload, payload_idx);}
    free_curl_string(&responce);
}
int test_network_by_ping(){
    char target_url[256];
    snprintf(target_url,256,"%s%s",BROKER_BASE_URL,BROKER_PING);
    return test_conectivity(target_url);
}
