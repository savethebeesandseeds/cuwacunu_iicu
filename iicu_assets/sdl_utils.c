#include "sdl_utils.h"
/**
 * @brief wait_for_sdl_event
 *      wait for an event
 */
int wait_for_sdl_event(SDL_Event event){
    printf("[waka] wating sdl event...\n");
	int nBreak=1;
	int keyCode=SDL_EVENT_CONTINUE;
	#ifndef __cwcn_WAIT_NO_EVENT__ // activate to render at the CPU speed
	while (nBreak){
		#ifdef __cwcn_WAIT_KEY_EVENT__ // activate if blocking update is needed
	    if(SDL_WaitEvent(&event) || 1){ 
		#endif
		#ifdef __cwcn_WAIT_POLL_EVENT__ // activate if constat update is needed (high cpu usage)
		if (SDL_PollEvent(&event)){
		#endif
            switch (event.type){
                case SDL_QUIT:
                    nBreak=0;
                    keyCode=SDL_EVENT_BREAK;
                    exit(0);
                case SDL_KEYDOWN:
                    keyCode=event.key.keysym.sym;
                    switch (event.key.keysym.sym){
                        case SDLK_ESCAPE:
                        case SDLK_q:
                            nBreak=0;
                            keyCode=SDL_EVENT_CONTINUE;
                            break;
                    }
                    break;
            }
        }
	}
	#endif
    return keyCode;
}
// if (SDL_PollEvent(&event)){
//     switch (event.type){
//         case SDL_QUIT:
//             gameover = 1;
//             break;

//     case SDL_KEYDOWN:
//         switch (event.key.keysym.sym){
//             case SDLK_ESCAPE:
//             case SDLK_q:
//                 gameover = 1;
//                 break;

//         }
//         break;
//     }
// }