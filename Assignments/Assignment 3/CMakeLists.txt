cmake_minimum_required(VERSION 3.21)
project(ASSIGN3 C)

set(CMAKE_C_STANDARD 17)

add_executable(ASSIGN3 src/main.c inc/studentRecord.h src/studentRecord.c)
