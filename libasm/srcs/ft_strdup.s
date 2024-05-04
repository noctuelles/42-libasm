section .text
    global ft_strdup

    extern ft_strlen
    extern ft_strcpy
    extern malloc

; ft_strdup: duplicate a string
; ARGS: rsi = string to duplicate
; MODIFIES: rdi
; RETURN: rax = duplicated string
ft_strdup:
    push rbp
    mov rbp, rsp
    call ft_strlen
    inc rax ; add 1 for null terminator
    push rdi
    mov rdi, rax
    call malloc
    pop rdi
    cmp rax, 0x00
    jz .ret
    mov rsi, rdi
    mov rdi, rax
    call ft_strcpy
.ret:
    pop rbp
    ret