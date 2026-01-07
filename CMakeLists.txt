cmake_minimum_required(VERSION 4.0)
project(phone_book)

set(CMAKE_CXX_STANDARD 17)

add_executable(phone_book
        src/main.cpp
        src/texts.h
        src/menus/menus.h
        src/menus/query_menu.cpp
        src/menus/modify_menu.cpp
        src/menus/saveload_menu.cpp
        src/phone_book/phone_book.h
        src/phone_book/phone_book.cpp
        src/cli/cli.h
)

target_include_directories(phone_book PRIVATE src)