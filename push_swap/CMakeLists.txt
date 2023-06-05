cmake_minimum_required(VERSION 3.24)
project(push_swap C)
set(CMAKE_C_STANDARD 11)
include_directories(.)
add_executable(push_swap
        ft_atoi.c
        ft_split.c
        merge_sort.c
        partition.c
        push_swap.c
        push_swap.h
        sort_less_3.c
        stack_oper.c
        utility.c)