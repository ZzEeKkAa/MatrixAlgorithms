cmake_minimum_required(VERSION 3.3)
project(MatrixAlgorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("./" "Multiplication/" "LinearEquations")

set(HEADERS Matrix.h Multiplication/MatrixMultiplication.h Multiplication/BaseMatrixMultiplication.h)
set(SOURCE_FILES main.cpp Multiplication/WinogradMatrixMultiplication.h JacobiMethod.h LinearEquations/GramSchmidtProcess.h LinearEquations/QRDecomposition.h Vector.h LinearEquations/LinearEquationSolver.h LinearEquations/QRLinearEquationSolver.h)
add_executable(MatrixAlgorithms ${SOURCE_FILES})