state0 = 1
state1 = 2
mask64 = 0xFFFFFFFFFFFFFFFF


def xorshift128plus():
    global state0, state1
    s1 = state0
    s0 = state1
    state0 = s0
    s1 ^= (s1 << 23) & mask64
    s1 ^= (s1 >> 17) & mask64
    s1 ^= s0
    s1 ^= (s0 >> 26) & mask64
    state1 = s1
    return (state0 + state1) & mask64

for i in range(20):
    xorshift128plus()
