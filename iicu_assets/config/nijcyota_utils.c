#include "nijcyota_utils.h"

__iicu_nijcyota_t *nijcyota_fabric(){
    __iicu_nijcyota_t *new_nijcyota=malloc(sizeof(__iicu_nijcyota_t));
    new_nijcyota->nijcyota_index=NIJCYOTA_ALLIU_INDEX;
    SDL_Color line_color={
        .r=NIJCYOTA_LINE_COLOR_R,
        .g=NIJCYOTA_LINE_COLOR_G,
        .b=NIJCYOTA_LINE_COLOR_B
    };
    SDL_Color alliu_color={
        .r=NIJCYOTA_ALLIU_COLOR_R,
        .g=NIJCYOTA_ALLIU_COLOR_G,
        .b=NIJCYOTA_ALLIU_COLOR_B
    };
    SDL_Color timestamp_color={
        .r=NIJCYOTA_TIMESTAMP_COLOR_R,
        .g=NIJCYOTA_TIMESTAMP_COLOR_G,
        .b=NIJCYOTA_TIMESTAMP_COLOR_B
    };
    SDL_Color positive_color={
        .r=NIJCYOTA_POSITIVE_COLOR_R,
        .g=NIJCYOTA_POSITIVE_COLOR_G,
        .b=NIJCYOTA_POSITIVE_COLOR_B
    };
    SDL_Color negative_color={
        .r=NIJCYOTA_NEGATIVE_COLOR_R,
        .g=NIJCYOTA_NEGATIVE_COLOR_G,
        .b=NIJCYOTA_NEGATIVE_COLOR_B
    };

    new_nijcyota->positive_color=positive_color;
    new_nijcyota->negative_color=negative_color;
    
    new_nijcyota->alliu_index=NIJCYOTA_ALLIU_INDEX;
    new_nijcyota->line_color=line_color;
    new_nijcyota->timestamp_color=timestamp_color;
    
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

    new_nijcyota->main_box_x=NIJCYOTA_MAIN_BOX_X;
    new_nijcyota->main_box_y=NIJCYOTA_MAIN_BOX_Y;
    new_nijcyota->main_box_w=NIJCYOTA_MAIN_BOX_W;
    new_nijcyota->main_box_h=NIJCYOTA_MAIN_BOX_H;

    new_nijcyota->alliu_color=alliu_color;

    new_nijcyota->tactical_draw_jk_policy=NIJCYOTA_DRAW_TACTICAL_JK_POLICY;

    return new_nijcyota;
}

void destroy_nijcyota(__iicu_nijcyota_t *_nijcyota){
    free(_nijcyota);
}

void print_nijcyota(__iicu_nijcyota_t *_nijcyota){
    fprintf(stdout," : : : --- --- --- --- --- --- NIJCYOTA --- --- --- --- --- \n");
    fprintf(stdout," : : : _nijcyota->nijcyota_index : %d \n",_nijcyota->nijcyota_index);
    fprintf(stdout," : : : _nijcyota->alliu_index : %d \n",_nijcyota->alliu_index);
    fprintf(stdout," : : : _nijcyota->line_color : %d \n",_nijcyota->line_color.r);
    fprintf(stdout," : : : _nijcyota->line_color : %d \n",_nijcyota->line_color.g);
    fprintf(stdout," : : : _nijcyota->line_color : %d \n",_nijcyota->line_color.b);
    
    fprintf(stdout," : : : _nijcyota->orbital_caption : %s \n",_nijcyota->orbital_caption);
    fprintf(stdout," : : : _nijcyota->orbital_centreX : %d \n",_nijcyota->orbital_centreX);
    fprintf(stdout," : : : _nijcyota->orbital_centreY : %d \n",_nijcyota->orbital_centreY);
    fprintf(stdout," : : : _nijcyota->orbital_radius : %d \n",_nijcyota->orbital_radius);

    fprintf(stdout," : : : _nijcyota->noise_box_x : %d \n",_nijcyota->noise_box_x);
    fprintf(stdout," : : : _nijcyota->noise_box_y : %d \n",_nijcyota->noise_box_y);
    fprintf(stdout," : : : _nijcyota->noise_box_w : %d \n",_nijcyota->noise_box_w);
    fprintf(stdout," : : : _nijcyota->noise_box_h : %d \n",_nijcyota->noise_box_h);

    fprintf(stdout," : : : _nijcyota->data_box_x : %d \n",_nijcyota->data_box_x);
    fprintf(stdout," : : : _nijcyota->data_box_y : %d \n",_nijcyota->data_box_y);

    fprintf(stdout," : : : _nijcyota->draw_line : %d \n",_nijcyota->draw_line);
    fprintf(stdout," : : : _nijcyota->draw_perpendicular : %d \n",_nijcyota->draw_perpendicular);
    fprintf(stdout," : : : _nijcyota->draw_dot : %d \n",_nijcyota->draw_dot);

    fprintf(stdout," : : : _nijcyota->main_box_x : %d \n",_nijcyota->main_box_x);
    fprintf(stdout," : : : _nijcyota->main_box_y : %d \n",_nijcyota->main_box_y);
    fprintf(stdout," : : : _nijcyota->main_box_w : %d \n",_nijcyota->main_box_w);
    fprintf(stdout," : : : _nijcyota->main_box_h : %d \n",_nijcyota->main_box_h);
}

void update_iicu_nicjyota(__iicu_nijcyota_t *_nijcyota){
    // #FIXME implement
}