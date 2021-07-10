#include "sdl_helpers.h"

void check_sdl_code(int code)
{
    if (code < 0) {
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
        exit(1);
    }
}

void *check_sdl_ptr(void *ptr)
{
    if (ptr == NULL) {
        fprintf(stderr, "SDL ERROR: %s\n", SDL_GetError());
        exit(1);
    }

    return ptr;
}

Vec2f window_size(SDL_Window * window)
{
    int x, y;
    SDL_GetWindowSize(window, &x, &y);

    return vec2f(x,y);
}
