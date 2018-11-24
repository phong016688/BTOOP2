//
// Created by vo phong on 24/10/2018.
//

#ifndef INC_102160058_16T1_BT02_MATRIX_H
#define INC_102160058_16T1_BT02_MATRIX_H

#include <iostream>

class Matrix {
private:
    int hang;
    int cot;
    double **A;
public:
    Matrix();

    Matrix(int hang, int cot);

    Matrix(Matrix &matrix);

    virtual ~Matrix();

    void capphat();

    void xoamang();

    int getHang() const;

    int getCot() const;

    friend std::istream &operator>>(std::istream &is, Matrix &matrix);

    friend std::ostream &operator<<(std::ostream &os, Matrix &matrix);

    Matrix operator+(const Matrix& matrix);

    Matrix operator-(const Matrix& matrix);

    Matrix operator*(const Matrix& matrix);

    Matrix& operator=(Matrix const& matrix);

    double operator()(int index1, int index2);

    double operator^(int );

    friend double det(Matrix matrix);
};


#endif //INC_102160058_16T1_BT02_MATRIX_H
