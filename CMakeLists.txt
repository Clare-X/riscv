cmake_minimum_required(VERSION 3.13)
project(book)

set(CMAKE_CXX_STANDARD 14)

add_executable(book main.cpp users.cpp users.h database.cpp database.h order.cpp order.h)