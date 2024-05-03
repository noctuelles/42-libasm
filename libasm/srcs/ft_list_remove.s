%include "srcs/ft_list.mac"

section .text
    global ft_list_remove

; void ft_list_remove(t_list **begin_list, t_list *elem);
ft_list_delete_one:
    push rbp
    mov rbp, rsp
    pop rbp
    ret