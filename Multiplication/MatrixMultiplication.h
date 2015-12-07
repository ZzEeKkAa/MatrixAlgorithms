//
// Created by Zeka on 12/5/2015.
//
#ifndef MATRIXALGORITHMS_MATRIXMULTIPLICATION_H
#define MATRIXALGORITHMS_MATRIXMULTIPLICATION_H
template<typename T>
class MatrixMultiplication;

#include "Matrix.h"

template<typename T>
class MatrixMultiplication {
public:
    virtual Matrix<T> multiply(Matrix<T> const&A, Matrix<T> const&B) = 0;
};

#endif //MATRIXALGORITHMS_MATRIXMULTIPLICATION_H