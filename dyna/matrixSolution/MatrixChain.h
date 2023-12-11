#pragma once
#include <vector>
#include "Matrix.h"
class MatrixChain {
    private:
        std::vector<Matrix*> *matricesPtr = nullptr;
        int matrixMultiplicationCount[10][10] = {};
    public:
        MatrixChain(std::vector<Matrix*> *matrices){
            this->matricesPtr = matrices;
        }

        ~MatrixChain(){
            delete[] this->matricesPtr;
        }

        int solve(){
            // get P's
            int P[11] = {};
            P[0] = this->matricesPtr->at(0)->rows;
            for (int i = 0; i < this->matricesPtr->size(); i++){
                P[i+1] = this->matricesPtr->at(i)->cols;
            }
            //debug output
            // for (int i = 0; i <= this->matricesPtr->size(); i++){
            //     std::cout << P[i] << std::endl;
            // }

            for (int k = 1; k < this->matricesPtr->size(); k++){
                for (int i = 0; i < this->matricesPtr->size(); i++){
                    if (i + k >= this->matricesPtr->size()) break;
                    matrixMultiplicationCount[i][i+k] = matrixMultiplicationCount[i][i] + matrixMultiplicationCount[i+1][i+k] + P[i] * P[i+1] * P[i+k+1];
                    for (int j = i + 1; j < i + k; j++){
                        int temp = matrixMultiplicationCount[i][j] + matrixMultiplicationCount[j+1][i+k] + P[i] * P[j+1] * P[i+k+1];
                        if (temp < matrixMultiplicationCount[i][i+k]) matrixMultiplicationCount[i][i+k] = temp;
                    }
                }
            }
            return matrixMultiplicationCount[0][this->matricesPtr->size()-1];
        }

        void print_matrixMulCount(){
            for (int i = 0; i < this->matricesPtr->size(); i++){
                for (int j = 0; j < this->matricesPtr->size(); j++){
                    std::cout << matrixMultiplicationCount[i][j] << "\t";
                }
                std::cout << std::endl;
            }
            std::cout << "The minimal number of multiplications is " << matrixMultiplicationCount[0][this->matricesPtr->size()-1] << std::endl;
        }
};