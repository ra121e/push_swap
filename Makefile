# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 15:54:11 by athonda           #+#    #+#              #
#    Updated: 2024/07/12 17:39:09 by athonda          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libpushswap.a

CFLAGS	=	-Wall -Wextra -Werror -g3 -O0

SRCS	=	ft_split.c ft_utils.c make_list.c \
			op_swap.c op_rotate.c op_rev_rotate.c op_push.c

MAIN	=	push_swap.c

OBJS	=	$(patsubst %.c,%.o,$(SRCS))

all: $(NAME) $(MAIN)
		cc $(CFLAGS) $(MAIN) $(NAME)

$(NAME): $(OBJS)
		ar rsc $@ $?

%.o: %.c push_swap.h
		cc -o $@ $(CFLAGS) -c $<

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME) a.out push_swap.o

re: fclean all

.PHONY: all clean fclean re
