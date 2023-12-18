# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 14:11:28 by seykim            #+#    #+#              #
#    Updated: 2023/12/14 03:53:55 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ANSI escape code
CYAN  := \033[1;36;40m
RESET := \033[0m
LOG   := printf "[$(CYAN)INFO$(RESET)] %s\n"

## directory
INC_DIRS = vector view figure
SRC_DIRS = vector view figure

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

CC= cc 
#-g3 -fsanitize=address
CFLAGS = -g #-Wall -Wextra -Werror 
CLIB= -Lmlx -framework OpenGl -framework AppKit -Imlx
HEADERS = vector.h view.h figure.h
SRCS=main.c vector_func.c vector_func2.c vector_func3.c sphere.c
SRCS+=camera.c ray.c
OBJS=$(SRCS:.c=.o)
NAME=miniRT
LIBFT= libft/libft.a

.PHONY : bonus all clean fclean re

all : $(NAME)

$(NAME):$(OBJS)
	@$(LOG) "Linking"
	@make -C libft
	@make -C mlx
	$(CC) $(CFLAGS) $(CLIB) $^ -o $@ ./$(LIBFT) ./mlx/libmlx.a

$(OBJS): %.o: %.c $(HEADERS)
	@$(LOG) "Compiling.."
	@$(CC) $(CFLAGS) -o $@ -c $<

# bonus : $(BONUS)

# $(BONUS):$(BONUS_OBJS)
# 	$(CC) $(CFLAGS) $(CLIB) $^ -o $@ ./$(LIBFT) ./$(PRINTF) ./mlx/libmlx.a

clean:
	@$(LOG) "clean"
	@make clean -C libft
	@make clean -C mlx
	@rm -f $(OBJS) 
#$(BONUS_OBJS)

fclean: clean
	@$(LOG) "fclean"
	@make fclean -C libft
	@make clean -C mlx
	@rm -f $(NAME)
#$(BONUS)

re:
	@$(LOG) "re"
	@make fclean
	@make all
