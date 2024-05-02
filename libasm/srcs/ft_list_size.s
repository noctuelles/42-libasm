/*
    typedef struct s_list
    {
        void          *data;
        struct s_list *next;
    }               t_list;
*/
section .text
    global ft_list_size

ft_list_size:
    push   rbp
    mov rbp, rsp
    sub rbp, 0x20
    mov qword [rbp - 0x18], rdi
    mov qword [rbp - 0x8], 0x0
.loop:
    mov rax, qword [rbp - 0x18]
    mov rax, qword [rax + 8] ; next
    cmp rax, 0x0
    je .ret
    add qword [rbp - 0x8], 0x1
    jmp .loop
.ret:
    mov rax, qword [rbp - 0x8]
    add rbp, 0x20
    pop rbp
    ret