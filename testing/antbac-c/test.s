# Notes:
# Use %r for pointers and long
# Use %e for integers
#
# Parameters
# ----------
# 1 : %edi
# 2 : %esi
# 3 : %edx
# 4 : %ecx
# 5 : %r8
# 6 : %r9
#
# %xmm0-7 (128 bit, lower half of ymmX)
# %ymm0-7 (256 bit)
#
# Return : %eax for an int or %rax for a long
#

.section .text
.globl vec_mul
.type vec_mul, @function
# Parameters:
# %rdi = pointer to r-array
# %rsi = pointer to a-array
# %rdx = pointer to b-array
vec_mul:
vmovapd (%rdx),%ymm0      # Copy b-array to ymm0
vmulpd (%rsi),%ymm0,%ymm0 # Multiply a-array into ymm0
vmovapd %ymm0,(%rdi)      # Move the multiplied array into the r-array (this causes an error)
vzeroupper                # Set the top 128 bits of all ymmX registers to 0, probably a convention
retq
