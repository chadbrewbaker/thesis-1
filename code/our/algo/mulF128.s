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
.globl _asmMulF128
#.type asmMulF128, @function
# Parameters:
# %rdi = pointer to a-array
# %rsi = pointer to b-array
# %rdx = pointer to c-array
_asmMulF128:
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
vmovaps 0x200(%rsi,%r8,1),%ymm1
vmovaps 0x400(%rsi,%r8,1),%ymm2
vmovaps 0x600(%rsi,%r8,1),%ymm3

vbroadcastss (%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm4
vbroadcastss 0x4(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm4
vbroadcastss 0x8(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm4
vbroadcastss 0xC(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm4

vbroadcastss 0x200(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm5
vbroadcastss 0x204(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm5
vbroadcastss 0x208(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm5
vbroadcastss 0x20C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm5

vbroadcastss 0x400(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm6
vbroadcastss 0x404(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm6
vbroadcastss 0x408(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm6
vbroadcastss 0x40C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm6

vbroadcastss 0x600(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm7
vbroadcastss 0x604(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm7
vbroadcastss 0x608(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm7
vbroadcastss 0x60C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm7



vbroadcastss 0x800(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm10
vbroadcastss 0x804(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm10
vbroadcastss 0x808(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm10
vbroadcastss 0x80C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm10

vbroadcastss 0xA00(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm11
vbroadcastss 0xA04(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm11
vbroadcastss 0xA08(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm11
vbroadcastss 0xA0C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm11

vbroadcastss 0xC00(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm12
vbroadcastss 0xC04(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm12
vbroadcastss 0xC08(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm12
vbroadcastss 0xC0C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm12

vbroadcastss 0xE00(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm13
vbroadcastss 0xE04(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm13
vbroadcastss 0xE08(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm13
vbroadcastss 0xE0C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm13


vmovaps 0x800(%rsi,%r8,1),%ymm0
vmovaps 0xA00(%rsi,%r8,1),%ymm1
vmovaps 0xC00(%rsi,%r8,1),%ymm2
vmovaps 0xE00(%rsi,%r8,1),%ymm3




vbroadcastss 0x10(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm4
vbroadcastss 0x14(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm4
vbroadcastss 0x18(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm4
vbroadcastss 0x1C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm4

vbroadcastss 0x210(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm5
vbroadcastss 0x214(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm5
vbroadcastss 0x218(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm5
vbroadcastss 0x21C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm5

vbroadcastss 0x410(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm6
vbroadcastss 0x414(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm6
vbroadcastss 0x418(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm6
vbroadcastss 0x41C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm6

vbroadcastss 0x610(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm7
vbroadcastss 0x614(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm7
vbroadcastss 0x618(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm7
vbroadcastss 0x61C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm7


vbroadcastss 0x810(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm10
vbroadcastss 0x814(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm10
vbroadcastss 0x818(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm10
vbroadcastss 0x81C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm10

vbroadcastss 0xA10(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm11
vbroadcastss 0xA14(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm11
vbroadcastss 0xA18(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm11
vbroadcastss 0xA1C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm11

vbroadcastss 0xC10(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm12
vbroadcastss 0xC14(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm12
vbroadcastss 0xC18(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm12
vbroadcastss 0xC1C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm12

vbroadcastss 0xE10(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm0, %ymm13
vbroadcastss 0xE14(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm1, %ymm13
vbroadcastss 0xE18(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm2, %ymm13
vbroadcastss 0xE1C(%rdi, %r10, 1), %ymm9
vfmadd231ps %ymm9, %ymm3, %ymm13



add $0x1000,%r8
add $0x20,%rcx
cmp $0x200,%rcx
jne label3

mov %rax, %r10
add %r9, %r10

vmovaps %ymm4,(%rdx,%r10,1)
vmovaps %ymm5,0x200(%rdx,%r10,1)
vmovaps %ymm6,0x400(%rdx,%r10,1)
vmovaps %ymm7,0x600(%rdx,%r10,1)

vmovaps %ymm10,0x800(%rdx,%r10,1)
vmovaps %ymm11,0xA00(%rdx,%r10,1)
vmovaps %ymm12,0xC00(%rdx,%r10,1)
vmovaps %ymm13,0xE00(%rdx,%r10,1)

add $0x20,%r9
cmp $0x200,%r9
jne label2

add $0x1000,%rax                           # Add 2048 to the value in rax
cmp $0x10000,%rax                          # Compare rax to 32768
jne label1                                # Jump to label2 if rax != 32768

vzeroupper                                # Set the top 128 bits of all ymmX registers to 0, probably a convention
retq
