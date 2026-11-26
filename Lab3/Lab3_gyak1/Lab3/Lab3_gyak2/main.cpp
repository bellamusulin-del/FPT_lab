#include "SZLL.h"
#include <iostream>
using namespace std;

void menuKiir()
{
	cout << "===== SZLL MENU =====" << endl;
	cout << "1 - Beszuras az elejere" << endl;
	cout << "2 - Beszuras a vegere" << endl;
	cout << "3 - Beszuras megadott poziciora" << endl;
	cout << "4 - Az elso elem torlese" << endl;
	cout << "5 - Az utolso elem torlese" << endl;
	cout << "6 - Torles megadott pozicionrol" << endl;
	cout << "7 - Lista kiirasa" << endl;
	cout << "8 - Elemek szamanak kiirasa" << endl;
	cout << "9 - Lista masolasa (copy-konstruktor kiprobalasa)" << endl;
	cout << "0 - Kilepes" << endl;
	cout << "Valasztas: ";
}

int main()
{
	SZLL lista;
	int valasztas = -1;
	do
	{
		menuKiir();
		cin >> valasztas;

		switch (valasztas)
		{
		case 1:
		{
			int beirtAdat = 0;
			cout << "Add meg a beszurando szamot: ";
			cin >> beirtAdat;
			lista.beszurElejere(beirtAdat);
			lista.kiir();
			break;
		}
		case 2:
		{
			int beirtAdat = 0;
			cout << "Add meg a beszurando szamot: ";
			cin >> beirtAdat;
			lista.beszurVegere(beirtAdat);
			lista.kiir();
			break;
		}
		case 3:
		{
			int beirtAdat = 0;
			int beirtPozicio = 0;
			cout << "Add meg a beszurando szamot: ";
			cin >> beirtAdat;
			cout << "Add meg a poziciot (0-tol szamolva): ";
			cin >> beirtPozicio;
			lista.beszurPozicioba(beirtAdat, beirtPozicio);
			lista.kiir();
			break;
		}
		case 4:
		{
			lista.torolElsot();
			lista.kiir();
			break;
		}
		case 5:
		{
			lista.torolUtolsot();
			lista.kiir();
			break;
		}
		case 6:
		{
			int beirtPozicio = 0;
			cout << "Add meg a torlendo elem poziciojat (0-tol szamolva): ";
			cin >> beirtPozicio;
			lista.torolPozicio(beirtPozicio);
			lista.kiir();
			break;
		}
		case 7:
		{
			lista.kiir();
			break;
		}
		case 8:
		{
			cout << "Elemek szama: " << lista.getMeret() << endl;
			break;
		}
		case 9:
		{
			SZLL masolat(lista);
			masolat.beszurVegere(99);
			cout << "Eredeti lista: ";
			lista.kiir();
			cout << "Masolat (a vegere beszurva a 99): ";
			masolat.kiir();
			break;
		}
		case 0:
		{
			cout << "Viszontlatasra!" << endl;
			break;
		}
		default:
		{
			cout << "Hibas valasztas, probald ujra." << endl;
			break;
		}
		}

		cout << endl;

	} while (valasztas != 0);

	return 0;
}