#include "algo/quad.h"
int main() {
  my_type *A = (my_type *)malloc(sizeof(my_type) * ARRAYSIZE * ARRAYSIZE);
  my_type *C = (my_type *)malloc(sizeof(my_type) * ARRAYSIZE * ARRAYSIZE);

  Quad *quadA = newQuad();

  for (int i = 0; i < ARRAYSIZE * ARRAYSIZE; i++) {
    A[i] = i;
  }

  mortonify(A, quadA, ARRAYSIZE, 0, 0);
  deMortonify(C, quadA, ARRAYSIZE, 0, 0);

  compare(A, C);

  // printAddresses(quadA);
  // printValues(quadA);
  /*
  for (size_t i = 0; i < ARRAYSIZE * ARRAYSIZE; i++) {
    printf("%lu\n", quadA->matrix[i]);
  }
  */
  return 0;
}
