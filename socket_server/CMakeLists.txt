cmake_minimum_required(VERSION 3.10)
project(my_socket)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_socket main.cpp serever.h serever.cpp)