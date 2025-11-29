section .text
    global  ft_strlen

ft_strlen  :
    ; Input: rdi - pointer to null-terminated string
    ; Output: rax - length of the string

    mov     rax, 0          ; Initialize length counter to 0

loop :
    cmp byte [rdi + rax], 0
    je done
    inc rax
    jmp loop

done :
    ret
