#include<stdio.h>
#include<stdlib.h>

#ifndef TRUNCATE
#define TRUNCATE 4
#endif

#ifndef SIZE
#define SIZE 8
#endif

static int *A;

typedef struct Quad {
  int* matrix;
  int dimensions;
  struct Quad *children[4];
} Quad;

void constructQuad(Quad *quad) {
  if(quad->dimensions > TRUNCATE) {
    int dimensions = quad->dimensions >> 1;
    int blockSize = dimensions * dimensions;

    int* address0 = quad->matrix;
    int* address1 = address0 + blockSize * sizeof(int);
    int* address2 = address0 + blockSize * sizeof(int) * 2;
    int* address3 = address0 + blockSize * sizeof(int) * 3;

    quad->children[0] = (Quad*) malloc(sizeof(Quad));
    quad->children[1] = (Quad*) malloc(sizeof(Quad));
    quad->children[2] = (Quad*) malloc(sizeof(Quad));
    quad->children[3] = (Quad*) malloc(sizeof(Quad));

    quad->children[0]->matrix = address0;
    quad->children[1]->matrix = address1;
    quad->children[2]->matrix = address2;
    quad->children[3]->matrix = address3;

    quad->children[0]->dimensions = dimensions;
    quad->children[1]->dimensions = dimensions;
    quad->children[2]->dimensions = dimensions;
    quad->children[3]->dimensions = dimensions;


    constructQuad(quad->children[0]);
    constructQuad(quad->children[1]);
    constructQuad(quad->children[2]);
    constructQuad(quad->children[3]);
  }
}

void printAddresses(struct Quad *quad) {
  if(quad->dimensions == TRUNCATE) {
    printf("%zd\n", quad->matrix);
  }else{
    printAddresses(quad->children[0]);
    printAddresses(quad->children[1]);
    printAddresses(quad->children[2]);
    printAddresses(quad->children[3]);
  }
}

Quad* newQuad(int dimensions) {
  Quad *temp = (Quad*) malloc(sizeof(Quad));
  int *matrix = (int*) malloc(dimensions * dimensions * sizeof(int));
  temp->dimensions = dimensions;
  temp->matrix = matrix;
  constructQuad(temp);
  return temp;
}

int main() {
  A = (int*) malloc(sizeof(int) * SIZE * SIZE);

  Quad * quadA = newQuad(SIZE);
  constructQuad(quadA);
  for (int i = 0; i < SIZE * SIZE; i++) {
    A[i] = i;
  }

  printf("%zd\n", &(quadA->children[0]->dimensions));
  printAddresses(quadA);
  return 0;
}
