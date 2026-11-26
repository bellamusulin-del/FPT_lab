#pragma once
#include <iostream>
#include <string>
using namespace std;

class Szinesz {
private:
    string nev;
    int kor;
    string nemzetiseg;

public:
    Szinesz();
    Szinesz(string n, int k, string nem);

    string getNev();
    void kiir();
};