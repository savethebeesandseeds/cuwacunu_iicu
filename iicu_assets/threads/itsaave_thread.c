#include "itsaave_thread.h"
#include "../iicu/iicu_loops.h"
void *IICU_itsaave_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[%s cuwacunu %s:] : start : IICU_itsaave_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    while(0xFF){
        Uint32 start_time = SDL_GetTicks();
        itsaave_loop(_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_ITSAAVE_PERIOD)){
            SDL_Delay((1000*CLOCK_ITSAAVE_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    fprintf(stdout,"[%s cuwacunu %s:] : end : IICU_itsaave_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    pthread_exit(NULL);
}