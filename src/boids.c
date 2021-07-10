#include "boids.h"
#include "sdl_helpers.h"
#include <SDL2/SDL2_gfxPrimitives.h>
#include <math.h>

Boid boid(Vec2f pos, Vec2f vel, Vec2f acc, float size) 
{	
	return (Boid) {pos, vel, acc, size};
}

void render_boids(Boid boids[], size_t size, SDL_Renderer *renderer)
{
    Vec2f v0, v1, v2, v3;
    for(size_t i = 0; i < size; i++) {
        v0 = vec2f_scl(vec2f_nml(boids[i].vel),boids[i].size);
        v1 = vec2f_add(boids[i].pos, vec2f_scl(v0,2));	
        v2 = vec2f_add(boids[i].pos, vec2f_rot(v0,RADIANS(120)));
        v3 = vec2f_add(boids[i].pos, vec2f_rot(v0,RADIANS(240)));

        filledTrigonRGBA(renderer, v1.x,v1.y, v2.x, v2.y, v3.x, v3.y, UNHEX(0xff6188),255);
    }
}

void update_boids(Boid boids[], size_t size, Vec2f window_size)
{
    for(size_t i = 0; i < size; i++) {
        boids[i].vel = vec2f_clamp(vec2f_add(boids[i].vel, boids[i].acc), MAX_SPEED);
        boids[i].pos = vec2f_add(boids[i].pos, boids[i].vel);

        if(boids[i].pos.x > window_size.x) {
            boids[i].pos.x = 0;
        } else if (boids[i].pos.x < 0) {
            boids[i].pos.x = window_size.x;        
        } 

        if(boids[i].pos.y > window_size.y) {
            boids[i].pos.y = 0;
        } else if (boids[i].pos.y < 0) {
            boids[i].pos.y = window_size.y;        
        }  
    }
}

void update_allignment_boids(Boid boids[], size_t  size, float radius) 
{
    for(size_t i = 0; i < size; i++) {
        size_t local_count = 0;
        Vec2f total_local_vel = vec2f(0.0f, 0.0f);
        for(size_t j = 0; j < size; j++) {
            if(j != i && vec2f_dst(boids[j].pos, boids[i].pos) < radius) {
                local_count++;
                total_local_vel = vec2f_add(total_local_vel, boids[j].vel);
            }
        }

        if(local_count > 0) {
            boids[i].acc = vec2f_add(boids[i].acc, vec2f_clamp(vec2f_nml(vec2f_sub(vec2f_div(total_local_vel, vec2fs(local_count)), boids[i].vel)), 
                                                               MAX_ALLIGN_FORCE));
        }
    }
}

void update_cohesion_boids(Boid boids[], size_t  size, float radius) 
{
    for(size_t i = 0; i < size; i++) {
        size_t local_count = 0;
        Vec2f total_local_pos = vec2f(0.0f, 0.0f);
        for(size_t j = 0; j < size; j++) {
            if(j != i && vec2f_dst(boids[j].pos, boids[i].pos) < radius) {
                local_count++;
                total_local_pos.x += boids[j].pos.x;
                total_local_pos.y += boids[j].pos.y;
            }
        }

        if(local_count > 0) {
            boids[i].acc = vec2f_add(boids[i].acc, vec2f_clamp(vec2f_nml(vec2f_sub(vec2f_div(total_local_pos, vec2fs(local_count)), boids[i].vel)), 
                                                               MAX_COHESION_FORCE));
        }
    }
}

void update_separation_boids(Boid boids[], size_t  size, float radius) 
{
    for(size_t i = 0; i < size; i++) {
        size_t local_count = 0;
        Vec2f total_local_pos = vec2f(0.0f, 0.0f);
        for(size_t j = 0; j < size; j++) {
            if(j != i && vec2f_dst(boids[j].pos, boids[i].pos) < radius) {
                local_count++;
                const float vec_dst = vec2f_dst(boids[j].pos, boids[i].pos);
                if(vec_dst > 0.0f) {
                    total_local_pos = vec2f_add(total_local_pos, vec2f_scl(vec2f_sub(boids[i].pos, boids[j].pos), 1.0f / vec_dst));
                }
            }
        }

        if(local_count > 0) {
            boids[i].acc = vec2f_add(boids[i].acc, vec2f_clamp(vec2f_nml(vec2f_sub(vec2f_div(total_local_pos, vec2fs(local_count)), boids[i].vel)), 
                                                               MAX_SEPARATION_FORCE));
        }
    }
}
