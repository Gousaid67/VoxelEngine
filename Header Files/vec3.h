#ifndef VEC3_H
#define VEC3_H

#include <malloc.h>

typedef struct
{
  float x;
  float y;
  float z;
} vec3;

typedef struct
{
  unsigned char x;
  unsigned char y;
  unsigned char z;
} UByteVec3;

vec3 new_vec3(float x, float y, float z);
UByteVec3 new_UByteVec3(unsigned char x, unsigned char y, unsigned char z);

#endif
