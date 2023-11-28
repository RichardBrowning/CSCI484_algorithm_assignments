#include "MatrixChain.h"

MatrixChain::MatrixChain(Matrix matrices[], int nMatrices) {
    MatrixChain::nMatrices = nMatrices;
    for (int i = 0; i < nMatrices; i++) {
        MatrixChain::matrices[i] = matrices[i];
    }
}