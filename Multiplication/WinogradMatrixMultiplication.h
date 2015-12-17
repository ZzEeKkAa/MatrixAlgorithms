//
// Created by Zeka on 12/16/2015.
//

#ifndef MATRIXALGORITHMS_WINOGRADMATRIXMULTIPLICATION_H
#define MATRIXALGORITHMS_WINOGRADMATRIXMULTIPLICATION_H

#include "BaseMatrixMultiplication.h"

template <typename T>
class WinogradMatrixMultiplication: public BaseMatrixMultiplication<T> {

public:
    virtual Matrix<T> multiply(Matrix<T> const &A, Matrix<T> const &B) override{
        Matrix<T> C(0,0);
        if(A.getN() != B.getM()) return C;
        C.setM(A.getM());
        C.setN(B.getN());

        int n2 = (A.getN())+1>>1;

        std::vector<T> Ai(A.getM(),0),Bj(B.getN(),0);

        for(int i=0; i<A.getM(); ++i)
            for (int k = 0; k < n2; ++k)
                Ai[i] += A(i, 2 * k) * A(i, 2 * k+1);

        for(int j=0; j<B.getN(); ++j)
            for (int k = 0; k < n2; ++k)
                Bj[j] += B(2 * k,j) * B(2 * k+1,j);

        for(int i=0; i<A.getM(); ++i) {
            for (int j = 0; j < B.getN(); ++j) {
                C(i, j) = -Ai[i] - Bj[j];
                for (int k = 0; k < n2; ++k) {
                    C(i, j) += (A(i, 2 * k) + B(2 * k + 1, j)) * (A(i, 2 * k + 1) + B(2 * k, j));
                }
            }
        }

        return C;
    }
};


#endif //MATRIXALGORITHMS_WINOGRADMATRIXMULTIPLICATION_H
