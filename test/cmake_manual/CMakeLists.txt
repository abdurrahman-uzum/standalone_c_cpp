#add minimum tested version
cmake_minimum_required( VERSION 3.18.4 )

#project name and language
project( testproject LANGUAGES C )

#additional include directories
include_directories( ${CMAKE_SOURCE_DIR}/include/ )

#additional link directories
link_directories( ${CMAKE_SOURCE_DIR}/lib/ )


#Compiler options for warnings and errors
if ( CMAKE_C_COMPILER_ID STREQUAL "GNU" )

    add_compile_options( -Wall -Wextra -Werror -pedantic )

elseif( CMAKE_C_COMPILER_ID STREQUAL "MSVC" )

    add_compile_options( /W4 /WX )
endif()


# output directories
# set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)


# subdirectories containing source files
# main source directory is <src/> which will contain the sources to create libraries
# <test/> source directory will contain test related source files.
add_subdirectory(src/)
add_subdirectory(test/)

# add_executable( ${PROJECT_NAME} src/main.c src/test.c )

# target_include_directories( ${PROJECT_NAME} PUBLIC include )

