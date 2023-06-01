cmake_minimum_required(VERSION 3.24)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(push_swap
        ft_atoi.c
        ft_split.c
        push_swap.c
        stack_oper.c
        utility.c
        push_swap.h
        merge_sort.c)
