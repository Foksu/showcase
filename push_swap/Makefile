# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvaltone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/29 13:21:26 by vvaltone          #+#    #+#              #
#    Updated: 2019/12/29 13:21:27 by vvaltone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP	= 	push_swap
CHECKER		=	checker

CC			= 	gcc

CFLAGS		= 	-Wall -Wextra -Werror

SRCS_PUSH 	=	project/algorithm_utils.c\
			project/algorithm.c\
			project/actions_utils.c\
			project/actions.c \
			project/stack_utils.c \
			project/stack.c \
			project/utils.c \
			project/valid.c \
			project/push_swap.c
			

SRCS_CHECK 	=	project/algorithm_utils.c\
			project/algorithm.c\
			project/actions_utils.c\
			project/actions.c \
			project/stack_utils.c \
			project/stack.c \
			project/utils.c \
			project/valid.c \
			project/checker.c

HDR 		= 	./includes/

LIBFT 		= 	libft

OBJS_PUSH 	= 	$(SRCS_PUSH:.c=.o)
OBJS_CHECK 	= 	$(SRCS_CHECK:.c=.o)

all: 		$(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP): 	lib
	$(CC) $(CFLAGS) $(SRCS_PUSH) -o $(PUSH_SWAP) -I $(HDR) -L. libft/libft.a

$(CHECKER): 	lib
	$(CC) $(CFLAGS) $(SRCS_CHECK) -o $(CHECKER) -I $(HDR) -L. libft/libft.a

lib:
	make -C $(LIBFT)

clean:
	/bin/rm -rf $(OBJS_PUSH)
	/bin/rm -rf $(OBJS_CHECK)
	make -C libft clean

fclean: clean
	/bin/rm -rf $(PUSH_SWAP)
	/bin/rm -rf $(CHECKER)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re