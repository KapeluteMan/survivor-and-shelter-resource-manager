cmake_minimum_required(VERSION 4.1)
project(untitled5 C)

set(CMAKE_C_STANDARD 11)

add_executable(survivor-and-shelter-resource-manager
        main.c
        programStart/startingFuntions.c
        programStart/startingFuntions.h
        insertingFunctions/insertingFunctions.c
        insertingFunctions/insertingFunctions.h
        quest/addFromFile.c
        quest/addFromFile.h
        survivor/addFromFIle.c
        survivor/addFromFIle.h
        survivor/show.c
        survivor/show.h
        quest/show.c
        quest/show.h
        survivor/listOperations.c
        survivor/listOperations.h
        quest/listOperations.c
        quest/listOperations.h
        quest/questStruct.h
        survivor/survivorStruct.h
        survivor/survivorStruct.c
        survivor/find.c
        survivor/find.h
)
