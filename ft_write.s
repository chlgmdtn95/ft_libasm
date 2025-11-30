section .text
    global  ft_write
    extern  __errno_location    ; errno의 주소를 얻는 함수

ft_write  :
    mov rax, 1
    syscall

check_error:    
    cmp rax, 0
    jl error
    ret

error:
    neg rax                     ; 에러 코드를 양수로 변환
    mov rdi, rax                ; 에러 코드 임시 저장
    call __errno_location wrt ..plt  ; errno 주소를 rax에 받음
    mov [rax], rdi              ; errno에 에러 코드 설정
    mov rax, -1                 ; -1 반환
    ret