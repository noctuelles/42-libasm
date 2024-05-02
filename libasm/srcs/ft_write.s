section .text
    global ft_write
    extern __errno_location
ft_write:
    push rbp
    mov rbp, rsp
    mov rax, 0x01
    syscall
    cmp rax, 0x00
    jge .ret
    neg rax
    mov rbx, rax
    call __errno_location
    mov [rax], ebx
    mov rax, -1
.ret:
    pop rbp
    ret 