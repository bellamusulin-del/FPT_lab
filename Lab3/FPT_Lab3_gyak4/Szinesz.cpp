#include "Szinesz.h"

Szinesz::Szinesz() {
    nev = "";
    kor = 0;
    nemzetiseg = "";
}

Szinesz::Szinesz(string n, int k, string nem) {
    nev = n;
    kor = k;
    nemzetiseg = nem;
}

string Szinesz::getNev() {
    return nev;
}

void Szinesz::kiir() {
    cout << "Nev: " << nev << endl;
    cout << "Kor: " << kor << endl;
    cout << "Nemzetiseg: " << nemzetiseg << endl;
}