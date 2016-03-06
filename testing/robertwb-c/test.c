#include <stdio.h>
#include <stdlib.h>

typedef double double_32 __attribute__((aligned(32)));

void fct(double_32 *__restrict r, const double_32 *__restrict a, const double_32 *__restrict b) {
  for (unsigned i = 0; i < 4; ++i)
    r[i] = a[i] * b[i];
}

/* prototype for asembler function */
void transpose(double_32 *__restrict r, const double_32 *__restrict a);

int main() {
  double_32 *a = (double_32 *) aligned_alloc(32, sizeof(double_32) * 16);
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
  for (int i = 0; i < 16; i++) {
    printf("%f\n", a[i]);
  }
  double_32 *r = (double_32 *) aligned_alloc(32, sizeof(double_32) * 16);

  printf("a : %p\n", a);
  printf("r : %p\n", r);

  /* call the regular function */
  // fct(r, a, b);
  for (int i = 0; i < 16; i++) {
    r[i] = 0xDEAD;
  }

  /* call the asembler function */
  transpose(r, a);
  for (int i = 0; i < 16; i++) {
    printf("%f\n", r[i]);
  }

  return 0;
}
