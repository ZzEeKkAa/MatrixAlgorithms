//
// Created by Zeka on 12/17/2015.
//

#ifndef MATRIXALGORITHMS_GRAMSCHMIDTPROCESS_H
#define MATRIXALGORITHMS_GRAMSCHMIDTPROCESS_H


#include <math.h>
#include "QRDecomposition.h"

template <typename T>
class GramSchmidtProcess: public QRDecomposition<T> {

public:
    virtual void decompose(Matrix<T> const &A) override{
        if(A.getM()!=A.getN()){
            Matrix<T>();
        }
        const int n = A.getM();

        std::vector<Vector<T> > q;
        for(int i=0; i<n; ++i)
            q.push_back(A.getColumn(i));
        this->R=Matrix<T>(n,n);

        std::cout<<q[0]/norm(q[0])<<std::endl;

        for(int i=0; i<n; ++i){
            for(int j=0; j<i; ++j){
                q[i]-=project(q[j],q[i]);
            }
        }

        this->Q.setM(n);
        this->Q.setN(n);
        for(int i=0; i<n; ++i) this->Q.setColumn(i,q[i]/norm(q[i]));
        this->R=transpose(this->Q)*A;
    }
};


#endif //MATRIXALGORITHMS_GRAMSCHMIDTPROCESS_H

