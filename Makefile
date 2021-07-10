NAME=boids
SRCS=src/main.c src/sdl_helpers.c src/math_helpers.c src/la.c src/boids.c
CFLAGS=-Wall -Wextra -std=c11 -pedantic -ggdb `pkg-config --cflags sdl2 SDL2_gfx`
LIBS=`pkg-config --libs sdl2 SDL2_gfx` -lm

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(LIBS)
