CC = gcc -Wall -g -O0
CFLAGS = -O3
LDFLAGS = -lm -lcurl

sdl_cflags := $(shell pkg-config --cflags sdl2 SDL2_mixer SDL2_image SDL2_ttf)
sdl_libs := $(shell pkg-config --libs sdl2 SDL2_mixer SDL2_image SDL2_ttf)
override CFLAGS += $(sdl_cflags)
override LIBS += $(sdl_libs)

HEADERS = \
	-I./iicu_assets/sdl_tools/ \
	-I./iicu_assets/sdl_interfaces/ \
	-I./iicu_assets/encription/ \
	-I./iicu_assets/data/ \
	-I./iicu_assets/config/ \
	-I./iicu_assets/threads/ \
	-I./iicu_assets/communications/ \
	-I./iicu_assets/iicu/

clean:
	rm -f *.o
	rm -f test_*

interfaces: \
		sdl_utils.o \
		sdl_object.o \
		sdl_control.o \
		./iicu_assets/sdl_interfaces/loading.c \
		./iicu_assets/sdl_interfaces/home.c \
		./iicu_assets/sdl_interfaces/state_panel.c \
		./iicu_assets/sdl_interfaces/debug_panel.c \
		./iicu_assets/sdl_interfaces/scene_panel.c \
		./iicu_assets/sdl_interfaces/login.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/loading.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/home.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/login.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/debug_panel.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/state_panel.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/scene_panel.c

encription: \
		./iicu_assets/encription/rcsi.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/encription/rcsi.c

data: \
		./iicu_assets/data/kemu_utils.c \
		./iicu_assets/data/polinomial_kemu.c \
		./iicu_assets/data/regressive_kemu.c \
		./iicu_assets/data/staticques_kemu.c \
		./iicu_assets/data/mewaajacune_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/data/kemu_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/data/polinomial_kemu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/data/regressive_kemu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/data/staticques_kemu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/data/mewaajacune_utils.c

sdl: \
		./iicu_assets/sdl_tools/sdl_plot_queue.c \
		./iicu_assets/sdl_tools/sdl_plot_orbital.c \
		./iicu_assets/sdl_tools/sdl_jkimyei.c \
		./iicu_assets/sdl_tools/sdl_itsaave.c \
		./iicu_assets/sdl_tools/sdl_utils.c \
		./iicu_assets/sdl_tools/sdl_object.c \
		./iicu_assets/sdl_tools/sdl_noise_box.c \
		./iicu_assets/sdl_tools/sdl_main_plot.c \
		./iicu_assets/sdl_interfaces/home.c \
		./iicu_assets/sdl_tools/sdl_control.c \
		./iicu_assets/sdl_interfaces/loading.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_object.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_control.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_plot_queue.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_itsaave.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_jkimyei.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_main_plot.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_noise_box.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_plot_orbital.c

communications: \
		./iicu_assets/communications/broker_api.c \
		./iicu_assets/communications/curl_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/communications/curl_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/communications/broker_api.c

threads: \
		./iicu_assets/threads/broker_thread.c \
		./iicu_assets/threads/jkimyei_thread.c \
		./iicu_assets/threads/itsaave_thread.c \
		./iicu_assets/threads/regressive_thread.c \
		./iicu_assets/threads/polinomial_thread.c \
		./iicu_assets/threads/staticques_thread.c \
		./iicu_assets/threads/state_thread.c \
		./iicu_assets/threads/clock_thread.c \
		./iicu_assets/threads/threads_launcher.c \
		./iicu_assets/threads/main_thread.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/broker_thread.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/itsaave_thread.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/jkimyei_thread.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/regressive_thread.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/polinomial_thread.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/staticques_thread.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/state_thread.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/clock_thread.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/threads_launcher.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/main_thread.c

config: \
		./iicu_assets/config/nijcyota_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/config/nijcyota_utils.c

iicu: \
		curl_utils.o \
		broker_api.o \
		broker_api.o \
		nijcyota_utils.o \
		sdl_utils.o \
		nijcyota_utils.o \
		sdl_control.o \
		sdl_noise_box.o \
		./iicu_assets/iicu/iicu_loops.c \
		./iicu_assets/iicu/iicu_itsaave.c \
		./iicu_assets/iicu/iicu_wikimyei.c \
		./iicu_assets/iicu/iicu_jkimyei.c \
		./iicu_assets/iicu/iicu_scene_utils.c \
		./iicu_assets/iicu/iicu_state_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/iicu_jkimyei.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/iicu_itsaave.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/iicu_wikimyei.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/iicu_scene_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/iicu_state_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/iicu_loops.c
	
