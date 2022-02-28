#include "sdl_control.h"

// ---- ---- ---- ---- ---- 
void sdl_abandon_ship(){
    fprintf(stdout,"[cuwacunu:] iicu quit...\n");
    exit(0);
}
int test_keyboard(){
    int return_state=STATE_STATUS_UP;
    return return_state; // #FIXME allways true
}
int test_controller(){
    int return_state;
    if(SDL_NumJoysticks()==0){
        return_state=STATE_STATUS_DOWN;
    } else {
        return_state=STATE_STATUS_UP;
    }
    return return_state;
}
// ---- ---- ---- ---- ---- 
int handle_joystick_events(__iicu_wikimyei_t *_iicu_wikimyei){
	int keyCode=__cwcn_EVENT_WAIT;
    SDL_Event *event=&_iicu_wikimyei->obj_sdl->event;
    switch (event->type){ // SDL_JOYAXISMOTION,SDL_JOYBALLMOTION,SDL_JOYHATMOTION,SDL_JOYBUTTONDOWN,SDL_JOYBUTTONUP,SDL_JOYDEVICEADDED,SDL_JOYDEVICEREMOVED
    case SDL_JOYDEVICEADDED:
        #ifdef __cwcn_DEBUG_JOYSTICK_EVENTS__
        fprintf(stdout,"SDL_JOYDEVICEADDED...\n");
        #endif
        break;
    case SDL_JOYDEVICEREMOVED:
        #ifdef __cwcn_DEBUG_JOYSTICK_EVENTS__
        fprintf(stdout,"SDL_JOYDEVICEREMOVED...\n");
        #endif
        break;
    case SDL_JOYBUTTONDOWN:
        #ifdef __cwcn_DEBUG_JOYSTICK_EVENTS__
        fprintf(stdout,"[waka] Joystick-KEY : jbutton.button: %d\n",
            event->jbutton.button);
        #endif
        switch (event->jbutton.button){
        case 9:
            keyCode=__cwcn_EVENT_CONTINUE;
            break;
        break;
        }
    case SDL_JOYAXISMOTION:
        // event->jaxis.value == -129 means the jaxis action return to steady position
        #ifdef __cwcn_DEBUG_JOYSTICK_EVENTS__
        fprintf(stdout,"[waka] Joystick-KEY : jbutton.button: %d ,jaxis.axis: %d, jaxis.value: %d \n",
            event->jbutton.button,
            event->jaxis.axis,
            event->jaxis.value);
        #endif
        switch (event->jbutton.button){
        case 1: // UP/DOWN/LEFT/RIGHT
            if(event->jaxis.value!=-129 && abs(event->jaxis.value)>100){
                switch (event->jaxis.axis){
                case 1: // UP/DOWN
                    switch (event->jaxis.value<0){
                        case 0x01: // UP
                        printf("UP \n");
                        iicu_scene_go_up(_iicu_wikimyei);
                        break;
                        case 0x00: // DOWN
                        printf("DOWN \n");
                        iicu_scene_go_down(_iicu_wikimyei);
                        break;
                    }
                    break;
                default:
                    break;
                }
            }
        default:
            break;
        }
        break;
    default:
        break;
    }
    return keyCode;
}

