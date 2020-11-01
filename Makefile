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

.PHONY: all clean fclean re

NAME = cub3D

MLX = mlx

SRC =  src/main.c \
		src/map.c \
		src/tool.c \
		src/textures.c \
		src/parsf.c \
		src/errors.c \
		src/get_next_line.c \
		src/get_next_line_utils.c \
		src/check_pars.c \
		src/check_map.c \
		src/pimg.c\
		src/sprites.c\
		src/ptextures.c\
		src/key_move.c\
		src/keyp.c\
		src/sprite.c\
		src/sprite2.c\
		src/bmp.c

OBJ = main.o \
		map.o \
		tool.o \
		textures.o \
		parsf.o \
		errors.o \
		get_next_line.o \
		get_next_line_utils.o \
		check_pars.o \
		check_map.o \
		pimg.o\
		sprites.o\
		ptextures.o \
		key_move.o \
		keyp.o \
		sprite.o \
		sprite2.o \
		bmp.o

O = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror -I. -c

MLXFLAG = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	gcc  $(FLAG) $<

$(NAME):$(O)
		gcc -o $(NAME) -L $(MLX) $(MLXFLAG) $(OBJ)
clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
