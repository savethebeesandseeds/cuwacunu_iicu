#include "jkimyei_thread.h"
#include "../iicu/iicu_loops.h"
void *IICU_jkimyei_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[cuwacunu:] : start : IICU_jkimyei_thread()\n");
    while(0xFF){
        Uint32 start_time = SDL_GetTicks();
        jkimyei_loop(_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_JKIMYEI_PERIOD)){
            SDL_Delay((1000*CLOCK_JKIMYEI_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    pthread_exit(NULL);
    fprintf(stdout,"[cuwacunu:] : end : IICU_jkimyei_thread()\n");
}