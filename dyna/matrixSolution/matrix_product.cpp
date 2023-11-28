#include <iostream>
#include <climits>
#include "Matrix.h"
#include "MatrixChain.h"

int main() {
    // Example usage
    Matrix matrices[] = { {5, 4}, {4, 6}, {6, 2}, {2, 7} };
    int n = sizeof(matrices) / sizeof(matrices[0]);
    MatrixChain matrixChain(matrices, n);
    if (n > 10) std::cout << "Warning: More than 10 matrices inputted, only the first 10 matrices will be considered" << std::endl;


    return 0;
}



