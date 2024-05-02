section .text
    global ft_isspace
CARRIAGE_RETURN equ 0x0D
LINE_FEED equ 0x0A
TAB equ 0x09
VERTICAL_TAB equ 0x0B
FORM_FEED equ 0x0C
SPACE equ 0x20
ft_isspace:
    push rbp
    mov rbp,rsp
    mov eax, 0x00
    cmp edi, TAB ; \t
    je .eq
    cmp edi, LINE_FEED ; \n
    je .eq
    cmp edi, VERTICAL_TAB ; \v
    je .eq
    cmp edi, FORM_FEED ; \f
    je .eq
    cmp edi, CARRIAGE_RETURN ; \r
    je .eq
    cmp edi, SPACE ; ' '
    je .eq
    jmp .ret
.eq:
    mov eax, 0x01
.ret:
    pop rbp
    ret