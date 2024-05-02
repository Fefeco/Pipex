# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 10:54:20 by fcarranz          #+#    #+#              #
#    Updated: 2024/05/02 12:00:26 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CC=gcc
FLAGS=-Wall -Wextra -Werror

OBJ_DIR=objs/
SRC_DIR=src/
LIBFT_DIR=libft/

SRC=main.c
OBJS=$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) Makefile
	make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
