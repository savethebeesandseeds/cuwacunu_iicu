#include "cuwacunu_iicu.h"


void loading_loop(sdl_screen_object_t *obj_sdl){
    step_screen(obj_sdl);
        render_loading(obj_sdl);
    draw_screen(obj_sdl);
}

void home_loop(sdl_screen_object_t *obj_sdl){
        update_iicu_state(obj_sdl);
    step_screen(obj_sdl);
        render_state_panel(obj_sdl);
        render_home(obj_sdl);
    draw_screen(obj_sdl);
        wait_for_sdl_event(obj_sdl);
}

void *IICU_main_loop(void *threadid){
    fprintf(stdout,"[cuwacunu:] : start : IICU_main_loop()\n");
	clock_t begin;
	clock_t end;
	double time_spent;
    float rand_event;
    float orb_angle;
    char orb_caption[20];
    SDL_Color orbitalColor={.r = 255, .g = 255, .b = 255, .a = 255};
    // --- --- --- --- · --- --- --- --- SCREEN
    sdl_screen_object_t obj_sdl;
    initialize_screen(&obj_sdl);
    // --- --- --- --- · --- --- --- --- LOADING
    loading_loop(&obj_sdl);
    // --- --- --- --- · --- --- --- --- STATE
    initialize_iicu_state(&obj_sdl);
    // --- --- --- --- · --- --- --- --- HOME
    home_loop(&obj_sdl);
    // --- --- --- --- · --- --- --- --- MAIN LOOP
    while (0xFF){
        // --- --- --- --- · --- --- --- --- populate coordinate list
        populate_central_plot_coordinate_list(&obj_sdl);
        begin = clock();
        // --- --- --- --- · --- --- --- --- PLOT 
        step_screen(&obj_sdl);
        obj_sdl.screen_state.interface_id=CENTRAL_SCREEN_PANEL_STATE_ID;
        draw_central_plot(&obj_sdl);
        rand_event=(float)rand()/(float)RAND_MAX;
        orb_angle=(float)rand_event*360.0-180.0;
        sprintf(orb_caption,"orbital :: %f",orb_angle);
        DrawOrbital(&obj_sdl, orb_caption, 750, 250, 40, orb_angle, orbitalColor);
        rand_event=(float)rand()/(float)RAND_MAX;
        orb_angle=(float)rand_event*360.0-180.0;
        sprintf(orb_caption,"orbital :: %f",orb_angle);
        DrawOrbital(&obj_sdl, orb_caption, 750, 350, 40, orb_angle, orbitalColor);
        draw_screen(&obj_sdl);
        end = clock();
        time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
        printf("[waka] :: update screen :: fps :: %f\n",1/time_spent);
        wait_for_sdl_event(&obj_sdl);
    }
	clean_plot(&obj_sdl.central_plot, &obj_sdl.central_plot_params);
    clean_screen(&obj_sdl);
    pthread_exit(NULL);
    fprintf(stdout,"[cuwacunu:] : end : IICU_main_loop()\n");
}

void launch_IICU(){
    fprintf(stdout,"[cuwacunu:] : start : launch_IICU()\n");
    pthread_t threads[1];
    int rc;
    rc=pthread_create(&threads[0],NULL,IICU_main_loop,(void*)1);
    if(rc){
        fprintf(stderr,"ERROR; return code from pthread_create() is %d\n",rc);
        exit(-1);
    }
    pthread_exit(NULL);
    fprintf(stdout,"[cuwacunu:] : end : launch_IICU()\n");
}
    