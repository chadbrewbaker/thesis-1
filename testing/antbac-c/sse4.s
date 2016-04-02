.section .text
.globl matrix_mul_2_2_double
.type matrix_mul_2_2_double, @function
.globl matrix_mul_4_4_float
.type matrix_mul_4_4_float, @function

matrix_mul_2_2_double:
# Store the b-matrix in xmm0 and xmm1
movapd 0x00(%rsi), %xmm0
movapd 0x10(%rsi), %xmm1

# Broadcast row 1 of the A-matrix to xmm2 and xmm3
movsd 0x0(%rdi), %xmm2
shufpd $0x0, %xmm2, %xmm2
movsd 0x8(%rdi), %xmm3
shufpd $0x0, %xmm3, %xmm3

# Multiplications
mulpd %xmm0, %xmm2
mulpd %xmm1, %xmm3

# Additions
addpd %xmm2, %xmm3

# Store the result in row 1 of the R-matrix
movapd %xmm3, (%rdx)

# Broadcast row 2 of the A-matrix to xmm2 and xmm3
movsd 0x10(%rdi), %xmm2
shufpd $0x0, %xmm2, %xmm2
movsd 0x18(%rdi), %xmm3
shufpd $0x0, %xmm3, %xmm3

# Multiplications
mulpd %xmm0, %xmm2
mulpd %xmm1, %xmm3

# Additions
addpd %xmm2, %xmm3

# Store the result in row 2 of the R-matrix
movapd %xmm3, 0x10(%rdx)
ret

matrix_mul_4_4_float:
# Load B-matrix into xmm0-xmm3
movaps 0x00(%rsi), %xmm0
movaps 0x10(%rsi), %xmm1
movaps 0x20(%rsi), %xmm2
movaps 0x30(%rsi), %xmm3

# Broadcast row 1 of the A-matrix to xmm4-xmm7
movss 0x0(%rdi), %xmm4
shufps $0x0, %xmm4, %xmm4
movss 0x4(%rdi), %xmm5
shufps $0x0, %xmm5, %xmm5
movss 0x8(%rdi), %xmm6
shufps $0x0, %xmm6, %xmm6
movss 0xC(%rdi), %xmm7
shufps $0x0, %xmm7, %xmm7

# Multiplications
mulps %xmm0, %xmm4
mulps %xmm1, %xmm5
mulps %xmm2, %xmm6
mulps %xmm3, %xmm7

# Additions
addps %xmm4, %xmm5
addps %xmm6, %xmm7
addps %xmm5, %xmm7

# Store the result in row 1 of the R-matrix
movaps %xmm7, (%rdx)

# Broadcast row 2 of the A-matrix to xmm4-xmm7
movss 0x10(%rdi), %xmm4
shufps $0x0, %xmm4, %xmm4
movss 0x14(%rdi), %xmm5
shufps $0x0, %xmm5, %xmm5
movss 0x18(%rdi), %xmm6
shufps $0x0, %xmm6, %xmm6
movss 0x1C(%rdi), %xmm7
shufps $0x0, %xmm7, %xmm7

# Multiplications
mulps %xmm0, %xmm4
mulps %xmm1, %xmm5
mulps %xmm2, %xmm6
mulps %xmm3, %xmm7

# Additions
addps %xmm4, %xmm5
addps %xmm6, %xmm7
addps %xmm5, %xmm7

# Store the result in row 2 of the R-matrix
movaps %xmm7, 0x10(%rdx)

# Broadcast row 3 of the A-matrix to xmm4-xmm7
movss 0x20(%rdi), %xmm4
shufps $0x0, %xmm4, %xmm4
movss 0x24(%rdi), %xmm5
shufps $0x0, %xmm5, %xmm5
movss 0x28(%rdi), %xmm6
shufps $0x0, %xmm6, %xmm6
movss 0x2C(%rdi), %xmm7
shufps $0x0, %xmm7, %xmm7

# Multiplications
mulps %xmm0, %xmm4
mulps %xmm1, %xmm5
mulps %xmm2, %xmm6
mulps %xmm3, %xmm7

# Additions
addps %xmm4, %xmm5
addps %xmm6, %xmm7
addps %xmm5, %xmm7

# Store the result in row 3 of the R-matrix
movaps %xmm7, 0x20(%rdx)

# Broadcast row 4 of the A-matrix to xmm4-xmm7
movss 0x30(%rdi), %xmm4
shufps $0x0, %xmm4, %xmm4
movss 0x34(%rdi), %xmm5
shufps $0x0, %xmm5, %xmm5
movss 0x38(%rdi), %xmm6
shufps $0x0, %xmm6, %xmm6
movss 0x3C(%rdi), %xmm7
shufps $0x0, %xmm7, %xmm7

# Multiplications
mulps %xmm0, %xmm4
mulps %xmm1, %xmm5
mulps %xmm2, %xmm6
mulps %xmm3, %xmm7

# Additions
addps %xmm4, %xmm5
addps %xmm6, %xmm7
addps %xmm5, %xmm7

# Store the result in row 4 of the R-matrix
movaps %xmm7, 0x30(%rdx)
ret
