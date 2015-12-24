//
// Created by Zeka on 12/17/2015.
//

#ifndef MATRIXALGORITHMS_QRLINEAREQUATIONSOLVER_H
#define MATRIXALGORITHMS_QRLINEAREQUATIONSOLVER_H


#include "LinearEquationSolver.h"
#include "QRDecomposition.h"

template<typename T>
class QRLinearEquationSolver: public LinearEquationSolver<T> {
private:
    QRDecomposition<T>* decomposition;
public:
    QRLinearEquationSolver(QRDecomposition<T>* decomposition){
        QRLinearEquationSolver::decomposition=decomposition;
    }
    virtual Vector<T> solve(AugmentedMatrix<T> const &A) override{
        decomposition->decompose(A.getA());
        return ~decomposition->getR() * transpose(decomposition->getQ()) * A.getB();
    }
    virtual ~QRLinearEquationSolver(){
        delete decomposition;
    }
};


#endif //MATRIXALGORITHMS_QRLINEAREQUATIONSOLVER_H
