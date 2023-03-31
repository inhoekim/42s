# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 05:28:44 by inhkim            #+#    #+#              #
#    Updated: 2023/03/31 10:21:51 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_check_formats.c ft_init_format.c ft_isdigit.c ft_lstclear.c \
ft_lstnew.c ft_make_hexstr.c ft_memset.c ft_print_addr.c \
ft_print_char.c ft_print_format.c ft_print_hex_lower.c ft_print_hex_upper.c \
ft_print_int.c ft_print_percent.c ft_print_str.c ft_print_width.c \
ft_print_zero.c ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c 
BONUS_SRCS=ft_check_formats_bonus.c ft_init_format_bonus.c ft_isdigit_bonus.c \
ft_lstclear_bonus.c ft_lstnew_bonus.c ft_make_hexstr_bonus.c ft_memset_bonus.c \
ft_print_addr_bonus.c ft_print_char_bonus.c ft_print_format_bonus.c ft_print_hex_lower_bonus.c \
ft_print_hex_upper_bonus.c ft_print_int_bonus.c ft_print_percent_bonus.c ft_print_str_bonus.c \
ft_print_width_bonus.c ft_print_zero_bonus.c ft_printf_bonus.c ft_putchar_fd_bonus.c \
ft_putstr_fd_bonus.c ft_strlen_bonus.c
SRCS_WITH_PATH=$(addprefix srcs/,$(SRCS))
BONUS_WITH_PATH=$(addprefix bonus_srcs/,$(BONUS_SRCS))
SRCS_OBJS=$(SRCS_WITH_PATH:.c=.o)
BONUS_OBJS=$(BONUS_WITH_PATH:.c=.o)
NAME=libftprintf.a

all : MANDATORY

bonus : BONUS_SUB

MANDATORY : $(SRCS_OBJS)
	ar rc $(NAME) $^
	@touch $@
	@rm -f BONUS_SUB

BONUS_SUB : $(BONUS_OBJS)
	ar rc $(NAME) $^
	@touch $@
	@rm -f MANDATORY
	
$(SRCS_OBJS) $(BONUS_OBJS): %.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I./includes

clean :
	rm -f $(SRCS_OBJS) $(BONUS_OBJS)
	@rm -f MANDATORY
	@rm -f BONUS_SUB

fclean : clean
	rm -f $(TARGET)

re : fclean
	make all

.PHONY : all clean fclean re bonus
