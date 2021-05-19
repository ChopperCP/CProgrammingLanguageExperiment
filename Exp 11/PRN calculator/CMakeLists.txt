cmake_minimum_required(VERSION 3.19)
project(PRN_calculator C)

set(CMAKE_C_STANDARD 99)

add_executable(PRN_calculator main.c mystack.c mystack.h)