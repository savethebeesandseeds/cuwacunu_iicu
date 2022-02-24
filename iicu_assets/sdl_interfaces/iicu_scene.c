#include "iicu_scene.h"
void render_iicu_scene(sdl_screen_object_t *obj_sdl){
    // --- --- --- --- · --- --- --- --- auxiliar variables
    clock_t begin;
	clock_t end;
	double time_spent;
    float rand_event;
    float orb_angle;
    char orb_caption[256];
	splot_t *cplot = &obj_sdl->iicu_scene[obj_sdl->iicu_state.scene_id].central_plot;
    // --- --- --- --- · --- --- --- --- populate coordinate list
    populate_central_plot_coordinate_list(obj_sdl);
	// print_list_coord(obj_sdl->iicu_scene[obj_sdl->iicu_state.scene_id].central_plot.splot_params.coordinate_list);
begin = clock();
    // step_sdl_object(obj_sdl);
    // --- --- --- --- · --- --- --- --- PLOT 
    draw_central_plot(cplot);
    // --- --- --- --- · --- --- --- --- ORBITAL 1
    rand_event=(float)rand()/(float)RAND_MAX;
    orb_angle=(float)rand_event*360.0-180.0;
    sprintf(orb_caption,"orbital :: %f",orb_angle);
    DrawOrbital(obj_sdl, orb_caption, 750, 250, 40, orb_angle);
    // --- --- --- --- · --- --- --- --- ORBITAL 2
    rand_event=(float)rand()/(float)RAND_MAX;
    orb_angle=(float)rand_event*360.0-180.0;
    sprintf(orb_caption,"orbital :: %f",orb_angle);
    DrawOrbital(obj_sdl, orb_caption, 750, 350, 40, orb_angle);
    // draw_sdl_object(obj_sdl);
end = clock();
time_spent = (double)(end-begin) / CLOCKS_PER_SEC;
printf("[waka] :: update screen :: fps :: %f\n",1/time_spent);
    // wait_for_sdl_event(obj_sdl);
}
void refresh_iicu_scene(iicu_scene_struct_t *iicu_scene){
	SDL_DestroyTexture(iicu_scene->central_plot.textureX);
	SDL_DestroyTexture(iicu_scene->central_plot.textureY);
	SDL_FreeSurface(iicu_scene->central_plot.plot_mask_surface);
	SDL_FreeSurface(iicu_scene->central_plot.plot_surface);
	SDL_FreeSurface(iicu_scene->central_plot.caption_mask_surface);
	SDL_FreeSurface(iicu_scene->central_plot.caption_surface);
	SDL_FreeSurface(iicu_scene->central_plot.captionX);
	SDL_FreeSurface(iicu_scene->central_plot.captionY);
	iicu_scene->central_plot.splot_params.coordinate_list = clear_coord(iicu_scene->central_plot.splot_params.coordinate_list);
}
void kill_iicu_scene(iicu_scene_struct_t *iicu_scene){

	refresh_iicu_scene(iicu_scene);
	iicu_scene->central_plot.splot_params.caption_list = clear_caption(iicu_scene->central_plot.splot_params.caption_list);

}
void refresh_current_iicu_scene(sdl_screen_object_t *obj_sdl){
	refresh_iicu_scene(&obj_sdl->iicu_scene[obj_sdl->iicu_state.scene_id]);
}
void kill_current_iicu_scene(sdl_screen_object_t *obj_sdl){
	kill_iicu_scene(&obj_sdl->iicu_scene[obj_sdl->iicu_state.scene_id]);
}
void kill_all_iicu_scenes(sdl_screen_object_t *obj_sdl){
	for(int i;i<obj_sdl->iicu_state.scene_count;i++){
		kill_iicu_scene(&obj_sdl->iicu_scene[obj_sdl->iicu_state.scene_id]);
	}
	obj_sdl->iicu_state.scene_count=0x00;
	obj_sdl->iicu_state.scene_id=0x00;
}

void fabric_iicu_scene(sdl_screen_object_t *obj_sdl){
	if(obj_sdl->iicu_state.scene_count>=MAX_IICU_SCREENS){
		fprintf(stderr,"ERROR :: fabric_iicu_scene :: request exceded de limit for MAX_IICU_SCREENS\n");
		assert(0x00);
	}
	make_splot(obj_sdl,obj_sdl->iicu_state.scene_count);
	obj_sdl->iicu_state.scene_id=obj_sdl->iicu_state.scene_count;
	obj_sdl->iicu_state.scene_count++;
}


