//
// Created by yingly on 2018-08-04.
//

#include "matrix.h"
#include <iostream>

using std::cin;
using std::cout;

void Matrix::Init(int dimension_m, int dimension_n) {
    dimension_m_ = dimension_m;
    dimension_n_ = dimension_n;
    pVal = new int *[dimension_m];
    for (int i = 0; i < dimension_m; i++) {
        pVal[i] = new int[dimension_n]();
    }
}

Matrix::~Matrix() {
    cout << "deleting memory:.." << std::endl;
    for (int i = 0; i < dimension_m_; i++) {
        delete[](pVal[i]);
    }
    delete[](pVal);
}

void Matrix::Print() {
    cout << "Matrix: " << std::endl;
    for (int i = 0; i < dimension_m_; i++) {
        for (int j = 0; j < dimension_n_; j++) {
            cout << pVal[i][j] << " ";
        }
        cout << std::endl;
    }
}

void LoadMatrix(Matrix &matrix_a, Matrix &matrix_b) {
    int m, n;
    std::ifstream cin("C:\\Users\\Administrator\\CLionProjects\\cpp-interview\\matrix_product_sample");
    cin >> m >> n;
    matrix_a.Init(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix_a.pVal[i][j];
        }
    }
    matrix_a.Print();
    cin >> m >> n;
    matrix_b.Init(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix_b.pVal[i][j];
        }
    }
    matrix_b.Print();
}

Matrix *MatrixProduct(const Matrix &matrix_a, const Matrix &matrix_b) {
    Matrix *matrix_product = new Matrix();
    matrix_product->Init(matrix_a.dimension_m_, matrix_b.dimension_n_);
    for (int i = 0; i < matrix_a.dimension_m_; i++) {
        for (int j = 0; j < matrix_b.dimension_n_; j++) {
            // a[i]xb[j]
            for (int k = 0; k < matrix_a.dimension_n_; k++) {
                matrix_product->pVal[i][j] += matrix_a.pVal[i][k] * matrix_b.pVal[k][j];
            }
        }
    }
    return matrix_product;
}