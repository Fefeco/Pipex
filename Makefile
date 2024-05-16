# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 10:54:20 by fcarranz          #+#    #+#              #
#    Updated: 2024/05/16 19:41:04 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CC=gcc
FLAGS=-Wall -Wextra -Werror -g
LIB_FLAG=-lftprintf -Llibft
LIB=$(LIBFT_DIR)libftprintf.a
INC=-Iinc -Ilibft/inc

OBJ_DIR=objs/
SRC_DIR=src/
LIBFT_DIR=libft/

MAIN=pipex.c
MAIN_BONUS=pipex_bonus.c

SRC=get_path.c \
	create_pipe.c \
	create_process.c \
	init.c \
	free.c \
	close_fds.c \
	pipex_utils.c
OBJS=$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
MAIN_OBJ=$(patsubst %.c, $(OBJ_DIR)%.o, $(MAIN))
MAIN_BONUS_OBJ=$(patsubst %.c, $(OBJ_DIR)%.o, $(MAIN_BONUS))

.PHONY: all clean fclean re

all: $(NAME)
	@echo "===== READY ====="

$(NAME): $(LIB) $(MAIN_OBJ) $(OBJS) Makefile
	$(CC) $(FLAGS) $(LIB_FLAG) $(MAIN_OBJ) $(OBJS) -o $(NAME)

bonus: clean $(LIB) $(MAIN_BONUS_OBJ) $(OBJS) Makefile
	$(CC) $(FLAGS) $(LIB_FLAG) $(MAIN_BONUS_OBJ) $(OBJS) -o $(NAME)

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
