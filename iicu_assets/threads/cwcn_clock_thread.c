#include "cwcn_clock_thread.h"
void *IICU_clock_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[%s cuwacunu %s:] : start : IICU_clock_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    while(0xFF){
        fprintf(stdout,"[%s cuwacunu %s:] sleep thread--- ... ---\n",COLOR_CUWACUNU,COLOR_REGULAR);
        Uint32 start_time = SDL_GetTicks();
        launch_step_event();
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_MAIN_PERIOD)){
            SDL_Delay((1000*CLOCK_MAIN_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    fprintf(stdout,"[%s cuwacunu %s:] : end : IICU_clock_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    pthread_exit(NULL);
}