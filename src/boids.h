#ifndef BOID_H_
#define BOID_H_

#include <SDL2/SDL.h>
#include "la.h"

#define WIDTH 1280
#define HEIGHT 800
#define MAX_SPEED 5
#define MAX_ALLIGN_FORCE 0.002f
#define MAX_COHESION_FORCE 0.002f
#define MAX_SEPARATION_FORCE 0.002f
#define N 50
#define SIZE 8
#define PERCEP_RADIUS 100

typedef struct {
	Vec2f pos, vel, acc;
	float size;
} Boid;

Boid boid(Vec2f pos, Vec2f vel, Vec2f acc, float size);

void render_boids(Boid boids[], size_t size, SDL_Renderer *renderer);

void update_boids(Boid boids[], size_t size, Vec2f window_size);

void update_allignment_boids(Boid boids[], size_t size, float radius);

void update_cohesion_boids(Boid boids[], size_t size, float radius);

void update_separation_boids(Boid boids[], size_t  size, float radius);
#endif
