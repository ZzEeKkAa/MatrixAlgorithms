//
// Created by Zeka on 12/17/2015.
//

#ifndef MATRIXALGORITHMS_QRDECOMPOSITION_H
#define MATRIXALGORITHMS_QRDECOMPOSITION_H

#include "Matrix.h"

template <typename T>
class QRDecomposition {
protected:
    Matrix<T> Q,R;
public:
    virtual void decompose(Matrix<T> const & A)=0;
    Matrix<T> getQ(){ return Q; }
    Matrix<T> getR(){ return R; }

};


#endif //MATRIXALGORITHMS_QRDECOMPOSITION_H
