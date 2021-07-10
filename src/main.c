#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <SDL2/SDL.h>

#include "boids.h"
#include "la.h"
#include "sdl_helpers.h"
#include "math_helpers.h"

#define FPS 60
#define DELAY_MS (1000/FPS)

Boid boids[N];

int main(void)
{
	SDL_Window * window = check_sdl_ptr(SDL_CreateWindow("Boids", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN));
	SDL_Renderer * renderer = check_sdl_ptr(SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED));

	srand(time(NULL));
	for (size_t i = 0; i < N; i++) { 
	    boids[i] = boid(vec2f(rand_int(WIDTH), rand_int(HEIGHT)), 
                        vec2f(rand_float(-MAX_SPEED, MAX_SPEED), rand_float(-MAX_SPEED, MAX_SPEED)), vec2f(0,0), SIZE);		
	}

	bool quit = false;
    unsigned int last_time = 0, current_time;

	while(!quit) {
		SDL_Event e;
		while(SDL_PollEvent(&e)) {
			switch(e.type) {
				case SDL_QUIT:
					quit = true;
					break;
                case SDL_KEYDOWN:
                    switch(e.key.keysym.sym) {
                        case SDLK_r:
                            for (size_t i = 0; i < N; i++) { 
                                boids[i] = boid(vec2f(rand_int(WIDTH), rand_int(HEIGHT)), 
                                                vec2f(rand_float(-MAX_SPEED, MAX_SPEED), rand_float(-MAX_SPEED, MAX_SPEED)), vec2f(0,0), SIZE);		
                            }
                        break;
                    }
                break;
			}
		}

        current_time = SDL_GetTicks();
        if (current_time > last_time + DELAY_MS) {
            check_sdl_code(SDL_SetRenderDrawColor(renderer, UNHEX(0x282C34), 0xAA));
            check_sdl_code(SDL_RenderClear(renderer));
            render_boids(boids, N, renderer); 
            SDL_RenderPresent(renderer);

            update_allignment_boids(boids, N, PERCEP_RADIUS);
            update_cohesion_boids(boids, N, PERCEP_RADIUS);
            update_separation_boids(boids, N, PERCEP_RADIUS);
            update_boids(boids, N, window_size(window));
            last_time = current_time;
        }
	}

	return 0;
}


