#ifndef LA_H_
#define LA_H_

#define RADIANS(deg)(deg * M_PI / 180.0)

typedef struct {
	float x, y;
} Vec2f;

Vec2f vec2f(float x, float y);

Vec2f vec2fs(float x);

Vec2f vec2f_add(Vec2f vec_a, Vec2f vec_b);

Vec2f vec2f_sub(Vec2f vec_a, Vec2f vec_b);

Vec2f vec2f_mul(Vec2f vec_a, Vec2f vec_b);

Vec2f vec2f_scl(Vec2f vec, float x);

Vec2f vec2f_div(Vec2f vec_a, Vec2f vec_b);

void vec2f_print(Vec2f *vec);

float vec2f_mag(Vec2f vec);

Vec2f vec2f_clamp(Vec2f vec, float max_mag);

Vec2f vec2f_nml(Vec2f vec);

Vec2f vec2f_rot(Vec2f vec, float ang);

float vec2f_dst(Vec2f vec_a, Vec2f vec_b);

#endif // LA_H
