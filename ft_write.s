section .text
    global  ft_write
    extern  __errno_location    ; errno의 주소를 얻는 함수

ft_write  :
    mov rax, 1                  ; syscall number: write
    syscall                     ; 시스템 콜 실행
    
    cmp rax, 0                  ; 반환값이 음수인지 확인
    jl error                    ; 음수면 에러 처리
    ret                         ; 성공이면 그대로 반환

error:
    neg rax                     ; 에러 코드를 양수로 변환
    mov rdi, rax                ; 에러 코드 임시 저장
    call __errno_location       ; errno 주소를 rax에 받음
    mov [rax], rdi              ; errno에 에러 코드 설정
    mov rax, -1                 ; -1 반환
    ret
