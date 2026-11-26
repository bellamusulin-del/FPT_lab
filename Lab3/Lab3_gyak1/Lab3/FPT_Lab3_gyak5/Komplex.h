#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class Komplex {
private:
    double re;
    double im;

public:
    Komplex();
    Komplex(double r, double i);
    Komplex(const Komplex& k);
    ~Komplex();

    Komplex operator+(const Komplex& k);
    Komplex operator-(const Komplex& k);
    Komplex operator*(const Komplex& k);
    Komplex operator/(const Komplex& k);
    Komplex& operator=(const Komplex& k);

    bool operator==(const Komplex& k);
    bool operator!=(const Komplex& k);

    friend double modulus(const Komplex& k);
    friend Komplex konjugalt(const Komplex& k);

    void kiir();
};