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

.text
.globl _asmMulF64
#.type asmMulF64, @function
# Parameters:
# %rdi = pointer to a-array
# %rsi = pointer to b-array
# %rdx = pointer to c-array
_asmMulF64:
xor %rax,%rax                             # Set rax to 0
xor %r10,%r10                             # Set register r10 to 0

label1:
xor %r9,%r9                               # Set register r9 to 0

label2:
vzeroall                                  # Set all ymm registers to 0
xor %rcx,%rcx                             # Set rcx to 0
mov %r9,%r8                               # Copy the value of r9 to r8 (horizontal offset)

label3:
mov %rcx, %r10                            # Copy the value of rcx to r10
add %rax, %r10                            # Add the value of rax to r10
/*mov 0x40,%r8*/
/*imul %rcx,%r8*/
vmovaps (%rsi,%r8,1),%ymm0
vmovaps 0x100(%rsi,%r8,1),%ymm1
vmovaps 0x200(%rsi,%r8,1),%ymm2
vmovaps 0x300(%rsi,%r8,1),%ymm3

vbroadcastss (%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm4
vbroadcastss 0x4(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm4
vbroadcastss 0x8(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm4
vbroadcastss 0xC(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm4

vbroadcastss 0x100(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm5
vbroadcastss 0x104(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm5
vbroadcastss 0x108(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm5
vbroadcastss 0x10C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm5

vbroadcastss 0x200(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm6
vbroadcastss 0x204(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm6
vbroadcastss 0x208(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm6
vbroadcastss 0x20C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm6

vbroadcastss 0x300(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm7
vbroadcastss 0x304(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm7
vbroadcastss 0x308(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm7
vbroadcastss 0x30C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm7



vbroadcastss 0x400(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm10
vbroadcastss 0x404(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm10
vbroadcastss 0x408(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm10
vbroadcastss 0x40C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm10

vbroadcastss 0x500(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm11
vbroadcastss 0x504(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm11
vbroadcastss 0x508(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm11
vbroadcastss 0x50C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm11

vbroadcastss 0x600(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm12
vbroadcastss 0x604(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm12
vbroadcastss 0x608(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm12
vbroadcastss 0x60C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm12

vbroadcastss 0x700(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm13
vbroadcastss 0x704(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm13
vbroadcastss 0x708(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm13
vbroadcastss 0x70C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm13


vmovaps 0x400(%rsi,%r8,1),%ymm0
vmovaps 0x500(%rsi,%r8,1),%ymm1
vmovaps 0x600(%rsi,%r8,1),%ymm2
vmovaps 0x700(%rsi,%r8,1),%ymm3




vbroadcastss 0x10(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm4
vbroadcastss 0x14(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm4
vbroadcastss 0x18(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm4
vbroadcastss 0x1C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm4

vbroadcastss 0x110(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm5
vbroadcastss 0x114(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm5
vbroadcastss 0x118(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm5
vbroadcastss 0x11C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm5

vbroadcastss 0x210(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm6
vbroadcastss 0x214(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm6
vbroadcastss 0x218(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm6
vbroadcastss 0x21C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm6

vbroadcastss 0x310(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm7
vbroadcastss 0x314(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm7
vbroadcastss 0x318(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm7
vbroadcastss 0x31C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm7


vbroadcastss 0x410(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm10
vbroadcastss 0x414(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm10
vbroadcastss 0x418(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm10
vbroadcastss 0x41C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm10

vbroadcastss 0x510(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm11
vbroadcastss 0x514(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm11
vbroadcastss 0x518(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm11
vbroadcastss 0x51C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm11

vbroadcastss 0x610(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm12
vbroadcastss 0x614(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm12
vbroadcastss 0x618(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm12
vbroadcastss 0x61C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm12

vbroadcastss 0x710(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm13
vbroadcastss 0x714(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm13
vbroadcastss 0x718(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm13
vbroadcastss 0x71C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm13



add $0x800,%r8
add $0x20,%rcx
cmp $0x100,%rcx
jne label3

mov %rax, %r10
add %r9, %r10

vmovaps %ymm4,(%rdx,%r10,1)
vmovaps %ymm5,0x100(%rdx,%r10,1)
vmovaps %ymm6,0x200(%rdx,%r10,1)
vmovaps %ymm7,0x300(%rdx,%r10,1)

vmovaps %ymm10,0x400(%rdx,%r10,1)
vmovaps %ymm11,0x500(%rdx,%r10,1)
vmovaps %ymm12,0x600(%rdx,%r10,1)
vmovaps %ymm13,0x700(%rdx,%r10,1)

add $0x20,%r9
cmp $0x100,%r9
jne label2

add $0x800,%rax                           # Add 2048 to the value in rax
cmp $0x4000,%rax                          # Compare rax to 32768
jne label1                                # Jump to label2 if rax != 32768

vzeroupper                                # Set the top 128 bits of all ymmX registers to 0, probably a convention
retq
