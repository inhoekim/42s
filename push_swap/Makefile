# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 05:28:44 by inhkim            #+#    #+#              #
#    Updated: 2023/06/07 12:19:36 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=empty_sort_4.c empty_sort.c ft_atoi.c ft_split.c merge_sort.c\
partition.c push_swap.c sort_less_3.c stack_oper.c utility.c
SRCS_OBJS=$(SRCS:.c=.o)
NAME=push_swap
PRINTF=./lib_printf

all : $(NAME)

$(NAME) : $(SRCS_OBJS)
	make -C $(PRINTF) 
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTF)/libftprintf.a
	
$(SRCS_OBJS): %.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f $(SRCS_OBJS)
	make -C $(PRINTF) clean

fclean : clean
	rm -f $(NAME)
	make -C $(PRINTF) fclean

re : fclean
	make -C ./lib_printf fclean
	make $(NAME) 

.PHONY : all clean fclean re
