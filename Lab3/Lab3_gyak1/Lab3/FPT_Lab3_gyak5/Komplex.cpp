#include "Komplex.h"

Komplex::Komplex() {
    re = 0;
    im = 0;
}

Komplex::Komplex(double r, double i) {
    re = r;
    im = i;
}

Komplex::Komplex(const Komplex& k) {
    re = k.re;
    im = k.im;
}

Komplex::~Komplex() {
}

Komplex Komplex::operator+(const Komplex& k) {
    return Komplex(re + k.re, im + k.im);
}

Komplex Komplex::operator-(const Komplex& k) {
    return Komplex(re - k.re, im - k.im);
}

Komplex Komplex::operator*(const Komplex& k) {
    double r = re * k.re - im * k.im;
    double i = re * k.im + im * k.re;

    return Komplex(r, i);
}

Komplex Komplex::operator/(const Komplex& k) {
    double oszto = k.re * k.re + k.im * k.im;

    if (oszto == 0) {
        cout << "Nullaval nem lehet osztani!" << endl;
        return Komplex();
    }

    double r = (re * k.re + im * k.im) / oszto;
    double i = (im * k.re - re * k.im) / oszto;

    return Komplex(r, i);
}

Komplex& Komplex::operator=(const Komplex& k) {
    if (this != &k) {
        re = k.re;
        im = k.im;
    }

    return *this;
}

bool Komplex::operator==(const Komplex& k) {
    return re == k.re && im == k.im;
}

bool Komplex::operator!=(const Komplex& k) {
    return !(*this == k);
}

double modulus(const Komplex& k) {
    return sqrt(k.re * k.re + k.im * k.im);
}

Komplex konjugalt(const Komplex& k) {
    return Komplex(k.re, -k.im);
}

void Komplex::kiir() {
    cout << re;

    if (im >= 0) {
        cout << " + " << im << "i";
    }
    else {
        cout << " - " << -im << "i";
    }

    cout << endl;
}