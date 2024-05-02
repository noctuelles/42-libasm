section .text
    global ft_atoi_base
    global ft_check_base
    global ft_get_base_nbr

    extern ft_isspace

NUL equ 0x00
CHAR_PLUS equ 0x2B
CHAR_MINUS equ 0x2D

; take a string as an argument, and verify that this is a valid base.
; returns 0 if not.
; returns the base number if valid.
ft_check_base:
    push rbp
    mov rbp,rsp
    sub rsp, 0x10
    mov qword [rbp - 0x8], 0x00 ; i
.loop:
    mov rcx, [rbp - 0x8]
    mov al, byte [rdi + rcx]
    cmp al, NUL
    jz .ret_base_nbr

    ; is the actual character a +, -
    cmp al, CHAR_PLUS
    je .ret_zero
    cmp al, CHAR_MINUS
    je .ret_zero

    ; a whitespace ?
    push rax
    push rdi
    movzx edi, al
    call ft_isspace
    pop rdi
    cmp eax, 0x1
    pop rax
    je .ret_zero

    ; verify that it does not contains a duplicate character
.loop2:
    inc rcx
    mov ah, byte [rdi + rcx]
    cmp ah, NUL
    jz .ret_loop2
    cmp al, ah
    je .ret_zero
    jmp .loop2

.ret_loop2:
    inc qword [rbp - 0x8]
    jmp .loop

.ret_zero:
    mov rax, 0x00
    jmp .ret
.ret_base_nbr:
    mov rax, qword [rbp - 0x8]
.ret:
    add rsp, 0x10
    pop rbp
    ret

ft_get_base_nbr:
    push rbp
    mov rbp,rsp
    mov rcx, 0x00
    mov rax, -1
.loop:
    mov bl, byte [rdi + rcx]
    cmp bl, NUL
    jz .ret
    cmp bl, sil
    je .ret_base_nbr
    inc rcx
    jmp .loop
.ret_base_nbr:
    mov rax, rcx
.ret:
    pop rbp
    ret

ft_atoi_base:
    push rbp
    mov rbp,rsp
    pop rbp
    ret
