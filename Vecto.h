//
// Created by vo phong on 22/10/2018.
//

#ifndef INC_102160058_16T1_BT02_VECTO_H
#define INC_102160058_16T1_BT02_VECTO_H


#include <iostream>

class Vecto {
private :
    int n;
    double* A;
public:
    Vecto();

    Vecto(int n);

    Vecto(Vecto& vec);

    virtual ~Vecto();

    int getN() const;

    double *getA() const;


    friend std::ostream &operator<<(std::ostream &os, const Vecto &vecto);

    friend std::istream &operator>>(std::istream &is, Vecto &vecto);

    Vecto operator+(const Vecto& vec);

    Vecto operator-(const Vecto& vec);

    Vecto operator*(const Vecto& vec);

    Vecto& operator=(Vecto const& vec);

    double operator[](int index);

    double operator^(int);


};


#endif //INC_102160058_16T1_BT02_VECTO_H
