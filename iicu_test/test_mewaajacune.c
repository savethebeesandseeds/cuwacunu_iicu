#include "../iicu_assets/config/sdl_config.h"
#include "../iicu_assets/config/general_config.h"
#include "../iicu_assets/data/mewaajacune_utils.h"
int main(int argc, char* argv[]){
    __iicu_mewaajacune_t *static_mewaajacune=mewaajacune_fabric();
    bnc_klines_t klines_payload={};
    get_klines(&klines_payload, "BTCUSDT", "1m");
    int klines_size=klines_payload.klines_count;
    __cwcn_type_t *klines_list=malloc(klines_size*sizeof(__cwcn_type_t));

    for(int x_position=0x00;x_position<klines_size;x_position++){
        klines_list[x_position]=(__cwcn_type_t)klines_payload.klines[x_position].close;
    }

    while(0x01){
        __iicu_mewaajacune_t *tmp_mewaajacune=mewaajacune_fabric();
        // fprintf(stdout,"------------------------------------------ : %p\n",tmp_mewaajacune);
        // getchar();
        // yield_next_trayectory(tmp_mewaajacune);
        // yield_next_trayectory(tmp_mewaajacune);
        // load_print_up_trayectory_pointers(tmp_mewaajacune);
        // --- update temporal mewaajacune
        // populate_alliu_with_klines(tmp_mewaajacune, 0x00, "BTCUSDT", "1m");
        test_populate_alliu_with_list(tmp_mewaajacune, 0x00, klines_list, klines_size);
        // tmp_mean=mean_alliu_in_load(tmp_mewaajacune, _alliu_index);
        // tmp_std=std_alliu_in_load(tmp_mewaajacune, _alliu_index);
        // get_state(_iicu_wikimyei)->kline_last_update[idx_scene][idx_kline]=(double) time(NULL);
        // --- safely update desired mewaajacune
        // beseech_mewaajacune(_iicu_wikimyei, idx_scene, idx_kline);
        rebase_mewaajacune(static_mewaajacune,tmp_mewaajacune);
        // release_mewaajacune(_iicu_wikimyei, idx_scene, idx_kline);
        // --- safely destoy temporal mewaajacune
        destroy_mewaajacune(tmp_mewaajacune);
    }
    destroy_mewaajacune(static_mewaajacune);
    free(klines_list);
	return EXIT_SUCCESS;
}

