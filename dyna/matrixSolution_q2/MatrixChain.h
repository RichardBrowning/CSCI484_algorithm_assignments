#pragma once
#include <vector>
#include <string>
#include "Matrix.h"
class MatrixChain {
    private:
        std::vector<Matrix*> *matricesPtr = nullptr;
        int matrixMultiplicationCount[10][10] = {0};
        int kValue[10][10] = {0};
        int P[11] = {};
    public:
        MatrixChain(std::vector<Matrix*> *matrices){
            this->matricesPtr = matrices;
            P[0] = this->matricesPtr->at(0)->rows;
            for (int i = 0; i < this->matricesPtr->size(); i++){
                P[i+1] = this->matricesPtr->at(i)->cols;
            }
        }

        ~MatrixChain(){
            delete[] this->matricesPtr;
        }

        int solve(){
            //debug output
            // for (int i = 0; i <= this->matricesPtr->size(); i++){
            //     std::cout << P[i] << std::endl;
            // }

            for (int i = 1; i < this->matricesPtr->size(); i++){
                for (int j = 0; j < this->matricesPtr->size(); j++){
                    if (i + j >= this->matricesPtr->size()) break;
                    matrixMultiplicationCount[j][i+j] = matrixMultiplicationCount[j][j] + matrixMultiplicationCount[j+1][i+j] + P[j] * P[j+1] * P[i+j+1];
                    for (int k = j + 1; k < i + j; k++){
                        int temp = matrixMultiplicationCount[j][k] + matrixMultiplicationCount[k+1][i+j] + P[j] * P[k+1] * P[i+j+1];
                        if (temp < matrixMultiplicationCount[j][i+j]) {
                            matrixMultiplicationCount[j][i+j] = temp;
                            kValue[j][i+j] = k;
                        }
                    }
                }
            }
            for (int i = 1; i < this->matricesPtr->size(); i++){
                for (int j = 0; j < this->matricesPtr->size(); j++){
                    if ((i + 1) == j) kValue[i][j] = i;
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
            for (int i = 0; i < this->matricesPtr->size(); i++){
                for (int j = 0; j < this->matricesPtr->size(); j++){
                    std::cout << kValue[i][j] << "\t";
                }
                std::cout << std::endl;
            }
            std::cout << "The optimal parenthesization is " << this->getParenthesizedForm(0, this->matricesPtr->size()-1) << "=" <<  matrixMultiplicationCount[0][this->matricesPtr->size()-1] << std::endl;
        }

        std::string getParenthesizedForm(int i, int j){
            std::string result = "";
            result += "(";
            if (i == j){
                result += "0";
            } else {
                result += (getParenthesizedForm(i, kValue[i][j]) + "+");
                result += (getParenthesizedForm(kValue[i][j]+1, j) + "+");
                result += std::to_string(P[i]) + "x" + std::to_string(P[kValue[i][j]+1]) + "x" + std::to_string(P[j+1]);
            }
            result += ")";
            return result;
        }
};