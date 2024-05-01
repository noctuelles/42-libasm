# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 22:26:26 by plouvel           #+#    #+#              #
#    Updated: 2024/05/01 16:34:50 by plouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR=srcs/
OBJS_DIR=objs/
TEST_FILE=test/main.c

COMPILER=nasm
CFLAGS=-f elf64
CCFLAGS=-Wall -Werror -Wextra
CC=cc

SRCS=ft_strlen.s \
	 ft_strcpy.s \
	 ft_strcmp.s \
	 ft_write.s  \
	 ft_strdup.s \
	 ft_read.s

OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.s=.o))

NAME=libasm.a
TESTER=tester
RM=rm -rf
MKDIR=mkdir -p


all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $@ $^
$(TESTER): $(NAME) $(TEST_FILE)
	$(CC) -g3 -static -static-libgcc -o $@ $(TEST_FILE) -L. -l$(patsubst lib%.a,%,$<)
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