cmake_minimum_required(VERSION 3.5)
project(Mmultiplication)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
set(SOURCE_FILES
    file_processing.c
    file_processing.h
    main.c
    matrices_data.h
    matrix_util.c
    matrix_util.h
    multiply.c
    multiply.h
    naive_mmultiplication.c
    naive_mmultiplication.h)

add_executable(Mmultiplication ${SOURCE_FILES})