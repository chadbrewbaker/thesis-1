.section .text
.globl my_alloc
.type my_alloc, @function
my_alloc:
movslq  %edi, %rsi
mov    $0x20, %edi
shl    $0x3,  %rsi
call   aligned_alloc
ret
