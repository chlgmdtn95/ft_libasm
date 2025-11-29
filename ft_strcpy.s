section .text
    global  ft_strcpy

ft_strcpy   :
    mov rax, rdi
    test rsi, rsi
    je done

loop:
    mov al, byte [rsi]
    mov byte [rdi], al
    cmp al, 0
    je done
    inc rdi
    inc rsi
    jmp loop

done :
    ret