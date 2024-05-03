%include "srcs/ft_list.mac"

section .text
    global  ft_list_sort

; void ft_list_sort(t_list **begin_list, int (*cmp)())
; rdi = t_list **begin_list
; rsi = int (*cmp)()
ft_list_sort:
    push rbp
    mov rbp, rsp
    mov r8, qword [rdi] ; current
    mov r9, 0x00        ; next
    mov r10, 0x00       ; tmp
.loop:
    cmp r8, 0x00
    jz .ret
    mov r9, qword [r8 + t_list.next]
.loop2:
    cmp r9, 0x00
    jz .inc_loop

    mov rax, rsi
    push rdi 
    push rsi
    push r8
    push r9
    push r10
    mov rdi, [r8 + t_list.content]
    mov rsi, [r9 + t_list.content]
    call rax
    pop r10
    pop r9
    pop r8
    pop rsi
    pop rdi 

    cmp eax, 0x00
    jle .inc_loop2
.swap_elements:
    mov r10, qword [r8 + t_list.content] ; tmp = current->content
    mov rax, qword [r9 + t_list.content] ;
    mov [r8 + t_list.content], rax ; current->content = next->content
    mov qword [r9 + t_list.content], r10 ; next->content = tmp;
.inc_loop2:
    mov r9, qword [r9 + t_list.next]
    jmp .loop2
.inc_loop:
    mov r8, qword [r8 + t_list.next]
    jmp .loop
.ret:
    pop rbp
    ret