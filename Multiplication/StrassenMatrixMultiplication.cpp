//
// Created by Zeka on 12/5/2015.
//

#include <iostream>
#include "StrassenMatrixMultiplication.h"

template <typename T>
Matrix<T> StrassenMatrixMultiplication<T>::multiply(Matrix<T> const &A, Matrix<T> const &B) {
    Matrix<T> C(0,0);

    //std::cout<<"HERE!!!!!!!"<<std::endl;
    //std::cout<<A<<std::endl<<B<<"-----------------------------"<<std::endl;

    if(A.getM() != B.getN() || A.getN() != B.getM()) return C;
    //std::cout<<"Again"<<std::endl;
    //std::cout<<A.getM()<<"x"<<A.getN()<<std::endl;
    if(A.getN()<=1) {return BaseMatrixMultiplication<T>::multiply(A,B); }
    //std::cout<<"Again"<<std::endl;

    int n=A.getN()+1>>1;
    int m=A.getM()+1>>1;

    //std::cout<<m<<"x"<<n<<std::endl;

    Matrix<T> A11(m,n), A12(m,n), A21(m,n), A22(m,n);
    Matrix<T> B11(n,m), B12(n,m), B21(n,m), B22(n,m);

    //std::cout<<"Dividing.."<<std::endl;
    for(int i=0; i<m; ++i) {
        for (int j = 0; j < n; ++j) {
            //std::cout << i << "," << j << ":" << A(i, j) << std::endl;
            A11(i, j) = A(i, j);     B11(j, i) = B(j, i);
            A12(i, j) = A(i, j+n);   B21(j, i) = B(j+n,i);
            A21(i, j) = A(i+m, j);   B12(j, i) = B(j,i+m);
            A22(i, j) = A(i+m, j+n); B22(j, i) = B(j+n,i+m);
        }
        //std::cout<<i<<std::endl;
    }

    //std::cout<<"11,12,21,22:"<<std::endl;
    //std::cout<<A11<<A12<<A21<<A22<<std::endl;
    //std::cout<<B11<<B12<<B21<<B22<<std::endl;


    Matrix<T> P1,P2,P3,P4,P5,P6,P7;

    P1 = multiply(A11+A22,B11+B22);
    P2 = multiply(A21+A22,B11);
    P3 = multiply(A11,B12-B22);
    P4 = multiply(A22,B21-B11);
    P5 = multiply(A11+A12,B22);
    P6 = multiply(A21-A11,B11+B12);
    P7 = multiply(A12-A22,B21+B22);

    Matrix<T> C11,C12,C21,C22;

    //std::cout<<"Adding results..."<<std::endl;

    /*C11 = P1+P4-P5+P7;
    C12 = P3+P5;
    C21 = P2+P4;
    C22 = P1-P2+P3+P6;*/

    C11 = multiply(A11,B11)+multiply(A12,B21);
    C21 = multiply(A21,B11)+multiply(A22,B21);
    C12 = multiply(A11,B12)+multiply(A12,B22);
    C22 = multiply(A21,B12)+multiply(A22,B22);


    //std::cout<<C11<<C12<<C21<<C22<<std::endl;

   // std::cout<<"Computing result"<<std::endl;

    C.setN(2*m);
    C.setM(2*m);
    for(int i=0; i<m; ++i)
        for(int j=0; j<m; ++j) {
            C(i, j) =     C11(i, j);
            C(i, j+m) =   C12(i, j);
            C(i+m, j) =   C21(i, j);
            C(i+m, j+m) = C22(i, j);
        }

    //std::cout<<"Resizing..."<<std::endl;

    C.setM(A.getM());
    C.setN(A.getM());

    return C;
}

template class StrassenMatrixMultiplication<int>;
