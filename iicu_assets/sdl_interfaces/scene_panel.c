#include "scene_panel.h"
void render_scene_panel(__iicu_wikimyei_t *_iicu_wikimyei){
    // --- --- --- --- · --- --- --- --- 
    // --- --- --- --- · --- --- --- --- auxiliar variables
    float rand_event;
    float orb_angle;
    time_t now;
    struct tm ts;
    char aux_caption[512];
    char aux_time_caption[256];
    // --- --- --- --- · --- --- --- --- DATA 1
    sprintf(aux_caption,"SCENE : %d",gcsid(_iicu_wikimyei));
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);
    sprintf(aux_caption,"SYMBOL : %s",get_state(_iicu_wikimyei)->scene_symbol);
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+2*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);    
    sprintf(aux_caption,"INTERVAL:%s",BROKER_CANDLE_INTERVALS[gcklid(_iicu_wikimyei)]);
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+4*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);
    
    sprintf(aux_caption,"SCENE[%d]POCKET:%f",gcsid(_iicu_wikimyei),get_scene_itsaave(_iicu_wikimyei,gcsid(_iicu_wikimyei))->__it_pocket->__holding_value);
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+6*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);

    sprintf(aux_caption,"WK_POCKET:%f",get_wk_itsaave(_iicu_wikimyei)->__it_pocket->__holding_value);
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+8*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);
    time(&now);
    ts=*localtime(&now);
    strftime(aux_time_caption,sizeof(aux_time_caption),TIMEDATE_FORMAT,&ts);
    // sprintf(aux_caption,"TIMESTAMP:%s",aux_time_caption);
    sprintf(aux_caption,"TIMESTAMP:%ld",now);
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+10*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);

    // --- --- --- --- · --- --- --- --- MAIN PLOT
    if(load_is_empty(giicm(_iicu_wikimyei))){
        sprintf(aux_caption,"loading ...");
            SDL_Color font_color_2 = {51,251,51};
            sdl_draw_text(aux_caption,
                giicn(_iicu_wikimyei)->main_box_x,
                giicn(_iicu_wikimyei)->main_box_y,
                font_color_2,
                _iicu_wikimyei->__obj_sdl->mark_font,
                _iicu_wikimyei->__obj_sdl->renderer);
    } else {
        sdl_draw_main_plot(_iicu_wikimyei);
    }
    // --- --- --- --- · --- --- --- --- JK
    if(giicn(_iicu_wikimyei)->tactical_draw_jk_policy){
        if(!giicjk(_iicu_wikimyei)->__jk_policy_has_computed){
            sprintf(aux_caption,"policy not loaded...");
                sdl_draw_text(aux_caption,
                    giicn(_iicu_wikimyei)->main_box_x+giicn(_iicu_wikimyei)->main_box_w-25,
                    giicn(_iicu_wikimyei)->main_box_y-75,
                    giicn(_iicu_wikimyei)->negative_color,
                    _iicu_wikimyei->__obj_sdl->screen_font,
                    _iicu_wikimyei->__obj_sdl->renderer);
        } else {
            sdl_draw_itsaave(_iicu_wikimyei);
            sdl_draw_jkimyei_policy(_iicu_wikimyei);
        }
    }

    // --- --- --- --- · --- --- --- --- noise box 1
    // if(load_is_empty(giicm(_iicu_wikimyei))){
    //     // #FIXME add loading screen.
    // }else{
    //     sdl_draw_noise_box(_iicu_wikimyei->__obj_sdl, 
    //         giicm(_iicu_wikimyei), 
    //         giicn(_iicu_wikimyei));
    // }
    // --- --- --- --- · --- --- --- --- ORBITAL 1
    sdl_draw_1d_orbital(_iicu_wikimyei->__obj_sdl, 
        giicm(_iicu_wikimyei), 
        giicn(_iicu_wikimyei),
        giicsq(_iicu_wikimyei));
    // --- --- --- --- · --- --- --- --- 
}