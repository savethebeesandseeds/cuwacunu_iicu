#include "state_thread.h"
void *IICU_state_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[cuwacunu:] : start : IICU_state_thread()\n");
    while(0xFF){
        fprintf(stdout,"[cuwacunu:] step state thread--- ... ---\n");
        Uint32 start_time = SDL_GetTicks();
        update_iicu_state((__iicu_wikimyei_t *)_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*STATE_THREAD_PERIOD)){
            SDL_Delay((1000*STATE_THREAD_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    pthread_exit(NULL);
    fprintf(stdout,"[cuwacunu:] : end : IICU_state_thread()\n");
}