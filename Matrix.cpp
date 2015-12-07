//
// Created by Zeka on 12/5/2015.
//

#include <string>
#include <sstream>
#include "Matrix.h"
#include "BaseMatrixMultiplication.h"

template <typename T>
MatrixMultiplication<T>* Matrix<T>::multiplication = new BaseMatrixMultiplication<T>();

template <typename T>
int Matrix<T>::getM() const {
    return m;
}

template <typename T>
void Matrix<T>::setM(int m) {
    Matrix::m = m;
    matrix.resize(m, std::vector<T>(n, 0));
}

template <typename T>
int Matrix<T>::getN() const {
    return n;
}

template <typename T>
void Matrix<T>::setN(int n) {
    Matrix::n = n;
    for(int i=0; i < m; ++i)
        matrix[i].resize(n, 0);
}

template <typename T>
void Matrix<T>::setDefaultMultiplication(MatrixMultiplication<T> *multiplication) {
    delete Matrix::multiplication;
    Matrix::multiplication = multiplication;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix<T>& A) const {
    return multiplication->multiply(*this,A);
}

template <typename T>
T &Matrix<T>::operator()(int m, int n) {
    return matrix[m][n];
}

template <typename T>
T Matrix<T>::operator()(int m, int n) const {
    if(m>=matrix.size()) return 0;
    if(n>=matrix[m].size()) return 0;
    return matrix[m][n];
}

template <typename T>
Matrix<T> Matrix<T>::operator=(const Matrix<T> &A) {
    Matrix::m = A.m;
    Matrix::n = A.n;
    for(auto& item: matrix)
        item.resize(n,0);
    matrix.resize(m,std::vector<T>(n,0));
    for(int i=0; i<m; ++i)
        for(int j=0; j<n; ++j)
            matrix[i][j] = A(i,j);
    return *this;
}

template <typename T>
Matrix<T>::Matrix (int m, int n) : m(m), n(n) {
    Matrix::n=n;
    Matrix::m=m;
    matrix.assign(m,std::vector<T>(n,0));
};

template <typename T>
std::ostream& operator<<(std::ostream& out, Matrix<T>const &A){
    for(int i=0; i<A.m; ++i){
        for(int j=0; j<A.n; ++j){
            out.width(4);
            out<<A.matrix[i][j];
        }
        out<<std::endl;
    }
    return out;
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &A) const {
    Matrix C;
    if(n!=A.getN() || m!=A.getM()) return C;

    C=*this;
    for(int i=0; i<C.getM(); ++i)
        for(int j =0; j<C.getN(); ++j)
            C(i,j)+=A(i,j);

    return C;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &A) const {
    Matrix C;
    if(n!=A.getN() || m!=A.getM()) return C;

    C=*this;
    for(int i=0; i<C.getM(); ++i)
        for(int j =0; j<C.getN(); ++j)
            C(i,j)-=A(i,j);

    return C;
}


template<typename T>
std::istream &operator>>(std::istream &in, Matrix<T> &A) {
    std::string line;
    //std::stringstream ss;
    /*int n=1,m=0;
    A.setM(0);
    A.setN(0);
    while(n>0) {// while not null line
        /*std::getline(in, line);
        ss << line;

        T tmp;
        n=0;
        if(ss >> tmp) { // if line not null
            A.setM(m+1);
            do{
                if(A.getN()<=n){
                    A.setN(n+1);
                }
                A(n,m)=tmp;
                ++n;
            } while(ss >> tmp);
        }*/
    //}
    return in;
}


template std::ostream& operator<<(std::ostream& out, Matrix<int>const &A);
template std::istream& operator>>(std::istream& in, Matrix<int> &A);
template class Matrix<int>;
