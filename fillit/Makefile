# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/02 14:05:59 by vvaltone          #+#    #+#              #
#    Updated: 2019/11/21 12:51:41 by vvaltone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	fillit

CC		= 	gcc

CFLAGS	= 	-Wall -Wextra -Werror

SRCS 	=	project/main.c\
			project/creator.c\
			project/map.c\
			project/parser.c\
			project/solver.c

HDR 	= 	/project/fillit.h

LIBFT 	= 	libft/

OBJS 	= 	$(SRCS:.c=.o)

all: 		$(NAME)

$(NAME): 	lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L libft -lft

lib:
	make -C $(LIBFT)

clean:
	/bin/rm -rf $(OBJS)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re