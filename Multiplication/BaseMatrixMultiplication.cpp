//
// Created by Zeka on 12/5/2015.
//
#include "BaseMatrixMultiplication.h"

template <typename T>
Matrix<T> BaseMatrixMultiplication<T>::multiply(Matrix<T> const &A, Matrix<T> const &B) {
    Matrix<T> C(0,0);
    if(A.getM() != B.getN() || A.getN() != B.getM()) return C;
    C.setN(A.getM());
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

template class BaseMatrixMultiplication<int>;
