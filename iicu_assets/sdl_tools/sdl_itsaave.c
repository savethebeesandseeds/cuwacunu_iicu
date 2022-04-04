#include "sdl_itsaave.h"

// int how_many_in_the_range(): // #FIXME fix superposition of numbers in [itsaave]
void sdl_draw_itsaave(__iicu_wikimyei_t *_iicu_wikimyei){
    __sdl_screen_object_t *c_obj_sdl=_iicu_wikimyei->__obj_sdl;
    __iicu_nijcyota_t *c_nijcyota=giicn(_iicu_wikimyei);
    __iicu_mewaajacune_t *c_mewaajacune=giicm(_iicu_wikimyei);
    __cwcn_type_t main_box_max=max_alliu_in_load(c_mewaajacune,NIJCYOTA_ALLIU_INDEX);
    __cwcn_type_t main_box_min=min_alliu_in_load(c_mewaajacune,NIJCYOTA_ALLIU_INDEX);
    __cwcn_type_t c_delta_alliu;
    __cwcn_type_t c_latest_alliu;
    for(int _idx_th=0x00;_idx_th<MAX_IICU_ITSAAVES;_idx_th++){ // get_next_aviable_itsaave_thread()
        if(get_it_thread_order(_iicu_wikimyei,_idx_th)->__it_thead_is_bussy==0x01 && get_it_thread_order(_iicu_wikimyei,_idx_th)->__it_policy_is_bussy==0x01){
            // --- --- --- --- --- 
            c_latest_alliu=gentil_get_alliu_latest(_iicu_wikimyei,get_it_thread_order(_iicu_wikimyei,_idx_th)->__scene_id);
            // --- --- --- --- --- 
            __iicu_itsaave_t *c_itsaave=get_it_thread_order(_iicu_wikimyei,_idx_th)->__ref_iicu_itsaave;
            // --- --- --- --- --- 
            // __inteligent_order_policy_t *c_policy=c_itsaave->__it_policy;
            // --- --- --- --- --- 
            SDL_Color draw_factor_color;
            char aux_caption[512]="";
            int alliu_dx=5;
            int alliu_dy=-5;
            int draw_factor_y=0x00, draw_factor_x=0x00;
            // --- --- --- --- --- 
            draw_factor_x=(int)(c_nijcyota->main_box_x+c_nijcyota->main_box_w-35);
            draw_factor_y=(int)(c_nijcyota->main_box_y-75);
            draw_factor_color=c_nijcyota->grey_color;
            c_delta_alliu=(c_latest_alliu-c_itsaave->__it_alliu_start)*c_itsaave->__it_alliu_quantity;
            sprintf(aux_caption,"[%d] itsaave : [%s] :: %.8f",_idx_th,IICU_SCENES_SYMBOLS[get_it_thread_order(_iicu_wikimyei,_idx_th)->__scene_id],c_delta_alliu);
            sdl_draw_text(aux_caption,
                draw_factor_x-15,
                draw_factor_y-125+15*(_idx_th+0x01),
                draw_factor_color,
                c_obj_sdl->screen_font,
                c_obj_sdl->renderer);
            // --- --- --- --- --- 
            if(get_it_thread_order(_iicu_wikimyei,_idx_th)->__scene_id==gcsid(_iicu_wikimyei)){
                draw_factor_x=c_nijcyota->main_box_x+c_nijcyota->main_box_w+alliu_dx;
                draw_factor_y=(int)((c_itsaave->__it_alliu_start-main_box_min)*((__cwcn_type_t)c_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
                draw_factor_color=c_nijcyota->grey_color;
                sprintf(aux_caption,"              _______________[%d]",_idx_th);
                sdl_draw_text(aux_caption, // alliu current
                    draw_factor_x,
                    c_nijcyota->main_box_y+c_nijcyota->main_box_h-draw_factor_y+alliu_dy,
                    draw_factor_color,c_obj_sdl->screen_font,c_obj_sdl->renderer);
                // --- --- --- --- --- 
                // draw_factor_x=c_nijcyota->main_box_x+c_nijcyota->main_box_w+alliu_dx;
                // draw_factor_y=(int)((c_itsaave->__it_alliu_start*(0x01+BROKER_MARKET_TOTAL_COMMISSION)-main_box_min)*((__cwcn_type_t)c_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
                // sprintf(aux_caption,"-----------------------------");
                // sdl_draw_text(aux_caption, // alliu margin of comission
                //     draw_factor_x,
                //     c_nijcyota->main_box_y+c_nijcyota->main_box_h-draw_factor_y+alliu_dy,
                //     c_nijcyota->negative_color,c_obj_sdl->screen_font,c_obj_sdl->renderer);
                // --- --- --- --- --- 
                draw_factor_x=c_nijcyota->main_box_x+c_nijcyota->main_box_w+alliu_dx;
                draw_factor_y=(int)((c_itsaave->__it_alliu_downbreak-main_box_min)*((__cwcn_type_t)c_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
                draw_factor_color=c_nijcyota->grey_color;
                sprintf(aux_caption,"-----------------------------[%d]",_idx_th);
                sdl_draw_text(aux_caption, // alliu magin of max loss
                    draw_factor_x,
                    c_nijcyota->main_box_y+c_nijcyota->main_box_h-draw_factor_y+alliu_dy,
                    draw_factor_color,c_obj_sdl->screen_font,c_obj_sdl->renderer);
                // --- --- --- --- --- 
                draw_factor_x=c_nijcyota->main_box_x+c_nijcyota->main_box_w+alliu_dx;
                draw_factor_y=(int)((c_itsaave->__it_alliu_uperbreak-main_box_min)*((__cwcn_type_t)c_nijcyota->main_box_h)/(main_box_max-main_box_min+1e-9));
                draw_factor_color=c_nijcyota->grey_color;
                sprintf(aux_caption,"+++++++++++++++++++++++++++++[%d]",_idx_th);
                sdl_draw_text(aux_caption, // alliu margine of gain
                    draw_factor_x,
                    c_nijcyota->main_box_y+c_nijcyota->main_box_h-draw_factor_y+alliu_dy,
                    draw_factor_color,c_obj_sdl->screen_font,c_obj_sdl->renderer);
                
                // --- --- --- --- --- 
            }
        }
    }
}