cmake_minimum_required(VERSION 3.5)
project(code)

set(CMAKE_CXX_STANDARD 14)

add_executable(code main.cpp id.hpp base.hpp if.hpp ex.hpp wb.hpp mem.hpp)
