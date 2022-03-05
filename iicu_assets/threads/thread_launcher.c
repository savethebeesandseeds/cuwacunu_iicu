#include "thread_launcher.h"
void launch_IICU(){
    // --- --- --- thread launcher
    fprintf(stdout,"[cuwacunu:] : start : launch_IICU()\n");
    // --- --- --- --- · --- --- --- --- INITIALIZE
    __iicu_wikimyei_t *c_iicu_wikimyei=iicu_wikimyei_fabric();
    pthread_t threads[NUM_THREADS];
    int rc;
    // --- --- --- 
    #ifdef __cwcn_CLOCK_THREAD__
    // --- --- --- clock thread
    rc=pthread_create(&threads[1],NULL,IICU_clock_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_clock_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    #ifdef __cwcn_BROKER_THREAD__
    // --- --- --- broker thread
    rc=pthread_create(&threads[1],NULL,IICU_broker_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_broker_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- main thread
    #ifdef __cwcn_MAIN_THREAD__
    rc=pthread_create(&threads[0],NULL,IICU_main_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_main_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- state thread
    #ifdef __cwcn_STATE_THREAD__
    rc=pthread_create(&threads[0],NULL,IICU_state_thread,(void*)c_iicu_wikimyei);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_state_thread) is %d\n",rc);
        exit(-1);
    }
    #endif
    // --- --- --- 
    pthread_exit(NULL);
    fprintf(stdout,"[cuwacunu:] : end   : launch_IICU()\n");
}
