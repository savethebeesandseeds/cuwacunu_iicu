#ifndef __BROKER_CONFIG__
#define __BROKER_CONFIG__
#include <wsclient/wsclient.h>
#define BROKER_BASE_URL "http://api.binance.com"
#define BROKER_PING "/api/v1/ping"
#define BROKER_TICKER_PRICE "/api/v3/ticker/price"
#define BROKER_KLINES "/api/v3/klines"
#define BINANCE_WEBSOCKET_ENDPOINT "wss://stream.binance.com:9443/ws"
#define BROKER_WEBSOCKET_SUBSCRIBE_TO "miniTicker"

#define INTERPRET_CURRENT_PRICE_AS_CLOSE_PRICE
// #define INTERPRET_CURRENT_PRICE_AS_OPEN_PRICE
#if !defined(INTERPRET_CURRENT_PRICE_AS_CLOSE_PRICE) && !defined(INTERPRET_CURRENT_PRICE_AS_OPEN_PRICE)
#error (broker_config.h) Please define INTERPRET_CURRENT_PRICE_AS_CLOSE_PRICE or INTERPRET_CURRENT_PRICE_AS_OPEN_PRICE
#endif

#define KLINES_N_LIMIT (int) 1000 // max of 1000
#define BROKER_CANDLE_N_INTERVALS (int) 15
#define BROKER_CANDLE_INTERVALS (char[BROKER_CANDLE_N_INTERVALS][6]) {"1m","3m","5m","15m","30m","1h","2h","4h","6h","8h","12h","1d","3d","1w","1M"}
#define BROKER_CANDLE_PERIODS (double[BROKER_CANDLE_N_INTERVALS]) {1*60,3*60,5*60,15*60,30*60,60*60,2*60*60,4*60*60,6*60*60,8*60*60,12*60*60,1*24*60*60,3*24*60*60,7*24*60*60,30*24*60*60}

#define BROKER_MARKET_COMMISSION_MAKER (float) 0.001 // 0.1%
#define BROKER_MARKET_COMMISSION_TAKER (float) 0.001 // 0.1%
#define BROKER_MARKET_TOTAL_COMMISSION (float) BROKER_MARKET_COMMISSION_MAKER + BROKER_MARKET_COMMISSION_TAKER

#endif