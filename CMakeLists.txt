cmake_minimum_required(VERSION 3.13)
project(bookstore)

set(CMAKE_CXX_STANDARD 14)

add_executable(book main.cpp users.cpp users.h database.cpp database.h
        order.cpp order.h books.cpp books.h finance.cpp finance.h dataB.cpp dataB.h)