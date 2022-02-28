CC = gcc -Wall
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
		./iicu_assets/sdl_interfaces/scene_panel.c \
		./iicu_assets/sdl_interfaces/login.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/loading.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/home.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/login.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/state_panel.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/scene_panel.c

encription: \
		./iicu_assets/encription/rcsi.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/encription/rcsi.c

data: \
		./iicu_assets/data/mewaajacune_utils.c \
		./iicu_assets/data/data_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/data/data_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/data/mewaajacune_utils.c

sdl: \
		./data_utils.o \
		./iicu_assets/sdl_tools/sdl_plot_queue.c \
		./iicu_assets/sdl_tools/sdl_plot_orbital.c \
		./iicu_assets/sdl_tools/sdl_utils.c \
		./iicu_assets/sdl_tools/sdl_object.c \
		./iicu_assets/sdl_tools/sdl_noise_box.c \
		./iicu_assets/sdl_interfaces/home.c \
		./iicu_assets/sdl_tools/sdl_control.c \
		./iicu_assets/sdl_interfaces/state_panel.c \
		./iicu_assets/sdl_interfaces/loading.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_object.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_control.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_plot_queue.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_noise_box.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_plot_orbital.c

communications: \
		./iicu_assets/communications/broker_api.c \
		./iicu_assets/communications/curl_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/communications/curl_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/communications/broker_api.c

threads: \
		./iicu_assets/threads/thread_launcher.c \
		./iicu_assets/threads/clock_thread.c \
		./iicu_assets/threads/main_thread.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/thread_launcher.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/threads/clock_thread.c
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
		./iicu_assets/iicu/iicu_wikimyei.c \
		./iicu_assets/iicu/iicu_scene_utils.c \
		./iicu_assets/iicu/iicu_state_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/iicu_wikimyei.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/iicu_scene_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/iicu_state_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/iicu_loops.c
	
test_joystick: \
		./iicu_test/test_sdl_joystick_events.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_sdl_joystick_events.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_broker_api: \
		broker_api.o \
		curl_utils.o \
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
		thread_launcher.o \
		main_thread.o \
		iicu_state_utils.o \
		iicu_scene_utils.o \
		sdl_object.o \
		state_panel.o \
		sdl_control.o \
		loading.o \
		home.o \
		login.o \
		sdl_noise_box.o \
		sdl_plot_orbital.o \
		sdl_utils.o \
		data_utils.o \
		rcsi.o \
		curl_utils.o \
		broker_api.o \
		nijcyota_utils.o \
		mewaajacune_utils.o \
		sdl_plot_queue.o \
		iicu_loops.o \
		sdl_utils.o \
		sdl_object.o \
		scene_panel.o \
		iicu_wikimyei.o \
		./iicu_test/test_iicu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_iicu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_queue: \
		clock_thread.o \
		thread_launcher.o \
		main_thread.o \
		iicu_state_utils.o \
		iicu_scene_utils.o \
		sdl_object.o \
		state_panel.o \
		sdl_control.o \
		loading.o \
		home.o \
		login.o \
		sdl_noise_box.o \
		sdl_plot_orbital.o \
		sdl_utils.o \
		data_utils.o \
		rcsi.o \
		curl_utils.o \
		broker_api.o \
		nijcyota_utils.o \
		mewaajacune_utils.o \
		sdl_plot_queue.o \
		iicu_loops.o \
		sdl_utils.o \
		sdl_object.o \
		scene_panel.o \
		iicu_wikimyei.o \
		./iicu_test/test_queue.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_queue.c
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
	time ./test_iicu

test:
	make clean
	make encription
	make communications
	make config
	make data
	make sdl
	make iicu
	make threads
	make interfaces
	make test_queue
	time ./test_queue
