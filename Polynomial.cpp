//
// Created by vo phong on 25/10/2018.
//

#include <cmath>
#include "Polynomial.h"

Polynomial::Polynomial() {
    this->n = 0;
    this->A = NULL;
}

Polynomial::Polynomial(int n) {
    this->n = n;
    this->A = new double[this->n];
}

Polynomial::Polynomial(Polynomial &polynomial) {
    this->n = polynomial.n;
    this->A = new double[this->n];
    for (int i = 0; i < this->n; i++) {
        this->A[i] = polynomial.A[i];
    }
}

Polynomial::~Polynomial() {
    if (this->A != NULL)
        delete[] this->A;
}

int Polynomial::getN() const {
    return this->n;
}

double *Polynomial::getA() const {
    return this->A;
}

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
    for (int i = 0; i < polynomial.n; i++) {
        os << polynomial.A[i];
        if (i != 0 && i != 1)
            os << "x^" << i;
        else if (i == 1)
            os << "x";
        if (i != polynomial.n - 1)
            os << " + ";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Polynomial &polynomial) {
    if (polynomial.A != NULL)
        delete[] polynomial.A;
    do {
        std::cout << "nhap n(n>=0): ";
        is >> polynomial.n;
        if (polynomial.n < 0)
            std::cout << "n phai lon hon 0" << std::endl;
    } while (polynomial.n < 0);
    polynomial.A = new double[polynomial.n];
    for (int i = 0; i < polynomial.n; i++) {
        std::cout << "he so cua x^" << i << ":  ";
        is >> polynomial.A[i];
    }
    return is;
}

Polynomial Polynomial::operator+(const Polynomial &polynomial) {
    Polynomial polynomial_tong;
    if (this->n >= polynomial.n) {
        polynomial_tong.n = this->n;
        polynomial_tong.A = new double[polynomial_tong.n];
        for (int i = 0; i < polynomial.n; i++) {
            polynomial_tong.A[i] = this->A[i] + polynomial.A[i];
        }
        for (int i = polynomial.n; i < polynomial_tong.n; i++) {
            polynomial_tong.A[i] = this->A[i];
        }
    } else {
        polynomial_tong = polynomial.n;
        polynomial_tong.A = new double[polynomial_tong.n];
        for (int i = 0; i < this->n; i++) {
            polynomial_tong.A[i] = this->A[i] + polynomial.A[i];
        }
        for (int i = this->n; i < polynomial_tong.n; i++) {
            polynomial_tong.A[i] = polynomial.A[i];
        }
    }
    return polynomial_tong;
}

Polynomial Polynomial::operator-(const Polynomial &polynomial) {
    Polynomial polynomial_hieu;
    if (this->n >= polynomial.n) {
         polynomial_hieu.n = this->n;
        polynomial_hieu.A = new double[polynomial_hieu.n];
        for (int i = 0; i < polynomial.n; i++) {
            polynomial_hieu.A[i] = this->A[i] - polynomial.A[i];
        }
        for (int i = polynomial.n; i < polynomial_hieu.n; i++) {
            polynomial_hieu.A[i] = this->A[i];
        }
    } else {
        polynomial_hieu = polynomial.n;
        polynomial_hieu.A = new double[polynomial_hieu.n];
        for (int i = 0; i < this->n; i++) {
            polynomial_hieu.A[i] = this->A[i] - polynomial.A[i];
        }
        for (int i = this->n; i < polynomial_hieu.n; i++) {
            polynomial_hieu.A[i] = polynomial.A[i];
        }
    }
    return polynomial_hieu;
}

Polynomial Polynomial::operator*(const Polynomial &polynomial) {
    double tmp;
    Polynomial polynomial_tich;
    polynomial_tich.n = this->n + polynomial.n -1;
    polynomial_tich.A = new double [polynomial_tich.n];
	double* arr_this = new double[polynomial_tich.n];
	double* arr_pol = new double[polynomial_tich.n];
    for (int k = 0; k < polynomial_tich.n; k++) {
        if(k < this->n)
            arr_this[k] = this->A[k];
        else
            arr_this[k] = 0;
        if(k < polynomial.n)
            arr_pol[k] = polynomial.A[k];
        else
            arr_pol[k] = 0;
    }
    for (int i = 0; i < polynomial_tich.n; i++) {
        tmp = 0;
        for (int j = 0; j <= i/2 ; j++) {
                tmp += (arr_this[j] * arr_pol[i-j] + arr_this[i - j] * arr_pol[j]);
        }
        if(i%2 == 0)
            tmp -= arr_this[i/2]*arr_pol[i/2];
        polynomial_tich.A[i] = tmp;
    }
	delete[] arr_this;
	delete[] arr_pol;
    return polynomial_tich;
}

double Polynomial::operator[](int index) {
    return 0;
}

double Polynomial::operator()(double x) {
    double giatri = 0;
    for (int i = 0; i <this->n ; ++i) {
        giatri += this->A[i] * pow(x, i);
    }
    return giatri;
}

Polynomial& Polynomial::operator=(Polynomial const &polynomial) {
    this->n = polynomial.n;
    this->A = new double[this->n];
    for (int i = 0; i < this->n; i++) {
        this->A[i] = polynomial.A[i];
    }
    return *this;
}


