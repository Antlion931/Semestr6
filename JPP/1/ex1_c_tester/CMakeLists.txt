cmake_minimum_required(VERSION 3.10)
project(tester)

add_executable(tester main.c)

# Set compiler flags
target_compile_options(tester PRIVATE -Wall -Wextra -Werror -std=c11)

find_library(LIB_TO_INCLUDE math_c_loops ../ex1_c_loops/)

find_path (LIB_INCLUDES math_c_loops.h ../ex1_c_loops/)

include_directories(${LIB_INCLUDES})

target_link_libraries(tester ${LIB_TO_INCLUDE})

find_library(LIB_TO_INCLUDEE math_c_recursion ../ex1_c_recursion/)

find_path (LIB_INCLUDEES math_c_recursion.h ../ex1_c_recursion/)

include_directories(${LIB_INCLUDEES})

target_link_libraries(tester ${LIB_TO_INCLUDEE})
