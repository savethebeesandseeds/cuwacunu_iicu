#include "itsaave_thread.h"
#include "../iicu/iicu_loops.h"
void *IICU_itsaave_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[cuwacunu:] : start : IICU_itsaave_thread()\n");
    while(0xFF){
        Uint32 start_time = SDL_GetTicks();
        itsaave_loop(_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_ITSAAVE_PERIOD)){
            SDL_Delay((1000*CLOCK_ITSAAVE_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    pthread_exit(NULL);
    fprintf(stdout,"[cuwacunu:] : end : IICU_itsaave_thread()\n");
}