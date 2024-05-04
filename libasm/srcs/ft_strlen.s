section .text
    global ft_strlen 

; ft_strlen - returns the length of a string
; rdi - pointer to the string
; MODIFIES: rax, rdi
; ARGS: rdi - pointer to the string
; RETURNS: rax - length of the string
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
