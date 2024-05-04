# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 22:26:26 by plouvel           #+#    #+#              #
#    Updated: 2024/05/04 17:07:49 by plouvel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_DIR=srcs/
INCLUDES_DIR=includes/
OBJS_DIR=objs/
LIBASM_DIR=libasm/

CC=cc
CFLAGS=-Wall -Werror -Wextra
LIBCSTATIC=-static -static-libgcc
DEBUG=-g3
INCS=-I$(INCLUDES_DIR)

SRCS=ft_strlen.c \
	 ft_strcpy.c \
	 ft_strcmp.c \
	 ft_strdup.c \
	 ft_write.c \
	 ft_read.c  \
     ft_isspace.c \
	 ft_atoi_base.c \
	 ft_list_create_elem.c \
	 ft_list_push_front.c \
	 ft_list_size.c \
	 ft_list_remove_if.c \
	 ft_list_sort.c \
	 main.c

OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

NAME=tester
RM=rm -rf
MKDIR=mkdir -p
LIBASM=$(LIBSASM_DIR)libasm.a

all: $(LIBASM) $(NAME)
$(NAME): $(OBJS)
	$(CC) $(LIBCSTATIC) $^ -o $@ -L$(LIBASM_DIR) -lasm
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(DEBUG) $(INCS) -c $< -o $@
$(OBJS_DIR):
	$(MKDIR) $@
$(LIBASM):
	$(MAKE) -C $(LIBASM_DIR)
clean:
	$(RM) $(OBJS_DIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fclean re