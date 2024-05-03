%include "srcs/ft_list.mac"
section .text
    extern malloc
    global ft_list_create_elem

ft_list_create_elem:
    push rbp
    mov rbp, rsp
    push rdi
    mov rdi, t_list_size
    call malloc
    pop rdi
    cmp rax, 0x00
    jz .ret
    mov qword [rax + t_list.content], rdi
    mov qword [rax + t_list.next], 0x00
.ret:
    pop rbp
    ret