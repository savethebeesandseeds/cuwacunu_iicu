#include "state_thread.h"
void *IICU_state_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[%s cuwacunu %s:] : start : IICU_state_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    while(0xFF){
        fprintf(stdout,"[%s cuwacunu %s:] step state thread--- ... ---\n",COLOR_CUWACUNU,COLOR_REGULAR);
        Uint32 start_time = SDL_GetTicks();
        update_iicu_state((__iicu_wikimyei_t *)_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_STATE_PERIOD)){
            SDL_Delay((1000*CLOCK_STATE_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    fprintf(stdout,"[%s cuwacunu %s:] : end : IICU_state_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    pthread_exit(NULL);
}