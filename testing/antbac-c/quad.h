#ifndef FOO_GUARD_FOR_QUAD /* Include guard */
#define FOO_GUARD_FOR_QUAD

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MY_DATA_TYPE uint64_t;

typedef struct Quad Quad;
struct Quad {
  uint64_t *matrix;
  int elements;
  struct Quad *children[4];
};

void constructQuad(Quad *);
Quad *newQuad();
void printAddresses(Quad *);
void printValues(Quad *);
void mortonify(uint64_t *, Quad *, int, int, int);

#endif
