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
    virtual Matrix<T> multiply(Matrix<T> const &A, Matrix<T> const &B) override{
        Matrix<T> C(0,0);
        if(A.getN() != B.getM()) return C;
        C.setN(B.getN());
        C.setM(A.getM());
        for(int i=0; i< C.getM(); ++i){
            for(int j=0; j< C.getN(); ++j){
                for(int k=0; k< A.getN(); ++k){
                    C(i,j)+=A(i,k)*B(k,j);
                }
            }
        }
        return C;
    }
};


#endif //MATRIXALGORITHMS_BASEMATRIXMULTIPLICATION_H
