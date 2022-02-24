#ifndef __SDL_UTILS__
#define __SDL_UTILS__
#ifdef __ANDROID__
#   include "SDL.h"
#   include "SDL_ttf.h"
#   include "android/log.h"
#else
#   include "SDL2/SDL.h"
#   include "SDL2/SDL_ttf.h"
#endif
#include "sdl_object.h"
//-------------------------------------------
void sdl_abandon_ship();
int miss_or_catch_sdl_event(sdl_screen_object_t *obj_sdl);
int handle_sdl_event(sdl_screen_object_t *obj_sdl);
int wait_for_sdl_event(sdl_screen_object_t *obj_sdl);
int handle_joystick_events(const SDL_Event * event);
int handle_keyboard_events(const SDL_Event * event);
int handle_mouse_events(const SDL_Event * event);
int handle_window_events(const SDL_Event * event);
int is_sdl_event(SDL_Event * event);
int is_sdl_quit_event(const SDL_Event * event);
int is_sdl_keyboard_event(const SDL_Event * event);
int is_sdl_window_event(const SDL_Event * event);
int is_sdl_mouse_event(const SDL_Event * event);
int test_keyboard();
int test_controller();
#include "../config/sdl_config.h"
#include "../config/states_config.h"
#endif