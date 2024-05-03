%include "srcs/ft_list.mac"
section .text
    global ft_list_size

; size_t ft_list_size(t_list *begin_list);
ft_list_size:
    push   rbp
    mov rbp, rsp
    mov rcx, 0
.loop:
    cmp rdi, 0x00
    je .ret
    mov rdi, qword [rdi + t_list.next]
    inc rcx
    jmp .loop
.ret:
    mov rax, rcx
    pop rbp
    ret