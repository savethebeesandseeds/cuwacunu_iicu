#include "sdl_plot_orbital.h"
void sdl_draw_1d_orbital(__iicu_wikimyei_t *_iicu_wikimyei){
    // --- --- --- 
    __sdl_screen_object_t * c_obj_sdl=_iicu_wikimyei->__obj_sdl;
    // __iicu_mewaajacune_t *_mewaajacune=giicm(_iicu_wikimyei);
    __iicu_nijcyota_t *c_nijcyota=giicn(_iicu_wikimyei);
    // --- --- --- 
    __cwcn_type_t angle=0.5; // #FIXME
    // char *caption=c_nijcyota->orbital_caption;
    int centreX=c_nijcyota->orbital_centreX;
    int centreY=c_nijcyota->orbital_centreY;
    int radius=c_nijcyota->orbital_radius;
    SDL_Color color=c_nijcyota->line_color;

    int x1=centreX;
    int x2=centreX+(1+ORBITAL_EXCENTRICITY)*radius*0.95;
    int y1=centreY;
    int y2=centreY;

    SDL_SetRenderDrawColor(c_obj_sdl->renderer,color.r,color.g,color.b,color.a);
    sdl_draw_circle(c_obj_sdl->renderer, centreX, centreY, radius);
    sdl_draw_circle(c_obj_sdl->renderer, centreX, centreY, radius-1);
    sdl_draw_circle(c_obj_sdl->renderer, centreX, centreY, radius-2);
    sdl_draw_circle(c_obj_sdl->renderer, centreX, centreY, radius-3);
    sdl_draw_line(c_obj_sdl->renderer, x1, y1, x2, y2);

    // __cwcn_type_t tan_angle=2*tanh(angle/180.0);
    // x1=centreX;
    // x2=centreX+cos(6./8.*MATH_PI)*radius*0.95;
    // y1=centreY;
    // y2=centreY-sin(6./8.*MATH_PI)*radius*0.95;
    // sdl_draw_line(c_obj_sdl->renderer, x1, y1, x2, y2);
    // y2=centreY+sin(6./8.*MATH_PI)*radius*0.95;
    // sdl_draw_line(c_obj_sdl->renderer, x1, y1, x2, y2);

    __cwcn_type_t dx = radius*cos(angle*MATH_PI/180.0);
    __cwcn_type_t dy = radius*sin(angle*MATH_PI/180.0);
    x1=centreX-ORBITAL_EXCENTRICITY*dx;
    x2=centreX+(1+ORBITAL_EXCENTRICITY)*dx;
    y1=centreY+ORBITAL_EXCENTRICITY*dy;
    y2=centreY-(1+ORBITAL_EXCENTRICITY)*dy;

    if(dy<0){SDL_SetRenderDrawColor(c_obj_sdl->renderer,255,0,0,255); // legend item border left
    } else  {SDL_SetRenderDrawColor(c_obj_sdl->renderer,0,255,0,255);} // legend item border left
    sdl_draw_circle(c_obj_sdl->renderer, centreX, centreY, ORBITAL_EXCENTRICITY*radius);
    // sdl_draw_circle(c_obj_sdl->renderer, centreX, centreY, ORBITAL_EXCENTRICITY*radius-1);
    sdl_draw_line(c_obj_sdl->renderer, x1, y1, x2, y2);
    // sdl_draw_line(c_obj_sdl->renderer, x1+1, y1, x2, y2+1);
    // sdl_draw_line(c_obj_sdl->renderer, x1+2, y1, x2, y2+2);

    // --- DRAW TEXT
    // sprintf(caption," :: %f",angle);
    // sdl_draw_text(caption,
    //     centreX+(1+ORBITAL_EXCENTRICITY)*radius*1.05,
    //     centreY-SCREEN_FONT_SIZE-15,
    //     color,
    //     c_obj_sdl->screen_font,
    //     c_obj_sdl->renderer);
}
    // char d_caption[2]="";
    // for(int caption_idx=0x00;caption_idx<strlen(caption);caption_idx++){
    //     SDL_Color d_color={.r=(int)rand()/(__cwcn_type_t)RAND_MAX*((__cwcn_type_t)256),.g=(int)rand()/(__cwcn_type_t)RAND_MAX*((__cwcn_type_t)256),.b=(int)rand()/(__cwcn_type_t)RAND_MAX*((__cwcn_type_t)256)};
    //     d_caption[0]=caption[caption_idx];
    //     fprintf(stdout,"[waka] strlen : caption : %ld : letter : %s : pixel_sizeof : %d \n",strlen(caption),d_caption, TTF_SizeText(c_obj_sdl->screen_font,d_caption,NULL,NULL));
    //     sdl_draw_text(d_caption,
    //         centreX+(1+ORBITAL_EXCENTRICITY)*radius*1.05+caption_idx*(SCREEN_FONT_DELTA),
    //         centreY-SCREEN_FONT_SIZE,
    //         d_color,
    //         c_obj_sdl->screen_font,
    //         c_obj_sdl->renderer);
    // }