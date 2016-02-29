#include<stdio.h>
#include<stdlib.h>

#ifndef truncate
#define truncate 2
#endif

#ifndef size
#define size 4
#endif

static int *A, *B, *C;

struct Quad {
  int* matrix;
  int dimensions;
  struct Quad *children[4];
} quadA, quadB;

void constructQuad(struct Quad *quad) {
  if(quad->dimensions > truncate) {
    int dimensions = quad->dimensions >> 1;
    int* address0 = quad->matrix;
    int* address1 = address0 + (dimensions) * sizeof(int);
    int* address2 = address0 + (dimensions * quad->dimensions) * sizeof(int);
    int* address3 = address1 + (dimensions * quad->dimensions) * sizeof(int);

// TODO : How do I make this more beautiful?
    struct Quad temp0 = {address0, dimensions};
    struct Quad temp1 = {address1, dimensions};
    struct Quad temp2 = {address2, dimensions};
    struct Quad temp3 = {address3, dimensions};
    quad->children[0] = &temp0;
    quad->children[1] = &temp1;
    quad->children[2] = &temp2;
    quad->children[3] = &temp3;
// end TODO
    constructQuad(quad->children[0]);
    constructQuad(quad->children[1]);
    constructQuad(quad->children[2]);
    constructQuad(quad->children[3]);
  }
}

void printAddresses(struct Quad *quad) {
  if(quad->dimensions == truncate) {
    printf("%u\n", quad->matrix);
  }else{
    printAddresses(quad->children[0]);
    printAddresses(quad->children[1]);
    printAddresses(quad->children[2]);
    printAddresses(quad->children[3]);
  }
}

int main() {
  A = (int*) malloc(sizeof(int) * size * size);
  B = (int*) malloc(sizeof(int) * size * size);
  C = (int*) malloc(sizeof(int) * size * size);
  quadA.matrix = A;
  quadA.dimensions = size;
  quadB.matrix = B;
  quadB.dimensions = size;
  constructQuad(&quadA);
  for (int i = 0; i < size * size; i++) {
    A[i] = i;
    B[i] = i+i;
    C[i] = i+i+i;
  }

  printf("%d\n", &(quadA.children[0]->dimensions)); // This does not give me the address of the integer called dimensions in the first child of quadA
  printAddresses(&quadA);
  return 0;
}
