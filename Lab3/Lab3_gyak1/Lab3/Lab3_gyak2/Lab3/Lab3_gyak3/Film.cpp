#include "Film.h"

int Film::peldanyokSzama = 0;

Film::Film(string c, int e, double b) {
    cim = c;
    ev = e;
    bevetel = b;
    db = 0;
    szineszek = new Szinesz[100];
}

Film::Film(const Film& f) {
    cim = f.cim;
    ev = f.ev;
    bevetel = f.bevetel;
    db = f.db;

    szineszek = new Szinesz[100];

    for (int i = 0; i < db; i++) {
        szineszek[i] = f.szineszek[i];
    }
}

Film::~Film() {
    delete[] szineszek;
}

Film& Film::operator=(const Film& f) {
    if (this != &f) {
        cim = f.cim;
        ev = f.ev;
        bevetel = f.bevetel;
        db = f.db;

        delete[] szineszek;
        szineszek = new Szinesz[100];

        for (int i = 0; i < db; i++) {
            szineszek[i] = f.szineszek[i];
        }
    }

    return *this;
}

void Film::hozzaad(Szinesz sz) {
    if (db < 100) {
        szineszek[db] = sz;
        db++;
    }
}

void Film::torol(string nev) {
    for (int i = 0; i < db; i++) {
        if (szineszek[i].getNev() == nev) {
            for (int j = i; j < db - 1; j++) {
                szineszek[j] = szineszek[j + 1];
            }

            db--;
            break;
        }
    }
}

int Film::getDb() {
    return db;
}

double Film::getBevetel() {
    return bevetel;
}

string Film::getCim() {
    return cim;
}

void Film::kiir() {
    cout << "Film: " << cim << endl;
    cout << "Ev: " << ev << endl;
    cout << "Bevetel: " << bevetel << endl;
    cout << "Szineszek szama: " << db << endl;

    for (int i = 0; i < db; i++) {
        szineszek[i].kiir();
    }

    cout << endl;
}
void rendezBevetel(Film tomb[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tomb[i].bevetel < tomb[j].bevetel) {
                Film seged = tomb[i];
                tomb[i] = tomb[j];
                tomb[j] = seged;
            }
        }
    }
}
void rendezSzineszek(Film tomb[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (tomb[i].db < tomb[j].db) {
                Film seged = tomb[i];
                tomb[i] = tomb[j];
                tomb[j] = seged;
            }
        }
    }
}
void kozosSzineszek(Film f1, Film f2) {
    cout << "Kozos szineszek:" << endl;

    for (int i = 0; i < f1.db; i++) {
        for (int j = 0; j < f2.db; j++) {
            if (f1.szineszek[i].getNev() == f2.szineszek[j].getNev()) {
                cout << f1.szineszek[i].getNev() << endl;
            }
        }
    }
}