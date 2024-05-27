# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/02 10:54:20 by fcarranz          #+#    #+#              #
#    Updated: 2024/05/27 13:23:15 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CC=gcc
FLAGS=-Wall -Wextra -Werror
LIB_FLAG=-lftprintf -Llibft
LIB=$(LIBFT_DIR)libftprintf.a
INC=-Iinc -Ilibft/inc

OBJ_DIR=objs/
DEP_DIR=deps/
SRC_DIR=src/
OBJ_BONUS_DIR=$(OBJ_DIR)bonus_files/
DEP_BONUS_DIR=$(DEP_DIR)bonus_files/
SRC_BONUS_DIR=$(SRC_DIR)bonus_files/
LIBFT_DIR=libft/

SRC=get_path.c \
	pipex.c \
	create_pipe.c \
	create_process.c \
	init.c \
	free.c \
	close_fds.c \
	parse_args.c \
	read.c \
	pipex_utils.c

SRC_BONUS=get_path_bonus.c \
		  pipex_bonus.c \
		  create_pipe_bonus.c \
		  create_process_bonus.c \
		  init_bonus.c \
		  free_bonus.c \
		  close_fds_bonus.c \
		  parse_args_bonus.c \
		  read_bonus.c \
		  pipex_utils_bonus.c

OBJS=$(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
DEPS=$(patsubst %.c, $(DEP_DIR)%.d, $(SRC))
OBJS_BONUS=$(patsubst %.c, $(OBJ_BONUS_DIR)%.o, $(SRC_BONUS))
DEPS_BONUS=$(patsubst %.c, $(DEP_BONUS_DIR)%.d, $(SRC_BONUS))

.PHONY: all clean fclean re

all: $(NAME)
	@echo "===== READY ====="

$(NAME): $(LIB) $(OBJS) Makefile
	@rm -rf $(OBJ_BONUS_DIR)
	$(CC) $(FLAGS) $(OBJS) $(LIB_FLAG) -o $(NAME)

bonus: $(LIB) $(OBJS_BONUS) Makefile
	@rm -f $(OBJS)
	$(CC) $(FLAGS) $(OBJS_BONUS) $(LIB_FLAG) -o $(NAME)
	@touch bonus

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(DEP_DIR)
	$(CC) $(FLAGS) $(INC) -c -MMD $< -o $@
	@mv $(OBJ_DIR)*.d $(DEP_DIR)

$(OBJ_BONUS_DIR)%.o: $(SRC_BONUS_DIR)%.c
	@mkdir -p $(OBJ_BONUS_DIR)
	@mkdir -p $(DEP_BONUS_DIR)
	$(CC) $(FLAGS) $(INC) -c -MMD $< -o $@
	@mv $(OBJ_BONUS_DIR)*.d $(DEP_BONUS_DIR)

$(LIB): $(LIBFT_DIR)Makefile
	@echo "LIBFT COMPILING..."
	@make -C $(LIBFT_DIR) > /dev/null

clean:
	@make clean -C $(LIBFT_DIR) > /dev/null
	@rm -rf $(OBJ_DIR) $(DEP_DIR) bonus

fclean: clean
	@make fclean -C $(LIBFT_DIR) > /dev/null
	@rm -f $(NAME)

-include $(DEPS)

re: fclean all
