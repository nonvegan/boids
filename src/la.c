#include "la.h"
#include <math.h>
#include <stdio.h>


Vec2f vec2f(float x, float y) 
{
	Vec2f vec = {x, y};	
	return vec;
}

Vec2f vec2fs(float x)
{
    return vec2f(x, x);
}

Vec2f vec2f_add(Vec2f vec_a, Vec2f vec_b)
{
	return vec2f(vec_a.x + vec_b.x, vec_a.y + vec_b.y);
}

Vec2f vec2f_sub(Vec2f vec_a, Vec2f vec_b)
{
	return vec2f(vec_a.x - vec_b.x, vec_a.y - vec_b.y);
}

Vec2f vec2f_mul(Vec2f vec_a, Vec2f vec_b)
{
	return vec2f(vec_a.x * vec_b.x, vec_a.y * vec_b.y);
}

Vec2f vec2f_scl(Vec2f vec, float x) 
{
	return vec2f(x * vec.x, x * vec.y);
}

Vec2f vec2f_div(Vec2f vec_a, Vec2f vec_b)
{
	return vec2f(vec_a.x / vec_b.x, vec_a.y / vec_b.y);
}

float vec2f_mag(Vec2f vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

Vec2f vec2f_nml(Vec2f vec)
{
	float vec_mag = vec2f_mag(vec);
	return vec_mag ? vec2f(vec.x / vec_mag, vec.y / vec_mag) : vec2f(0.0f, 0.0f);
}

Vec2f vec2f_clamp(Vec2f vec, float max_mag) 
{
    return vec2f_scl(vec2f_nml(vec), fmin(vec2f_mag(vec), max_mag));
}

float vec2f_dst(Vec2f vec_a, Vec2f vec_b)
{
	return sqrt(pow(vec_b.x - vec_a.x, 2) + pow(vec_b.y - vec_a.y,2));
}

Vec2f vec2f_rot(Vec2f vec, float ang)
{
	return vec2f(vec.x * cos(ang) - vec.y * sin(ang), vec.y * cos(ang) + vec.x * sin(ang));
}


void vec2f_print(Vec2f *vec)
{
	printf("Vec2f -> (%f, %f)\n",vec->x,vec->y);
}
