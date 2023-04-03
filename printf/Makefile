# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 05:28:44 by inhkim            #+#    #+#              #
#    Updated: 2023/04/04 06:11:09 by inhkim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
SRCS=ft_check_formats.c ft_init_format.c ft_isdigit.c ft_lstclear.c \
ft_lstnew.c ft_make_hexstr.c ft_memset.c ft_print_addr.c ft_intlen.c\
ft_print_char.c ft_print_format.c ft_print_hex.c ft_print_int.c \
ft_print_percent.c ft_print_str.c ft_print_width.c ft_print_zero.c \
ft_printf.c ft_putchar_fd.c ft_putstr_fd.c ft_strlen.c ft_itoa.c
BONUS_SRCS=ft_check_formats_bonus.c ft_init_format_bonus.c ft_isdigit_bonus.c \
ft_lstclear_bonus.c ft_lstnew_bonus.c ft_make_hexstr_bonus.c ft_memset_bonus.c \
ft_print_addr_bonus.c ft_intlen_bonus.c ft_print_char_bonus.c ft_print_format_bonus.c \
ft_print_hex_bonus.c ft_print_int_bonus.c ft_print_percent_bonus.c \
ft_print_str_bonus.c ft_print_width_bonus.c ft_print_zero_bonus.c ft_printf_bonus.c \
ft_putchar_fd_bonus.c ft_putstr_fd_bonus.c ft_strlen_bonus.c ft_itoa_bonus.c
SRCS_WITH_PATH=$(addprefix srcs/,$(SRCS))
BONUS_WITH_PATH=$(addprefix bonus_srcs/,$(BONUS_SRCS))
SRCS_OBJS=$(SRCS_WITH_PATH:.c=.o)
BONUS_OBJS=$(BONUS_WITH_PATH:.c=.o)
NAME=libftprintf.a

all : MANDATORY

bonus : BONUS_SUB

MANDATORY : $(SRCS_OBJS)
	ar rcs $(NAME) $^
	@if [ -f "BONUS_SUB" ]; then \
		ar ds $(NAME) $(BONUS_OBJS); \
	fi
	@touch $@
	@rm -f BONUS_SUB

BONUS_SUB : $(BONUS_OBJS)
	ar rcs $(NAME) $^
	@if [ -f "MANDATORY" ]; then \
		ar ds $(NAME) $(SRCS_OBJS); \
	fi
	@touch $@
	@rm -f MANDATORY
	
$(SRCS_OBJS) $(BONUS_OBJS): %.o : %.c 
	$(CC) $(CFLAGS) -c $< -o $@ -I./includes

clean :
	rm -f $(SRCS_OBJS) $(BONUS_OBJS)
	@rm -f MANDATORY
	@rm -f BONUS_SUB

fclean : clean
	rm -f $(NAME)

re : fclean
	make all

test : $(BONUS_WITH_PATH) main.c
	$(CC) $(CFLAGS) -g3 $^ -o $@ -I./includes

.PHONY : all clean fclean re bonus
