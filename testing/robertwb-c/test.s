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
.globl transpose
.type transpose, @function
# Parameters:
# %rdi = pointer to r-array
# %rsi = pointer to a-array
transpose:
xor %rcx,%rcx
vmovapd %rcx(%rsi),%ymm0      # Copy b-array to ymm0
vmovapd 0x20(%rsi),%ymm1
vmovapd 0x40(%rsi),%ymm2
vmovapd 0x60(%rsi),%ymm3
vmovapd %ymm0,(%rdi)      # Move the multiplied array into the r-array
vmovapd %ymm1,0x20(%rdi)
vmovapd %ymm2,0x40(%rdi)
vmovapd %ymm3,0x60(%rdi)
vzeroupper                # Set the top 128 bits of all ymmX registers to 0, probably a convention
retq
