# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 05:28:44 by inhkim            #+#    #+#              #
#    Updated: 2023/06/21 06:18:03 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = arch
CFLAGS = -Wall -Wextra -Werror 
#-fsanitize=address -g3
MLX_FLAGS = -x86_64 -Lmlx -lmlx -framework Metal -framework Metalkit

MAIN = main.c error.c

MAP = check_map.c create_map.c init_map.c
MAP_PATH = $(addprefix map/,$(MAP))

CORE = key_input.c frame_update.c alloc_img.c render.c init_game.c
CORE_PATH = $(addprefix core/,$(CORE))

UTILS = str_utils.c
UTILS_PATH = $(addprefix utils/,$(UTILS))

GNL = get_next_line_utils.c get_next_line.c
GNL_PATH = $(addprefix gnl/,$(GNL))

SRCS = $(MAIN) $(MAP_PATH) $(CORE_PATH) $(UTILS_PATH) $(GNL_PATH)
OBJS = *.o

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $^ -o $@
	
$(OBJS) : $(SRCS)
	$(CC) $(CFLAGS) -c $^

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean
	make $(NAME)

.PHONY : all clean fclean re