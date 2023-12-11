#pragma once
#include <iostream>
#include <ostream>
class Matrix {
    public:
    int rows;
    int cols;
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
    }
    Matrix(Matrix *matrix) {
        this->rows = matrix->rows;
        this->cols = matrix->cols;
    }
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        os << "(" << matrix.rows << ", " << matrix.cols << ")";
        return os;
    }
};