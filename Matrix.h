//
// Created by Zeka on 12/5/2015.
//

#ifndef MATRIXALGORITHMS_MATRIX_H
#define MATRIXALGORITHMS_MATRIX_H
template <typename T>
class Matrix;

#include "MatrixMultiplication.h"
#include "BaseMatrixMultiplication.h"
#include <vector>
#include <istream>
#include <ostream>

template <typename T>
class Matrix {
private:
    int m, n;
    std::vector<std::vector<T> > matrix;
    static MatrixMultiplication<T>* multiplication;
public:
    Matrix(int m=0, int n=0);
    Matrix(const std::vector<std::vector<T> > &matrix) : matrix(matrix) { }

    int getM() const;
    void setM(int m);
    int getN() const;
    void setN(int n);

    static void setDefaultMultiplication(MatrixMultiplication<T>*);
    Matrix<T> operator*(const Matrix<T>& A) const;
    T& operator()(int m, int n);
    T operator()(int m, int n) const;
    Matrix<T> operator=(const Matrix<T>& A);
    Matrix<T> operator+(const Matrix<T>& A) const;
    Matrix<T> operator-(const Matrix<T>& A) const;
    template <typename T0>
    friend std::ostream& operator<<(std::ostream& out, Matrix<T0>const &A);
    template <typename T0>
    friend std::istream& operator>>(std::istream& in, Matrix<T0> &A);

};


#endif //MATRIXALGORITHMS_MATRIX_H
