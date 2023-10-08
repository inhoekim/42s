# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 05:28:44 by inhkim            #+#    #+#              #
#    Updated: 2023/10/08 19:51:20 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror -fsanitize=address
NAME=server

all : $(NAME)
	@make client

$(NAME) : server.o
	@make -C ./libft
	$(CC) $(CFLAGS) $^ -o $@ -L./libft -lft

server.o : server.c minitalk.h
	$(CC) $(CFLAGS) -c $^

client : client.o
	@make -C ./libft
	$(CC) $(CFLAGS) $^ -o $@ -L./libft -lft

client.o : client.c minitalk.h
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f client.o server.o minitalk.h.gch

fclean : clean 
	rm -f client server

re : fclean 
	make client server

.PHONY : all fclean re clean