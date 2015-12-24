//
// Created by Zeka on 12/17/2015.
//

#ifndef MATRIXALGORITHMS_LINEAREQUATIONSOLVER_H
#define MATRIXALGORITHMS_LINEAREQUATIONSOLVER_H

#include "Matrix.h"
#include "Vector.h"

template <typename T>
class LinearEquationSolver {
public:
    virtual Vector<T> solve(AugmentedMatrix<T> const & A)=0;
};


#endif //MATRIXALGORITHMS_LINEAREQUATIONSOLVER_H
