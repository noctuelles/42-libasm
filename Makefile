# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plouvel <plouvel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/29 22:26:26 by plouvel           #+#    #+#              #
#    Updated: 2024/05/04 17:57:35 by plouvel          ###   ########.fr        #
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
	 main.c

SRCS_BONUS=ft_isspace_bonus.c \
	       ft_atoi_base_bonus.c \
	       ft_list_create_elem_bonus.c \
	       ft_list_push_front_bonus.c \
	       ft_list_size_bonus.c \
	       ft_list_remove_if_bonus.c \
	       ft_list_sort_bonus.c \
		   main_bonus.c

OBJS=$(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_BONUS=$(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))

NAME=tester
NAME_BONUS=tester_bonus
RM=rm -rf
MKDIR=mkdir -p

LIBASM=$(LIBSASM_DIR)libasm.a
LIBASM_BONUS=$(LIBSASM_DIR)libasm_bonus.a

all: $(LIBASM) $(NAME)
bonus: $(LIBASM_BONUS) $(NAME_BONUS)
$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(LIBCSTATIC) $^ -o $@ -L$(LIBASM_DIR) -lasm_bonus
$(NAME): $(OBJS)
	$(CC) $(LIBCSTATIC) $^ -o $@ -L$(LIBASM_DIR) -lasm
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(DEBUG) $(INCS) -c $< -o $@
$(OBJS_DIR):
	$(MKDIR) $@
$(LIBASM):
	$(MAKE) -C $(LIBASM_DIR) all
$(LIBASM_BONUS):
	$(MAKE) -C $(LIBASM_DIR) bonus
clean:
	$(MAKE) -C $(LIBASM_DIR) clean
	$(RM) $(OBJS_DIR)
fclean: clean
	$(MAKE) -C $(LIBASM_DIR) fclean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
re: fclean all

.PHONY: all bonus clean fclean re