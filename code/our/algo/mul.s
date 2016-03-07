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
.globl asmMul
.type asmMul, @function
# Parameters:
# %rdi = pointer to a-array
# %rsi = pointer to b-array
# %rdx = pointer to c-array
asmMul:
xor %rax,%rax
xor %r10,%r10
label1:
xor %r9,%r9
label2:
vzeroall
xor %rcx,%rcx
mov %r9,%r8
label3:
mov %rcx, %r10
add %rax, %r10
/*mov 0x40,%r8*/
/*imul %rcx,%r8*/
vmovapd (%rsi,%r8,1),%ymm0
vmovapd 0x200(%rsi,%r8,1),%ymm1
vmovapd 0x400(%rsi,%r8,1),%ymm2
vmovapd 0x600(%rsi,%r8,1),%ymm3

vbroadcastsd (%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm0, %ymm4

vbroadcastsd 0x8(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm1, %ymm4

vbroadcastsd 0x10(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm2, %ymm4

vbroadcastsd 0x18(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm3, %ymm4

vbroadcastsd 0x200(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm0, %ymm5

vbroadcastsd 0x208(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm1, %ymm5

vbroadcastsd 0x210(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm2, %ymm5

vbroadcastsd 0x218(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm3, %ymm5

vbroadcastsd 0x400(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm0, %ymm6

vbroadcastsd 0x408(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm1, %ymm6

vbroadcastsd 0x410(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm2, %ymm6

vbroadcastsd 0x418(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm3, %ymm6

vbroadcastsd 0x600(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm0, %ymm7

vbroadcastsd 0x608(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm1, %ymm7

vbroadcastsd 0x610(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm2, %ymm7

vbroadcastsd 0x618(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm3, %ymm7

add $0x800,%r8
add $0x20,%rcx
cmp $0x200,%rcx
jne label3

mov %rax, %r10
add %r9, %r10

vmovapd %ymm4,(%rdx,%r10,1)
vmovapd %ymm5,0x200(%rdx,%r10,1)
vmovapd %ymm6,0x400(%rdx,%r10,1)
vmovapd %ymm7,0x600(%rdx,%r10,1)

add $0x20,%r9
cmp $0x200,%r9
jne label2

add $0x800,%rax
cmp $0x8000,%rax
jne label1

vzeroupper                # Set the top 128 bits of all ymmX registers to 0, probably a convention
retq
