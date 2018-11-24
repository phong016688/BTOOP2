//
// Created by vo phong on 22/10/2018.
//

#include <iostream>
#include <cmath>
#include "Vecto.h"

Vecto::Vecto() {
    this->n = 0;
    this->A = NULL;
}

Vecto::Vecto(int n) {
    this->n = n;
    this->A = new double[this->n];
}

Vecto::Vecto(Vecto &vec) {
    this->n = vec.n;
    this->A = new double[this->n];
    for (int i = 0; i < this->n; i++) {
        this->A[i] = vec.A[i];
    }
}

Vecto::~Vecto() {
    if (this->A != NULL)
        delete[] this->A;
}

int Vecto::getN() const {
    return n;
}

double *Vecto::getA() const {
    return A;
}

std::ostream &operator<<(std::ostream &os, const Vecto &vecto) {
    os << "(";
    for (int i = 0; i < vecto.n; i++) {
        os << vecto.A[i];
        if (i != vecto.n - 1)
            std::cout << ",";
    }
    os << ")" << "\n";
    return os;
}

std::istream &operator>>(std::istream &is, Vecto &vecto) {
    delete[] vecto.A;
    do {
        std::cout << "nhap n(n>=0): ";
        is >> vecto.n;
        if (vecto.n < 0)
            std::cout << "n phai lon hon 0" << std::endl;
    } while (vecto.n < 0);
    vecto.A = new double[vecto.n];
	std::cout << "nhap toa do vector cach nhau boi khoang trang \n";
    for (int i = 0; i < vecto.n; i++) {
        is >> vecto.A[i];
    }
    return is;
}

Vecto Vecto::operator+(const Vecto &vec) {
    if (vec.n != this->n)
        throw ("loi: phep cong duoc thuc hien khi 2 vecto cung so chieu");
    else {
        Vecto vector_tong;
        vector_tong.n = vec.n;
        vector_tong.A = new double[vector_tong.n];
        for (int i = 0; i < vector_tong.n; i++) {
            vector_tong.A[i] = this->A[i] + vec.A[i];
        }
        return vector_tong;
    }
}

Vecto Vecto::operator-(const Vecto &vec) {
    if (vec.n != this->n)
        throw ("loi: phep cong duoc thuc hien khi 2 vecto cung so chieu");
    else {
        Vecto vector_hieu;
        vector_hieu.n = vec.n;
        vector_hieu.A = new double[vector_hieu.n];
        for (int i = 0; i < vector_hieu.n; i++) {
            vector_hieu.A[i] = this->A[i] + vec.A[i];
        }
        return vector_hieu;
    }
}

Vecto Vecto::operator*(const Vecto &vec) {
    if (vec.n != this->n)
        throw ("loi: phep nhan duoc thuc hien khi 2 vecto cung so chieu");
    else {
        Vecto vector_tich;
        vector_tich.n = vec.n;
        vector_tich.A = new double[vector_tich.n];
        for (int i = 0; i < vector_tich.n; i++) {
            vector_tich.A[i] = this->A[i] * vec.A[i];
        }
        return vector_tich;
    }
}

double Vecto::operator[](int index) {
    if (index < 0 || index >= this->n)
        throw ("vi tri phan tu khong hop le");
    else {
        return *(this->A + index);
    }
}

double Vecto::operator^(int) {
    double tong = 0;
    for (int i = 0; i < this->n; i++) {
        tong += this->A[i] * this->A[i];
    }
    return sqrt(tong);
}

Vecto& Vecto::operator=(Vecto const &vec) {
    this->n = vec.n;
    this->A = new double[this->n];
    for (int i = 0; i < this->n; i++) {
        this->A[i] = vec.A[i];
    }
    return *this;
}





