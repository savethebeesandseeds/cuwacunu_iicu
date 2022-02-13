#ifndef __SDL_CONFIG__
#define __SDL_CONFIG__

#define SCREEN_TITLE "IICU (cuwacunu:waajacu)"
#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 640
#define SCREEN_FONT "./iicu_resources/opensans.ttf" // #FIXME change to monospaced font FreeMono
#define SCREEN_FONT_SIZE 12

#define SDL_RENDERER_METHOD 0 // SDL_RENDERER_SOFTWARE // SDL_RENDERER_ACCELERATED // SDL_RENDERER_PRESENTVSYNC // SDL_RENDERER_TARGETTEXTURE
// #define SCREEN_MAXIMIZED SDL_WINDOW_FULLSCREEN_DESKTOP // SDL_WINDOW_FULLSCREEN // 0

#define DOT_RADIUS 4
#define CAPTION_OFFSET_CIRCLE_TO_TEXT 10
#define CAPTION_OFFSET_DELIMITER 40
#define GRADUATION_HEIGTH 10
#define CAPTION_Y_LABEL_OFFSET 10
#define CAPTION_MARGIN 30

#define ORBITAL_EXCENTRICITY 0.3
#define MATH_PI (float) acos(-1)

#define __cwcn_DEBUG_EVENTS__
#define __cwcn_DEBUG_JOYSTICK_EVENTS__
#define __cwcn_DEBUG_KEYBOARD_EVENTS__
// #define __cwcn_DEBUG_MOUSE_EVENTS__
// #define __cwcn_DEBUG_WINDOW_EVENTS__

// #define __cwcn_WAIT_NO_EVENT__
#define __cwcn_WAIT_KEY_EVENT__
// #define __cwcn_WAIT_POLL_EVENT__


#define __cwcn_EVENT_WAIT 0xF0F1FF0
#define __cwcn_EVENT_BREAK 0xF1F11F1
#define __cwcn_EVENT_CONTINUE 0xF5F1FF5

#include "../sdl_tools/sdl_screen.h"

plot_params central_plot_config(plot_params c_plot_params);

#if !defined(__cwcn_WAIT_KEY_EVENT__) && !defined(__cwcn_WAIT_POLL_EVENT__) && !defined(__cwcn_WAIT_NO_EVENT__)
#error (sdl_config.h) Please define the __cwcn_WAIT_(*)_EVENT__ : __cwcn_WAIT_NO_EVENT__ or __cwcn_WAIT_KEY_EVENT__ or __cwcn_WAIT_POLL_EVENT__
#endif
#if \
(defined(__cwcn_WAIT_POLL_EVENT__) && (defined(__cwcn_WAIT_NO_EVENT__) || defined(__cwcn_WAIT_KEY_EVENT__))) || \
(defined(__cwcn_WAIT_KEY_EVENT__) && (defined(__cwcn_WAIT_POLL_EVENT__) || defined(__cwcn_WAIT_NO_EVENT__))) || \
(defined(__cwcn_WAIT_NO_EVENT__) && (defined(__cwcn_WAIT_KEY_EVENT__) || defined(__cwcn_WAIT_POLL_EVENT__)))
#error (sdl_config.h) Please define just one for __cwcn_WAIT_(*)_EVENT__ : __cwcn_WAIT_NO_EVENT__ or __cwcn_WAIT_KEY_EVENT__ or __cwcn_WAIT_POLL_EVENT__
#endif
#endif