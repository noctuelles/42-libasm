# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 22:26:26 by plouvel           #+#    #+#              #
#    Updated: 2024/04/29 22:28:17 by plouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR=srcs/
OBJS_DIR=objs/

COMPILER=nasm
CFLAGS=-f elf64

SRCS=ft_strlen.s
OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.s=.o))

NAME=libasm.so
RM=rm -rf
MKDIR=mkdir -p

all: $(NAME)
$(NAME): $(OBJS)
	ld -o $@ -shared $^
$(OBJS_DIR)%.o: $(SRCS_DIR)%.s | $(OBJS_DIR)
	$(COMPILER) $(CFLAGS) $< -o $@
$(OBJS_DIR):
	$(MKDIR) $@
clean:
	$(RM) $(OBJS_DIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re