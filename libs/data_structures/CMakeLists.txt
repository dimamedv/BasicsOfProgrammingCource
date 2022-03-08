add_library(data_structures
        matrix/matrix.c string/string_.c string/string_.h)

target_link_libraries(data_structures algorithms)

add_library(str string/string_.h string/string_.c

        string/tasks/removeNonLetters.h)