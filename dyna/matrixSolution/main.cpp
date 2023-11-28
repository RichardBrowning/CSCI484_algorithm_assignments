#include <iostream>
#include "Matrix.h"
#include "MatrixChain.h"

int main() {
    // Example usage
    Matrix* matrices = new Matrix[4]{{30, 1}, {1, 40}, {40, 10}, {10, 25}};
    int size = sizeof(matrices) / sizeof(matrices[0]);
    //MatrixChain matrixChain(matrices, n);
    if (size > 10) std::cout << "Warning: More than 10 matrices inputted, only the first 10 matrices will be considered" << std::endl;
    MatrixChain matrixChain(matrices, size);
    matrixChain.solve();
    // Destruct matrixChain
    matrixChain.~MatrixChain();
    delete[] matrices;
    return 0;
}



