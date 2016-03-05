# Notes:
# Use %r for pointers and long
# Use %e for integers
#
# Registers RBP, RBX, and R12 through R15 belong to the calling function
# The called function is required to preserve their values
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

# callq 8c <main+0x18> (8c = <label + constant> = return address)
# R_X86_64_PC32 fn-0x4 (this is a function call to "fn" and will return to '8c' as stated in the previous line)

# push %r14
# pop %r14
