global ft_strcpy
ft_strcpy:
    ;function prologue
    push rbp
    mov rbp, rsp
    push rdi
.loop:
    mov al, byte [rsi]
    cmp al, 0
    jz .ret
    mov byte [rdi], al
    add rdi, 0x1
    add rsi, 0x1
    jmp .loop
.ret:
    mov byte [rdi], 0x0
    pop rdi
    ;function epilogue
    mov rax, rdi
    mov rsp, rbp
    pop rbp
    ret