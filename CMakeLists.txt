cmake_minimum_required(VERSION 3.28)
project(Rubik_s_cube_solver)

set(CMAKE_CXX_STANDARD 17)

add_executable(Rubik_s_cube_solver main.cpp
        Model/RubiksCube.cpp
        Model/RubiksCube.h
        Model/RubiksCube3dArray.cpp
        Model/RubiksCube1dArray.cpp
        Model/RubiksCubeBitboard.cpp
        Solver/DFSSolver.h
        Solver/BFSSolver.h
        Solver/IDDFSSolver.h
        Solver/IDAstarSolver.h)
