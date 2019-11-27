cmake_minimum_required(VERSION 3.15)
project(infix_to_polish_notation)

set(CMAKE_CXX_STANDARD 14)

add_executable(infix_to_polish ../../../structures/helpers/ExpressionAnalyzer.cpp infix_to_polish.cpp)