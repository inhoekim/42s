cmake_minimum_required(VERSION 3.24)
project(libftprintf C)

set(CMAKE_C_STANDARD 11)

add_executable(libftprintf main.c ft_printf.c format_srcs/ft_check_formats.c format_srcs/ft_init_format.c format_srcs/ft_print_format.c srcs/ft_memset.c srcs/ft_print_addr.c srcs/ft_print_str.c srcs/ft_print_char.c srcs/ft_print_width.c srcs/ft_putchar_fd.c srcs/ft_strlen.c srcs/ft_isdigit.c srcs/ft_lstnew.c srcs/ft_print_int.c srcs/ft_putstr_fd.c srcs/ft_print_zero.c)
