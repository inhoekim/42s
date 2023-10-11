# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:43:07 by inhkim            #+#    #+#              #
#    Updated: 2023/10/09 20:01:55 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=client

CC=cc
CFLAGS=-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : client.o
	@rm -rf bonus
	make -C ../libft
	$(CC) $(CFLAGS) $^ -o $(NAME) -L../libft -lft 
	@touch all

client.o : client.c
	$(CC) $(CFLAGS) -c $^

bonus : client_bonus.o
	@rm -rf all
	@make -C ../libft
	$(CC) $(CFLAGS) $^ -o $(NAME) -L../libft -lft
	@touch bonus

client_bonus.o : client_bonus.c
	$(CC) $(CFLAGS) -c $^

clean :
	@rm -f all bonus
	rm -f client.o client_bonus.o

fclean : clean 
	rm -f $(NAME)

re : fclean 
	make all

.PHONY : all fclean re clean bonus
