cmake_minimum_required(VERSION 3.24)
project(push_swap C)
set(CMAKE_C_STANDARD 11)
include_directories(./bonus)
add_executable(
        checker_bonus.c
        ./bonus/chk_util_bonus.c
        ./bonus/ft_atoi_bonus.c
        ./bonus/ft_split_bonus.c
        ./bonus/get_next_line_bonus.c
        ./bonus/merge_sort_bonus.c
        ./bonus/get_next_line_utils_bonus.c
        ./bonus/stack_oper_bonus.c
        ./bonus/utility_bonus.c bonus/checker_bonus.c)