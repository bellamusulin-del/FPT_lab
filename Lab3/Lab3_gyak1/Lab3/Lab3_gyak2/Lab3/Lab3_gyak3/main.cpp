#include <iostream>
#include "Film.h"
using namespace std;

int szineszPeldanyok(Film tomb[], int n) {
    int db = 0;

    for (int i = 0; i < n; i++) {
        db += tomb[i].getDb();
    }

    return db;
}

int main() {
    Film filmek[3] = {
        Film("Titanic", 1997, 2200000000),
        Film("Avatar", 2009, 2900000000),
        Film("Inception", 2010, 800000000)
    };

    Szinesz s1("Leonardo DiCaprio", 51, "Amerikai");
    Szinesz s2("Kate Winslet", 51, "Angol");
    Szinesz s3("Sam Worthington", 50, "Ausztral");
    Szinesz s4("Tom Hardy", 48, "Angol");

    filmek[0].hozzaad(s1);
    filmek[0].hozzaad(s2);

    filmek[1].hozzaad(s2);
    filmek[1].hozzaad(s3);

    filmek[2].hozzaad(s1);
    filmek[2].hozzaad(s4);

    int valasztas;

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Filmek kiirasa" << endl;
        cout << "2. Rendezes bevetel szerint" << endl;
        cout << "3. Rendezes szineszek szama szerint" << endl;
        cout << "4. Kozos szineszek keresese" << endl;
        cout << "5. Szinesz torlese" << endl;
        cout << "6. Szinesz peldanyok szama" << endl;
        cout << "0. Kilepes" << endl;

        cout << "Valasztas: ";
        cin >> valasztas;

        switch (valasztas) {
        case 1:
            for (int i = 0; i < 3; i++) {
                filmek[i].kiir();
            }
            break;

        case 2:
            rendezBevetel(filmek, 3);

            cout << "Rendezes bevetel szerint:" << endl;

            for (int i = 0; i < 3; i++) {
                filmek[i].kiir();
            }
            break;

        case 3:
            rendezSzineszek(filmek, 3);

            cout << "Rendezes szineszek szama szerint:" << endl;

            for (int i = 0; i < 3; i++) {
                filmek[i].kiir();
            }
            break;

        case 4:
            kozosSzineszek(filmek[0], filmek[1]);
            break;

        case 5:
        {
            string nev;
            cout << "Add meg a torlendo szinesz nevet: ";
            cin.ignore();
            getline(cin, nev);

            filmek[0].torol(nev);
            cout << "Torles utan:" << endl;
            filmek[0].kiir();
            break;
        }

        case 6:
            cout << "Szinesz peldanyok szama: "
                << szineszPeldanyok(filmek, 3) << endl;
            break;

        case 0:
            cout << "Kilepes..." << endl;
            break;

        default:
            cout << "Hibas valasztas!" << endl;
        }

    } while (valasztas != 0);

    return 0;
}