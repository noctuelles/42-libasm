global ft_strlen 
ft_strlen:
    ; function prologue
    push rbp
    mov rbp, rsp
    sub rsp, 8
    mov qword [rbp - 8], 0x0
.loop:
    mov rax, rdi
    add rax, qword [rbp - 8]
    mov al, byte [rax]
    cmp al, 0
    jz .ret
    add qword [rbp - 8], 0x1
    jmp .loop
.ret:
    ; function epilogue
    mov rax, qword [rbp - 8]
    mov rsp, rbp
    pop rbp
    ret

