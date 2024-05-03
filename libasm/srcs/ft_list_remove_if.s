%include "srcs/ft_list.mac"

global .text
    global ft_list_remove_if

; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
ft_list_remove_if:
    push rbp
    mov rbp, rsp
    pop rbp
    ret