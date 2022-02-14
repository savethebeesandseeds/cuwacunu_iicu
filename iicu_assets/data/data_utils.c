#include "data_utils.h"
void populate_central_plot_coordinate_list(sdl_screen_object_t *obj_sdl){
    float rand_float;
    // --- --- --- --- · --- --- --- --- populate coordinate list
    obj_sdl->central_plot_params.coordinate_list = clear_coord(obj_sdl->central_plot_params.coordinate_list);
    obj_sdl->central_plot_params.coordinate_list = NULL;
    for(int label=0;label<2;label++){
        for(int data_x=0;data_x<=obj_sdl->central_plot_params.max_x;data_x++){
            rand_float=(float)rand()/(float)RAND_MAX*obj_sdl->central_plot_params.max_y;
            obj_sdl->central_plot_params.coordinate_list=push_back_coord(obj_sdl->central_plot_params.coordinate_list,label,data_x,rand_float);
        }
    }
}