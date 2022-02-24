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
		./iicu_assets/sdl_interfaces/iicu_scene.c \
		./iicu_assets/sdl_interfaces/login.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/loading.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/home.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/login.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/state_panel.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/iicu_scene.c

encription: \
		./iicu_assets/encription/rcsi.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/encription/rcsi.c

data: \
		./iicu_assets/data/queue_utils.c \
		./iicu_assets/data/data_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/data/data_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/data/queue_utils.c

sdl: \
		./data_utils.o \
		./iicu_assets/sdl_tools/sdl_plot_linked_list.c \
		./iicu_assets/sdl_tools/sdl_plot_queue.c \
		./iicu_assets/sdl_tools/sdl_plot.c \
		./iicu_assets/sdl_tools/sdl_orbital.c \
		./iicu_assets/sdl_tools/sdl_utils.c \
		./iicu_assets/sdl_tools/sdl_object.c \
		./iicu_assets/sdl_interfaces/home.c \
		./iicu_assets/sdl_tools/sdl_control.c \
		./iicu_assets/sdl_interfaces/state_panel.c \
		./iicu_assets/sdl_interfaces/loading.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_plot_linked_list.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_object.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_control.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_plot.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_plot_queue.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_orbital.c

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

loops: \
		curl_utils.o \
		broker_api.o \
		./iicu_assets/iicu/iicu_loops.c \
		./iicu_assets/iicu/state_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/state_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/iicu_loops.c

test_queue: \
		iicu_loops.o \
		clock_thread.o \
		thread_launcher.o \
		main_thread.o \
		state_utils.o \
		sdl_plot_linked_list.o \
		sdl_object.o \
		state_panel.o \
		sdl_control.o \
		loading.o \
		home.o \
		login.o \
		iicu_scene.o \
		sdl_plot.o \
		sdl_orbital.o \
		sdl_utils.o \
		data_utils.o \
		rcsi.o \
		curl_utils.o \
		broker_api.o \
		queue_utils.o \
		sdl_plot_queue.o \
		iicu_loops.o \
		sdl_utils.o \
		sdl_object.o \
		./iicu_test/test_queue.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_queue.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

	
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

test_sdl_plot: \
		sdl_plot_linked_list.o \
		sdl_plot.o \
		./iicu_test/test_plot.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_plot.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_iicu: \
		iicu_loops.o \
		clock_thread.o \
		thread_launcher.o \
		main_thread.o \
		state_utils.o \
		sdl_plot_linked_list.o \
		sdl_object.o \
		state_panel.o \
		sdl_control.o \
		loading.o \
		home.o \
		login.o \
		iicu_scene.o \
		sdl_plot.o \
		sdl_orbital.o \
		sdl_utils.o \
		data_utils.o \
		rcsi.o \
		curl_utils.o \
		broker_api.o \
		queue_utils.o \
		sdl_plot_queue.o \
		iicu_loops.o \
		sdl_utils.o \
		sdl_object.o \
		./iicu_test/test_iicu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_iicu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^


all:
	make clean
	make encription
	make communications
	make data
	make sdl
	make loops
	make threads
	make interfaces
	make test_iicu
	time ./test_iicu

test:
	make clean
	make encription
	make communications
	make data
	make sdl
	make loops
	make threads
	make interfaces
	make test_queue
	time ./test_queue
