# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 10:54:20 by fcarranz          #+#    #+#              #
#    Updated: 2024/05/08 18:39:54 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CC=gcc
FLAGS=-Wall -Wextra -Werror
LIB_FLAG=-lftprintf -Llibft
LIB=$(LIBFT_DIR)libftprintf.a
INC=-Iinc -Ilibft/inc

OBJ_DIR=objs/
SRC_DIR=src/
LIBFT_DIR=libft/

SRC=pipex.c \
	get_path.c \
	pipex_utils.c
OBJS=$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

.PHONY: all clean fclean re

all: $(NAME)
	@echo "===== READY ====="

$(NAME): $(LIB) $(OBJS) Makefile
	$(CC) $(FLAGS) $(LIB_FLAG) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(FLAGS) $(INC) -c $< -o $@

$(LIB): $(LIBFT_DIR)Makefile
	@echo "LIBFT COMPILING..."
	@make -C $(LIBFT_DIR) > /dev/null

clean:
	@make clean -C $(LIBFT_DIR) > /dev/null
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME)

re: fclean all
