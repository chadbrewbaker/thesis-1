#include "header.h"

typedef double double_32 __attribute__((aligned(32)));

/* Code to allocate an array of double_32 */
double_32 * my_alloc_d(size_t elements) {
  return (double_32 *) aligned_alloc(32, sizeof(double_32) * elements);
}

/* Code to allocate an array of float_32 */
float_32 * my_alloc_f(size_t elements) {
  return (float_32 *) aligned_alloc(32, sizeof(float_32) * elements);
}

double_32 sum(const double_32 *__restrict a, const double_32 *__restrict b) {
  return a[0] + a[1] + b[0] + b[1];
}

double_32 naive(const double_32 *__restrict a, const double_32 *__restrict b) {
  return a[0] + a[1] + b[0] + b[1];
}

void print_d(const double_32 *__restrict a) {
  for(size_t y = 0; y < 2; y++){
    for(size_t x = 0; x < 2; x++){
      printf("%f\t", a[x+2*y]);
    }
    printf("\n");
  }
  printf("\n");
}

void print_f(const float_32 *__restrict a) {
  for(size_t y = 0; y < 4; y++){
    for(size_t x = 0; x < 4; x++){
      printf("%f\t", a[x+4*y]);
    }
    printf("\n");
  }
  printf("\n");
}

void assign_f(float_32 *__restrict a) {
  for(size_t y = 0; y < 4; y++){
    for(size_t x = 0; x < 4; x++){
      a[x+4*y] = x+10*y;
    }
  }
}

void assign_d(double_32 *__restrict a) {
  for(size_t y = 0; y < 2; y++){
    for(size_t x = 0; x < 2; x++){
      a[x+2*y] = x+10*y;
    }
  }
}

void run_f(float_32 *__restrict a) {
  printf("Float 4x4:\n----------\n");
  print_f(a);
  transpose_4_4_float(a);
  print_f(a);
  printf("\n\n");
}

void run_d(double_32 *__restrict a) {
  printf("Double 2x2:\n-----------\n");
  print_d(a);
  transpose_2_2_double(a);
  print_d(a);
  printf("\n\n");
}

int main(int argc, char const *argv[]) {
  float_32 *matr_f = my_alloc_f(4*4);
  assign_f(matr_f);
  run_f(matr_f);

  double_32 *matr_d = my_alloc_d(2*2);
  assign_d(matr_d);
  run_d(matr_d);

  return 0;
}
/*
unpckhpd %xmm1, %xmm0 :

INTERLEAVE_HIGH_QWORDS(src1[127:0], src2[127:0]){
 dst[63:0] := src1[127:64]
 dst[127:64] := src2[127:64]
 RETURN dst[127:0]
}

In:             Out:
xmm0 = 1, 2     2, 17
xmm1 = 11, 17
*/

/*
unpcklpd %xmm1, %xmm0 :

INTERLEAVE_LOW_QWORDS(src1[127:0], src2[127:0]){
 dst[63:0] := src1[63:0]
 dst[127:64] := src2[63:0]
 RETURN dst[127:0]
}

In:             Out:
xmm0 = 1, 2     1, 11
xmm1 = 11, 17
*/

/*
shufpd imm8, %xmm1, %xmm0 :

Shuffle_double_precision(imm8, src1[127:0], src2[127:0]){
  if imm8[0] = 0 then dst[63:0] := a[63:0]
  else dst[63:0] := a[127:64]
  if imm8[1] = 0 then dst[127:64] := b[63:0]
  else dst[127:64] := b[127:64]
  RETURN dst[127:0]
}

In:             Out:
imm8 = 0b10     1, 17
xmm0 = 1, 2
xmm1 = 11, 17
*/
