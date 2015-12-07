//
// Created by Zeka on 12/5/2015.
//

#ifndef MATRIXALGORITHMS_STRASSENMATRIXMULTIPLICATION_H
#define MATRIXALGORITHMS_STRASSENMATRIXMULTIPLICATION_H

#include "BaseMatrixMultiplication.h"

template <typename T>
class StrassenMatrixMultiplication: public BaseMatrixMultiplication<T> {
public:
    virtual Matrix<T> multiply(Matrix<T> const &A, Matrix<T> const &B) override;
};


#endif //MATRIXALGORITHMS_STRASSENMATRIXMULTIPLICATION_H
