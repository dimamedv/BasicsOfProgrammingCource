cmake_minimum_required(VERSION 3.21)
project(BasicsOfProgrammingCourse C)

set(CMAKE_C_STANDARD 11)

add_executable(BasicsOfProgrammingCourse main.c
        libs/data_structures/matrix/matrix.c
        libs/data_structures/matrix/matrix.h libs/algorithms/array/array.c libs/algorithms/algorithms.c libs/algorithms/algorithms.h libs/data_structures/string/string_.c libs/data_structures/string/string_.h libs/data_structures/string/tasks/removeNonLetters.h)

add_subdirectory(libs)
