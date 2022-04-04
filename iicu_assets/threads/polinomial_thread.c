#include "polinomial_thread.h"
#include "../iicu/iicu_loops.h"
// so what the polinomial! 
// this a indea of a frined of mine, to be know as kike.
// in antempt to make it frendly all its knowing is here.
// i dont now belive in polinomials ---he does!
void *IICU_polinomial_thread(void *_iicu_wikimyei){
    fprintf(stdout,"[%s cuwacunu %s:] : start : IICU_polinomial_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    while(0xFF){
        Uint32 start_time = SDL_GetTicks();
        polinomial_loop(_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_POLINOMIAL_PERIOD)){
            SDL_Delay((1000*CLOCK_POLINOMIAL_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    fprintf(stdout,"[%s cuwacunu %s:] : end : IICU_polinomial_thread()\n",COLOR_CUWACUNU,COLOR_REGULAR);
    pthread_exit(NULL);
}