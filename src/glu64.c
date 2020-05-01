#include "../include/nus64.h"
#include "../include/assert64.h"
FILENUM(3)

int64_t map2l(int64_t x, int64_t in_min, int64_t in_max, int64_t out_min, int64_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int64_t mapf2i(int64_t x, float in_min, float in_max, int64_t out_min, int64_t out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

float mapi2f(float x, int64_t in_min, int64_t in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}