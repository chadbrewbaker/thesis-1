#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double double_32 __attribute__((aligned(32)));

void fct(double_32 *__restrict r, const double_32 *__restrict a, const double_32 *__restrict b) {
  for (unsigned i = 0; i < 4; ++i)
    r[i] = a[i] * b[i];
}

/* prototype for asembler function */
void m4mul(const double_32 *__restrict a, const double_32 *__restrict b, double_32 *__restrict r);
size_t SIZE = 16;

int main() {
  double_32 *a = (double_32 *) aligned_alloc(32, sizeof(double_32) * SIZE);
  a[0] = 1;
  a[1] = 2;
  a[2] = 3;
  a[3] = 4;
  a[4] = 5;
  a[5] = 6;
  a[6] = 7;
  a[7] = 8;
  a[8] = 9;
  a[9] = 10;
  a[10] = 11;
  a[11] = 12;
  a[12] = 13;
  a[13] = 14;
  a[14] = 15;
  a[15] = 16;
  double_32 *b = (double_32 *) aligned_alloc(32, sizeof(double_32) * SIZE);
  b[0] = 1;
  b[1] = 2;
  b[2] = 3;
  b[3] = 4;
  b[4] = 5;
  b[5] = 6;
  b[6] = 7;
  b[7] = 8;
  b[8] = 9;
  b[9] = 10;
  b[10] = 11;
  b[11] = 12;
  b[12] = 13;
  b[13] = 14;
  b[14] = 15;
  b[15] = 16;
  for (int i = 0; i < SIZE; i++) {
    printf("%f\n", a[i]);
  }
  double_32 *r = (double_32 *) aligned_alloc(32, sizeof(double_32) * SIZE);

  printf("a : %p\n", a);
  printf("r : %p\n", r);

  /* call the regular function */
  // fct(r, a, b);
  for (int i = 0; i < SIZE; i++) {
    r[i] = 0xDEAD;
  }

  /* call the asembler function */
  m4mul(a, b, r);
  size_t square = 4;
  for (int i = 0; i < square; i++) {
    for (int j = 0; j < square; j++) {
      printf("%f ", r[i*square + j]);
    }
    printf("\n");
  }

  return 0;
}
