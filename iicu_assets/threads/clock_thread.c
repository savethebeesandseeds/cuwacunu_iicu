#include "clock_thread.h"
void *IICU_clock_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[cuwacunu:] : start : IICU_clock_thread()\n");
    while(0xFF){
        fprintf(stdout,"[cuwacunu:] sleep thread--- ... ---\n");
        Uint32 start_time = SDL_GetTicks();
        launch_step_event();
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_THREAD_PERIOD)){
            SDL_Delay((1000*CLOCK_THREAD_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    pthread_exit(NULL);
    fprintf(stdout,"[cuwacunu:] : end : IICU_clock_thread()\n");
}