cmake_minimum_required(VERSION 3.3)
project(MatrixAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("Multiplication/" "./")

set(HEADERS Matrix.h Multiplication/MatrixMultiplication.h Multiplication/BaseMatrixMultiplication.h)
set(SOURCE_FILES main.cpp Matrix.cpp Multiplication/BaseMatrixMultiplication.cpp Multiplication/StrassenMatrixMultiplication.cpp Multiplication/StrassenMatrixMultiplication.h)
add_executable(MatrixAlgorithms ${SOURCE_FILES})