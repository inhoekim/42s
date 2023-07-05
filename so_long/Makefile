# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/10 05:28:44 by inhkim            #+#    #+#              #
#    Updated: 2023/07/04 18:33:39 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -fsanitize=address -g3 -Wall -Wextra -Werror
MLX_FLAGS = -L./mlx -lmlx -framework OpenGL -framework AppKit

MAIN = main.c

MAP = check_map.c create_map.c init_map.c
MAP_PATH = $(addprefix map/,$(MAP))

CORE = key_input.c frame_update.c alloc_img.c alloc_img2.c render.c init_game.c
CORE_PATH = $(addprefix core/,$(CORE))

CORE_BONUS = key_input_bonus.c frame_update_bonus.c alloc_img_bonus.c alloc_img2_bonus.c render_bonus.c init_game_bonus.c
CORE_BONUS_PATH = $(addprefix bonus/,$(CORE_BONUS))

UTILS = str_utils.c ft_itoa.c
UTILS_PATH = $(addprefix utils/,$(UTILS))

GNL = get_next_line_utils.c get_next_line.c
GNL_PATH = $(addprefix gnl/,$(GNL))

# ------------------------------------ SRCS ----------------------------------------#
SRCS_WITH_PATH = $(MAIN) $(MAP_PATH) $(CORE_PATH) $(UTILS_PATH) $(GNL_PATH)
BONUS_WITH_PATH = $(MAIN) $(MAP_PATH) $(CORE_BONUS_PATH) $(UTILS_PATH) $(GNL_PATH)

#------------------------------------- RULES ----------------------------------------#

all : $(NAME)

$(NAME) : _MANDATORY

_MANDATORY : $(SRCS_WITH_PATH:.c=.o)
	@rm -f _BONUS
	@make -C ./mlx
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $^ -o $(NAME)
	touch $@

$(SRCS_WITH_PATH:.c=.o) : %.o : %.c
	$(CC) $(CFLAGS) $^ -o $@

bonus : _BONUS

_BONUS : $(BONUS_WITH_PATH:.c=.o)
	@rm -f _MANDATORY
	@make -C ./mlx
	$(CC) $(CFLAGS) $(MLX_FLAGS) -c $^ -o $(NAME)
	touch $@

$(CORE_BONUS_PATH:.c=.o) : %.o : %.c
	$(CC) $(CFLAGS) $^ -o $@

clean :
	@rm -f _MANDATORY _BONUS
	rm -f $(SRCS_WITH_PATH:.c=.o) $(CORE_BONUS:.c=.o)

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

.PHONY : all clean fclean re bonus