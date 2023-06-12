# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 05:28:44 by inhkim            #+#    #+#              #
#    Updated: 2023/06/12 14:10:23 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=check_util.c empty_sort_4.c empty_sort.c ft_atoi.c ft_split.c \
merge_sort.c partition.c push_swap.c sort_less_3.c stack_oper.c utility.c
#BONUS_SRCS=
SRCS_WITH_PATH=$(addprefix main/,$(SRCS))
SRCS_OBJS=$(SRCS_WITH_PATH:.c=.o)
BONUS_NAME=checker
NAME=push_swap
PRINTF=./lib_printf

all : $(NAME)

$(NAME) : $(SRCS_OBJS)
	make -C $(PRINTF) 
	@mv -f *.o ./main
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTF)/libftprintf.a
	
$(SRCS_OBJS): %.o : %.c ./main/push_swap.h
	$(CC) $(CFLAGS) -c $^ -I./

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
