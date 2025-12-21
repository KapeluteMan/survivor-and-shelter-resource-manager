cmake_minimum_required(VERSION 4.1)
project(untitled5 C)

set(CMAKE_C_STANDARD 11)

add_executable(survivor-and-shelter-resource-manager
        main.c
        startPage/startPage.c
        startPage/startPage.h
        insertingFunctions/insertingFunctions.c
        insertingFunctions/insertingFunctions.h
)
