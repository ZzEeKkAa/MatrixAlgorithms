#include <bits/stdc++.h>
#include "StrassenMatrixMultiplication.h"
#include "Matrix.h"

using namespace std;


int main() {
    //freopen("input.txt","r",stdin);
    //Matrix<int> a,b;
    //int k;
    //cin>>k; cout<<k<<endl;
    //cin>>a>>b;
    //cout<<a*b<<endl;
    cout<<"strating..."<<endl;

    Matrix<int> A(3,2), B(2,3), C;

    A(0,0) = 1; A(0,1) = 0;
    A(1,0) = 3; A(1,1) = -2;
    A(2,0) = 0; A(2,1) = 1;

    B(0,0) = 5; B(0,1) = 1; B(0,2) = 1;
    B(1,0) = 0; B(1,1) = -3; B(1,2) = 3;


    C=A*B;
/*
    Matrix<int>::setDefaultMultiplication(new StrassenMatrixMultiplication<int>());

    cout<<A<<endl;
    cout<<B<<endl;
    cout<<C<<endl;
    cout<<endl;

    Matrix<int> C1 = A*B;
    cout<<"result:"<<endl;
    cout<<C1<<endl;
*/
    return 0;
}