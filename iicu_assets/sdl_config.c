#include "sdl_config.h"
/**
 * @brief make_plot_config
 *      utility for filling
 * @param c_plot_params
 *      empty plot_params struct to be filled
 * @param ...
 */
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
    rgb_color *text_color){ // Specify Config
    c_plot_params.screen_width=screen_width;
    c_plot_params.screen_heigth=screen_heigth;
    c_plot_params.plot_window_title=plot_window_title;
    c_plot_params.font_text_path=font_text_path;
    c_plot_params.font_text_size=font_text_size;
    c_plot_params.caption_text_x=caption_text_x;
    c_plot_params.caption_text_y=caption_text_y;
    c_plot_params.caption_list=caption_list;
    c_plot_params.coordinate_list=coordinate_list;
    c_plot_params.scale_x=scale_x;
    c_plot_params.scale_y=scale_y;
    c_plot_params.max_x=max_x;
    c_plot_params.max_y=max_y;
    c_plot_params.plot_backgrownd_color=plot_backgrownd_color;
    c_plot_params.screen_backgrownd_color=screen_backgrownd_color;
    c_plot_params.borders_color=borders_color;
    c_plot_params.text_color=text_color;
    return c_plot_params;
}
/**
 * @brief central_plot_config
 *      default configuration to populate central plot configuration
 * @param c_plot_params
 *      empty plot_params struct to be filled
 *  plot_params.caption_list        is left blank or NULL
 *  plot_params.coordinate_list     is left blank or NULL
 */
plot_params central_plot_config(plot_params c_plot_params){
    // --- --- --- --- 
    // --- --- screen
    c_plot_params.screen_width=800;
	c_plot_params.screen_heigth=640;
    // --- --- text
	c_plot_params.plot_window_title="CUWACUNU IICU";
	c_plot_params.font_text_path="./iicu_resources/opensans.ttf";
	c_plot_params.font_text_size=18;
    // --- --- x,y
	c_plot_params.caption_text_x="Time (s)";
	c_plot_params.caption_text_y="Price";
	c_plot_params.scale_x = 1;
	c_plot_params.scale_y = 10;
	c_plot_params.max_x = 10;
	c_plot_params.max_y = 120;
    // --- --- data
    c_plot_params.caption_list=NULL;            // left blank
    c_plot_params.coordinate_list=NULL;         // left blank
    // --- --- colors
    c_plot_params.plot_backgrownd_color=NULL;
    c_plot_params.screen_backgrownd_color=NULL;
    c_plot_params.borders_color=NULL;
    c_plot_params.text_color=NULL;
    // --- --- --- --- 
    return c_plot_params;
}