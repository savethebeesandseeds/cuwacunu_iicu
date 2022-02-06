#ifndef __SDL_CONFIG__
#define __SDL_CONFIG__
#define SDL_EVENT_CONTINUE 0xF5F5FF5
#define SDL_EVENT_BREAK 0xF1F51F1
// #define __cwcn_WAIT_NO_EVENT__
// #define __cwcn_WAIT_KEY_EVENT__
#define __cwcn_WAIT_POLL_EVENT__
#if !defined(__cwcn_WAIT_KEY_EVENT__) && !defined(__cwcn_WAIT_POLL_EVENT__) && !defined(__cwcn_WAIT_NO_EVENT__)
#error (sdl_config.h) Please define the __cwcn_WAIT_(*)_EVENT__ : __cwcn_WAIT_NO_EVENT__ or __cwcn_WAIT_KEY_EVENT__ or __cwcn_WAIT_POLL_EVENT__
#endif
#if \
(defined(__cwcn_WAIT_POLL_EVENT__) && (defined(__cwcn_WAIT_NO_EVENT__) || defined(__cwcn_WAIT_KEY_EVENT__))) || \
(defined(__cwcn_WAIT_KEY_EVENT__) && (defined(__cwcn_WAIT_POLL_EVENT__) || defined(__cwcn_WAIT_NO_EVENT__))) || \
(defined(__cwcn_WAIT_NO_EVENT__) && (defined(__cwcn_WAIT_KEY_EVENT__) || defined(__cwcn_WAIT_POLL_EVENT__)))
#error (sdl_config.h) Please define just one for __cwcn_WAIT_(*)_EVENT__ : __cwcn_WAIT_NO_EVENT__ or __cwcn_WAIT_KEY_EVENT__ or __cwcn_WAIT_POLL_EVENT__
#endif

#include "plotsdl/sdl_plot.h"

plot_params make_plot_config(
    plot_params c_plot_params,
    int screen_width,
	int screen_heigth,
	char * plot_window_title,
	char * font_text_path,
	int font_text_size,
	char * caption_text_x,
	char * caption_text_y,
	captionlist caption_list,
	coordlist coordinate_list,
	float scale_x,
	float scale_y,
	float max_x,
	float max_y,
    rgb_color *plot_backgrownd_color,
	rgb_color *screen_backgrownd_color,
	rgb_color *borders_color,
	rgb_color *text_color);
plot_params central_plot_config(plot_params c_plot_params);
#endif