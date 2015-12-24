//
// Created by Zeka on 12/20/2015.
//

#ifndef MATRIXALGORITHMS_HOUSEHOLDERREFLECTIONS_H
#define MATRIXALGORITHMS_HOUSEHOLDERREFLECTIONS_H

#include "QRDecomposition.h"

template <typename T>
class HouseholderReflections:public QRDecomposition<T> {

public:
    virtual void decompose(Matrix<T> const &A) override{

    }
};


#endif //MATRIXALGORITHMS_HOUSEHOLDERREFLECTIONS_H