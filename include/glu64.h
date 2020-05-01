#ifndef __GLU64__
#define __GLU64__

#include "../include/nus64.h" // includes "datatypes.h"

int64_t map2l(int64_t x, int64_t in_min, int64_t in_max, int64_t out_min, int64_t out_max);
int64_t mapf2i(int64_t x, float in_min, float in_max, int64_t out_min, int64_t out_max);
float mapi2f(float x, int64_t in_min, int64_t in_max, float out_min, float out_max);
int64_t mapd2i(int64_t x, double in_min, double in_max, int64_t out_min, int64_t out_max);
double mapi2d(float x, int64_t in_min, int64_t in_max, double out_min, double out_max);

#endif //__GLU64__