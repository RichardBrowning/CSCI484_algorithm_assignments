#include <iostream>
#include <vector>
#include "Matrix.h"
#include "MatrixChain.h"

int main() {
    // Example usage
    std::vector<Matrix> *matrices = new std::vector<Matrix>{
        Matrix(30, 1),
        Matrix(1, 40),
        Matrix(40, 10),
        Matrix(10, 25)
    };
    
    int size = matrices->size();
    //MatrixChain matrixChain(matrices, n);
    if (size > 10) std::cout << "Warning: More than 10 matrices inputted, only the first 10 matrices will be considered" << std::endl;
    MatrixChain matrixChain(matrices);
    matrixChain.solve();
    matrixChain.print_matrixMulCount();
    // Destruct matrixChain
    //matrixChain.~MatrixChain();
    
    // Delete matrices
    delete matrices;
    
    return 0;
}



