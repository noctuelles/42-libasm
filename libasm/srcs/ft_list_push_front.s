%include "srcs/ft_list.mac"
section .text
    extern ft_list_create_elem
    global ft_list_push_front

; void ft_list_push_front(t_list **begin_list, void *data);
; rdi = begin_list
; rsi = data
ft_list_push_front:
    push rbp
    mov rbp, rsp
    ; allocate the new element
    push rdi
    mov rdi, rsi
    call ft_list_create_elem
    pop rdi
    cmp rax, 0x00
    jz .ret
    ; check if the list is empty
    cmp qword [rdi], 0x00
    jz .update_list_beginning
    ; if not empty, update the 'next' pointer of the new element, aka the new beginning of the list
    mov rdx, qword [rdi]
    mov qword [rax + t_list.next], rdx
.update_list_beginning:
    mov qword [rdi], rax
.ret:
    pop rbp
    ret