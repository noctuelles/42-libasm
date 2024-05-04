section .text
    global ft_write
    extern __errno_location
; ft_write : imitation of write function
; ARGS: rdi - file descriptor, rsi - buffer, rdx - count
; MODIFIES: rax, r11
; RETURNS: rax = -1 on error, rax = count of written bytes on success. Set errno on error.
ft_write:
    push rbp
    mov rbp, rsp
    mov rax, 0x01 ; sys_write
    syscall
    cmp rax, 0x00
    jge .ret
    neg rax
    push rax
    call __errno_location
    pop r11
    mov [rax], r11d
    mov rax, -1
.ret:
    pop rbp
    ret 