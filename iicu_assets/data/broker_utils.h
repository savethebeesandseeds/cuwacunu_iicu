#ifndef __BROKER_UTILS__
#define __BROKER_UTILS__
#include "../config/general_config.h"
#include "../config/broker_config.h"
#include "../iicu/iicu_wikimyei.h"
// --- --- --- TICKER FUNKS
void broker_update_price_forall_symbols(void *_iicu_wikimyei);
// --- --- --- KLINES FUNKS
___cwcn_bool_t symbol_kline_broker_update_needed(void *_iicu_wikimyei, int _idx_scene, int _idx_kline);
void update_broker_mewaajacune_klines(void *_iicu_wikimyei);
void update_mewaajacune_item(void *_iicu_wikimyei, char *symbol, char *interval);
// --- --- --- WEBSOCKET FUNKS
void broker_websocketclient_factory(void *_iicu_wikimyei);
void destroy_broker_websocketclient(__wsclient_t *_client);

void broker_websocket_suscriber(__wsclient_t *c);
int broker_websocket_on_close(__wsclient_t *c);
int broker_websocket_on_error(__wsclient_t *c, __wsclient_error_t *err);
int broker_websocket_on_message(__wsclient_t *c, __wsclient_message_t *msg);
int broker_websocket_on_open(__wsclient_t *c);
#endif