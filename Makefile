# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wsallei <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/20 16:31:53 by wsallei           #+#    #+#              #
#    Updated: 2020/08/20 16:31:56 by wsallei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re bonus

NAME = cub3D

SRC =  src/main.c \
		src/map.c \
		src/tool.c \
		src/textures.c \
		src/parsf.c \
		src/errors.c \
		src/get_next_line.c \
		src/get_next_line_utils.c \
		src/check_pars.c \
		src/check_map.c
OBJ = main.o \
		map.o \
		tool.o \
		textures.o \
		parsf.o \
		errors.o \
		get_next_line.o \
		get_next_line_utils.o \
		check_pars.o \
		check_map.o

O = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror -I. -c

all: $(NAME)

%.o: %.c
	gcc  $(FLAG) $<

$(NAME):$(O)
		gcc -o $(NAME) $(OBJ)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
