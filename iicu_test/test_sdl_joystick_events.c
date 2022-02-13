#include "sdl_utils.h"
#define __cwcn_WAIT_POLL_EVENT__

int handle_joystick_evnet(SDL_Event j_event){
    int nBreak=1;
	int keyCode=SDL_EVENT_CONTINUE;
    printf("[waka] J-KEY : %d \n",j_event.jbutton.button);
    switch (j_event.type){
        case SDL_QUIT:
            nBreak=0;
            keyCode=SDL_EVENT_BREAK;
            fprintf(stdout,"IICU QUIT...\n");
            exit(0);
        case SDL_JOYDEVICEADDED:
            fprintf(stdout,"SDL_JOYDEVICEADDED...\n");
            break;
        case SDL_JOYDEVICEREMOVED:
            fprintf(stdout,"SDL_JOYDEVICEREMOVED...\n");
            break;
        case SDL_JOYBUTTONDOWN:
            printf("[waka] J-KEY : jbutton.button: %d\n",j_event.jbutton.button);
            break;
        case SDL_JOYAXISMOTION:
            printf("[waka] J-KEY : jbutton.button: %d ,jaxis.axis: %d, jaxis.value: %d \n",j_event.jbutton.button,j_event.jaxis.axis,j_event.jaxis.value);
            // jaxis.value == -129 means the jaxis action return to steady position
            break;

        break;
    }
    return SDL_EVENT_CONTINUE;
}
/**
 * @brief wait_for_sdl_joystick_event
 *      wait for an event
 */
int wait_for_sdl_joystick_event(){
    #ifdef __cwcn_DEBUG_EVENTS__
    printf("[waka] [start] wait_for_sdl_joystick_event...\n");
    #endif

    if(SDL_NumJoysticks()==0){
        fprintf(stdout,"WARNING: wait_for_sdl_joystick_event : no joystick device were found, calling wait_for_sdl_keyboard_event() instead...\n");
    } else {
        SDL_JoystickEventState(SDL_ENABLE);
        if(!SDL_JoystickOpen(0)){ // SDL_Joystick *joy = SDL_JoystickOpen(0);
            fprintf(stdout,"WARNING: wait_for_sdl_joystick_event : unable to open joystick device, calling wait_for_sdl_keyboard_event() instead...\n");
        }
    }
    SDL_Event j_event;
	int nBreak=1;
	int keyCode=SDL_EVENT_CONTINUE;
	while (nBreak){
		#ifdef __cwcn_WAIT_KEY_EVENT__ // activate if blocking update is needed
	    if(SDL_WaitEvent(&j_event) || 1){ 
		#endif
		#if defined(__cwcn_WAIT_POLL_EVENT__) || defined(__cwcn_WAIT_NO_EVENT__)// activate if constat update is needed (high cpu usage)
		if (SDL_PollEvent(&j_event)){
		#endif
            printf("[waka] KEY : %s \n",SDL_GetKeyName(j_event.key.keysym.sym));
            // switch (j_event.type){
            //     case SDL_QUIT:
            //         nBreak=0;
            //         keyCode=SDL_EVENT_BREAK;
            //         fprintf(stdout,"IICU QUIT...\n");
            //         exit(0);
            //     case SDL_MOUSEBUTTONDOWN:
            //         keyCode=j_event.key.keysym.sym;
            //         switch (j_event.button.button){
            //             case SDL_BUTTON_LEFT:
            //                 fprintf(stdout,"SDL_BUTTON_LEFT  (x=%d,y=%d)\n",j_event.button.x,j_event.button.y);
            //                 break;
            //             case SDL_BUTTON_RIGHT:
            //                 fprintf(stdout,"SDL_BUTTON_RIGHT (x=%d,y=%d)\n",j_event.button.x,j_event.button.y);
            //                 break;
            //         }
            //     case SDL_KEYDOWN:
            //         keyCode=j_event.key.keysym.sym;
            //         switch (j_event.key.keysym.sym){
            //             case SDLK_ESCAPE:
            //                 nBreak=0;
            //                 keyCode=SDL_EVENT_BREAK;
            //                 fprintf(stdout,"IICU QUIT...\n");
            //                 exit(0);
            //             case SDLK_q:
            //                 nBreak=0;
            //                 keyCode=SDL_EVENT_CONTINUE;
            //                 break;
            //         }
            //         break;
            // }
            keyCode=handle_joystick_evnet(j_event);
        }
        #ifdef __cwcn_WAIT_NO_EVENT__
        break;
        #endif
	}
    #ifdef __cwcn_DEBUG_EVENTS__
    printf("[waka] [end  ] wait_for_sdl_joystick_event...\n");
    #endif
    return keyCode;
}

int main(){
    SDL_Init(SDL_INIT_JOYSTICK);
    // atexit(SDL_Quit);
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    while(1){
        wait_for_sdl_joystick_event();
    }
}