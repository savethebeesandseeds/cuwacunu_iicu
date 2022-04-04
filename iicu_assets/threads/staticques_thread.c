#include "staticques_thread.h"
#include "../iicu/iicu_loops.h"
// i do instead belive in machines and adaptivness, so i'll be
// driving most of the flow, until polinomial shows wordty. 
void *IICU_staticques_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[%s cuwacunu %s:] : start : IICU_staticques_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    while(0xFF){
        fprintf(stdout,"[%s cuwacunu %s:] step staticques thread--- ... ---\n",COLOR_CUWACUNU,COLOR_REGULAR);
        Uint32 start_time = SDL_GetTicks();
        staticques_loop(_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_STATICQUES_PERIOD)){
            SDL_Delay((1000*CLOCK_STATICQUES_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    fprintf(stdout,"[%s cuwacunu %s:] : end : IICU_staticques_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    pthread_exit(NULL);
}