test_joystick: \
		./iicu_test/test_sdl_joystick_events.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_sdl_joystick_events.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_broker_api: \
		curl_utils.o \
		broker_api.o \
		./iicu_test/text_broker_api.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/text_broker_api.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_curl: \
		./iicu_test/test_curl_simple.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_curl_simple.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_encription: \
		rcsi.o
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_iicu: \
		clock_thread.o \
		broker_thread.o \
		state_thread.o \
		jkimyei_thread.o \
		itsaave_thread.o \
		regressive_thread.o \
		polinomial_thread.o \
		staticques_thread.o \
		threads_launcher.o \
		main_thread.o \
		kemu_utils.o \
		iicu_state_utils.o \
		iicu_scene_utils.o \
		sdl_object.o \
		state_panel.o \
		debug_panel.o \
		sdl_control.o \
		loading.o \
		home.o \
		login.o \
		sdl_main_plot.o \
		sdl_noise_box.o \
		sdl_plot_orbital.o \
		sdl_jkimyei.o \
		sdl_itsaave.o \
		sdl_utils.o \
		rcsi.o \
		curl_utils.o \
		broker_api.o \
		nijcyota_utils.o \
		regressive_kemu.o \
		polinomial_kemu.o \
		staticques_kemu.o \
		mewaajacune_utils.o \
		sdl_plot_queue.o \
		iicu_loops.o \
		sdl_utils.o \
		sdl_object.o \
		scene_panel.o \
		iicu_jkimyei.o \
		iicu_itsaave.o \
		iicu_wikimyei.o \
		./iicu_test/test_iicu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_iicu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_queue: \
		clock_thread.o \
		broker_thread.o \
		state_thread.o \
		jkimyei_thread.o \
		itsaave_thread.o \
		regressive_thread.o \
		polinomial_thread.o \
		staticques_thread.o \
		threads_launcher.o \
		main_thread.o \
		kemu_utils.o \
		iicu_state_utils.o \
		iicu_scene_utils.o \
		sdl_object.o \
		state_panel.o \
		debug_panel.o \
		sdl_control.o \
		loading.o \
		home.o \
		login.o \
		sdl_main_plot.o \
		sdl_jkimyei.o \
		sdl_itsaave.o \
		sdl_noise_box.o \
		sdl_plot_orbital.o \
		sdl_utils.o \
		rcsi.o \
		curl_utils.o \
		broker_api.o \
		nijcyota_utils.o \
		regressive_kemu.o \
		polinomial_kemu.o \
		staticques_kemu.o \
		mewaajacune_utils.o \
		sdl_plot_queue.o \
		iicu_loops.o \
		sdl_utils.o \
		sdl_object.o \
		scene_panel.o \
		iicu_jkimyei.o \
		iicu_itsaave.o \
		iicu_wikimyei.o \
		./iicu_test/test_queue.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_queue.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_linalg: \
	curl_utils.o \
	broker_api.o \
	mewaajacune_utils.o \
	regressive_kemu.o \
	polinomial_kemu.o \
	staticques_kemu.o \
	./iicu_test/test_linalg.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_linalg.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_jkimyei: \
		clock_thread.o \
		broker_thread.o \
		state_thread.o \
		jkimyei_thread.o \
		itsaave_thread.o \
		threads_launcher.o \
		main_thread.o \
		kemu_utils.o \
		iicu_state_utils.o \
		iicu_scene_utils.o \
		sdl_object.o \
		state_panel.o \
		debug_panel.o \
		sdl_control.o \
		loading.o \
		home.o \
		login.o \
		sdl_main_plot.o \
		sdl_jkimyei.o \
		sdl_itsaave.o \
		sdl_noise_box.o \
		sdl_plot_orbital.o \
		sdl_utils.o \
		rcsi.o \
		curl_utils.o \
		broker_api.o \
		nijcyota_utils.o \
		regressive_kemu.o \
		polinomial_kemu.o \
		staticques_kemu.o \
		mewaajacune_utils.o \
		sdl_plot_queue.o \
		iicu_loops.o \
		sdl_utils.o \
		sdl_object.o \
		scene_panel.o \
		iicu_itsaave.o \
		iicu_jkimyei.o \
		iicu_wikimyei.o \
	./iicu_test/test_jkimyei.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_jkimyei.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

all:
	make clean
	make encription
	make communications
	make config
	make data
	make sdl
	make iicu
	make threads
	make interfaces
	make test_iicu
	gdb ./test_iicu

test_d_mewaajacune: \
		mewaajacune_utils.o \
		broker_api.o \
		curl_utils.o \
		./iicu_test/test_mewaajacune.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_mewaajacune.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test:
	make clean
	make communications
	make data
	make test_d_mewaajacune
	gdb ./test_d_mewaajacune
