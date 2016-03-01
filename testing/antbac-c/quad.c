#include "quad.h"

#ifndef TRUNCATE
#define TRUNCATE 32
#endif

#ifndef SIZE
#define SIZE 256
#endif

void constructQuad(Quad *quad) {
  if (quad->elements > TRUNCATE * TRUNCATE) {
    int elements = quad->elements >> 2;

    uint64_t *address0 = quad->matrix;
    uint64_t *address1 = address0 + elements * 1;
    uint64_t *address2 = address0 + elements * 2;
    uint64_t *address3 = address0 + elements * 3;

    quad->children[0] = (Quad *)malloc(sizeof(Quad));
    quad->children[1] = (Quad *)malloc(sizeof(Quad));
    quad->children[2] = (Quad *)malloc(sizeof(Quad));
    quad->children[3] = (Quad *)malloc(sizeof(Quad));

    quad->children[0]->matrix = address0;
    quad->children[1]->matrix = address1;
    quad->children[2]->matrix = address2;
    quad->children[3]->matrix = address3;

    quad->children[0]->elements = elements;
    quad->children[1]->elements = elements;
    quad->children[2]->elements = elements;
    quad->children[3]->elements = elements;

    constructQuad(quad->children[0]);
    constructQuad(quad->children[1]);
    constructQuad(quad->children[2]);
    constructQuad(quad->children[3]);
  }
}

Quad *newQuad() {
  Quad *temp = (Quad *)malloc(sizeof(Quad));
  uint64_t *matrix = (uint64_t *)malloc(SIZE * SIZE * sizeof(uint64_t));
  temp->elements = SIZE * SIZE;
  temp->matrix = matrix;
  constructQuad(temp);
  return temp;
}

void printAddresses(Quad *quad) {
  if (quad->elements == TRUNCATE * TRUNCATE) {
    printf("Address : %zd\n", quad->matrix);
  } else {
    printAddresses(quad->children[0]);
    printAddresses(quad->children[1]);
    printAddresses(quad->children[2]);
    printAddresses(quad->children[3]);
  }
}

void printValues(Quad *quad) {
  if (quad->elements == TRUNCATE * TRUNCATE) {
    for (size_t i = 0; i < quad->elements; i++) {
      printf("Value : %zd\n", quad->matrix[i]);
    }
  } else {
    printValues(quad->children[0]);
    printValues(quad->children[1]);
    printValues(quad->children[2]);
    printValues(quad->children[3]);
  }
}

void mortonify(uint64_t *original, Quad *quad, int dimensions, int x, int y) {
  if (dimensions == TRUNCATE) {
    for (size_t i = 0; i < TRUNCATE; i++) {
      for (size_t j = 0; j < TRUNCATE; j++) {
        quad->matrix[j + i * dimensions] = original[SIZE * (y + i) + x + j];
      }
    }
  } else {
    mortonify(original, quad->children[0], dimensions >> 1, x, y);
    mortonify(original, quad->children[1], dimensions >> 1,
              x + (dimensions >> 1), y);
    mortonify(original, quad->children[2], dimensions >> 1, x,
              y + (dimensions >> 1));
    mortonify(original, quad->children[3], dimensions >> 1,
              x + (dimensions >> 1), y + (dimensions >> 1));
  }
}

void deMortonify(uint64_t *original, Quad *quad, int dimensions, int x, int y) {
  if (dimensions == TRUNCATE) {
    for (size_t i = 0; i < TRUNCATE; i++) {
      for (size_t j = 0; j < TRUNCATE; j++) {
        original[SIZE * (y + i) + x + j] = quad->matrix[j + i * dimensions];
      }
    }
  } else {
    deMortonify(original, quad->children[0], dimensions >> 1, x, y);
    deMortonify(original, quad->children[1], dimensions >> 1,
              x + (dimensions >> 1), y);
    deMortonify(original, quad->children[2], dimensions >> 1, x,
              y + (dimensions >> 1));
    deMortonify(original, quad->children[3], dimensions >> 1,
              x + (dimensions >> 1), y + (dimensions >> 1));
  }
}

void compare(uint64_t *a, uint64_t *b) {
  for (size_t i = 0; i < SIZE * SIZE; i++) {
    if(a[i] != b[i]) {
      printf("Error! i = %lu a was : %lu b was : %lu\n", i, a[i], b[i]);
      return;
    }
  }
}

int main() {
  uint64_t *A = (uint64_t *)malloc(sizeof(uint64_t) * SIZE * SIZE);
  uint64_t *C = (uint64_t *)malloc(sizeof(uint64_t) * SIZE * SIZE);

  Quad *quadA = newQuad();

  for (int i = 0; i < SIZE * SIZE; i++) {
    A[i] = i;
  }

  mortonify(A, quadA, SIZE, 0, 0);
  deMortonify(C, quadA, SIZE, 0, 0);

  compare(A, C);

  // printAddresses(quadA);
  // printValues(quadA);
  /*
  for (size_t i = 0; i < SIZE * SIZE; i++) {
    printf("%lu\n", quadA->matrix[i]);
  }
  */
  return 0;
}
