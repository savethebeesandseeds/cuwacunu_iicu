#include "broker_thread.h"
void *IICU_broker_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[%s cuwacunu %s:] : start : IICU_broker_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    broker_update_price_forall_symbols(_iicu_wikimyei);
    libwsclient_run(((__iicu_wikimyei_t *)_iicu_wikimyei)->__broker_wsclient);
    while(0xFF){
        fprintf(stdout,"[%s cuwacunu %s:] step broker thread--- ... ---\n",COLOR_CUWACUNU,COLOR_REGULAR);
        Uint32 start_time = SDL_GetTicks();
        update_broker_mewaajacune_klines((__iicu_wikimyei_t *)_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_BROKER_PERIOD)){
            SDL_Delay((1000*CLOCK_BROKER_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    pthread_exit(NULL);
    fprintf(stdout,"[%s cuwacunu %s:] : end : IICU_broker_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
}