#include<stdio.h>

typedef double double_32 __attribute__((aligned(32)));
double_32 * my_alloc(int elements);

int main() {
  double_32 *a = my_alloc(4);
  printf("%p\n", a);
  return 0;
}
