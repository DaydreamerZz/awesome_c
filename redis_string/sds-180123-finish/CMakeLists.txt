cmake_minimum_required(VERSION 3.5)
project(sds C)

set(CMAKE_C_STANDARD 99)

add_executable(sds main.c  sds.c testhelp.h zmalloc.c)