#include<stdio.h>
#include<stdlib.h>

#ifndef TRUNCATE
#define TRUNCATE 32
#endif

#ifndef SIZE
#define SIZE 64
#endif

static int *A;

typedef struct Quad {
  int* matrix;
  int elements;
  struct Quad *children[4];
} Quad;

void constructQuad(Quad *quad) {
  if(quad->elements > TRUNCATE * TRUNCATE) {
    int elements = quad->elements >> 2;

    int* address0 = quad->matrix;
    int* address1 = address0 + elements * 1;
    int* address2 = address0 + elements * 2;
    int* address3 = address0 + elements * 3;

    quad->children[0] = (Quad*) malloc(sizeof(Quad));
    quad->children[1] = (Quad*) malloc(sizeof(Quad));
    quad->children[2] = (Quad*) malloc(sizeof(Quad));
    quad->children[3] = (Quad*) malloc(sizeof(Quad));

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

Quad* newQuad() {
  Quad *temp = (Quad*) malloc(sizeof(Quad));
  int *matrix = (int*) malloc(SIZE * SIZE * sizeof(int));
  temp->elements = SIZE * SIZE;
  temp->matrix = matrix;
  constructQuad(temp);
  return temp;
}

void printAddresses(struct Quad *quad) {
  if(quad->elements == TRUNCATE * TRUNCATE) {
    printf("Address : %zd\n", quad->matrix);
  }else{
    printAddresses(quad->children[0]);
    printAddresses(quad->children[1]);
    printAddresses(quad->children[2]);
    printAddresses(quad->children[3]);
  }
}

void printValues(struct Quad *quad) {
  if(quad->elements == TRUNCATE * TRUNCATE) {
    for (size_t i = 0; i < quad->elements; i++) {
      printf("Value : %zd\n", quad->matrix[i]);
    }
  }else{
    printValues(quad->children[0]);
    printValues(quad->children[1]);
    printValues(quad->children[2]);
    printValues(quad->children[3]);
  }
}

int main() {
  A = (int*) malloc(sizeof(int) * SIZE * SIZE);

  Quad *quadA = newQuad();

  for (int i = 0; i < SIZE * SIZE; i++) {
    quadA->matrix[i] = i;
  }

  printAddresses(quadA);
  printValues(quadA);
  return 0;
}
