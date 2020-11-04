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
		src/pimg.c \
		src/sprites.c \
		src/ptextures.c \
		src/key_move.c \
		src/keyp.c \
		src/sprite.c \
		src/sprite2.c \
		src/bmp.c \
		src/otext.c\
		src/utils.c \
		src/coctail.c

O = $(SRC:.c=.o)

FLAG =  -Wall -Wextra -Werror

MLXFLAG = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	gcc  $(FLAG) -g -c $< -o $@

$(NAME):$(O)
		make -C mlx
		gcc -o $(NAME) -L $(MLX) $(MLXFLAG) $(O)
clean:
		make -C mlx clean
		rm -f $(O)

fclean: clean
		rm -f $(NAME)

re: fclean all
