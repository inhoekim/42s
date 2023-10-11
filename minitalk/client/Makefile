# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:43:07 by inhkim            #+#    #+#              #
#    Updated: 2023/10/11 17:21:54 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=client

CC=cc
CFLAGS=-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : _MANDATORY

_MANDATORY : ft_client.o
	@rm -f _BONUS
	@make -C ../libft
	$(CC) $(CFLAGS) $^ -o $(NAME) -L../libft -lft 
	touch $@

ft_client.o : ft_client.c
	$(CC) $(CFLAGS) -c $^

bonus : _BONUS

_BONUS : ft_client_bonus.o
	@rm -f _MANDATORY
	@make -C ../libft
	$(CC) $(CFLAGS) $^ -o $(NAME) -L../libft -lft
	touch $@

ft_client_bonus.o : ft_client_bonus.c
	$(CC) $(CFLAGS) -c $^

clean :
	@rm -f _MANDATORY _BONUS
	rm -f ft_client.o ft_client_bonus.o

fclean : clean 
	rm -f client

re : fclean 
	make all

.PHONY : all fclean re clean
