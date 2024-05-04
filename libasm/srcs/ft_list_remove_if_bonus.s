%include "srcs/ft_list.mac"

global .text
    global ft_list_remove_if
    extern free

; void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
; rdi = t_list **begin_list
; rsi = void *data_ref
; rdx = int (*cmp)()
; rcx = void (*free_fct)(void *)
ft_list_remove_if:
    push rbp
    push r12
    mov rbp, rsp
    mov r11, [rdi] ; current
    mov r12, 0x00  ; previous
.loop:
    cmp r11, 0x00
    jz .ret

    ; call the cmp function
    push rdi
    push rsi
    push rdx
    push rcx
    mov rdi, qword [r11 + t_list.content]
    mov rsi, rsi ; redondant, just being explicit
    call rdx
    pop rcx
    pop rdx
    pop rsi
    pop rdi

    cmp eax, 0x00
    jnz .current_elem_not_removed

.remove_current_elem:
    cmp r12, 0x00
    mov r8, [r11 + t_list.next] ; current->next
    jnz .not_first_elem
.first_elem:
    mov [rdi], r8 ; *begin_list = current->next
    jmp .current_elem_remove
.not_first_elem:
    mov [r12 + t_list.next], r8 ; previous->next = current->next
.current_elem_remove:
    push rdi
    push rsi
    push rdx
    push rcx
    mov rdi, [r11 + t_list.content]
    call rcx ; free_fct(current->content)
    mov rdi, r11
    call free ; free(current)
    pop rcx
    pop rdx
    pop rsi
    pop rdi

    cmp r12, 0x00
    jz .current_begin_list
    mov r11, [r12 + t_list.next] ; current = previous->next
    jmp .loop
.current_begin_list:
    mov r11, [rdi] ; current = *begin_list
    jmp .loop
.current_elem_not_removed:
    mov r12, r11
    mov r11, [r11 + t_list.next]
    jmp .loop
.ret:
    pop r12
    pop rbp
    ret