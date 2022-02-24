#include "thread_launcher.h"
void launch_IICU(){
    // --- --- --- thread launcher
    fprintf(stdout,"[cuwacunu:] : start : launch_IICU()\n");
    pthread_t threads[NUM_THREADS];
    int rc;
    // --- --- --- main thread
    // IICU_main_thread((void *)1);
    rc=pthread_create(&threads[0],NULL,IICU_main_thread,(void*)1);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_main_thread) is %d\n",rc);
        exit(-1);
    }
    // --- --- --- clock thread
    rc=pthread_create(&threads[1],NULL,IICU_clock_thread,(void*)1);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create(IICU_clock_thread) is %d\n",rc);
        exit(-1);
    }
    // --- --- --- 
    pthread_exit(NULL);
    fprintf(stdout,"[cuwacunu:] : end   : launch_IICU()\n");
}
