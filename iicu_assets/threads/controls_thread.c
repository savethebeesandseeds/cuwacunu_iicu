#include "controls_thread.h"
void *IICU_controls_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[%s cuwacunu %s:] : start : IICU_controls_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    while(0xFF){
        Uint32 start_time = SDL_GetTicks();
        iicu_controls_loop(_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_CONTROLS_PERIOD)){
            SDL_Delay((1000*CLOCK_CONTROLS_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    fprintf(stdout,"[%s cuwacunu %s:] : end : IICU_controls_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    pthread_exit(NULL);
}