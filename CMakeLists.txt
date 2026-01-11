cmake_minimum_required(VERSION 4.1)
project(untitled5 C)

set(CMAKE_C_STANDARD 11)

add_executable(survivor-and-shelter-resource-manager
        main.c

        programStart/starting_functions.c
        programStart/starting_functions.h

        insertingFunctions/inserting_functions.c
        insertingFunctions/inserting_functions.h

        quest/quest_struct.h
        quest/add_from_file.c
        quest/add_from_file.h
        quest/show.c
        quest/show.h
        quest/list_operations.c
        quest/list_operations.h

        survivor/struct.h
        survivor/struct.c
        survivor/add_from_file.c
        survivor/add_from_file.h
        survivor/show.c
        survivor/show.h
        survivor/list_operations.c
        survivor/list_operations.h
        survivor/find.c
        survivor/find.h
)
