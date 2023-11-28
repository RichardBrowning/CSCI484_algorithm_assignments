#pragma once
#include "Matrix.h"
class MatrixChain {
    private:
        int nMatrices = 0;
        Matrix* matricesPtr = nullptr;
        int matrixMultiplicationCount[10][10] = {};

    public:
        MatrixChain(Matrix* matrices, int nMatrices){
            this->nMatrices = nMatrices;
            this->matricesPtr = matrices;
        }

        ~MatrixChain(){
            delete[] this->matricesPtr;
        }

        int solve(){
            // get P's
            int P[11] = {};
            P[0] = this->matricesPtr[0].rows;
            for (int i = 1; i < this->nMatrices; i++){
                P[i] = this->matricesPtr[i].cols;
            }
            for (int i = 0; i <= this->nMatrices; i++){
                std::cout << P[i] << std::endl;
            }
            return 0;
        }
};