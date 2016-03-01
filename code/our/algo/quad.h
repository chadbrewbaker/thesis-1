#ifndef FOO_GUARD_FOR_QUAD /* Include guard */
#define FOO_GUARD_FOR_QUAD

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "defines.h"


typedef struct Quad Quad;
struct Quad {
  my_type *matrix;
  uint32_t elements;
  struct Quad *children[4];
};

void constructQuad(Quad *);
Quad *newQuad();
void printAddresses(Quad *);
void printValues(Quad *);
void mortonify(my_type *, Quad *, uint32_t, uint32_t, uint32_t);
void deMortonify(my_type *, Quad *, uint32_t, uint32_t, uint32_t);
void compare(my_type *, my_type *);

#endif
