# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 05:28:44 by inhkim            #+#    #+#              #
#    Updated: 2023/09/17 20:27:45 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
CLIENT_SRC=client.c utils.c
SERVER_SRC=server.c utils.c

$(all) : server
	
server : $(SERVER_SRC:.c=.o)
	@make -C ./libft
	$(CC) $(CFLAGS) $^ -o $@ -L./libft -lft
	make client

$(SERVER_SRC:.c=.o) : %.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ -I./

client : $(CLIENT_SRC:.c=.o)
	$(CC) $(CFLAGS) $^ -o $@ -L./libft -lft

$(CLIENT_SRC:.c=.o) : %.o : %.c 
	$(CC) $(CFLAGS) -c $^ -o $@ -I./

clean :
	rm -f $(CLIENT_SRC:.c=.o) $(SERVER_SRC:.c=.o)

fclean : clean 
	rm -f client server

re : fclean 
	make client server

.PHONY : all fclean re clean client server
