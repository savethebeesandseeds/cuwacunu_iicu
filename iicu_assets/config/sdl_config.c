#include "sdl_config.h"
/**
 * @brief central_plot_config
 *      default configuration to populate central plot configuration
 * @param c_plot_params
 *      empty plot_params struct to be filled
 *  plot_params.caption_list        is left blank or NULL
 *  plot_params.coordinate_list     is left blank or NULL
 */
void central_plot_config(plot_params *c_plot_params){
    // --- --- --- --- 
    // --- --- plot
    c_plot_params->stroke_width=2;
    c_plot_params->plot_width=600;
	c_plot_params->plot_heigth=300;
    c_plot_params->plot_x=100;
    c_plot_params->plot_y=100;

    c_plot_params->real_plot_width=c_plot_params->plot_width*0.8;
	c_plot_params->real_plot_heigth=c_plot_params->plot_heigth*0.8;
	c_plot_params->real_plot_caption_heigth=c_plot_params->plot_heigth*0.05;
    // --- --- x,y
	c_plot_params->caption_text_x="Time (s)";
	c_plot_params->caption_text_y="Price";
	c_plot_params->scale_x = 1;
	c_plot_params->scale_y = 1;
	c_plot_params->max_x = 10;
	c_plot_params->max_y = 10;
    // #FIXME add dot size
    // --- --- data
    c_plot_params->coordinate_list=NULL;         // left blank
    c_plot_params->caption_list=NULL;            // left blank
    c_plot_params->caption_list=push_back_caption(c_plot_params->caption_list,"ONE",0,0x0000FF); // color the point
	c_plot_params->caption_list=push_back_caption(c_plot_params->caption_list,"TWO",1,0x00FF00); // color the point
    // --- --- colors
    c_plot_params->plot_backgrownd_color.r=0;
    c_plot_params->plot_backgrownd_color.g=0;
    c_plot_params->plot_backgrownd_color.b=0;
    c_plot_params->plot_backgrownd_color.a=255;

    // c_plot_params->screen_backgrownd_color=...;
    // c_plot_params->borders_color=...;
    // c_plot_params->text_color=...;
    // --- --- --- --- POSITIONS
    c_plot_params->plot_zone.x=c_plot_params->plot_x;
	c_plot_params->plot_zone.y=c_plot_params->plot_y;
	c_plot_params->plot_zone.w=c_plot_params->plot_width;
	c_plot_params->plot_zone.h=c_plot_params->plot_heigth;

	c_plot_params->plot_position.x=c_plot_params->plot_zone.x+(c_plot_params->plot_width/2)-(c_plot_params->plot_width*0.47);
	c_plot_params->plot_position.y=c_plot_params->plot_zone.y+(c_plot_params->plot_heigth*0.50)-(c_plot_params->plot_heigth/2);
	c_plot_params->plot_position.w=c_plot_params->real_plot_width;
	c_plot_params->plot_position.h=c_plot_params->real_plot_heigth;

	c_plot_params->plot_mask_position.x=c_plot_params->plot_position.x-c_plot_params->stroke_width;
	c_plot_params->plot_mask_position.y=c_plot_params->plot_position.y-c_plot_params->stroke_width;
	c_plot_params->plot_mask_position.w=c_plot_params->real_plot_width+c_plot_params->stroke_width*2;
	c_plot_params->plot_mask_position.h=c_plot_params->real_plot_heigth+c_plot_params->stroke_width*2;

	c_plot_params->plot_caption_position.x=c_plot_params->plot_position.x;
	c_plot_params->plot_caption_position.y=c_plot_params->plot_position.y-15-c_plot_params->real_plot_caption_heigth;
	c_plot_params->plot_caption_position.w=c_plot_params->real_plot_width;
	c_plot_params->plot_caption_position.h=c_plot_params->real_plot_caption_heigth;

	c_plot_params->plot_caption_mask_position.x=c_plot_params->plot_caption_position.x-c_plot_params->stroke_width;
	c_plot_params->plot_caption_mask_position.y=c_plot_params->plot_caption_position.y-c_plot_params->stroke_width;
	c_plot_params->plot_caption_mask_position.w=c_plot_params->real_plot_width+c_plot_params->stroke_width*2;
	c_plot_params->plot_caption_mask_position.h=c_plot_params->real_plot_caption_heigth+c_plot_params->stroke_width*2;

	c_plot_params->caption_y_position.x=c_plot_params->plot_position.x;
	c_plot_params->caption_y_position.y=c_plot_params->plot_position.y;
}