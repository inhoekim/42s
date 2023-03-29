cmake_minimum_required(VERSION 3.24)
project(libftprintf C)

set(CMAKE_C_STANDARD 11)

add_executable(libftprintf main.c ft_printf.c)
