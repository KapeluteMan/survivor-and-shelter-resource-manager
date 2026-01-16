cmake_minimum_required(VERSION 4.1)
project(untitled5 C)

set(CMAKE_C_STANDARD 11)

add_executable(survivor-and-shelter-resource-manager
        main.c

        programStart/starting_functions.c
        programStart/starting_functions.h

        logicFunctions/logic_functions.c
        logicFunctions/logic_functions.h

        quest/quest_struct.h
        quest/add_from_file.c
        quest/add_from_file.h
        quest/show.c
        quest/show.h
        quest/list_operations.c
        quest/list_operations.h

        survivor/survivor_struct.h
        survivor/survivor_struct.c
        survivor/file_operations.c
        survivor/file_operations.h
        survivor/show.c
        survivor/show.h
        survivor/list_operations.c
        survivor/list_operations.h
        survivor/find.c
        survivor/find.h
        programStart/main_menu.c
        programStart/main_menu.h
        programStart/ascii_titles.c
        programStart/ascii_titles.h
)
