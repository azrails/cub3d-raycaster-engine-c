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

SRC =  /src/main.c

O = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror -I. -c

all: $(NAME)

%.o: %.c
	gcc $(FLAG) $< 

$(NAME):$(O)
		
clean:
		rm -f $(O)

fclean: clean
		rm -f $(NAME)

re: fclean all
