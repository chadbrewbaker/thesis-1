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
.globl m4mul
.type m4mul, @function
# Parameters:
# %rdi = pointer to a-array
# %rsi = pointer to b-array
# %rdx = pointer to b-array
m4mul:
xor %rcx,%rcx

vmovapd (%rdi),%ymm0
vmovapd 0x20(%rdi),%ymm1
vmovapd 0x40(%rdi),%ymm2
vmovapd 0x60(%rdi),%ymm3

vmovupd (%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
vmulpd %ymm9, %ymm0, %ymm4

vmovupd 0x8(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm1, %ymm4

vmovupd 0x10(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm2, %ymm4

vmovupd 0x18(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm3, %ymm4

vmovupd 0x20(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
vmulpd %ymm9, %ymm0, %ymm5

vmovupd 0x28(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm1, %ymm5

vmovupd 0x30(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm2, %ymm5

vmovupd 0x38(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm3, %ymm5

vmovupd 0x40(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
vmulpd %ymm9, %ymm0, %ymm6

vmovupd 0x48(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm1, %ymm6

vmovupd 0x50(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm2, %ymm6

vmovupd 0x58(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm3, %ymm6

vmovupd 0x60(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
vmulpd %ymm9, %ymm0, %ymm7

vmovupd 0x68(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm1, %ymm7

vmovupd 0x70(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm2, %ymm7

vmovupd 0x78(%rsi),%ymm8
vbroadcastsd %xmm8, %ymm9
VFMADD231PD %ymm9, %ymm3, %ymm7

vmovapd %ymm4,(%rdx)
vmovapd %ymm5,0x20(%rdx)
vmovapd %ymm6,0x40(%rdx)
vmovapd %ymm7,0x60(%rdx)
vzeroupper                # Set the top 128 bits of all ymmX registers to 0, probably a convention
retq
