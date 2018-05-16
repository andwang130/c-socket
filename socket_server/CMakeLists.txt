cmake_minimum_required(VERSION 3.10)
project(my_socket)

set(CMAKE_CXX_STANDARD 11)

add_executable(my_socket main.cpp serever.h serever.cpp)
find_package(Threads REQUIRED)
target_link_libraries(my_socket Threads::Threads)