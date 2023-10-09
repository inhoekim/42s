# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 18:55:10 by inhkim            #+#    #+#              #
#    Updated: 2023/10/09 19:19:28 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=server

CC=cc
CFLAGS=-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : _MANDATORY

_MANDATORY : server.o
	@rm -f _BONUS
	@make -C ../libft
	$(CC) $(CFLAGS) -L../libft -lft $^ -o $(NAME)
	touch $@

server.o : server.c
	$(CC) $(CFLAGS) -c $^

bonus : _BONUS

_BONUS : server_bonus.o
	@rm -f _MANDATORY
	@make -C ../libft
	$(CC) $(CFLAGS) -L../libft -lft $^ -o $(NAME)
	touch $@

server_bonus.o : server_bonus.c
	$(CC) $(CFLAGS) -c $^

clean :
	@rm -f _MANDATORY _BONUS
	rm -f server.o server_bonus.o

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re bonus
