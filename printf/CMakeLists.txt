cmake_minimum_required(VERSION 3.24)
project(printf C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

add_executable(printf
        includes/ft_printf.h
        includes/ft_printf_bonus.h
        srcs/ft_check_formats.c
        srcs/ft_init_format.c
        srcs/ft_isdigit.c
        srcs/ft_lstclear.c
        srcs/ft_lstnew.c
        srcs/ft_make_hexstr.c
        srcs/ft_memset.c
        srcs/ft_print_addr.c
        srcs/ft_print_char.c
        srcs/ft_print_format.c
        srcs/ft_print_hex_lower.c
        srcs/ft_print_hex_upper.c
        srcs/ft_print_int.c
        srcs/ft_print_percent.c
        srcs/ft_print_str.c
        srcs/ft_print_width.c
        srcs/ft_print_zero.c
        srcs/ft_printf.c
        srcs/ft_putchar_fd.c
        srcs/ft_putstr_fd.c
        srcs/ft_strlen.c
        main.c)
