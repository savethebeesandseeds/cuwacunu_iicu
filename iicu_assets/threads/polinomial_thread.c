#include "polinomial_thread.h"
// so what the polinomial! 
// this a indea of a frined of mine, to be know as kike.
// in antempt to make it frendly all its knowing is here.
// i dont now belive in polinomials ---he does!
void *IICU_polinomial_|thread(void *_iicu_wikimyei){
    fprintf(stdout,"[cuwacunu:] : start : IICU_polinomial_thread()\n");
    while(0xFF){
        Uint32 start_time = SDL_GetTicks();
        polinomial_loop(_iicu_wikimyei);
        if((SDL_GetTicks()-start_time)<(1000*CLOCK_JKIMYEI_PERIOD)){
            SDL_Delay((1000*CLOCK_JKIMYEI_PERIOD)-(SDL_GetTicks()-start_time));
        }
    }
    pthread_exit(NULL);
    fprintf(stdout,"[cuwacunu:] : end : IICU_polinomial_thread()\n");
}