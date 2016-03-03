#include <stdio.h>
#include <stdlib.h>

typedef double double_32 __attribute__((aligned(32)));

void fct(double_32 *__restrict r, const double_32 *__restrict a, const double_32 *__restrict b) {
  for (unsigned i = 0; i < 4; ++i)
    r[i] = a[i] * b[i];
}

/* prototype for asembler function */
void vec_mul(double_32 *__restrict r, const double_32 *__restrict a, const double_32 *__restrict b);

int main() {
  double_32 *a = (double_32 *) malloc(sizeof(double_32) * 4);
  a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
  double_32 *b = (double_32 *) malloc(sizeof(double_32) * 4);
  b[0] = 10; b[1] = 10; b[2] = 10; b[3] = 10;
  double_32 *r = (double_32 *) malloc(sizeof(double_32) * 4);

  /* call the regular function */
  fct(r, a, b);
  for (int i = 0; i < 4; i++) {
    printf("%f\n", r[i]);
  }

  /* call the asembler function */
  vec_mul(r, a, b);
  for (int i = 0; i < 4; i++) {
    printf("%f\n", r[i]);
  }

  return 0;
}
