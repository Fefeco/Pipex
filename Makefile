# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 10:54:20 by fcarranz          #+#    #+#              #
#    Updated: 2024/05/16 21:07:32 by fcarranz         ###   ########.fr        #
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

SRC=get_path.c \
	pipex.c \
	create_pipe.c \
	create_process.c \
	init.c \
	free.c \
	close_fds.c \
	pipex_utils.c

SRC_BONUS=get_path_bonus.c \
		  pipex_bonus.c \
		  create_pipe_bonus.c \
		  create_process_bonus.c \
		  init_bonus.c \
		  free_bonus.c \
		  close_fds_bonus.c \
		  here_doc_bonus.c \
		  pipex_utils_bonus.c

OBJS=$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
OBJS_BONUS=$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_BONUS))

.PHONY: all clean fclean re

all: $(NAME)
	@echo "===== READY ====="

$(NAME): $(LIB) $(OBJS) Makefile
	$(CC) $(FLAGS) $(LIB_FLAG) $(OBJS) -o $(NAME)

bonus: $(LIB) $(OBJS_BONUS) Makefile
	$(CC) $(FLAGS) $(LIB_FLAG) $(OBJS_BONUS) -o $(NAME)
	@touch bonus

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(LIB): $(LIBFT_DIR)Makefile
	@echo "LIBFT COMPILING..."
	@make -C $(LIBFT_DIR) > /dev/null

clean:
	@make clean -C $(LIBFT_DIR) > /dev/null
	@rm -rf $(OBJ_DIR) bonus

fclean: clean
	@make fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME)

re: fclean all
