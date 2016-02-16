#include <stdio.h>
#include "myRandom.h"

int main(int argc, char const *argv[]) {

  // seed128plus(0x7468697369737365, 0x6372657473656564); //thisisse cretseed
  // uint64_t y = xorshift128plus();
  uint64_t sum = 0;
  for (size_t i = 0; i < 300000000; i++) {
    sum += xorshift128plus();
  }
  // printf("%lu\n", y);
  printf("%lu\n", sum);
  return 0;
}
