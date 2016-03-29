.section .text
.globl transpose_2_2_double
.type transpose_2_2_double, @function
.globl transpose_4_4_float
.type transpose_4_4_float, @function

transpose_2_2_double:
movapd 0x00(%rdi), %xmm0
movapd 0x00(%rdi), %xmm1
movapd 0x10(%rdi), %xmm2
unpcklpd %xmm2, %xmm0
unpckhpd %xmm2, %xmm1
movapd %xmm0, 0x00(%rdi)
movapd %xmm1, 0x10(%rdi)
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
