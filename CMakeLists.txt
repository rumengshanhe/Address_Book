cmake_minimum_required(VERSION 3.17)
project(telephone_book)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(telephone_book
        main.cpp
        mytelephonebook
        telephone_Book.cpp
        telephone_Book.h)
