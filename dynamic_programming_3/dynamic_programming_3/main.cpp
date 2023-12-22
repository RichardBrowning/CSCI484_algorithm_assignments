#include <iostream>
#include <vector>
#include "MatrixChain.hpp"

int main() {
    // Example usage
    std::vector<Matrix>* matrices = new std::vector<Matrix>{
        Matrix(10, 17),
        Matrix(17, 12),
        Matrix(12, 25),
        Matrix(25, 14),
        Matrix(14, 30),
        Matrix(30, 15),
        Matrix(15, 9),
    };

    int size = matrices->size();
    std::cout << size << std::endl;
    //MatrixChain matrixChain(matrices, n);
    if (size > 10) std::cout << "Warning: More than 10 matrices inputted, only the first 10 matrices will be considered" << std::endl;
    MatrixChain matrixChain(matrices, size);
    matrixChain.solve();
    matrixChain.print_matrixMulCount();

    // Delete matrices
    delete matrices;

    return 0;
}



