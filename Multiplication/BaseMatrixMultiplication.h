//
// Created by Zeka on 12/5/2015.
//
#ifndef MATRIXALGORITHMS_BASEMATRIXMULTIPLICATION_H
#define MATRIXALGORITHMS_BASEMATRIXMULTIPLICATION_H
template <typename T>
class BaseMatrixMultiplication;

#include "MatrixMultiplication.h"

template <typename T>
class BaseMatrixMultiplication: public MatrixMultiplication<T> {
public:
    virtual Matrix<T> multiply(Matrix<T> const &A, Matrix<T> const &B) override;
};


#endif //MATRIXALGORITHMS_BASEMATRIXMULTIPLICATION_H
