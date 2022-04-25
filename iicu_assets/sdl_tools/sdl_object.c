#include "sdl_object.h"

__sdl_screen_object_t *fabric_obj_sdl(){
	__sdl_screen_object_t *new_obj_sdl=malloc(sizeof(__sdl_screen_object_t));
	initialize_sdl_object(new_obj_sdl);
	return new_obj_sdl;
}
void destroy_obj_sdl(__sdl_screen_object_t *obj_sdl){
	kill_sdl_object(obj_sdl);
	free(obj_sdl);
}
/**
 * @brief initialize_sdl_object
 */
void initialize_sdl_object(__sdl_screen_object_t *obj_sdl){
	// --- --- --- --- · --- --- --- --- OS
	setvbuf(stdout, NULL, _IONBF, 0);
	SDL_Init(SDL_INIT_EVERYTHING); // SDL_Init(SDL_INIT_EVENTS);
	if(SDL_NumJoysticks()==0){
        fprintf(stdout,"WARNING: wait_for_sdl_joystick_event : no joystick device were found, calling wait_for_sdl_keyboard_event() instead...\n");
    } else {
        SDL_JoystickEventState(SDL_ENABLE);
        if(!SDL_JoystickOpen(0)){ // SDL_Joystick *joy = SDL_JoystickOpen(0);
            fprintf(stdout,"WARNING: wait_for_sdl_joystick_event : unable to open joystick device, calling wait_for_sdl_keyboard_event() instead...\n");
        }
    }
	// --- --- --- --- · --- --- --- --- FONTS
	if(TTF_Init() == -1){
		fprintf(stderr, "Error SDL TTF_Init error : %s\n", TTF_GetError());
		exit(-1);
	}
	if (SDL_Init(SDL_INIT_VIDEO)==-1){
		fprintf(stderr, "Error SDL init failure : %s\n", SDL_GetError());
		exit(-1);
	}
	obj_sdl->screen_font = TTF_OpenFont(SCREEN_FONT, (int) SCREEN_FONT_SIZE);
	if(obj_sdl->screen_font ==NULL){
		printf("Error font file read failure, check the SCREEN_FONT font file\n");
		exit(-1);
	}
	obj_sdl->home_font = TTF_OpenFont(HOME_FONT, (int) HOME_FONT_SIZE);
	if(obj_sdl->home_font ==NULL){
		printf("Error font file read failure, check the HOME_FONT font file\n");
		exit(-1);
	}

	obj_sdl->mark_font = TTF_OpenFont(MARK_FONT, (int) MARK_FONT_SIZE);
	if(obj_sdl->mark_font ==NULL){
		printf("Error font file read failure, check the MARK_FONT font file\n");
		exit(-1);
	}

	// --- --- --- --- · --- --- --- --- WINDOW
	obj_sdl->screen = SDL_CreateWindow(
		SDL_SCREEN_TITLE,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_SCREEN_WIDTH, 
		SDL_SCREEN_HEIGHT,
	#ifdef __cwcn_MAIN_THREAD__
		SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	#else 
		SDL_WINDOW_HIDDEN);
		#ifdef __cwcn_CONTROLS_THREAD__
		fprintf(stderr,"[%s WARNING: %s] controls actions are not detectable without focus and __cwcn_MAIN_THREAD__ is disabled. \n",COLOR_DANGER,COLOR_REGULAR);
		#endif
	#endif
	if(obj_sdl->screen==NULL){
		fprintf(stderr, "Error cant allocate memory for screen : %s\n", SDL_GetError());
		exit(-1);
	}
	#ifdef SCREEN_MAXIMIZED
    SDL_SetWindowFullscreen(obj_sdl->screen,SCREEN_MAXIMIZED);
    #endif
	
	// --- --- --- --- · --- --- --- --- RENDERER
    obj_sdl->renderer = SDL_CreateRenderer(obj_sdl->screen, -1, SDL_RENDERER_METHOD); // only use of screen
	if(obj_sdl->renderer==NULL){
		fprintf(stderr, "Error cant allocate memory for renderer : %s\n", SDL_GetError());
		exit(-1);
	}

	// --- --- --- --- · --- --- --- --- IICU
}

/**
 * @brief kill_sdl_object
 */
void kill_sdl_object(__sdl_screen_object_t *obj_sdl){
	SDL_DestroyRenderer(obj_sdl->renderer);
	SDL_DestroyWindow(obj_sdl->screen);

	TTF_CloseFont(obj_sdl->home_font);
	TTF_CloseFont(obj_sdl->screen_font);
	TTF_Quit();
	SDL_Quit();
}

/**
 * @brief step_sdl_object
 */
int step_sdl_object(__sdl_screen_object_t *obj_sdl){
	SDL_SetRenderDrawColor(obj_sdl->renderer,0,0,0,255);
	SDL_RenderClear(obj_sdl->renderer);
	return EXIT_SUCCESS;
}

/**
 * @brief draw_sdl_object
 */
int draw_sdl_object(__sdl_screen_object_t *obj_sdl){
	SDL_RenderPresent(obj_sdl->renderer);
	return EXIT_SUCCESS;
}
