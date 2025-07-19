cmake_minimum_required(VERSION 3.10)
project(phone_book)

set(CMAKE_C_STANDARD 99)

include_directories(includes)

add_executable(phone_book
    phone_book.c
    modules/contacts.c
    modules/exit_main_menu.c
    modules/func_to_add.c
    modules/input_utils.c
    modules/opening_files.c
    modules/validity_func.c
)