int handle_keyboard_events(__iicu_wikimyei_t *_iicu_wikimyei){
	int keyCode=__cwcn_EVENT_WAIT;
    SDL_Event *event=&_iicu_wikimyei->obj_sdl->event;
    #ifdef __cwcn_DEBUG_KEYBOARD_EVENTS__
    fprintf(stdout,"KEYBOARD-KEY : [%d] : %s \n",event->type,SDL_GetKeyName(event->key.keysym.sym));
    #endif
    #ifdef NO_KEY_REPEAT
    if(!event->key.repeat){
    #else
    if(0xFF){
    #endif
        switch (event->type){ // SDL_KEYDOWN,SDL_KEYUP;
        case SDL_KEYDOWN:
            switch (event->key.keysym.sym){
            case SDLK_ESCAPE:
                sdl_abandon_ship();
            case SDLK_q:
                keyCode=__cwcn_EVENT_CONTINUE;
                break;
            default:
                break;
            }
        // case SDL_KEYUP:
        default:
            break;
        }
    }
    return keyCode;
}

int handle_mouse_events(__iicu_wikimyei_t *_iicu_wikimyei){
	int keyCode=__cwcn_EVENT_WAIT;
    // SDL_Event *event=&_iicu_wikimyei->obj_sdl->event;
    #ifdef __cwcn_DEBUG_MOUSE_EVENTS__
    fprintf(stdout,"Mouse-KEY : %d \n",event->jbutton.button);
    #endif
    // switch (event->type){
    //     case SDL_MOUSEBUTTONDOWN:
    //         keyCode=event->key.keysym.sym;
    //         switch (event->button.button){
    //             case SDL_BUTTON_LEFT:
    //                 fprintf(stdout,"SDL_BUTTON_LEFT  (x=%d,y=%d)\n",event->button.x,event->button.y);
    //                 break;
    //             case SDL_BUTTON_RIGHT:
    //                 fprintf(stdout,"SDL_BUTTON_RIGHT (x=%d,y=%d)\n",event->button.x,event->button.y);
    //                 break;
    //         }
            // default:
            // fprintf(stdout,"Window %d got unknown event %d",
            //         event->window.windowID, event->window.event);
            // break;
    //     break;
    // }
    return keyCode;
}

int handle_window_events(__iicu_wikimyei_t *_iicu_wikimyei){
    int keyCode=__cwcn_EVENT_WAIT;
    SDL_Event *event=&_iicu_wikimyei->obj_sdl->event;
    switch (event->window.event) {
    case SDL_WINDOWEVENT_SHOWN:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d shown\n", event->window.windowID);
        #endif
        break;
    case SDL_WINDOWEVENT_HIDDEN:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d hidden\n", event->window.windowID);
        #endif
        break;
    case SDL_WINDOWEVENT_EXPOSED:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d exposed\n", event->window.windowID);
        #endif
        break;
    case SDL_WINDOWEVENT_MOVED:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d moved to %d,%d\n",
                event->window.windowID, event->window.data1,
                event->window.data2);
        #endif
        break;
    case SDL_WINDOWEVENT_RESIZED:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d resized to %dx%d\n",
                event->window.windowID, event->window.data1,
                event->window.data2);
        #endif
        break;
    case SDL_WINDOWEVENT_SIZE_CHANGED:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d size changed to %dx%d\n",
                event->window.windowID, event->window.data1,
                event->window.data2);
        #endif
        break;
    case SDL_WINDOWEVENT_MINIMIZED:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d minimized\n", event->window.windowID);
        #endif
        break;
    case SDL_WINDOWEVENT_MAXIMIZED:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d maximized\n", event->window.windowID);
        #endif
        break;
    case SDL_WINDOWEVENT_RESTORED:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d restored\n", event->window.windowID);
        #endif
        break;
    case SDL_WINDOWEVENT_ENTER:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Mouse entered window %d\n",
                event->window.windowID);
        #endif
        break;
    case SDL_WINDOWEVENT_LEAVE:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Mouse left window %d\n", event->window.windowID);
        #endif
        break;
    case SDL_WINDOWEVENT_FOCUS_GAINED:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d gained keyboard focus\n",
                event->window.windowID);
        #endif
        break;
    case SDL_WINDOWEVENT_FOCUS_LOST:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d lost keyboard focus\n",
                event->window.windowID);
        #endif
        break;
    case SDL_WINDOWEVENT_CLOSE:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d closed\n", event->window.windowID);
        #endif
        break;
    #if SDL_VERSION_ATLEAST(2, 0, 5)
    case SDL_WINDOWEVENT_TAKE_FOCUS:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d is offered a focus\n", event->window.windowID);
        #endif
        break;
    case SDL_WINDOWEVENT_HIT_TEST:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d has a special hit test\n", event->window.windowID);
        #endif
        break;
    #endif
    default:
        #ifdef __cwcn_DEBUG_WINDOW_EVENTS__
        fprintf(stdout,"Window %d got unknown event %d\n",
                event->window.windowID, event->window.event);
        #endif
        break;
    }
    return keyCode;
}
// ---- ---- ---- ---- ---- 
int is_sdl_event(SDL_Event * event){
    #ifdef __cwcn_WAIT_KEY_EVENT__ // activate if blocking update is needed
    return SDL_WaitEvent(event) || 1;
    #elif defined(__cwcn_WAIT_POLL_EVENT__) || defined(__cwcn_WAIT_NO_EVENT__)// activate if constat update is needed (high cpu usage)
    return SDL_PollEvent(event);
    #else
    fprintf(stderr,"ERROR: no cwcn event handling method configured...\n");
    sdl_abandon_ship();
    return 0;
    #endif
}
// ---- ---- ---- ---- ---- 
int is_sdl_quit_event(const SDL_Event * event){
    return event->type==SDL_QUIT;
}
int is_sdl_keyboard_event(const SDL_Event * event){
    return event->type==SDL_KEYDOWN || event->type==SDL_KEYUP;
}
int is_sdl_joystick_event(const SDL_Event * event){
    return event->type==SDL_JOYAXISMOTION ||
    event->type==SDL_JOYBALLMOTION ||
    event->type==SDL_JOYHATMOTION ||
    event->type==SDL_JOYBUTTONDOWN ||
    event->type==SDL_JOYBUTTONUP ||
    event->type==SDL_JOYDEVICEADDED ||
    event->type==SDL_JOYDEVICEREMOVED;
}
int is_sdl_window_event(const SDL_Event * event){
    return event->type == SDL_WINDOWEVENT;
}
int is_sdl_mouse_event(const SDL_Event * event){
    return event->type==SDL_MOUSEMOTION || 
    event->type==SDL_MOUSEBUTTONDOWN || 
    event->type==SDL_MOUSEBUTTONUP || 
    event->type==SDL_MOUSEWHEEL;
}
// ---- ---- ---- ---- ---- 

