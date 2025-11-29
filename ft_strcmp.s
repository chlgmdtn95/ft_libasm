section .text
    global  ft_strcmp

ft_strcmp  :

loop    :
    movzx rax, byte [rdi]
    movzx rcx, byte [rsi]
    
    cmp rax, rcx
    jne done
    
    test rax, rax
    je done
    
    inc rdi
    inc rsi
    jmp loop

done    :
    sub rax, rcx
    ret