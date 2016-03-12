#include "quad.h"

void constructQuad(Quad *quad) {
  if (quad->elements > FIXEDSIZE * FIXEDSIZE) {
    int elements = quad->elements >> 2;

    my_type *address0 = quad->matrix;
    my_type *address1 = address0 + elements * 1;
    my_type *address2 = address0 + elements * 2;
    my_type *address3 = address0 + elements * 3;

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

void freeQuad(Quad *quad) {
  if (quad->elements > FIXEDSIZE * FIXEDSIZE) {
    freeQuadRecursive(quad->children[0]);
    freeQuadRecursive(quad->children[1]);
    freeQuadRecursive(quad->children[2]);
    freeQuadRecursive(quad->children[3]);
    free(quad->children[0]);
    free(quad->children[1]);
    free(quad->children[2]);
    free(quad->children[3]);
  }
  free(quad->matrix);
  free(quad);
}

void freeQuadRecursive(Quad *quad) {
  if (quad->elements > FIXEDSIZE * FIXEDSIZE) {
    freeQuadRecursive(quad->children[0]);
    freeQuadRecursive(quad->children[1]);
    freeQuadRecursive(quad->children[2]);
    freeQuadRecursive(quad->children[3]);
    free(quad->children[0]);
    free(quad->children[1]);
    free(quad->children[2]);
    free(quad->children[3]);
  }
}

Quad *newQuad(size_t size) {
  Quad *temp = (Quad *)aligned_alloc(32, sizeof(Quad));
  my_type *matrix = (my_type *)aligned_alloc(32, size * size * sizeof(my_type));
  temp->elements = size * size;
  temp->matrix = matrix;
  constructQuad(temp);
  return temp;
}

void printAddresses(Quad *quad) {
  if (quad->elements == FIXEDSIZE * FIXEDSIZE) {
    printf("Address : %p\n", quad->matrix);
  } else {
    printAddresses(quad->children[0]);
    printAddresses(quad->children[1]);
    printAddresses(quad->children[2]);
    printAddresses(quad->children[3]);
  }
}

void printValues(Quad *quad) {
  if (quad->elements == FIXEDSIZE * FIXEDSIZE) {
    for (size_t i = 0; i < quad->elements; i++) {
      printf("Value : %f\n", quad->matrix[i]);
    }
  } else {
    printValues(quad->children[0]);
    printValues(quad->children[1]);
    printValues(quad->children[2]);
    printValues(quad->children[3]);
  }
}

void mortonify(my_type *original, Quad *quad, uint32_t dimensions, uint32_t x, uint32_t y) {
  if (dimensions == FIXEDSIZE) {
    for (size_t i = 0; i < FIXEDSIZE; i++) {
      for (size_t j = 0; j < FIXEDSIZE; j++) {
        quad->matrix[j + i * dimensions] = original[ARRAYSIZE * (y + i) + x + j];
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

void deMortonify(my_type *original, Quad *quad, uint32_t dimensions, uint32_t x, uint32_t y) {
  if (dimensions == FIXEDSIZE) {
    for (size_t i = 0; i < FIXEDSIZE; i++) {
      for (size_t j = 0; j < FIXEDSIZE; j++) {
        original[ARRAYSIZE * (y + i) + x + j] = quad->matrix[j + i * dimensions];
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

void compare(my_type *a, my_type *b) {
  for (size_t i = 0; i < ARRAYSIZE * ARRAYSIZE; i++) {
    if(a[i] != b[i]) {
      printf("Error! i = %lu a was : %f b was : %f\n", i, a[i], b[i]);
      return;
    }
  }
}
