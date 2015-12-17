//
// Created by Zeka on 12/13/2015.
//

#ifndef MATRIXALGORITHMS_JORDANINVERSEMATRIX_H
#define MATRIXALGORITHMS_JORDANINVERSEMATRIX_H

#include "Matrix.h"
#include <iostream>

template <typename T>
Matrix<T> getInverseMatrixByJordan(Matrix<T> const& A){
    Matrix<T> C;
    if(A.getN()!=A.getM()) return C;
    const int n=A.getN();
    const int nn=n<<1;

    Matrix<T> M(A);

    M.setN(nn);
    for(int i=0; i<n; ++i){
        M(i,n+i)=1;
    }

    //std::cout<<"Big:\n"<<M<<std::endl;

    bool found;
    for(int i=0; i<n; ++i) { // row+column
        found=false;
        for(int j=i; j<n; ++j){ // row
            if(M(j,i)!=0) {
                found=true;
                M.swapRows(i,j);
                break;
            }
        }

        if(!found) return C;

        //std::cout<<"M(i,i) = "<<M(i,i)<<std::endl;
        //const T t = ;
        for(int j=nn-1; j>=i; --j){
            M(i,j)/=M(i,i);
        }

        for(int j=i+1; j<n; ++j)
            for(int k=nn-1; k>=i; --k){
                M(j,k)-=M(i,k)*M(j,i);
            }

        //std::cout<<"TMP:\n"<<M<<std::endl;

    }

    //std::cout<<"Big:\n"<<M<<std::endl;

    for(int i=n-1; i>=0; --i){  // row+column
        for(int j=0; j<i; ++j){ // row
            for(int k=nn-1; k>=i; --k){
                M(j,k)-=M(i,k)*M(j,i);
            }
        }
    }

    //std::cout<<"Big:\n"<<M<<std::endl;

    C.setM(n);
    C.setN(n);

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            C(i,j)=M(i,j+n);
        }
    }

    return C;

}


#endif //MATRIXALGORITHMS_JORDANINVERSEMATRIX_H
