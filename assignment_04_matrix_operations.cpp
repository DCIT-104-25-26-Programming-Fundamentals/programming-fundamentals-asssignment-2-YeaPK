// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


const int MAX = 10;


void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}


void displayMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}


void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
}


void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
}


void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int result[MAX][MAX],
                       int M, int N, int P) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < P; j++) {
            result[i][j] = 0;
            for (int k = 0; k < N; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}


void runTranspose() {
    int matrix[MAX][MAX], result[MAX][MAX];
    int rows, cols;

    cout << "\n--- PART A: Transpose a Matrix ---\n";
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter matrix elements:\n";
    readMatrix(matrix, rows, cols);

    transposeMatrix(matrix, result, rows, cols);

    cout << "\nOriginal Matrix:\n";
    displayMatrix(matrix, rows, cols);

    cout << "\nTransposed Matrix:\n";
    displayMatrix(result, cols, rows); // note: dimensions swapped
}


void runAddition() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int rows, cols;

    cout << "\n--- PART B: Add Two Matrices ---\n";
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    cout << "\nEnter elements of Matrix A:\n";
    readMatrix(a, rows, cols);

    cout << "\nEnter elements of Matrix B:\n";
    readMatrix(b, rows, cols);

    addMatrices(a, b, result, rows, cols);

    cout << "\nMatrix A:\n";
    displayMatrix(a, rows, cols);

    cout << "\nMatrix B:\n";
    displayMatrix(b, rows, cols);

    cout << "\nSum (A + B):\n";
    displayMatrix(result, rows, cols);
}


void runMultiplication() {
    int a[MAX][MAX], b[MAX][MAX], result[MAX][MAX];
    int M, N, N2, P;

    cout << "\n--- PART C: Multiply Two Matrices ---\n";
    cout << "Matrix A dimensions (M x N)\n";
    cout << "Enter number of rows (M): ";
    cin >> M;
    cout << "Enter number of columns (N): ";
    cin >> N;

    cout << "\nEnter elements of Matrix A:\n";
    readMatrix(a, M, N);

    cout << "\nMatrix B dimensions (N x P)\n";
    cout << "Enter number of rows (must equal N = " << N << "): ";
    cin >> N2;

    if (N2 != N) {
        cout << "\nError: Number of rows in B must equal number of columns in A (" 
             << N << "). Multiplication aborted.\n";
        return;
    }

    cout << "Enter number of columns (P): ";
    cin >> P;

    cout << "\nEnter elements of Matrix B:\n";
    readMatrix(b, N, P);

    multiplyMatrices(a, b, result, M, N, P);

    cout << "\nMatrix A:\n";
    displayMatrix(a, M, N);

    cout << "\nMatrix B:\n";
    displayMatrix(b, N, P);

    cout << "\nProduct (A x B):\n";
    displayMatrix(result, M, P);
}

int main() {
    int choice;

    do {
        cout << "\n=====================================\n";
        cout << " MATRIX OPERATIONS MENU\n";
        cout << "=====================================\n";
        cout << "1. Transpose a Matrix\n";
        cout << "2. Add Two Matrices\n";
        cout << "3. Multiply Two Matrices\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: runTranspose();      break;
            case 2: runAddition();       break;
            case 3: runMultiplication(); break;
            case 0: cout << "\nExiting program. Goodbye!\n"; break;
            default: cout << "\nInvalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}



