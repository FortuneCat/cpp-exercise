cmake_minimum_required(VERSION 3.12)
project(cpp_exercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_exercise main.cpp math/equationsolution.cpp math/equationsolution.h math/matrix.cpp math/matrix.h stringexercise.cpp stringexercise.h quiz/hanoi.cpp quiz/hanoi.h quiz/knight.cpp quiz/knight.h datastructure/tree.cpp datastructure/tree.h template/complex.cpp template/complex.h)