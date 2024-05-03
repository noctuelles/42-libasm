# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 22:26:26 by plouvel           #+#    #+#              #
#    Updated: 2024/05/03 12:27:38 by plouvel          ###   ########.fr        #
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
	 ft_isspace.s \
	 ft_write.s  \
	 ft_strdup.s \
	 ft_atoi_base.s \
	 ft_list_create_elem.s \
	 ft_list_push_front.s \
	 ft_list_size.s \
	 ft_read.s

OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.s=.o))

NAME=libasm.a
RM=rm -rf
MKDIR=mkdir -p

all: $(NAME)
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
re: fclean all

.PHONY: all clean fclean re