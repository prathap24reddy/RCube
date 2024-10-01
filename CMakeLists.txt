cmake_minimum_required(VERSION 3.28)
project(Rubik_s_cube_solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rubik_s_cube_solver main.cpp
        GenericRubiksCube.cpp
        GenericRubiksCube.h
        cmake-build-debug/RubiksCube.cpp
        cmake-build-debug/RubiksCube.h)
