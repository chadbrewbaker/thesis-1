#include "myRandom.h"
static uint64_t state0 = 1;
static uint64_t state1 = 2;
uint64_t xorshift128plus() {
  uint64_t s1 = state0;
  uint64_t s0 = state1;
  state0 = s0;
  s1 ^= s1 << 23;
  s1 ^= s1 >> 17;
  s1 ^= s0;
  s1 ^= s0 >> 26;
  state1 = s1;
  return state0 + state1;
}

void seed128plus(uint64_t a, uint64_t b) {
  state0 = a;
  state1 = b;
}
