section .text
    global ft_strdup
    extern malloc
    extern ft_strcpy
    extern ft_strlen

ft_strdup:
    push rdi

get_length:
    call ft_strlen
    inc rax                     
    
str_malloc:
    mov rdi, rax
    call malloc wrt ..plt
    test rax, rax
    je error                    
    
str_copy:
    mov rdi, rax
    pop rsi
    call ft_strcpy
    ret

error:
    pop rdi
    xor rax, rax
    ret
