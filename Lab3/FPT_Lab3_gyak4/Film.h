#pragma once
#include "Szinesz.h"
#include <iostream>
#include <string>
using namespace std;

class Film {
private:
    string cim;
    int ev;
    double bevetel;

    Szinesz* szineszek;
    int db;

    static int peldanyokSzama;

public:
    Film(string c, int e, double b);
    Film(const Film& f);
    ~Film();

    Film& operator=(const Film& f);

    void hozzaad(Szinesz sz);
    void torol(string nev);

    int getDb();
    double getBevetel();
    string getCim();

    void kiir();

    friend void rendezBevetel(Film tomb[], int n);
    friend void rendezSzineszek(Film tomb[], int n);
    friend void kozosSzineszek(Film f1, Film f2);
};