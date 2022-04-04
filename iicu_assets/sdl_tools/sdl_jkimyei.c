#include "sdl_jkimyei.h"
void sdl_draw_jkimyei_policy(__iicu_wikimyei_t *_iicu_wikimyei){
    __sdl_screen_object_t *c_obj_sdl=_iicu_wikimyei->__obj_sdl;
    __iicu_mewaajacune_t *c_mewaajacune=giicm(_iicu_wikimyei);
    __iicu_nijcyota_t *c_nijcyota=giicn(_iicu_wikimyei);
    __cwcn_type_t c_latest_alliu=gentil_get_alliu_latest(_iicu_wikimyei, gcsid(_iicu_wikimyei));
    __cwcn_type_t main_box_max=max_alliu_in_load(c_mewaajacune,NIJCYOTA_ALLIU_INDEX);
    __cwcn_type_t main_box_min=min_alliu_in_load(c_mewaajacune,NIJCYOTA_ALLIU_INDEX);
    __iicu_jkimyei_t *c_jkimyei=giicjk(_iicu_wikimyei);
    __inteligent_order_policy_t *c_policy=c_jkimyei->__jk_inteligent_order_policy;
    SDL_Color draw_factor_color;
    char aux_caption[512]="";
    int alliu_dx=5;
    int alliu_dy=-5;
    int draw_factor_y=0x00, draw_factor_x=0x00;
    // --- --- --- --- --- 
    draw_factor_x=(int)(giicn(_iicu_wikimyei)->main_box_x+giicn(_iicu_wikimyei)->main_box_w-35);
    draw_factor_y=(int)(giicn(_iicu_wikimyei)->main_box_y-75);
    if(c_policy->__policy_total_reward>=0x00){
        draw_factor_color=giicn(_iicu_wikimyei)->positive_color;
    } else {
        draw_factor_color=giicn(_iicu_wikimyei)->negative_color;
    }
    sprintf(aux_caption,"jk [%s] :: %.8f",BROKER_CANDLE_INTERVALS[c_nijcyota->jkimyei_klines_index],c_policy->__policy_total_reward);
    sdl_draw_text(aux_caption,
        draw_factor_x,
        draw_factor_y-125,
        draw_factor_color,
        c_obj_sdl->screen_font,
        c_obj_sdl->renderer);
    // --- --- --- --- --- 
    draw_factor_x=c_nijcyota->main_box_x+c_nijcyota->main_box_w+alliu_dx;
    draw_factor_y=(int)((c_latest_alliu-main_box_min)*((__cwcn_type_t)c_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
    draw_factor_color=c_nijcyota->alliu_color;
    sprintf(aux_caption,"              _______________");
    sdl_draw_text(aux_caption, // alliu current
        draw_factor_x,
        c_nijcyota->main_box_y+c_nijcyota->main_box_h-draw_factor_y+alliu_dy,
        draw_factor_color,c_obj_sdl->screen_font,c_obj_sdl->renderer);
    // --- --- --- --- --- 
    // draw_factor_x=c_nijcyota->main_box_x+c_nijcyota->main_box_w+alliu_dx;
    // draw_factor_y=(int)((c_latest_alliu*(0x01+BROKER_MARKET_TOTAL_COMMISSION)-main_box_min)*((__cwcn_type_t)c_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
    // sprintf(aux_caption,"-----------------------------");
    // sdl_draw_text(aux_caption, // alliu margin of comission
    //     draw_factor_x,
    //     c_nijcyota->main_box_y+c_nijcyota->main_box_h-draw_factor_y+alliu_dy,
    //     c_nijcyota->negative_color,c_obj_sdl->screen_font,c_obj_sdl->renderer);
    // --- --- --- --- --- 
    draw_factor_x=c_nijcyota->main_box_x+c_nijcyota->main_box_w+alliu_dx;
    draw_factor_y=(int)((c_latest_alliu*(0x01-c_policy->__order_margin_down)-main_box_min)*((__cwcn_type_t)c_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
    draw_factor_color=c_nijcyota->negative_color;
    sprintf(aux_caption,"-----------------------------");
    sdl_draw_text(aux_caption, // alliu magin of max loss
        draw_factor_x,
        c_nijcyota->main_box_y+c_nijcyota->main_box_h-draw_factor_y+alliu_dy,
        draw_factor_color,c_obj_sdl->screen_font,c_obj_sdl->renderer);
    // --- --- --- --- --- 
    draw_factor_x=c_nijcyota->main_box_x+c_nijcyota->main_box_w+alliu_dx;
    draw_factor_y=(int)((c_latest_alliu*(0x01+c_policy->__order_margin_uper)-main_box_min)*((__cwcn_type_t)c_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
    draw_factor_color=c_nijcyota->positive_color;
    sprintf(aux_caption,"+++++++++++++++++++++++++++++");
    sdl_draw_text(aux_caption, // alliu margine of gain
        draw_factor_x,
        c_nijcyota->main_box_y+c_nijcyota->main_box_h-draw_factor_y+alliu_dy,
        draw_factor_color,c_obj_sdl->screen_font,c_obj_sdl->renderer);
}