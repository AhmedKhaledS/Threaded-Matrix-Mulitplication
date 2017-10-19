cmake_minimum_required(VERSION 3.5)
project(Mmultiplication)
set(CMAKE_CXX_STANDARD 11)
set(GCC_COVERAGE_LINK_FLAGS "-pthread")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}")
set(SOURCE_FILES
    file_processing.c
    main.c
    matrix_util.c
    multiply.c)

add_executable(Mmultiplication ${SOURCE_FILES})