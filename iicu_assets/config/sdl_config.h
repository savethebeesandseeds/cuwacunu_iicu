#ifndef __SDL_CONFIG__
#define __SDL_CONFIG__

#define SCREEN_TITLE "IICU (cuwacunu:waajacu)"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 640
#define STATE_PANEL_w_ZERO 20
#define STATE_PANEL_h_ZERO 20
#define STATE_PANEL_x_ZERO SCREEN_WIDTH - STATE_PANEL_w_ZERO - 10
#define STATE_PANEL_y_ZERO 10

#define SCREEN_FONT "./iicu_resources/NotoSansMono-Light.ttf"// "./iicu_resources/VT323-Regular.ttf" // "./iicu_resources/opensans.ttf"
#define SCREEN_FONT_SIZE 12
#define HOME_FONT "./iicu_resources/BungeeShade-Regular.ttf"
#define HOME_FONT_SIZE 36
#define MARK_FONT "./iicu_resources/NanumBrushScript-Regular.ttf"
#define MARK_FONT_SIZE 36

#define HOME_STATE_ID (int) 0xFE00
#define LOADING_STATE_ID (int) 0xFE01
#define LOGIN_STATE_ID (int) 0xFE02
#define CONFIG_PANEL_STATE_ID (int) 0xFE03
#define IICU_SCREEN_PANEL_STATE_ID (int) 0xFE04


#define STATE_PANEL_WIFI "./iicu_resources/wifi-solid_white.png"
#define STATE_PANEL_BROKER "./iicu_resources/Binance-coin-bnb-logo.png"
#define STATE_PANEL_KEYBOARD "./iicu_resources/keyboard-solid_white.png"
#define STATE_PANEL_CONTROLLER "./iicu_resources/Controller_white.png"

#define SDL_RENDERER_METHOD 0 // SDL_RENDERER_SOFTWARE // SDL_RENDERER_ACCELERATED // SDL_RENDERER_PRESENTVSYNC // SDL_RENDERER_TARGETTEXTURE
// #define SCREEN_MAXIMIZED SDL_WINDOW_FULLSCREEN_DESKTOP // SDL_WINDOW_FULLSCREEN // 0

#define DOT_PLOT_RADIUS 3
#define CAPTION_OFFSET_CIRCLE_TO_TEXT 10
#define CAPTION_OFFSET_DELIMITER 40
#define GRADUATION_HEIGTH 10
#define CAPTION_Y_LABEL_OFFSET 10
#define CAPTION_MARGIN 30

#define ORBITAL_EXCENTRICITY 0.3
#define MATH_PI (float) acos(-1)

// #define __cwcn_DEBUG_EVENTS__
#define __cwcn_DEBUG_JOYSTICK_EVENTS__
#define __cwcn_DEBUG_KEYBOARD_EVENTS__
// #define __cwcn_DEBUG_MOUSE_EVENTS__
// #define __cwcn_DEBUG_WINDOW_EVENTS__

// #define __cwcn_WAIT_NO_EVENT__
#define __cwcn_WAIT_KEY_EVENT__
// #define __cwcn_WAIT_POLL_EVENT__

// #define NO_KEY_REPEAT

#define __cwcn_EVENT_WAIT 0xF0F1FF0
#define __cwcn_EVENT_BREAK 0xF1F11F1
#define __cwcn_EVENT_CONTINUE 0xF5F1FF5

#include "../sdl_tools/sdl_object.h"

void central_plot_config(splot_params_t *c_plot_params);

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