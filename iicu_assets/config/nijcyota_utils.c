#include "nijcyota_utils.h"

__iicu_nijcyota_t *nijcyota_fabric(){
    __iicu_nijcyota_t *new_nijcyota=malloc(sizeof(__iicu_nijcyota_t));
    new_nijcyota->nijcyota_index=0x00;
    new_nijcyota->orbital_angle=0x00; // ANGLE STARTS AT ZERO // #FIXME put in mewaajacune 
    SDL_Color line_color={
        .r=NIJCYOTA_NOISE_BOX_LINE_COLOR_R,
        .g=NIJCYOTA_NOISE_BOX_LINE_COLOR_G,
        .b=NIJCYOTA_NOISE_BOX_LINE_COLOR_B
    };
    
    new_nijcyota->alliu_index=NIJCYOTA_ALLIU_INDEX;
    new_nijcyota->line_color=line_color;
    
    new_nijcyota->orbital_caption=NIJCYOTA_ORBITAL_CAPTION;
    new_nijcyota->orbital_centreX=NIJCYOTA_ORBITAL_CENTRE_X;
    new_nijcyota->orbital_centreY=NIJCYOTA_ORBITAL_CENTRE_Y;
    new_nijcyota->orbital_radius=NIJCYOTA_ORBITAL_RADIUS;

    new_nijcyota->noise_box_x=NIJCYOTA_NOISE_BOX_X;
    new_nijcyota->noise_box_y=NIJCYOTA_NOISE_BOX_Y;
    new_nijcyota->noise_box_w=NIJCYOTA_NOISE_BOX_W;
    new_nijcyota->noise_box_h=NIJCYOTA_NOISE_BOX_H;

    new_nijcyota->data_box_x=NIJCYOTA_DATA_BOX_X;
    new_nijcyota->data_box_y=NIJCYOTA_DATA_BOX_Y;

    new_nijcyota->draw_line=NIJCYOTA_NOISE_BOX_DRAW_LINE;
    new_nijcyota->draw_perpendicular=NIJCYOTA_NOISE_BOX_DRAW_PERPENDICULAR;
    new_nijcyota->draw_dot=NIJCYOTA_NOISE_BOX_DRAW_DOT;

    return new_nijcyota;
}

void destroy_nijcyota(__iicu_nijcyota_t *_nijcyota){
    free(_nijcyota);
}

void update_iicu_nicjyota(__iicu_nijcyota_t *_nijcyota){
    // #FIXME implement
}