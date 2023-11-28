#ifndef MATRIX_H
#define MATRIX_H
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
};
#endif