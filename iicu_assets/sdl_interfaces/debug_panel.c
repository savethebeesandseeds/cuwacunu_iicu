#include "debug_panel.h"
void render_debug_panel(__iicu_wikimyei_t *_iicu_wikimyei){
    // --- --- --- --- · --- --- --- --- 
    // --- --- --- --- · --- --- --- --- auxiliar variables
    time_t now;
    struct tm ts;
    char aux_caption[512];
    char aux_time_caption[256];
    // --- --- --- --- · --- --- --- --- DATA 1
    sprintf(aux_caption,"WK:%p",_iicu_wikimyei); // ->__holding_value
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+8*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);
    sprintf(aux_caption,"WK_STATE:%p",get_state(_iicu_wikimyei)); // ->__holding_value
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+10*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);
    sprintf(aux_caption,"WK_OBJ_SDL:%p",_iicu_wikimyei->__obj_sdl); // ->__holding_value
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+12*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);
    sprintf(aux_caption,"WK_ITSAVE:%p",get_wk_itsaave(_iicu_wikimyei)); // ->__holding_value
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+14*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);
    // sprintf(aux_caption,"WK_POCKET:%f",gentil_get_wk_itsaave_holding_value(_iicu_wikimyei));
    sprintf(aux_caption,"WK_ITSAAVE_POCKET:%p",get_wk_itsaave(_iicu_wikimyei)->__it_pocket); // ->__holding_value
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+16*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);

    // sprintf(aux_caption,"SCENE[%d]POCKET:%f",gcsid(_iicu_wikimyei),gentil_get_scene_itsaave_holding_value(_iicu_wikimyei,gcsid(_iicu_wikimyei)));
    sprintf(aux_caption,"SCENE[%d]:%p",gcsid(_iicu_wikimyei),get_scene(_iicu_wikimyei, gcsid(_iicu_wikimyei)));
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+18*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);
    // sprintf(aux_caption,"SCENE[%d]POCKET:%f",gcsid(_iicu_wikimyei),gentil_get_scene_itsaave_holding_value(_iicu_wikimyei,gcsid(_iicu_wikimyei)));
    sprintf(aux_caption,"SCENE[%d]ITSAAVE:%p",gcsid(_iicu_wikimyei),get_scene_itsaave(_iicu_wikimyei, gcsid(_iicu_wikimyei)));
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+20*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);
    // sprintf(aux_caption,"SCENE[%d]POCKET:%f",gcsid(_iicu_wikimyei),gentil_get_scene_itsaave_holding_value(_iicu_wikimyei,gcsid(_iicu_wikimyei)));
    sprintf(aux_caption,"SCENE[%d]ITSAAVE_POCKET:%p",gcsid(_iicu_wikimyei),get_scene_itsaave(_iicu_wikimyei, gcsid(_iicu_wikimyei))->__it_pocket);
    sdl_draw_text(aux_caption,
        giicn(_iicu_wikimyei)->data_box_x,
        giicn(_iicu_wikimyei)->data_box_y+22*SCREEN_FONT_DELTA,
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
        giicn(_iicu_wikimyei)->data_box_y+24*SCREEN_FONT_DELTA,
        giicn(_iicu_wikimyei)->line_color,
        _iicu_wikimyei->__obj_sdl->screen_font,
        _iicu_wikimyei->__obj_sdl->renderer);
}