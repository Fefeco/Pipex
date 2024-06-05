# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fcarranz <fcarranz@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 10:09:12 by fcarranz          #+#    #+#              #
#    Updated: 2024/06/05 10:40:11 by fcarranz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
CFLAGS = -Wall -Werror -Wextra -fPIE
INC=-Iinc

LIBFT_DIR = src/libft
GNL_DIR = src/gnl
PRTF_DIR = src/prtf

SRC_FILES = $(LIBFT_F) $(GNL_F) $(PRTF_F)

LIBFT_F=$(LIBFT_DIR)/ft_atoi.c \
		$(LIBFT_DIR)/ft_atol.c \
		$(LIBFT_DIR)/ft_bzero.c \
		$(LIBFT_DIR)/ft_calloc.c \
		$(LIBFT_DIR)/ft_free_array.c \
		$(LIBFT_DIR)/ft_free_array_len.c \
		$(LIBFT_DIR)/ft_isalnum.c \
		$(LIBFT_DIR)/ft_isalpha.c \
		$(LIBFT_DIR)/ft_isascii.c \
		$(LIBFT_DIR)/ft_isdigit.c \
		$(LIBFT_DIR)/ft_isprint.c \
		$(LIBFT_DIR)/ft_memchr.c \
		$(LIBFT_DIR)/ft_memcmp.c \
		$(LIBFT_DIR)/ft_memcpy.c \
		$(LIBFT_DIR)/ft_memmove.c \
		$(LIBFT_DIR)/ft_memset.c \
		$(LIBFT_DIR)/ft_strchr.c \
		$(LIBFT_DIR)/ft_strdup.c \
		$(LIBFT_DIR)/ft_strlcat.c \
		$(LIBFT_DIR)/ft_strlcpy.c \
		$(LIBFT_DIR)/ft_strlen.c \
		$(LIBFT_DIR)/ft_strncmp.c \
		$(LIBFT_DIR)/ft_strncmp_prot.c \
		$(LIBFT_DIR)/ft_strnstr.c \
		$(LIBFT_DIR)/ft_strrchr.c \
		$(LIBFT_DIR)/ft_tolower.c \
		$(LIBFT_DIR)/ft_toupper.c \
		$(LIBFT_DIR)/ft_substr.c \
		$(LIBFT_DIR)/ft_strtrim.c \
		$(LIBFT_DIR)/ft_itoa.c \
		$(LIBFT_DIR)/ft_split.c \
		$(LIBFT_DIR)/ft_strmapi.c \
		$(LIBFT_DIR)/ft_striteri.c \
		$(LIBFT_DIR)/ft_putchar_fd.c \
		$(LIBFT_DIR)/ft_putstr_fd.c \
		$(LIBFT_DIR)/ft_putendl_fd.c \
		$(LIBFT_DIR)/ft_putnbr_fd.c \
		$(LIBFT_DIR)/ft_len_char_nb.c \
		$(LIBFT_DIR)/ft_lstnew.c \
		$(LIBFT_DIR)/ft_lstadd_front.c \
		$(LIBFT_DIR)/ft_lstsize.c \
		$(LIBFT_DIR)/ft_lstlast.c \
		$(LIBFT_DIR)/ft_lstadd_back.c \
		$(LIBFT_DIR)/ft_lstdelone.c \
		$(LIBFT_DIR)/ft_lstclear.c \
		$(LIBFT_DIR)/ft_lstiter.c \
		$(LIBFT_DIR)/ft_lstmap.c

GNL_F=$(GNL_DIR)/get_next_line.c \
	  $(GNL_DIR)/get_next_line_utils.c

PRTF_F=$(PRTF_DIR)/ft_print_char.c \
	   $(PRTF_DIR)/ft_print_hexa.c \
	   $(PRTF_DIR)/ft_print_nb.c \
	   $(PRTF_DIR)/ft_print_ptr.c \
	   $(PRTF_DIR)/ft_print_str.c \
	   $(PRTF_DIR)/ft_print_unsigned.c \
	   $(PRTF_DIR)/ft_printf.c \
	   $(PRTF_DIR)/ft_strlen.c \
	   $(PRTF_DIR)/ft_write_arg.c \
	   $(PRTF_DIR)/ft_print_hexa.c

OBJECTS = $(SRC_FILES:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) Makefile
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@echo "CLEANING LIBFT OBJECTS...\n"
	@rm -f $(OBJECTS)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
