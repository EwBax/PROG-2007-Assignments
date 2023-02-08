cmake_minimum_required(VERSION 3.21)
project(ASSIGN4 C)

set(CMAKE_C_STANDARD 17)

add_executable(ASSIGN4 src/main.c inc/crypt.h src/crypt.c)
