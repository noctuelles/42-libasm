# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 22:26:26 by plouvel           #+#    #+#              #
#    Updated: 2024/05/04 17:57:06 by plouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR=srcs/
OBJS_DIR=objs/

COMPILER=nasm
CFLAGS=-f elf64 -gdwarf
CCFLAGS=-Wall -Werror -Wextra -g3
CC=cc

SRCS=ft_strlen.s \
	 ft_strcpy.s \
	 ft_strcmp.s \
	 ft_write.s  \
	 ft_strdup.s \
	 ft_read.s

SRCS_BONUS=ft_list_create_elem_bonus.s \
		   ft_list_push_front_bonus.s \
		   ft_list_size_bonus.s \
		   ft_list_remove_if_bonus.s \
		   ft_list_sort_bonus.s \
		   ft_isspace_bonus.s \
		   ft_atoi_base_bonus.s

OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.s=.o))
OBJS_BONUS=$(addprefix $(OBJS_DIR), $(SRCS_BONUS:.s=.o))

NAME=libasm.a
NAME_BONUS=libasm_bonus.a
RM=rm -rf
MKDIR=mkdir -p

all: $(NAME)
bonus: $(NAME_BONUS)
$(NAME_BONUS): $(OBJS) $(OBJS_BONUS)
	ar rcs $@ $^
$(NAME): $(OBJS)
	ar rcs $@ $^
$(OBJS_DIR)%.o: $(SRCS_DIR)%.s | $(OBJS_DIR)
	$(COMPILER) $(CFLAGS) $< -o $@
$(OBJS_DIR):
	$(MKDIR) $@
clean:
	$(RM) $(OBJS_DIR)
fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
re: fclean all

.PHONY: all bonus clean fclean re