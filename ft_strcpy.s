section .text
    global  ft_strcpy

ft_strcpy:
    mov rax, rdi
    test rsi, rsi
    je done

loop:

copy_byte:
    mov cl, byte [rsi]
    mov byte [rdi], cl

check_null:
    cmp cl, 0
    je done
    inc rdi
    inc rsi
    jmp loop

done:
    ret