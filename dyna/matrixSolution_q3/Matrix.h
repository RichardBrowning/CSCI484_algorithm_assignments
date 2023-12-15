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
    // Copy constructor
    Matrix(const Matrix& other) {
        this->rows = other.rows;
        this->cols = other.cols;
    }
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        os << "(" << matrix.rows << ", " << matrix.cols << ")";
        return os;
    }
};