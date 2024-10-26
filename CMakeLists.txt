cmake_minimum_required(VERSION 3.29)
project(skiplist)

set(CMAKE_CXX_STANDARD 23)

set(INCLUDE_DIR
    ${CMAKE_SOURCE_DIR}
)

add_executable(skiplist
        main.cpp
)
