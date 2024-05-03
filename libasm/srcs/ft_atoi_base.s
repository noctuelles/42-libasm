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

    mov r8, 0x00  ; base_nbr
    mov r9, 0x01  ; sign
    mov r10, 0x00 ; result
    mov r11, 0x00 ; base_result

    ; check the base passed in second argument (rsi). If the base is <= 2, the base is invalid
    push rdi
    mov rdi, rsi
    call ft_check_base
    pop rdi
    mov r8, rax
    cmp r8, 0x02
    jnge .error

.skip_whitespace_loop:
    push rdi
    movzx edi, byte [rdi]
    call ft_isspace
    pop rdi
    cmp eax, 0x00
    je .sign_loop
    inc rdi
    jmp .skip_whitespace_loop
.sign_loop:
    mov al, byte [rdi]
    cmp al, '-'
    je .negate_sign
    cmp al, '+'
    je .increment

    jmp .result_loop
.negate_sign:
    neg r9 ; minus
.increment:
    inc rdi
    jmp .sign_loop
.result_loop:
    push rdi 
    push rsi
    mov rax, rsi ; temp register
    mov sil, byte [rdi]
    mov rdi, rax
    call ft_get_base_nbr
    pop rsi
    pop rdi

    cmp rax, -0x01
    je .end_result_loop
    mov r11, rax ; base_result
    imul r10, r8 ; 
    add r10, r11
    inc rdi
    jmp .result_loop
.end_result_loop:
    mov rax, r10
    imul rax, r9
    jmp .ret
.error:
    mov eax, 0x00
.ret:
    pop rbp
    ret