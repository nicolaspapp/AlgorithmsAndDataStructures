cmake_minimum_required(VERSION 3.15)
project(.)

set(CMAKE_CXX_STANDARD 14)

file(GLOB header_files
            "structures/*/*.h"
)

file(GLOB library_files
            "structures/*/*.cpp"
)

add_executable(lists_1 ${header_files} ${library_files} programs/lists/lists_1.cpp)
add_executable(lists_2 ${header_files} ${library_files} programs/lists/lists_2.cpp)
add_executable(stack_1 ${header_files} ${library_files} programs/stacks/stack_1.cpp)
add_executable(stack_2 ${header_files} ${library_files} programs/stacks/stack_2.cpp)
add_executable(stack_3 ${header_files} ${library_files} programs/stacks/stack_3.cpp)
add_executable(infix_to_polish_notation ${header_files} ${library_files} programs/stacks/infix_to_polish.cpp)