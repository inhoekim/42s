# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 05:28:44 by inhkim            #+#    #+#              #
#    Updated: 2023/06/19 14:59:20 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=check_util.c empty_sort_4.c empty_sort.c ft_atoi.c ft_split.c \
merge_sort.c partition.c push_swap.c sort_less_3.c stack_oper.c utility.c
BONUS_SRCS=checker_bonus.c chk_util_bonus.c ft_atoi_bonus.c ft_split_bonus.c get_next_line_bonus.c \
get_next_line_utils_bonus.c merge_sort_bonus.c stack_oper_bonus.c utility_bonus.c
SRCS_WITH_PATH=$(addprefix main/,$(SRCS))
BONUS_WITH_PATH=$(addprefix bonus/,$(BONUS_SRCS))
SRCS_OBJS=$(SRCS_WITH_PATH:.c=.o)
BONUS_OBJS=$(BONUS_WITH_PATH:.c=.o)
BONUS_NAME=checker
NAME=push_swap
PRINTF=./lib_printf

all : $(NAME)

$(NAME) : $(SRCS_OBJS)
	make -C $(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ $(PRINTF)/libftprintf.a
	
$(SRCS_OBJS): %.o : %.c ./main/push_swap.h
	$(CC) $(CFLAGS) -c $^ -I./main
	@mv -f $(patsubst main/%,%,$@) ./main/

clean :
	rm -f $(SRCS_OBJS)
	rm -f $(BONUS_OBJS)
	make -C $(PRINTF) clean

fclean : clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	make -C $(PRINTF) fclean

re : fclean
	make -C ./lib_printf fclean
	make $(NAME)
	make $(BONUS_NAME)

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS_OBJS) : %.o : %.c ./bonus/get_next_line_bonus.h ./bonus/push_swap_bonus.h
	$(CC) $(CFLAGS) -c $^ -I./bonus
	@mv -f $(patsubst bonus/%,%,$@) ./bonus/

.PHONY : all clean fclean re bonus
