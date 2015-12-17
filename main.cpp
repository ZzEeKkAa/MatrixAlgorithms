#include <bits/stdc++.h>
#include "StrassenMatrixMultiplication.h"
#include "Matrix.h"
#include "JordanInverseMatrix.h"
#include "WinogradMatrixMultiplication.h"
#include "JacobiMethod.h"

using namespace std;


int main() {
    freopen("C:\\Users\\Zeka\\ClionProjects\\MatrixAlgorithms\\input.txt","r",stdin);
    Matrix<double> a,b;
    cin>>a>>b;
    cout<<a*b<<endl;
    cout<<"strating..."<<endl;

    Matrix<double> A(3,2), B(2,3), C;
    A(0,0) = 1; A(0,1) = 0;
    A(1,0) = 3; A(1,1) = -2;
    A(2,0) = 0; A(2,1) = 1;

    B(0,0) = 5; B(0,1) = 1; B(0,2) = 1;  //B(0,3) = -1;
    B(1,0) = 0; B(1,1) = -3; B(1,2) = 3; //B(1,3) = 1;

    /*Matrix<int> A(1,2), B(2,3), C;

    A(0,0) = 1; A(0,1) = 2;

    B(0,0) = 3; B(0,1) = 5; B(0,2) = 7;
    B(1,0) = 4; B(1,1) = 6; B(1,2) = 8;*/

    cout<<"Base multiplication: "<<endl<<A*B<<endl;

    Matrix<double>::setDefaultMultiplication(new StrassenMatrixMultiplication<double>());
    cout<<"Strassen multiplication: "<<endl<<A*B<<endl;

    Matrix<double>::setDefaultMultiplication(new WinogradMatrixMultiplication<double>());
    cout<<"Winograd multiplication: "<<endl<<A*B<<endl;

    Matrix<double> K(3,3);
    K(0,0) = 10; K(0,1) = 5;  K(0,2) = 6;
    K(1,0) = 5;  K(1,1) = 20; K(1,2) = 4;
    K(2,0) = 6;  K(2,1) = 4;  K(2,2) = 30;

    cout<<"Jacobi:"<<endl<<K<<endl<<~K<<endl;

    /*Matrix<double> K(2,2);
    K(0,0) = 1; K(0,1) = 2;
    K(1,0) = 3; K(1,1) = 4;


    auto K1 = getInverseMatrixByJordan(K);
    cout<<"A:"<<endl<<K<<endl;
    cout<<"A^-1:"<<endl<<K1<<endl;

    cout<<"A*A^-1 = "<<endl<<K*K1<<endl;
    cout<<"A^-1*A = "<<endl<<K1*K<<endl;
/**/
    return 0;
}