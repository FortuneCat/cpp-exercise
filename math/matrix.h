//
// Created by yingly on 2018-08-04.
//

#ifndef CPP_INTERVIEW_MATRIX_H
#define CPP_INTERVIEW_MATRIX_H

#include <fstream>

class Matrix {
public:
    Matrix() {};

    ~Matrix();

    void Init(int dimension_m, int dimension_n);

    void Print();

    int **pVal;
    int dimension_m_, dimension_n_;
private:

};

void LoadMatrix(Matrix &matrix_a, Matrix &matrix_b);

Matrix *MatrixProduct(const Matrix &matrix_a, const Matrix &matrix_b);

/*Test case*/
//Matrix matrix_a;
//Matrix matrix_b;
//LoadMatrix(matrix_a, matrix_b);
//Matrix *matrix_product = MatrixProduct(matrix_a, matrix_b);
//matrix_product->Print();
//delete matrix_product;

#endif //CPP_INTERVIEW_MATRIX_H
