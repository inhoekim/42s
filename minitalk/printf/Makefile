# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 05:28:44 by inhkim            #+#    #+#              #
#    Updated: 2023/09/17 15:36:26 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_check_formats_bonus.c ft_init_format_bonus.c ft_isdigit_bonus.c \
ft_lstclear_bonus.c ft_lstnew_bonus.c ft_make_hexstr_bonus.c ft_memset_bonus.c \
ft_print_addr_bonus.c ft_intlen_bonus.c ft_print_char_bonus.c ft_print_format_bonus.c \
ft_print_hex_bonus.c ft_print_int_bonus.c ft_print_percent_bonus.c \
ft_print_str_bonus.c ft_print_width_bonus.c ft_print_zero_bonus.c ft_printf_bonus.c \
ft_putchar_fd_bonus.c ft_putstr_fd_bonus.c ft_strlen_bonus.c ft_itoa_bonus.c ft_err_bonus.c
SRCS_WITH_PATH=$(addprefix bonus_srcs/,$(SRCS))
SRCS_OBJS=$(SRCS_WITH_PATH:.c=.o)
NAME=libftprintf.a

$(all) : $(NAME)

$(NAME) : $(SRCS_OBJS)
	ar rcs $(NAME) $^
	
$(SRCS_OBJS) : %.o : %.c 
	$(CC) $(CFLAGS) -c $^ -o $@ -I./includes

clean :
	rm -f $(SRCS_OBJS)

fclean : clean 
	rm -f $(NAME)

re : fclean 
	make $(NAME)

.PHONY : all fclean re clean
