cmake_minimum_required(VERSION 3.10)
project(math_library)

# Library source files
set(LIB_SRC simple_library.c)

# Library target
add_library(simple_library STATIC ${LIB_SRC})

# Set compiler flags
target_compile_options(simple_library PRIVATE -Wall -Wextra -Werror -std=c11)

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

# Clean target
add_custom_target(clean-all
    COMMAND ${CMAKE_BUILD_TOOL} clean
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_SOURCE_DIR}/cmake/clean-all.cmake
    COMMENT "Cleaning all generated files"
    VERBATIM)
