//
// Created by Zeka on 12/16/2015.
//

#ifndef MATRIXALGORITHMS_JACOBIMETHOD_H
#define MATRIXALGORITHMS_JACOBIMETHOD_H

#include "Matrix.h"
#include <cmath>

template <typename T>
Matrix<T> JacobiMethod(Matrix<T> const & A){
    if(A.getM()!=A.getN()) return Matrix<T>();
    if(A.getN()<2) return A;


    int k=0;
    double t;
    double fi;
    double eps = 1e-10;
    T tmp;
    Matrix<T> Ak(A),Uk(A.getM(),A.getN());

    for(int i=0; i<Uk.getN(); ++i) Uk(i,i)=1;

    int p,q;

    while(true) {
        p=0,q=1;
        for (int i = 0; i < Ak.getM(); ++i)
            for (int j = i + 1; j < Ak.getN(); ++j)
                if ( fabs(Ak(i, j)) > fabs(Ak(p, q))) p = i, q = j;

        if (fabs(Ak(p,q))<eps) break;

        t = (Ak(q, q) - Ak(p, p)) / 2. / Ak(p, q);
        fi = atan(0.5 / t);


        Uk(p, q) = sin(fi);
        Uk(q, p) = -sin(fi);
        Uk(p, p) = Uk(q, q) = cos(fi);

        Ak = Ak * Uk;

        tmp = Uk(p, q);
        Uk(p, q) = Uk(q, p);
        Uk(q, p) = tmp;

        Ak = Uk * Ak;

        Uk(p, q) = Uk(q, p) = 0;
        Uk(p, p) = Uk(q, q) = 1;
    }

    return Ak;

}


#endif //MATRIXALGORITHMS_JACOBIMETHOD_H
