cmake_minimum_required(VERSION 3.10)
project(math_c_recursion)

add_library(math_c_recursion
    math_c_recursion.c
)

# Include the 'include' directory to the search path
target_include_directories(math_c_recursion
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

# Documentation target
find_package(Doxygen)
if(DOXYGEN_FOUND)
    configure_file(Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
    add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)
endif()

