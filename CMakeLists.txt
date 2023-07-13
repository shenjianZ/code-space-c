cmake_minimum_required(VERSION 3.25)
project(git_space_c C)

set(CMAKE_C_STANDARD 99)

add_executable(git_space_c main.c List/arrayList.c List/listNode.c)
