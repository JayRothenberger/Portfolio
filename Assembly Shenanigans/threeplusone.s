;Jay Rothenberger #steps to reach one with collatz
   
    section .text
 
threeplusone:
    cmp rdi, 1
    je one
    test di, 1
    je even
odd:
    lea rdi, [2*rdi + rdi + 1]
    call threeplusone
    add rax, 1
    ret
even:
    shr rdi, 1
    call threeplusone
    add rax, 1
    ret
one:
    xor rax, rax
    ret
