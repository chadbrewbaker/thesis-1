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
.globl _asmMul
#.type asmMul, @function
# Parameters:
# %rdi = pointer to a-array
# %rsi = pointer to b-array
# %rdx = pointer to c-array
_asmMul:
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
vmovapd (%rsi,%r8,1),%ymm0                # Move the value of the b-array (offset by r8) to ymm0
vmovapd 0x200(%rsi,%r8,1),%ymm1           # Move the value of the b-array (offset by r8 + 512) to ymm1
vmovapd 0x400(%rsi,%r8,1),%ymm2           # Move the value of the b-array (offset by r8 + 1024) to ymm2
vmovapd 0x600(%rsi,%r8,1),%ymm3           # Move the value of the b-array (offset by r8 + 1536) to ymm3

vbroadcastsd (%rdi, %r10, 1), %ymm9       # Copy the element in the a-array (offset by r10) to each slot in ymm9
VFMADD231PD %ymm9, %ymm0, %ymm4           # Multiply ymm9 with ymm0 and add the results to ymm4
vbroadcastsd 0x8(%rdi, %r10, 1), %ymm9    # Copy the element in the a-array (offset by r10 + 8) to each slot in ymm9
VFMADD231PD %ymm9, %ymm1, %ymm4           # Multiply ymm9 with ymm1 and add the results to ymm4
vbroadcastsd 0x10(%rdi, %r10, 1), %ymm9   # Copy the element in the a-array (offset by r10 + 16) to each slot in ymm9
VFMADD231PD %ymm9, %ymm2, %ymm4           # Multiply ymm9 with ymm2 and add the results to ymm4
vbroadcastsd 0x18(%rdi, %r10, 1), %ymm9   # Copy the element in the a-array (offset by r10 + 24) to each slot in ymm9
VFMADD231PD %ymm9, %ymm3, %ymm4           # Multiply ymm9 with ymm3 and add the results to ymm4

vbroadcastsd 0x200(%rdi, %r10, 1), %ymm9  # Basically the same as the first "vbroadcastsd" block
VFMADD231PD %ymm9, %ymm0, %ymm5
vbroadcastsd 0x208(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm1, %ymm5
vbroadcastsd 0x210(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm2, %ymm5
vbroadcastsd 0x218(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm3, %ymm5

vbroadcastsd 0x400(%rdi, %r10, 1), %ymm9  # Basically the same as the first "vbroadcastsd" block
VFMADD231PD %ymm9, %ymm0, %ymm6
vbroadcastsd 0x408(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm1, %ymm6
vbroadcastsd 0x410(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm2, %ymm6
vbroadcastsd 0x418(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm3, %ymm6

vbroadcastsd 0x600(%rdi, %r10, 1), %ymm9  # Basically the same as the first "vbroadcastsd" block
VFMADD231PD %ymm9, %ymm0, %ymm7
vbroadcastsd 0x608(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm1, %ymm7
vbroadcastsd 0x610(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm2, %ymm7
vbroadcastsd 0x618(%rdi, %r10, 1), %ymm9
VFMADD231PD %ymm9, %ymm3, %ymm7

add $0x800,%r8                            # Add 2048 to r8
add $0x20,%rcx                            # Add 32 to rcx
cmp $0x200,%rcx                           # Compare rcx to 512
jne label3                                # Jump to label3 if rcx != 512

mov %rax, %r10                            # Copy the value of rax to r10
add %r9, %r10                             # Add the value in r9 to the value in r10

vmovapd %ymm4,(%rdx,%r10,1)               # Move the value in ymm4 to the c-array offset by r10
vmovapd %ymm5,0x200(%rdx,%r10,1)          # Move the value in ymm5 to the c-array offset by r10 + 512
vmovapd %ymm6,0x400(%rdx,%r10,1)          # Move the value in ymm6 to the c-array offset by r10 + 1024
vmovapd %ymm7,0x600(%rdx,%r10,1)          # Move the value in ymm7 to the c-array offset by r10 + 1536

add $0x20,%r9                             # Add 32 to the value in r9
cmp $0x200,%r9                            # Compare r9 to 512
jne label2                                # Jump to label2 if r9 != 512

add $0x800,%rax                           # Add 2048 to the value in rax
cmp $0x8000,%rax                          # Compare rax to 32768
jne label1                                # Jump to label2 if rax != 32768

vzeroupper                                # Set the top 128 bits of all ymmX registers to 0, probably a convention
retq
