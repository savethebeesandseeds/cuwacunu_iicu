CC = gcc
CFLAGS = -O3
LDFLAGS = -lm

sdl_cflags := $(shell pkg-config --cflags sdl2 SDL2_mixer SDL2_image SDL2_ttf)
sdl_libs := $(shell pkg-config --libs sdl2 SDL2_mixer SDL2_image SDL2_ttf)
override CFLAGS += $(sdl_cflags)
override LIBS += $(sdl_libs)

HEADERS = -I./iicu_assets/ -I./iicu_assets/plotsdl/

clean:
	rm -f test *.o
.PHONY:
	all clean


sdl: ./iicu_assets/plotsdl/sdl_plot_linked_list.c ./iicu_assets/plotsdl/sdl_plot.c ./iicu_assets/sdl_utils.c ./iicu_assets/sdl_config.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/plotsdl/sdl_plot_linked_list.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/plotsdl/sdl_plot.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_utils.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./iicu_assets/sdl_config.c

test_sdl_plot: sdl_plot_linked_list.o sdl_plot.o test_plot.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./test_plot.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test_iicu: sdl_plot_linked_list.o sdl_plot.o sdl_config.o sdl_utils.o test_iicu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -c ./test_iicu.c
	$(CC) $(HEADERS) $(LDFLAGS) $(LIBS) -o $@ $^

test: test.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LIBS)

all:
	make clean
	make sdl
	make test_iicu
	time ./test_iicu iicu_resources/opensans.ttf
