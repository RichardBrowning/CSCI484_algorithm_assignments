#include <iostream>
#include <vector>
#include "Matrix.h"
#include "MatrixChain.h"

int main() {
    // Example usage
    std::vector<Matrix*>* matrices = new std::vector<Matrix*>{
        new Matrix(10, 17),
        new Matrix(17, 12),
        new Matrix(12, 25),
        new Matrix(25, 14),
        new Matrix(14, 30),
        new Matrix(30, 15),
        new Matrix(15, 9),
    };

    int size = matrices->size();
    //MatrixChain matrixChain(matrices, n);
    if (size > 10) std::cout << "Warning: More than 10 matrices inputted, only the first 10 matrices will be considered" << std::endl;
    MatrixChain matrixChain(matrices);
    matrixChain.solve();
    matrixChain.print_matrixMulCount();
    // Destruct matrixChain
    matrixChain.~MatrixChain();

    // Delete matrices
    for (int i = 0; i < matrices->size(); i++) {
        delete matrices->at(i);
    }
    delete matrices;

    return 0;
}



