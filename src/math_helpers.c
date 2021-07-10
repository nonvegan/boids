#include "math_helpers.h"
#include <stdlib.h>
#include <assert.h>

float rand_float(float a, float b)
{
    assert(b > a); 
    float random = ((float) rand()) / (float) RAND_MAX;

    return random * (b - a) + a;
}

int rand_int(int a)
{
	return rand() % a;
}
