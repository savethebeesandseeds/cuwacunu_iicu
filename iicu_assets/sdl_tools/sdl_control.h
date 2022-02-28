#ifndef __SDL_CONTROL__
#define __SDL_CONTROL__
#include "../config/general_config.h"
#include "../config/sdl_config.h"
#include "../sdl_tools/sdl_object.h"
#include "../iicu/iicu_wikimyei.h"
//-------------------------------------------
void sdl_abandon_ship();
int miss_or_catch_sdl_event(__iicu_wikimyei_t *_iicu_wikimyei);
int handle_sdl_event(__iicu_wikimyei_t *_iicu_wikimyei);
int wait_for_sdl_event(__iicu_wikimyei_t *_iicu_wikimyei);
int handle_joystick_events(__iicu_wikimyei_t *_iicu_wikimyei);
int handle_keyboard_events(__iicu_wikimyei_t *_iicu_wikimyei);
int handle_mouse_events(__iicu_wikimyei_t *_iicu_wikimyei);
int handle_window_events(__iicu_wikimyei_t *_iicu_wikimyei);
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