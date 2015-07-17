cmake_minimum_required(VERSION 3.2)
project(only2d)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

if(MINGW)
    add_definitions("-DSDL_MAIN_HANDLED")
endif()

if(APPLE)
    include_directories(/usr/local/include)
endif()

add_subdirectory(only2d)
add_subdirectory(only2d_lua)
add_subdirectory(sample)