# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:43:07 by inhkim            #+#    #+#              #
#    Updated: 2023/10/09 18:49:25 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=client

CC=cc
CFLAGS=-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : _MANDATORY

_MANDATORY : client.o
	rm -f _BONUS
	make -C ../libft
	$(CC) $(CFLAGS) $^ -o $(NAME) -L../libft -lft 
	touch $@

client.o : client.c
	$(CC) $(CFLAGS) -c $^

bonus : _BONUS

_BONUS : client_bonus.o
	@rm -f _MANDATORY
	@make -C ../libft
	$(CC) $(CFLAGS) $^ -o $(NAME) -L../libft -lft
	touch $@

client_bonus.o : client_bonus.c
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f client.o client_bonus.o

fclean : clean 
	@rm -f _MANDATORY _BONUS
	rm -f client

re : fclean 
	make all

.PHONY : all fclean re clean bonus
