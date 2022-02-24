#include "data_utils.h"
void populate_central_plot_coordinate_list(sdl_screen_object_t *obj_sdl){
    splot_t *cplot = &obj_sdl->iicu_scene[obj_sdl->iicu_state.scene_id].central_plot;
    float rand_float;
    // --- --- --- --- · --- --- --- --- populate coordinate list
    cplot->splot_params.coordinate_list = clear_coord(cplot->splot_params.coordinate_list);
    cplot->splot_params.coordinate_list = NULL;
    for(int label=0;label<2;label++){
        for(int data_x=0;data_x<=cplot->splot_params.max_x;data_x++){
            rand_float=(float)rand()/(float)RAND_MAX*cplot->splot_params.max_y;
            cplot->splot_params.coordinate_list=push_back_coord(cplot->splot_params.coordinate_list,label,data_x,rand_float);
        }
    }
}

void test_populate_alliu(__mewaajacune_t *_mewaajacune){
    __cwcn_type_t rand_float;
    kill_load(_mewaajacune);
    // --- --- --- --- · --- --- --- --- populate coordinate list
    for(int data_x=0;data_x<64;data_x++){
        rand_float=(__cwcn_type_t)rand()/(__cwcn_type_t)RAND_MAX*((__cwcn_type_t)64);
        // fprintf(stdout,"rand_float:%f\n",rand_float);
        yield_next_trayectory(_mewaajacune);
        glti(_mewaajacune)->__alliu_state[0]=rand_float;
        // glti(_mewaajacune)->__alliu_state[0]=sin(2*2*3.141592/64*((__cwcn_type_t)data_x+1));
        // glti(_mewaajacune)->__alliu_state[0]=(__cwcn_type_t)data_x;
    }
}