cmake_minimum_required(VERSION 3.24)
project(printf C)

set(CMAKE_C_STANDARD 11)

include_directories(includes)

add_executable(printf
        bonus_srcs/ft_check_formats_bonus.c
        bonus_srcs/ft_init_format_bonus.c
        bonus_srcs/ft_intlen_bonus.c
        bonus_srcs/ft_isdigit_bonus.c
        bonus_srcs/ft_itoa_bonus.c
        bonus_srcs/ft_lstclear_bonus.c
        bonus_srcs/ft_lstnew_bonus.c
        bonus_srcs/ft_make_hexstr_bonus.c
        bonus_srcs/ft_memset_bonus.c
        bonus_srcs/ft_print_addr_bonus.c
        bonus_srcs/ft_print_char_bonus.c
        bonus_srcs/ft_print_format_bonus.c
        bonus_srcs/ft_print_hex_bonus.c
        bonus_srcs/ft_print_int_bonus.c
        bonus_srcs/ft_print_percent_bonus.c
        bonus_srcs/ft_print_str_bonus.c
        bonus_srcs/ft_print_width_bonus.c
        bonus_srcs/ft_print_zero_bonus.c
        bonus_srcs/ft_printf_bonus.c
        bonus_srcs/ft_putchar_fd_bonus.c
        bonus_srcs/ft_putstr_fd_bonus.c
        bonus_srcs/ft_strlen_bonus.c
        includes/ft_printf_bonus.h
        main.c)
