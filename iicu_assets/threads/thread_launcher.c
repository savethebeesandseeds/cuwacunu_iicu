#include "thread_launcher.h"

void launch_IICU(){
    // --- --- --- thread launcher
    fprintf(stdout,"[cuwacunu:] : start : launch_IICU()\n");
    // --- --- --- --- · --- --- --- --- INITIALIZE
    __iicu_wikimyei_t *c_iicu_wikimyei=iicu_wikimyei_fabric();
    pthread_t untsdao_launcher[MAIN_NUM_THREADS]; // main thread launcher
    int rc;
    // --- --- --- 
    #ifdef __cwcn_CLOCK_THREAD__
    // --- --- --- clock thread
    rc=pthread_create(&untsdao_launcher[0],NULL,IICU_clock_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_clock_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    #ifdef __cwcn_BROKER_THREAD__
    // --- --- --- broker thread
    rc=pthread_create(&untsdao_launcher[1],NULL,IICU_broker_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_broker_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- main thread
    #ifdef __cwcn_MAIN_THREAD__
    rc=pthread_create(&untsdao_launcher[2],NULL,IICU_main_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_main_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- state thread
    #ifdef __cwcn_STATE_THREAD__
    rc=pthread_create(&untsdao_launcher[3],NULL,IICU_state_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_state_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- itsaave thread
    #ifdef __cwcn_ITSAAVE_THREAD__
    SDL_Delay(2500); // #FIXME 
    rc=pthread_create(&untsdao_launcher[4],NULL,IICU_itsaave_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_itsaave_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- jkimyei thread
    #ifdef __cwcn_JKIMYEI_THREAD__
    SDL_Delay(2500); // #FIXME 
    rc=pthread_create(&untsdao_launcher[4],NULL,IICU_jkimyei_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_jkimyei_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- regressive thread
    #ifdef __cwcn_REGRESSIVE_THREAD__
    SDL_Delay(2500); // #FIXME 
    rc=pthread_create(&untsdao_launcher[5],NULL,IICU_regressive_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_regressive_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // // --- --- --- polinomial thread
    #ifdef __cwcn_POLINOMIAL_THREAD__
    SDL_Delay(2500); // #FIXME 
    rc=pthread_create(&untsdao_launcher[6],NULL,IICU_polinomial_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_polinomial_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- staticques thread
    #ifdef __cwcn_STATICQUES_THREAD__
    SDL_Delay(2500); // #FIXME 
    rc=pthread_create(&untsdao_launcher[7],NULL,IICU_staticques_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_staticques_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- 
    fprintf(stdout,"[cuwacunu:] : end   : launch_IICU()\n");
    pthread_exit(NULL);
}
