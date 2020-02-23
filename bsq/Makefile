# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/30 12:04:51 by vvaltone          #+#    #+#              #
#    Updated: 2019/07/31 16:17:30 by vvaltone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRC = main.c funcs.c brains.c map.c

OBJ = main.o funcs.o brains.o map.o

all: $(NAME)

$(NAME):
		@gcc -Wall -Wextra -Werror -c $(SRC)
		@gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

clean:
		@/bin/rm -f $(OBJ)

fclean: clean
		@/bin/rm -f $(NAME)

re:	fclean all
