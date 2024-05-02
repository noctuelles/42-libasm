global ft_strlen 
ft_strlen:
    ;function prologue
    push rbp
    mov rbp, rsp
    push rdi
.loop:
    mov al, byte [rdi]
    cmp al, 0x0
    jz .ret
    add rdi, 0x1
    jmp .loop
.ret:
    mov rax, rdi
    pop rdi
    sub rax, rdi
    ; function epilogue
    mov rsp, rbp
    pop rbp
    ret
