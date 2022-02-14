CC = gcc -Wall
CFLAGS = -O3
LDFLAGS = -lm -lcurl

sdl_cflags := $(shell pkg-config --cflags sdl2 SDL2_mixer SDL2_image SDL2_ttf)
sdl_libs := $(shell pkg-config --libs sdl2 SDL2_mixer SDL2_image SDL2_ttf)
override CFLAGS += $(sdl_cflags)
override LIBS += $(sdl_libs)

HEADERS = -I./iicu_assets/sdl_tools/ -I./iicu_assets/sdl_interfaces/ -I./iicu_assets/encription/ -I./iicu_assets/data/ -I./iicu_assets/config/ -I./iicu_assets/communications/ -I./iicu_assets/iicu/ 

clean:
	rm -f *.o
	rm -f test_*

sdl: ./iicu_assets/sdl_tools/sdl_plot_linked_list.c ./iicu_assets/sdl_tools/sdl_plot.c ./iicu_assets/sdl_tools/sdl_orbital.c ./iicu_assets/sdl_tools/sdl_utils.c ./iicu_assets/sdl_tools/sdl_screen.c ./iicu_assets/config/sdl_config.c ./iicu_assets/sdl_interfaces/home.c ./iicu_assets/sdl_tools/sdl_control.c ./iicu_assets/sdl_interfaces/state_panel.c ./iicu_assets/sdl_interfaces/loading.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_plot_linked_list.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_screen.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_control.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_plot.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/config/sdl_config.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_tools/sdl_orbital.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/loading.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/home.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_interfaces/state_panel.c

encription: ./iicu_assets/encription/rcsi.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/encription/rcsi.c

data: ./iicu_assets/data/data_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/data/data_utils.c

communications: ./iicu_assets/communications/binance_api.c ./iicu_assets/communications/curl_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/communications/curl_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/communications/binance_api.c

iicu: curl_utils.o binance_api.o ./iicu_assets/iicu/cuwacunu_iicu.c ./iicu_assets/iicu/state_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/cuwacunu_iicu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/iicu/state_utils.c

test_joystick: ./iicu_test/test_sdl_joystick_events.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_sdl_joystick_events.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_binance_api: binance_api.o curl_utils.o ./iicu_test/text_binance_api.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/text_binance_api.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_curl: ./iicu_test/test_curl_simple.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_curl_simple.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_encription: rcsi.o
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_sdl_plot: sdl_plot_linked_list.o sdl_plot.o ./iicu_test/test_plot.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_plot.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_iicu: cuwacunu_iicu.o state_utils.o sdl_plot_linked_list.o sdl_screen.o state_panel.o sdl_control.o loading.o home.o sdl_plot.o sdl_orbital.o sdl_config.o sdl_utils.o data_utils.o rcsi.o curl_utils.o binance_api.o ./iicu_test/test_iicu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_test/test_iicu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

all:
	make clean
	make encription
	make communications
	make data
	make sdl
	make iicu
	make test_iicu
	time ./test_iicu
