#ifndef __SDL_CONFIG__
#define __SDL_CONFIG__
#ifdef __ANDROID__
#	include "SDL.h"
#	include "SDL_ttf.h"
#	include "SDL_image.h"
#else
#	include "SDL2/SDL.h"
#	include "SDL2/SDL_ttf.h"
#	include "SDL2/SDL_image.h"
#endif
#define SDL_SCREEN_TITLE "IICU (cuwacunu:waajacu)"
#define SDL_SCREEN_WIDTH 1000
#define SDL_SCREEN_HEIGHT 600
#define STATE_PANEL_w_ZERO 20
#define STATE_PANEL_h_ZERO 20
#define STATE_PANEL_x_ZERO SDL_SCREEN_WIDTH - STATE_PANEL_w_ZERO - 10
#define STATE_PANEL_y_ZERO 10

#define SCREEN_FONT "./iicu_resources/NotoSansMono-Light.ttf"// "./iicu_resources/VT323-Regular.ttf" // "./iicu_resources/opensans.ttf"
#define SCREEN_FONT_SIZE 12
#define SCREEN_FONT_DELTA 7
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
#define STATE_PANEL_SCENE_BOX_W 75
#define STATE_PANEL_SCENE_BOX_H SCREEN_FONT_SIZE + 5
#define SDL_RENDERER_METHOD 0 // SDL_RENDERER_SOFTWARE // SDL_RENDERER_ACCELERATED // SDL_RENDERER_PRESENTVSYNC // SDL_RENDERER_TARGETTEXTURE
// #define SCREEN_MAXIMIZED SDL_WINDOW_FULLSCREEN_DESKTOP // SDL_WINDOW_FULLSCREEN // 0

#define DOT_PLOT_RADIUS 3

#define ORBITAL_EXCENTRICITY 0.3
#define MATH_PI (float) acos(-1)

#define NIJCYOTA_ALLIU_INDEX 0
#define NIJCYOTA_NOISE_BOX_LINE_COLOR_R 171
#define NIJCYOTA_NOISE_BOX_LINE_COLOR_G 171
#define NIJCYOTA_NOISE_BOX_LINE_COLOR_B 171
#define NIJCYOTA_DATA_BOX_X 100
#define NIJCYOTA_DATA_BOX_Y 100
#define NIJCYOTA_NOISE_BOX_W 150
#define NIJCYOTA_NOISE_BOX_H (NIJCYOTA_NOISE_BOX_W)
#define NIJCYOTA_NOISE_BOX_X NIJCYOTA_DATA_BOX_X + NIJCYOTA_NOISE_BOX_W - 25
#define NIJCYOTA_NOISE_BOX_Y NIJCYOTA_DATA_BOX_Y - 25
#define NIJCYOTA_NOISE_BOX_DRAW_LINE 0x01
#define NIJCYOTA_NOISE_BOX_DRAW_PERPENDICULAR 0x00
#define NIJCYOTA_NOISE_BOX_DRAW_DOT 0x01

#define NIJCYOTA_ORBITAL_CAPTION "ORBITAL_CAPTION"
#define NIJCYOTA_ORBITAL_RADIUS NIJCYOTA_NOISE_BOX_W*3/8
#define NIJCYOTA_ORBITAL_CENTRE_X NIJCYOTA_NOISE_BOX_X + NIJCYOTA_NOISE_BOX_W + NIJCYOTA_ORBITAL_RADIUS
#define NIJCYOTA_ORBITAL_CENTRE_Y NIJCYOTA_NOISE_BOX_Y + NIJCYOTA_NOISE_BOX_H/2
    

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