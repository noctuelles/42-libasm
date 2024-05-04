section .text
    global ft_read
    extern __errno_location

; ft_read - read from a file descriptor
; ARGS: rdi - file descriptor, rsi - buffer, rdx - count
; MODIFIES: rax, rbx
; RETURNS: rax - number of bytes read, or -1 on error
ft_read:
    push rbp
    mov rbp, rsp
    mov rax, 0x00
    syscall
    cmp rax, 0x00
    jge .ret
    neg rax
    push rax
    call __errno_location
    pop r11
    mov [rax], r11b
    mov rax, -1
.ret:
    pop rbp
    ret 