/**
 * @brief miss_or_catch_sdl_event
 */
int miss_or_catch_sdl_event(__iicu_wikimyei_t *_iicu_wikimyei){
	int keyCode=__cwcn_EVENT_CONTINUE;
    while(SDL_PollEvent(&_iicu_wikimyei->obj_sdl->event)){
        // fprintf(stdout,"miss_or_catch_sdl_event waka...\n");
        if(is_sdl_quit_event(&_iicu_wikimyei->obj_sdl->event)){
            sdl_abandon_ship();
        } else if(is_sdl_keyboard_event(&_iicu_wikimyei->obj_sdl->event)){
            keyCode=handle_keyboard_events(_iicu_wikimyei);
        } else if(is_sdl_joystick_event(&_iicu_wikimyei->obj_sdl->event)){
            keyCode=handle_joystick_events(_iicu_wikimyei);
        } else if(is_sdl_window_event(&_iicu_wikimyei->obj_sdl->event)){
            keyCode=handle_window_events(_iicu_wikimyei);
        } else if(is_sdl_mouse_event(&_iicu_wikimyei->obj_sdl->event)){
            keyCode=handle_mouse_events(_iicu_wikimyei);
        }  // else: unrecognized event
        if(keyCode!=__cwcn_EVENT_WAIT){
            break;
        }
    }
    return keyCode;
}

/**
 * @brief handle_sdl_event
 *      wait for an event
 */
int handle_sdl_event(__iicu_wikimyei_t *_iicu_wikimyei){
	int keyCode=__cwcn_EVENT_WAIT;
    while(is_sdl_event(&_iicu_wikimyei->obj_sdl->event)){
        // fprintf(stdout,"handle_sdl_event waka...\n");
        if(is_sdl_quit_event(&_iicu_wikimyei->obj_sdl->event)){
            sdl_abandon_ship();
        } else if(is_sdl_keyboard_event(&_iicu_wikimyei->obj_sdl->event)){
            keyCode=handle_keyboard_events(_iicu_wikimyei);
        } else if(is_sdl_joystick_event(&_iicu_wikimyei->obj_sdl->event)){
            keyCode=handle_joystick_events(_iicu_wikimyei);
        } else if(is_sdl_window_event(&_iicu_wikimyei->obj_sdl->event)){
            keyCode=handle_window_events(_iicu_wikimyei);
        } else if(is_sdl_mouse_event(&_iicu_wikimyei->obj_sdl->event)){
            keyCode=handle_mouse_events(_iicu_wikimyei);
        }  // else: unrecognized event
        if(keyCode!=__cwcn_EVENT_WAIT){
            break;
        }
    }
    return keyCode;
}
/**
 * @brief wait_for_sdl_event
 *      wait for an event
 */
int wait_for_sdl_event(__iicu_wikimyei_t *_iicu_wikimyei){
    #ifdef __cwcn_DEBUG_EVENTS__
    fprintf(stdout,"[waka] [start] wait_for_sdl_event...\n");
    #endif
	int keyCode=__cwcn_EVENT_WAIT;
	while (0xFF){
        #ifdef __cwcn_DEBUG_EVENTS__
        fprintf(stdout,"[waka] [event!]\n");
        #endif
    #ifdef __cwcn_WAIT_NO_EVENT__
    break;
    #endif
        keyCode=handle_sdl_event(_iicu_wikimyei);
        if(keyCode!=__cwcn_EVENT_WAIT){
            break;
        }
    }
    #ifdef __cwcn_DEBUG_EVENTS__
    fprintf(stdout,"[waka] [end  ] wait_for_sdl_event...\n");
    #endif
	return keyCode;
}