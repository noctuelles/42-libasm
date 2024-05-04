
global ft_strcmp

; ft_strcmp compares two strings and returns the difference between the first two different characters
; MODIFIES : rdi, rsi, rcx, rax
; ARGS : rdi - first string, rsi - second string
; RETURNS : rax - difference between the first two different characters
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
    movsx eax, cl
    pop rbp
    ret