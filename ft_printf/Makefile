# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 11:33:50 by vvaltone          #+#    #+#              #
#    Updated: 2019/12/04 11:33:50 by vvaltone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

SRCS		= 	project/add_ft.c\
				project/ft_printf.c\
				project/handle_conv.c\
				project/handle_cs.c\
				project/handle_diouxp.c\
				project/handle_float.c

LIBFT		=	libft/

LIB_N		=	libft.a

OBJS		=	$(SRCS:.c=.o)

all:			$(NAME)

$(NAME):	$(OBJS)
			make -C $(LIBFT)
			cp $(LIBFT)$(LIB_N) $(NAME)
			ar -r $(NAME) $(OBJS)
			ranlib $(NAME)

lib:
		make -C $(LIBFT)
	
clean:
		/bin/rm -rf $(OBJS)
		make -C libft clean

fclean:	clean
		/bin/rm -rf $(NAME)
		make -C libft fclean

re:		fclean all

.PHONY: all clean fclean re
