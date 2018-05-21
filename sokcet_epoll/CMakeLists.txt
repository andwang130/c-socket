cmake_minimum_required(VERSION 3.10)
project(sokcet_epoll)

set(CMAKE_CXX_STANDARD 11)

add_executable(sokcet_epoll main.cpp epoll_sereve.h epoll_server.cpp)