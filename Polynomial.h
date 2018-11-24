//
// Created by vo phong on 25/10/2018.
//

#ifndef INC_102160058_16T1_BT02_POLYNOMIAL_H
#define INC_102160058_16T1_BT02_POLYNOMIAL_H

#include <iostream>

class Polynomial {
private :
    int n;
    double* A;
public:
    Polynomial();

    Polynomial(int n);

    Polynomial(Polynomial& polynomial);

    virtual ~Polynomial();

    int getN() const;

    double *getA() const;


    friend std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial);

    friend std::istream &operator>>(std::istream &is, Polynomial &polynomial);

    Polynomial operator+(const Polynomial& polynomial);

    Polynomial operator-(const Polynomial& polynomial);

    Polynomial operator*(const Polynomial& polynomial);

    Polynomial& operator=(Polynomial const& polynomial);

    double operator[](int index);

    double operator()(double x);


};


#endif //INC_102160058_16T1_BT02_POLYNOMIAL_H
