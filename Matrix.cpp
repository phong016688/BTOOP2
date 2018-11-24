//
// Created by vo phong on 24/10/2018.
//

#include "Matrix.h"

Matrix::Matrix() {
    this->hang = 0;
    this->cot = 0;
    this->A = NULL;
}

Matrix::Matrix(int hang, int cot) {
    this->hang = hang;
    this->cot = cot;
    this->A = new double *[this->hang];
    for (int i = 0; i < this->hang; i++) {
        this->A[i] = new double[this->cot];
    }
}

Matrix::Matrix(Matrix &matrix) {
    this->hang = matrix.hang;
    this->cot = matrix.cot;
    this->A = new double *[this->hang];
    for (int i = 0; i < this->hang; i++) {
        this->A[i] = new double[this->cot];
    }
    for (int i = 0; i < this->hang; i++) {
        for (int j = 0; j < this->cot; j++) {
            this->A[i][j] = matrix.A[i][j];
        }
    }
}

void Matrix::capphat() {
    this->A = new double *[this->hang];
    for (int i = 0; i < this->hang; i++) {
        this->A[i] = new double[this->cot];
    }
}

void Matrix::xoamang() {
    for (int i = 0; i < this->hang; i++) {
        delete[] this->A[i];
    }
    delete[] this->A;
}

std::istream &operator>>(std::istream &is, Matrix &matrix) {
    if (matrix.A != NULL)
        matrix.xoamang();
    do {
        std::cout << "nhap so hang(>=0): ";
        is >> matrix.hang;
        if (matrix.hang < 0)
            std::cout << "so hang phai lon hon 0" << std::endl;
    } while (matrix.hang < 0);
    do {
        std::cout << "nhap so cot(>=0): ";
        is >> matrix.cot;
        if (matrix.cot < 0)
            std::cout << "so cot phai lon hon 0" << std::endl;
    } while (matrix.cot < 0);
    matrix.capphat();
    for (int i = 0; i < matrix.hang; i++) {
        for (int j = 0; j < matrix.cot; j++) {
            std::cout << "[" << i << "][" << j << "] = ";
            is >> matrix.A[i][j];
        }
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, Matrix &matrix) {
    for (int i = 0; i < matrix.hang; i++) {
        for (int j = 0; j < matrix.cot; j++) {
            os << matrix.A[i][j] << " ";
        }
        os << "\n";
    }
    return os;
}

Matrix Matrix::operator+(const Matrix &matrix) {
    if (this->hang != matrix.hang || this->cot != matrix.cot)
        throw ("muon cong hai ma tran phai cung hang va cot \n");
    else {
        Matrix matrix_tong(matrix.hang, matrix.cot);
        for (int i = 0; i < matrix.hang; i++) {
            for (int j = 0; j < matrix.cot; j++) {
                matrix_tong.A[i][j] = this->A[i][j] + matrix.A[i][j];
            }
        }
        return matrix_tong;
    }
}

Matrix Matrix::operator-(const Matrix &matrix) {
    if (this->hang != matrix.hang || this->cot != matrix.cot)
        throw ("muon tru hai ma tran phai cung hang va cot \n");
    else {
        Matrix matrix_hieu(matrix.hang, matrix.cot);
        for (int i = 0; i < matrix.hang; i++) {
            for (int j = 0; j < matrix.cot; j++) {
                matrix_hieu.A[i][j] = this->A[i][j] - matrix.A[i][j];
            }
        }
        return matrix_hieu;
    }
}

Matrix Matrix::operator*(const Matrix &matrix) {
    if (this->hang != matrix.hang || this->cot != matrix.cot)
        throw ("muon nhan hai ma tran phai cung hang va cot \n");
    else {
        Matrix matrix_tich(matrix.hang, matrix.cot);
        for (int i = 0; i < matrix.hang; i++) {
            for (int j = 0; j < matrix.cot; j++) {
                matrix_tich.A[i][j] = this->A[i][j] * matrix.A[i][j];
            }
        }
        return matrix_tich;
    }
}

double Matrix::operator()(int index1, int index2) {
    if (index1 > this->hang || index1 > this->cot || index1 < 0 || index2 < 0)
        throw ("phan tu truy xuat khong co trong ma tran \n");
    else
        return this->A[index1][index2];
}

Matrix::~Matrix() {
    xoamang();
}

double Matrix::operator^(int) {
    if (this->hang != this->cot)
        throw ("chi co the tinh dinh thuc cua ma tran vuog");
    Matrix matrix;
    matrix.hang = this->hang;
    matrix.cot = this->cot;
    matrix.A = new double *[matrix.hang];
    for (int i = 0; i < matrix.hang; i++) {
        matrix.A[i] = new double[matrix.cot];
    }
    for (int i = 0; i < matrix.hang; i++) {
        for (int j = 0; j < matrix.cot; ++j) {
            matrix.A[i][j] = this->A[i][j];
        }
    }
    return det(matrix);
}

double det(Matrix matrix) {
    int k, n = matrix.hang;
    double temp, det = 1.0;
    for (int i = 0; i < (n - 1); i++) {
        if (matrix.A[i][i] == 0) {
            k = i + 1;
            while ((k < n) && (matrix.A[k][i] == 0))
                k++;
            if (k > (n - 1)) {
                det = 0;
                break;
            } else {
                det = -det;
                for (int j = i; j < n; j++) {
                    double tmp = matrix.A[i][j];
                    matrix.A[i][j] = matrix.A[k][j];
                    matrix.A[k][j] = tmp;
                }
            }
        }
        for (k = i + 1; k < n; k++) {
            double a = -matrix.A[k][i] / matrix.A[i][i];
            for (int j = i; j < n; j++)
                matrix.A[k][j] += a * matrix.A[i][j];
        }
    }
    for (int i = 0; i < n; i++)
        det *= matrix.A[i][i];
    return det;
}

Matrix& Matrix::operator=(Matrix const &matrix) {
    this->hang = matrix.hang;
    this->cot = matrix.cot;
    this->A = new double *[this->hang];
    for (int i = 0; i < this->hang; i++) {
        this->A[i] = new double[this->cot];
    }
    for (int i = 0; i < this->hang; i++) {
        for (int j = 0; j < this->cot; j++) {
            this->A[i][j] = matrix.A[i][j];
        }
    }
    return *this;
}

int Matrix::getHang() const {
    return hang;
}

int Matrix::getCot() const {
    return cot;
}



