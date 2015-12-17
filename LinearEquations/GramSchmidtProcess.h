//
// Created by Zeka on 12/17/2015.
//

#ifndef MATRIXALGORITHMS_GRAMSCHMIDTPROCESS_H
#define MATRIXALGORITHMS_GRAMSCHMIDTPROCESS_H


#include "QRDecomposition.h"

template <typename T>
class GramSchmidtProcess: public QRDecomposition<T> {

public:
    virtual void decompose(Matrix<T> const &A) override{
        if(A.getM()!=A.getN()){
            Matrix<T>();
        }
        const int n = A.getM();
        Q=A;
        R=Matrix<T>(n,n);
        for(int i=0; i<n; ++i){

        }
    }
};


#endif //MATRIXALGORITHMS_GRAMSCHMIDTPROCESS_H

