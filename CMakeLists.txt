cmake_minimum_required(VERSION 4.0)
project(phone_book)

set(CMAKE_CXX_STANDARD 17)

add_executable(phone_book main.cpp
        phone_book.h
        phone_book.cpp
        cli.h
)
