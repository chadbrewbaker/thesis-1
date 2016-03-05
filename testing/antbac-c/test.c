#include <stdio.h>
#include <stdlib.h>

typedef double double_32 __attribute__((aligned(32)));

/* Multiply two arrays into one array */
void fct(double_32 *__restrict r, const double_32 *__restrict a, const double_32 *__restrict b) {
  for (unsigned i = 0; i < 4; ++i)
    r[i] = a[i] * b[i];
}

/* Add the sum of an array into an address */
void sum(double_32 *__restrict r, const double_32 *__restrict a) {
  for (unsigned i = 0; i < 4; ++i)
    *r += a[i];
}

/* The example from the youtube-video */
void video(double_32 *__restrict r, const double_32 *__restrict a,
         const double_32 *__restrict b, double f) {
  for (unsigned i = 0; i < 128; ++i)
    r[i] = a[i] * f + b[i];
}

/* Code to allocate an array of double_32 */
double_32 * my_alloc(size_t elements) {
  return (double_32 *) aligned_alloc(sizeof(double_32) * elements, 32);
}

/* prototype for asembler function */
void vec_mul(double_32 *__restrict r, const double_32 *__restrict a, const double_32 *__restrict b);

int main() {
  double_32 *a = (double_32 *) aligned_alloc(sizeof(double_32) * 4, 32);
  a[0] = 1; a[1] = 2; a[2] = 3; a[3] = 4;
  double_32 *b = (double_32 *) aligned_alloc(sizeof(double_32) * 4, 32);
  b[0] = 10; b[1] = 10; b[2] = 10; b[3] = 10;
  double_32 *r = (double_32 *) aligned_alloc(sizeof(double_32) * 4, 32);

  printf("a : %p\n", a);
  printf("b : %p\n", b);
  printf("r : %p\n", r);

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

  /* Call the sum function */
  sum(r, a);
  printf("%f\n", *r);

  return 0;
}
