#include "sdl_jkimyei.h"
void sdl_draw_jkimyei_policy(__iicu_wikimyei_t *_iicu_wikimyei){
    __sdl_screen_object_t *_obj_sdl=_iicu_wikimyei->__obj_sdl;
    __iicu_mewaajacune_t *_mewaajacune=giicm(_iicu_wikimyei);
    __iicu_nijcyota_t *_nijcyota=giicn(_iicu_wikimyei);
    __iicu_staticques_t *_staticques=giicsq(_iicu_wikimyei);
    __cwcn_type_t main_box_max=max_alliu_in_load(_mewaajacune,NIJCYOTA_ALLIU_INDEX);
    __cwcn_type_t main_box_min=min_alliu_in_load(_mewaajacune,NIJCYOTA_ALLIU_INDEX);
    __iicu_jkimyei_t *_jkimyei=giicjk(_iicu_wikimyei);
    char aux_caption[512]="";
    int alliu_dx=5;
    int alliu_dy=-5;
    int latest_alliu_relative_y=0x00;
    latest_alliu_relative_y=(int)((_staticques->alliu_latest-main_box_min)*((__cwcn_type_t)_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
    sprintf(aux_caption,"              ---------------");
    sdl_draw_text(aux_caption, // alliu current
        _nijcyota->main_box_x+_nijcyota->main_box_w+alliu_dx,
        _nijcyota->main_box_y+_nijcyota->main_box_h-latest_alliu_relative_y+alliu_dy,
        _nijcyota->alliu_color,_obj_sdl->screen_font,_obj_sdl->renderer);
    latest_alliu_relative_y=(int)((_staticques->alliu_latest*(0x01-_jkimyei->__jk_inteligent_order_policy->__order_margin_down)-main_box_min)*((__cwcn_type_t)_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
    latest_alliu_relative_y=(int)((_staticques->alliu_latest*(0x01+BROKER_MARKET_TOTAL_COMMISSION)-main_box_min)*((__cwcn_type_t)_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
    sprintf(aux_caption,"-----------------------------");
    sdl_draw_text(aux_caption, // alliu margin of comission
        _nijcyota->main_box_x+_nijcyota->main_box_w+alliu_dx,
        _nijcyota->main_box_y+_nijcyota->main_box_h-latest_alliu_relative_y+alliu_dy,
        _nijcyota->negative_color,_obj_sdl->screen_font,_obj_sdl->renderer);
    latest_alliu_relative_y=(int)((_staticques->alliu_latest*(0x01-_jkimyei->__jk_inteligent_order_policy->__order_margin_down)-main_box_min)*((__cwcn_type_t)_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
    sprintf(aux_caption,"-----------------------------");
    sdl_draw_text(aux_caption, // alliu magin of max loss
        _nijcyota->main_box_x+_nijcyota->main_box_w+alliu_dx,
        _nijcyota->main_box_y+_nijcyota->main_box_h-latest_alliu_relative_y+alliu_dy,
        _nijcyota->negative_color,_obj_sdl->screen_font,_obj_sdl->renderer);
    sprintf(aux_caption,"+++++++++++++++++++++++++++++");
    latest_alliu_relative_y=(int)((_staticques->alliu_latest*(0x01+_jkimyei->__jk_inteligent_order_policy->__order_margin_up)-main_box_min)*((__cwcn_type_t)_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
    sdl_draw_text(aux_caption, // alliu margine of gain
        _nijcyota->main_box_x+_nijcyota->main_box_w+alliu_dx,
        _nijcyota->main_box_y+_nijcyota->main_box_h-latest_alliu_relative_y+alliu_dy,
        _nijcyota->positive_color,_obj_sdl->screen_font,_obj_sdl->renderer);
}