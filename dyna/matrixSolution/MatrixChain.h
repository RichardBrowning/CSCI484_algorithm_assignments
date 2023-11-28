#pragma once
#include "Matrix.h"
class MatrixChain {
    private:
        int nMatrices = 0;
        Matrix matrices[10];
        int matrixMultiplicationCount[10][10] = {};

    public:
        MatrixChain(Matrix matrices[], int nMatrices);
        int solve();
};