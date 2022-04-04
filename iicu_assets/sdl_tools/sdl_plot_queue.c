#include "sdl_plot_queue.h"
/*
    function: sdl_draw_1d_plot
    comment: x coordinates are assumed equispaced and ordered as in the queue
*/
void sdl_draw_1d_plot(__sdl_screen_object_t *obj_sdl, 
    __iicu_mewaajacune_t *_mewaajacune, 
    int alliu_index,
    int box_x,
    int box_y,
    int box_w,
    int box_h,
    SDL_Color line_color,
    ___cwcn_bool_t draw_line,
    ___cwcn_bool_t draw_perpendicular,
    ___cwcn_bool_t draw_dot){    
    if(load_is_empty(_mewaajacune)){fprintf(stderr,"[WARNING:] trying to print an empy _mewaajacune\n");return;}
    __cwcn_type_t graph_max=max_alliu_in_load(_mewaajacune,alliu_index);
    __cwcn_type_t graph_min=min_alliu_in_load(_mewaajacune,alliu_index);
    int c_load_size=_mewaajacune->__load_size;
    __cwcn_type_t x_delta=(__cwcn_type_t)c_load_size;
    __cwcn_type_t y_delta=((__cwcn_type_t)graph_max-graph_min);
    __cwcn_type_t y_mid=(graph_max+graph_min)/((__cwcn_type_t)2);
    if(box_w<c_load_size){fprintf(stderr,"[WARNING:] not enough discrete pixels to print [%d] items in plot of size [%d]\n",c_load_size,box_w);return;} // #FIXME
    // if(box_h<graph_max-graph_min){fprintf(stderr,"[WARNING:] not enough discrete pixels to print [%d] items in plot of size [%d]\n",c_load_size,box_w);return;}
    __cwcn_type_t past_x;
    __cwcn_type_t past_y;
    __cwcn_type_t bias_x=((__cwcn_type_t)box_x);
    __cwcn_type_t bias_y=((__cwcn_type_t)box_y)+((__cwcn_type_t)box_h)/((__cwcn_type_t)2);//-y_delta*dot_dy/((__cwcn_type_t)2);
    __cwcn_type_t dot_dx=(__cwcn_type_t)fabs(((__cwcn_type_t)box_w)/(__cwcn_type_t)x_delta); // (dot) by multiplying it transform to speak about pixels in term of plot_scale  
    __cwcn_type_t dot_dy=(__cwcn_type_t)fabs(((__cwcn_type_t)box_h)/(__cwcn_type_t)y_delta);
    __cwcn_type_t dot_x=bias_x;//=(__cwcn_type_t)box_x;
    __cwcn_type_t dot_y=0;//=((__cwcn_type_t)box_y)+((__cwcn_type_t)box_h);
    int start_index=_mewaajacune->__load_index;
    ___cwcn_bool_t s_flag=0x0;
    SDL_SetRenderDrawColor(obj_sdl->renderer,line_color.r,line_color.g,line_color.b,line_color.a);
    load_to_start(_mewaajacune);
    // load_print_up_trayectory_queue(_mewaajacune); // waka
    // fprintf(stdout,"waka [graph_max]%f -> %f\n",graph_max,bias_y-(graph_max-y_mid)*dot_dy);
    // fprintf(stdout,"waka [graph_min]%f -> %f\n",graph_min,bias_y-(graph_min-y_mid)*dot_dy);
    // fprintf(stdout,"waka [y_mid]%f\n",y_mid);
    // fprintf(stdout,"waka [x_delta]%f\n",x_delta);
    // fprintf(stdout,"waka [y_delta]%f\n",y_delta);
    // fprintf(stdout,"waka [dot_dx]%f\n",dot_dx);
    // fprintf(stdout,"waka [dot_dy]%f\n",dot_dy);
    // fprintf(stdout,"waka [ok][bias_y]%f\n",bias_y);
    do{
        dot_x+=dot_dx;
        dot_y=bias_y-(glti(_mewaajacune)->__alliu_state[alliu_index]-y_mid)*dot_dy;
        if(!s_flag){
            s_flag=0x1;
            past_x=dot_x;
            past_y=dot_y;
        }
        // fprintf(stdout,"... --- ... ---\n");
        // fprintf(stdout,"waka [dot_x]%f\n",dot_x);
        // fprintf(stdout,"waka [dot_y]%f\n",dot_y);
        if(draw_perpendicular){
            past_x=dot_x;
            past_y=box_y+box_h;
        }
        if(draw_line){ // draw_line
            sdl_draw_line(obj_sdl->renderer,
                (int)(round(dot_x)),
                (int)(round(dot_y)),
                (int)(round(past_x)),
                (int)(round(past_y)));
        }
        if(draw_dot){ // draw_dot
            switch(glti(_mewaajacune)->__ujcamei_state){
            case _cwcn_FLAT:
                sdl_draw_filled_circle(obj_sdl->renderer,
                    (int)(round(dot_x)),
                    (int)(round(dot_y)),
                    DOT_PLOT_RADIUS);
                break;
            case _cwcn_BEAR:
                fprintf(stdout,"[WARNING:] method for printing _cwcn_BEAR (dot) not implemented\n");
                break;
            case _cwcn_BULL:
                fprintf(stdout,"[WARNING:] method for printing _cwcn_BULL (dot) not implemented\n");
                break;
            default:
                fprintf(stdout,"[WARNING:] found __ujcamei_state not set at _mewaajacune_index %d\n",c_load_size);
                break;
            }

        }
        past_x=dot_x;
        past_y=dot_y;
    }while(load_go_up(_mewaajacune)!=-1);
    load_to_index(_mewaajacune,start_index);
}