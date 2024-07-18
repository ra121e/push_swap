# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 15:54:11 by athonda           #+#    #+#              #
#    Updated: 2024/07/18 21:20:20 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

LIB		=	libpushswap.a

CFLAGS	=	-Wall -Wextra -Werror -g3 -O0

SRCS	=	ft_split.c ft_utils.c check_arg.c make_list.c \
			ft_lst_utils.c ft_lst_utils2.c \
			op_swap.c op_rotate.c op_rev_rotate.c op_push.c \
			algorithm.c optimize.c basic_sort.c

MAIN	=	push_swap.c

OBJS	=	$(patsubst %.c,%.o,$(SRCS))

all: $(LIB) $(MAIN)
		cc $(CFLAGS) $(MAIN) $(LIB) -o $(NAME)

$(LIB): $(OBJS)
		ar rsc $@ $?

%.o: %.c push_swap.h
		cc -o $@ $(CFLAGS) -c $<

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
