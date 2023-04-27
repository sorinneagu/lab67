cmake_minimum_required(VERSION 3.24)
project(Problem1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Problem1
        Circle.cpp
        Circle.h
        main.cpp
        Shape.cpp
        Shape.h
        Square.cpp
        Square.h)
