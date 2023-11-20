#include <iostream>
#include <vector>

using namespace std;

// Function to add two matrices
vector<vector<int>> add(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Function to subtract two matrices
vector<vector<int>> subtract(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Function to multiply two matrices using Strassen's Algorithm
vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B) {
    // get dimensions of matrices
    int n = A.size();
    // construct matrix with size n*n
    vector<vector<int>> C(n, vector<int>(n));
    // when size is 1, multiply directly
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }
    // divide matrices into 4 sub-matrices
    int m = n / 2;
    //initialize the sub-matrices
    vector<vector<int>> A00(m, vector<int>(m));
    vector<vector<int>> A01(m, vector<int>(m));
    vector<vector<int>> A10(m, vector<int>(m));
    vector<vector<int>> A11(m, vector<int>(m));
    vector<vector<int>> B00(m, vector<int>(m));
    vector<vector<int>> B01(m, vector<int>(m));
    vector<vector<int>> B10(m, vector<int>(m));
    vector<vector<int>> B11(m, vector<int>(m));
    // for 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            A00[i][j] = A[i][j];
            A01[i][j] = A[i][j + m];
            A10[i][j] = A[i + m][j];
            A11[i][j] = A[i + m][j + m];
            B00[i][j] = B[i][j];
            B01[i][j] = B[i][j + m];
            B10[i][j] = B[i + m][j];
            B11[i][j] = B[i + m][j + m];
        }
    }
    vector<vector<int>> P1 = strassen(add(A00, A11), add(B00, B11));
    vector<vector<int>> P2 = strassen(add(A10, A11), B00);
    vector<vector<int>> P3 = strassen(A00, subtract(B01, B11));
    vector<vector<int>> P4 = strassen(A11, subtract(B10, B00));
    vector<vector<int>> P5 = strassen(add(A00, A01), B11);
    vector<vector<int>> P6 = strassen(subtract(A10, A00), add(B00, B01));
    vector<vector<int>> P7 = strassen(subtract(A01, A11), add(B10, B11));
    vector<vector<int>> C11 = add(subtract(add(P1, P4), P5), P7);
    vector<vector<int>> C12 = add(P3, P5);
    vector<vector<int>> C21 = add(P2, P4);
    vector<vector<int>> C22 = add(subtract(add(P1, P3), P2), P6);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = C11[i][j];
            C[i][j + m] = C12[i][j];
            C[i + m][j] = C21[i][j];
            C[i + m][j + m] = C22[i][j];
        }
    }
    return C;
}

// Function to print a matrix
void printMatrix(vector<vector<int>> A) {
    int n = A.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> A = {{2, 3, 1, -2}, {5, 3, 6, -1}, {1, 3, 2, 2}, {0, 4, 1, 2}};
    vector<vector<int>> B = {{-1, 3, 2, 1}, {4, 2, -3, 1}, {1, 0, 3, 2}, {2, -2, 1, 4}};
    vector<vector<int>> C = strassen(A, B);
    printMatrix(C);
    return 0;
}