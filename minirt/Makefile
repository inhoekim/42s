# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 14:11:28 by seykim            #+#    #+#              #
#    Updated: 2023/12/23 21:20:27 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## ANSI escape code
CYAN  := \033[1;36;40m
RESET := \033[0m
LOG   := printf "[$(CYAN)INFO$(RESET)] %s\n"

## directory
INC_DIRS = vector view figure initailize util
SRC_DIRS = vector view figure initailize util

vpath %.h $(INC_DIRS)
vpath %.c $(SRC_DIRS)

CC= cc 
CFLAGS = -g -fsanitize=address #-Wall -Wextra -Werror 
CLIB= -Lmlx -framework OpenGl -framework AppKit -Imlx
HEADERS = vector.h view.h figure.h initailize.h get_next_line.h minirt.h
#main
SRCS+=main.c
# figure
SRCS+=hit.c object.c sphere.c plane.c
# initailize
SRCS+=alight_check.c camera_check.c cylinder.c cylinder_check.c error_check.c file_init.c light_check.c plane_check.c sphere_check.c  ft_atof.c
# util
SRCS+=get_next_line.c get_next_line_utils.c
# vector
SRCS+=vector_func.c vector_func2.c vector_func3.c
# view
SRCS+=camera.c phong.c ray.c
#
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
