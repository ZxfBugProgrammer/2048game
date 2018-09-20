cmake_minimum_required(VERSION 3.8)
project(2048game)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES 2048.cpp Control.cpp)
add_executable(2048game ${SOURCE_FILES})