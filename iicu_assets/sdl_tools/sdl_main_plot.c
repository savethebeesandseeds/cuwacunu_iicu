#include "sdl_main_plot.h"
void sdl_draw_main_plot(__iicu_wikimyei_t *_iicu_wikimyei){
    __sdl_screen_object_t *_obj_sdl=_iicu_wikimyei->__obj_sdl;
    __iicu_mewaajacune_t *_mewaajacune=giicm(_iicu_wikimyei);
    __iicu_nijcyota_t *_nijcyota=giicn(_iicu_wikimyei);
    __iicu_staticques_t *_staticques=giicsq(_iicu_wikimyei);
    char aux_caption[512]="";
    char aux_time_caption[256]="";
    struct tm ts_v;
    time_t tstmp_a=0x00;
    time_t tstmp_v=0x00;
    time_t tstmp_z=0x00;
    time_t tstmp_delta=0x00;
    int rot_x=0x00;
    int rot_y=0x00;
    int rot_dx=0x00;
    int rot_dy=0x00;
    int rot_line_dy=0x00;
    double rot_angle=0x00;
    __cwcn_type_t tstmp_pix_delta=0x00;
    __cwcn_type_t main_box_max=max_alliu_in_load(_mewaajacune,NIJCYOTA_ALLIU_INDEX);
    __cwcn_type_t main_box_min=min_alliu_in_load(_mewaajacune,NIJCYOTA_ALLIU_INDEX);
    sdl_draw_1d_plot(_obj_sdl, 
        _mewaajacune, 
        _nijcyota->alliu_index,
        _nijcyota->main_box_x,
        _nijcyota->main_box_y,
        _nijcyota->main_box_w,
        _nijcyota->main_box_h,
        _nijcyota->line_color,
        _nijcyota->draw_line,
        _nijcyota->draw_perpendicular,
        _nijcyota->draw_dot);
    // --- --- LINES
    SDL_SetRenderDrawColor(_obj_sdl->renderer,
        _nijcyota->line_color.r,
        _nijcyota->line_color.g,
        _nijcyota->line_color.b,
        _nijcyota->line_color.a);
    // --- --- UPPER LINE
    sdl_draw_line(_obj_sdl->renderer, 
        _nijcyota->main_box_x, 
        _nijcyota->main_box_y, 
        _nijcyota->main_box_x+_nijcyota->main_box_w, 
        _nijcyota->main_box_y);
    // --- --- LOWER LINE
    sdl_draw_line(_obj_sdl->renderer, 
        _nijcyota->main_box_x, 
        _nijcyota->main_box_y+_nijcyota->main_box_h, 
        _nijcyota->main_box_x+_nijcyota->main_box_w, 
        _nijcyota->main_box_y+_nijcyota->main_box_h);
    // --- --- ALLIU
    int alliu_dx=5;
    int alliu_dy=-5;
    int latest_alliu_relative_y=0x00;
    latest_alliu_relative_y=(int)((_staticques->alliu_latest-main_box_min)*((__cwcn_type_t)_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
    sprintf(aux_caption,"%.8f",_staticques->alliu_latest);
    sdl_draw_text(aux_caption, // alliu
        _nijcyota->main_box_x+_nijcyota->main_box_w+alliu_dx,
        _nijcyota->main_box_y+_nijcyota->main_box_h-latest_alliu_relative_y+alliu_dy,
        _nijcyota->alliu_color,_obj_sdl->screen_font,_obj_sdl->renderer);
    if(latest_alliu_relative_y>SCREEN_FONT_SIZE){
        sprintf(aux_caption,"%.8f",main_box_min);
        sdl_draw_text(aux_caption, // min alliu
            _nijcyota->main_box_x+_nijcyota->main_box_w+alliu_dx,
            _nijcyota->main_box_y+_nijcyota->main_box_h+alliu_dy,
            _nijcyota->alliu_color,_obj_sdl->screen_font,_obj_sdl->renderer);
    }
    latest_alliu_relative_y=(int)((main_box_max-_staticques->alliu_latest)*((__cwcn_type_t)_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
    if(latest_alliu_relative_y>SCREEN_FONT_SIZE){
        sprintf(aux_caption,"%.8f",main_box_max);
        sdl_draw_text(aux_caption, // max alliu
            _nijcyota->main_box_x+_nijcyota->main_box_w+alliu_dx,
            _nijcyota->main_box_y+alliu_dy,
            _nijcyota->alliu_color,_obj_sdl->screen_font,_obj_sdl->renderer);
    }
    // --- --- TIMESTAMPS
    rot_dx=-135;
    rot_dy=+25;
    rot_angle=-15;
    rot_line_dy=-10;
    load_to_end(_mewaajacune);
    tstmp_z = glti(_mewaajacune)->__alliu_timestamp;
    load_to_start(_mewaajacune);
    tstmp_a = glti(_mewaajacune)->__alliu_timestamp;
    tstmp_delta=(tstmp_z-tstmp_a)/((time_t)TIMEDATE_N_POINTS-0x01);
    tstmp_pix_delta=((__cwcn_type_t)_nijcyota->main_box_w) / ((__cwcn_type_t)TIMEDATE_N_POINTS-0x01);
    for(int td_idx=0x00;td_idx<TIMEDATE_N_POINTS;td_idx++){
        tstmp_v=tstmp_a+td_idx*tstmp_delta;
        ts_v=*localtime(&tstmp_v);
        strftime(aux_time_caption,sizeof(aux_time_caption),TIMEDATE_FORMAT,&ts_v);
        sprintf(aux_caption,"%s",aux_time_caption); // #FIXME not required
        rot_x=(int)(((__cwcn_type_t)td_idx)*((__cwcn_type_t)tstmp_pix_delta));
        rot_x=_nijcyota->main_box_x+rot_x+alliu_dx+rot_dx;
        rot_y=_nijcyota->main_box_y+_nijcyota->main_box_h+alliu_dy+rot_dy;
        sdl_draw_rot_text(aux_caption, rot_x,rot_y,
            _nijcyota->timestamp_color,_obj_sdl->screen_font,_obj_sdl->renderer,
            rot_angle);
        SDL_SetRenderDrawColor(_obj_sdl->renderer,
            _nijcyota->timestamp_color.r,
            _nijcyota->timestamp_color.g,
            _nijcyota->timestamp_color.b,
            _nijcyota->timestamp_color.a);
        sdl_draw_line(_obj_sdl->renderer, rot_x-rot_dx-4, rot_y-rot_dy+10, rot_x-rot_dx-4, rot_y-rot_dy+5+rot_line_dy);
        sdl_draw_line(_obj_sdl->renderer, rot_x-rot_dx-3, rot_y-rot_dy+10, rot_x-rot_dx-3, rot_y-rot_dy+5+rot_line_dy);
        // sdl_draw_line(_obj_sdl->renderer, rot_x-rot_dx-2, rot_y-rot_dy+10, rot_x-rot_dx-2, rot_y-rot_dy+5+rot_line_dy);
        // sdl_draw_line(_obj_sdl->renderer, rot_x-rot_dx-4, _nijcyota->main_box_y+_nijcyota->main_box_h, rot_x-rot_dx-4, _nijcyota->main_box_y);
        // sdl_draw_line(_obj_sdl->renderer, rot_x-rot_dx-3, _nijcyota->main_box_y+_nijcyota->main_box_h, rot_x-rot_dx-3, _nijcyota->main_box_y);
        // sdl_draw_line(_obj_sdl->renderer, rot_x-rot_dx-2, _nijcyota->main_box_y+_nijcyota->main_box_h, rot_x-rot_dx-2, _nijcyota->main_box_y);
    }
}