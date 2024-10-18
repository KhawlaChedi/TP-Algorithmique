cmake_minimum_required(VERSION 3.29)
project(Exercice_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Exercice_2
        main.cpp
    DivSeq.cpp
    DivSeq.h)
