#ifndef SDL_HELPERS_H_
#define SDL_HELPERS_H_

#include <SDL2/SDL.h>
#include "la.h"

#define UNHEX(color) ((color) >> (8 * 2)) & 0xFF, ((color) >> (8 * 1)) & 0xFF, ((color) >> (8 * 0)) & 0xFF

void check_sdl_code(int code);

void *check_sdl_ptr(void *ptr);

Vec2f window_size(SDL_Window * window);

#endif // SDL_HELPERS_H_
