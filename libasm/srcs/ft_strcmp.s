
global ft_strcmp

ft_strcmp:
    push rbp
    mov rbp, rsp
.loop:
    mov cl, byte [rdi]
    mov ch, byte [rsi]
    cmp cl, 0x00
    jz .ret
    cmp cl, ch
    jne .ret
    inc rdi
    inc rsi
    jmp .loop
.ret:
    sub cl, ch
    movsx rax, cl
    pop rbp
    ret