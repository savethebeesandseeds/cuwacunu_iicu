#include "thread_launcher.h"
void launch_IICU(){
    // --- --- --- thread launcher
    fprintf(stdout,"[cuwacunu:] : start : launch_IICU()\n");
    // --- --- --- --- · --- --- --- --- INITIALIZE
    __iicu_wikimyei_t *c_iicu_wikimyei=iicu_wikimyei_fabric();
    pthread_t main_thread_launcher[MAIN_NUM_THREADS]; // main thread launcher
    int rc;
    // --- --- --- 
    #ifdef __cwcn_CLOCK_THREAD__
    // --- --- --- clock thread
    rc=pthread_create(&main_thread_launcher[0],NULL,IICU_clock_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_clock_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    #ifdef __cwcn_BROKER_THREAD__
    // --- --- --- broker thread
    rc=pthread_create(&main_thread_launcher[1],NULL,IICU_broker_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_broker_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- main thread
    #ifdef __cwcn_MAIN_THREAD__
    rc=pthread_create(&main_thread_launcher[2],NULL,IICU_main_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_main_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- state thread
    #ifdef __cwcn_STATE_THREAD__
    rc=pthread_create(&main_thread_launcher[3],NULL,IICU_state_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_state_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- jkimyei thread
    #ifdef __cwcn_JKIMYEI_THREAD__
    SDL_Delay(5000); // #FIXME 
    rc=pthread_create(&main_thread_launcher[4],NULL,IICU_jkimyei_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_jkimyei_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- 
    fprintf(stdout,"[cuwacunu:] : end   : launch_IICU()\n");
    pthread_exit(NULL);
}
