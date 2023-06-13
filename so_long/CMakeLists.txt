cmake_minimum_required(VERSION 3.24)
project(so_long C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(so_long
        map/map.h
        map/check_map.c
        gnl/get_next_line.c
        gnl/get_next_line.h
        gnl/get_next_line_utils.c
        so_long.c
        so_long.h map/init_map.c map/create_map.c utils/utils.h utils/str_utils.c)
