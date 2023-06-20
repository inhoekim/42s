# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 05:28:44 by inhkim            #+#    #+#              #
#    Updated: 2023/06/21 02:40:28 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
MLX_FLAGS = -lmlx -framework OpenGl -framework AppKit -Imlx 

MAIN = main.c error.c

MAP = check_map.c create_map.c init_map.c
MAP_PATH = $(addprefix map/,$(MAP))

CORE = key_input.c
CORE_PATH = $(addprefix core/,$(CORE))

UTILS = str_utils.c
UTILS_PATH = $(addprefix utils/,$(UTILS))

GNL = get_next_line_utils.c get_next_line.c
GNL_PATH = $(addprefix gnl/,$(GNL))

SRCS = $(MAIN) $(MAP_PATH) $(CORE_PATH) $(UTILS_PATH) $(GNL_PATH)
OBJS = *.o

PRINTF=./lib_printf

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(PRINTF)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ $(PRINTF)/libftprintf.a -o $@
	
$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f $(OBJS)
	make -C $(PRINTF) clean

fclean : clean
	rm -f $(NAME)
	make -C $(PRINTF) fclean

re : fclean
	make -C ./lib_printf fclean
	make $(NAME)

.PHONY : all clean fclean re