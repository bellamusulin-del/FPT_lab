#include <iostream>
#include "Komplex.h"
using namespace std;

int main() {
    double r1, i1, r2, i2;

    cout << "Elso komplex szam valos resze: ";
    cin >> r1;

    cout << "Elso komplex szam imaginarius resze: ";
    cin >> i1;

    cout << "Masodik komplex szam valos resze: ";
    cin >> r2;

    cout << "Masodik komplex szam imaginarius resze: ";
    cin >> i2;

    Komplex k1(r1, i1);
    Komplex k2(r2, i2);

    int valasztas;

    do {
        cout << "\n----- MENU -----" << endl;
        cout << "1. Komplex szamok kiirasa" << endl;
        cout << "2. Osszeadas" << endl;
        cout << "3. Kivonas" << endl;
        cout << "4. Szorzas" << endl;
        cout << "5. Osztas" << endl;
        cout << "6. Elso komplex szam modulusa" << endl;
        cout << "7. Elso komplex szam konjugaltja" << endl;
        cout << "8. Komplex szamok osszehasonlitasa" << endl;
        cout << "0. Kilepes" << endl;

        cout << "Valasztas: ";
        cin >> valasztas;

        switch (valasztas) {
        case 1:
            cout << "Elso szam: ";
            k1.kiir();

            cout << "Masodik szam: ";
            k2.kiir();
            break;

        case 2:
        {
            Komplex eredmeny = k1 + k2;
            cout << "Osszeg: ";
            eredmeny.kiir();
            break;
        }

        case 3:
        {
            Komplex eredmeny = k1 - k2;
            cout << "Kulonbseg: ";
            eredmeny.kiir();
            break;
        }

        case 4:
        {
            Komplex eredmeny = k1 * k2;
            cout << "Szorzat: ";
            eredmeny.kiir();
            break;
        }

        case 5:
        {
            if (r2 == 0 && i2 == 0) {
                cout << "Nullaval nem lehet osztani!" << endl;
            }
            else {
                Komplex eredmeny = k1 / k2;
                cout << "Hanyados: ";
                eredmeny.kiir();
            }
            break;
        }

        case 6:
            cout << "Modulus: " << modulus(k1) << endl;
            break;

        case 7:
        {
            Komplex eredmeny = konjugalt(k1);
            cout << "Konjugalt: ";
            eredmeny.kiir();
            break;
        }

        case 8:
            if (k1 == k2) {
                cout << "A ket komplex szam egyenlo." << endl;
            }
            else {
                cout << "A ket komplex szam nem egyenlo." << endl;
            }
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