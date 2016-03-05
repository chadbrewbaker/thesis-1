.section .text
.globl my_alloc
.type my_alloc, @function
my_alloc:
push    %rbp
push    %rbx
mov     %edi, %esi
imul    $0x8, %esi
mov     $0x20, %esi
mov     $0x20, %edi
call    aligned_alloc
pop     %rbx
pop     %rbp
