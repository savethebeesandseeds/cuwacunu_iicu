#include "clock_thread.h"
void *IICU_clock_thread(void *threadid){
    /* Push a single left key event. */
    while(0xFF){
        fprintf(stdout,"[cuwacunu:] sleep thread--- ... ---\n");
        Uint32 start_time = SDL_GetTicks();
        launch_step_event();
        
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_THREAD_PERIOD)){
            SDL_Delay((1000*CLOCK_THREAD_PERIOD)-(SDL_GetTicks()-start_time));
        }
        // #ifdef __UNIX_OS__
        // usleep(1000000*CLOCK_THREAD_PERIOD);
        // #elif __WIN_OS__
        // Sleep(1000*CLOCK_THREAD_PERIOD);
        // #endif
    }
    pthread_exit(NULL);
}