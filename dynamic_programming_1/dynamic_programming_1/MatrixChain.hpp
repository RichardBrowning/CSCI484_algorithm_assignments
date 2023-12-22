#pragma once
#include <vector>
#include <string>
#include "Matrix.hpp"
class MatrixChain {
private:
    std::vector<Matrix>* matrices = new std::vector<Matrix>();
    int matrixMultiplicationCount[10][10] = { 0 };
    int P[11] = {};
public:
    MatrixChain(std::vector<Matrix>* matrices) {
        *this->matrices = *matrices;
        P[0] = this->matrices->at(0).rows;
        for (int i = 0; i < this->matrices->size(); i++) {
            P[i + 1] = this->matrices->at(i).cols;
        }
    }

    ~MatrixChain() {
        delete this->matrices;
    }

    int solve() {
        //debug output
        // for (int i = 0; i <=this->matrices->size(); i++){
        //     std::cout << P[i] << std::endl;
        // }

        for (int i = 1; i < this->matrices->size(); i++) {
            for (int j = 0; j < this->matrices->size(); j++) {
                if (i + j >= this->matrices->size()) break;
                matrixMultiplicationCount[j][i + j] = matrixMultiplicationCount[j][j] + matrixMultiplicationCount[j + 1][i + j] + P[j] * P[j + 1] * P[i + j + 1];
                for (int k = j + 1; k < i + j; k++) {
                    int temp = matrixMultiplicationCount[j][k] + matrixMultiplicationCount[k + 1][i + j] + P[j] * P[k + 1] * P[i + j + 1];
                    if (temp < matrixMultiplicationCount[j][i + j]) {
                        matrixMultiplicationCount[j][i + j] = temp;
                    }
                }
            }
        }
        return matrixMultiplicationCount[0][this->matrices->size() - 1];
    }

    void print_matrixMulCount() {
        for (int i = 0; i < this->matrices->size(); i++) {
            for (int j = 0; j < this->matrices->size(); j++) {
                std::cout << matrixMultiplicationCount[i][j] << "\t";
            }
            std::cout << std::endl;
        }
        std::cout << "The minimal number of multiplications is " << matrixMultiplicationCount[0][this->matrices->size() - 1] << std::endl;

    }
};