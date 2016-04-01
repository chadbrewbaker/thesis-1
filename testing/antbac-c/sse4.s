.section .text
.globl transpose_2_2_double
.type transpose_2_2_double, @function
.globl matrix_mul_2_2_double
.type matrix_mul_2_2_double, @function
.globl transpose_4_4_float
.type transpose_4_4_float, @function
.globl matrix_mul_4_4_float
.type matrix_mul_4_4_float, @function

transpose_2_2_double:
movapd 0x00(%rdi), %xmm0
movapd 0x00(%rdi), %xmm1
movapd 0x10(%rdi), %xmm2
unpcklpd %xmm2, %xmm0
unpckhpd %xmm2, %xmm1
movapd %xmm0, 0x00(%rdi)
movapd %xmm1, 0x10(%rdi)
ret

matrix_mul_2_2_double:
# Store the b-matrix in xmm registers 4-7
movapd 0x00(%rsi), %xmm2
movapd 0x10(%rsi), %xmm3

# Calculate row 1
movapd 0x00(%rdi), %xmm0
movapd 0x00(%rdi), %xmm1
dppd $0xF1, %xmm2, %xmm0
dppd $0xF1, %xmm3, %xmm1
movsd %xmm0, 0x0(%rdx)
movsd %xmm1, 0x8(%rdx)

# Calculate row 2
movapd 0x10(%rdi), %xmm0
movapd 0x10(%rdi), %xmm1
dppd $0xF1, %xmm2, %xmm0
dppd $0xF1, %xmm3, %xmm1
movsd %xmm0, 0x10(%rdx)
movsd %xmm1, 0x18(%rdx)
ret

transpose_4_4_float:
movaps 0x00(%rdi), %xmm0 # xmm0 := I0
movaps 0x00(%rdi), %xmm2 # xmm2 := I0
movaps 0x20(%rdi), %xmm1 # xmm1 := I2
movaps 0x20(%rdi), %xmm3 # xmm3 := I2
movaps 0x10(%rdi), %xmm4 # xmm4 := I1
movaps 0x30(%rdi), %xmm5 # xmm5 := I3
punpckldq %xmm4, %xmm0 # xmm0 := T0 = punpckldq(I1, I0)
punpckldq %xmm5, %xmm1 # xmm1 := T1 = punpckldq(I3, I2)
punpckhdq %xmm4, %xmm2 # xmm2 := T2 = punpckhdq(I1, I0)
punpckhdq %xmm5, %xmm3 # xmm3 := T3 = punpckhdq(I3, I2)
movaps %xmm1, %xmm4 # Backup T1 to xmm4
movaps %xmm0, %xmm1 # Copy T0 to xmm1
movaps %xmm3, %xmm5 # Backup T3 to xmm5
movaps %xmm2, %xmm3 # Copy T2 to xmm3
punpcklqdq %xmm4, %xmm0 # xmm0 := O0 = punpcklqdq(T1, T0)
punpckhqdq %xmm4, %xmm1 # xmm1 := O1 = punpckhdq(T1, T0)
punpcklqdq %xmm5, %xmm2 # xmm2 := O2 = punpcklqdq(T3, T2)
punpckhqdq %xmm5, %xmm3 # xmm3 := O3 = punpckhdq(T3, T2)
movaps %xmm0, 0x00(%rdi)
movaps %xmm1, 0x10(%rdi)
movaps %xmm2, 0x20(%rdi)
movaps %xmm3, 0x30(%rdi)
ret

matrix_mul_4_4_float:
# Store the b-matrix in xmm registers 4-7
movaps 0x00(%rsi), %xmm4
movaps 0x10(%rsi), %xmm5
movaps 0x20(%rsi), %xmm6
movaps 0x30(%rsi), %xmm7

# Calculate row 1
movaps (%rdi), %xmm0
movaps (%rdi), %xmm1
movaps (%rdi), %xmm2
movaps (%rdi), %xmm3
dpps $0xF1, %xmm4, %xmm0
dpps $0xF1, %xmm5, %xmm1
dpps $0xF1, %xmm6, %xmm2
dpps $0xF1, %xmm7, %xmm3
movss %xmm0, 0x0(%rdx)
movss %xmm1, 0x4(%rdx)
movss %xmm2, 0x8(%rdx)
movss %xmm3, 0xC(%rdx)

# Calculate row 2
movaps 0x10(%rdi), %xmm0
movaps 0x10(%rdi), %xmm1
movaps 0x10(%rdi), %xmm2
movaps 0x10(%rdi), %xmm3
dpps $0xF1, %xmm4, %xmm0
dpps $0xF1, %xmm5, %xmm1
dpps $0xF1, %xmm6, %xmm2
dpps $0xF1, %xmm7, %xmm3
movss %xmm0, 0x10(%rdx)
movss %xmm1, 0x14(%rdx)
movss %xmm2, 0x18(%rdx)
movss %xmm3, 0x1C(%rdx)

# Calculate row 3
movaps 0x20(%rdi), %xmm0
movaps 0x20(%rdi), %xmm1
movaps 0x20(%rdi), %xmm2
movaps 0x20(%rdi), %xmm3
dpps $0xF1, %xmm4, %xmm0
dpps $0xF1, %xmm5, %xmm1
dpps $0xF1, %xmm6, %xmm2
dpps $0xF1, %xmm7, %xmm3
movss %xmm0, 0x20(%rdx)
movss %xmm1, 0x24(%rdx)
movss %xmm2, 0x28(%rdx)
movss %xmm3, 0x2C(%rdx)

# Calculate row 4
movaps 0x30(%rdi), %xmm0
movaps 0x30(%rdi), %xmm1
movaps 0x30(%rdi), %xmm2
movaps 0x30(%rdi), %xmm3
dpps $0xF1, %xmm4, %xmm0
dpps $0xF1, %xmm5, %xmm1
dpps $0xF1, %xmm6, %xmm2
dpps $0xF1, %xmm7, %xmm3
movss %xmm0, 0x30(%rdx)
movss %xmm1, 0x34(%rdx)
movss %xmm2, 0x38(%rdx)
movss %xmm3, 0x3C(%rdx)
ret
