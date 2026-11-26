#include "Pont.h"
#include "Egyenes.h"
#include <iostream>
using namespace std;


Pont sulypont(Pont* pontok, int pontokSzama)
{
	double xOsszeg = 0;
	double yOsszeg = 0;

	for (int index = 0; index < pontokSzama; index++)
	{
		xOsszeg = xOsszeg + pontok[index].getX();
		yOsszeg = yOsszeg + pontok[index].getY();
	}

	double sulyponX = xOsszeg / pontokSzama;
	double sulyponY = yOsszeg / pontokSzama;

	return Pont(sulyponX, sulyponY);
}

int main()
{
	
	Egyenes sajatEgyenes(3, -2);
	sajatEgyenes.kiir();

	Egyenes egyenesMasolat(sajatEgyenes);
	egyenesMasolat.kiir();

	
	int pontokSzama = 0;
	cout << "Hany pontot szeretnel megadni? ";
	cin >> pontokSzama;

	if (pontokSzama <= 0)
	{
		cout << "Hiba: a pontok szama pozitiv kell legyen." << endl;
		return 0;
	}

	
	Pont* pontok = new Pont[pontokSzama];

	
	for (int index = 0; index < pontokSzama; index++)
	{
		double beolvasottX = 0;
		double beolvasottY = 0;

		cout << (index + 1) << ". pont x koordinataja: ";
		cin >> beolvasottX;
		cout << (index + 1) << ". pont y koordinataja: ";
		cin >> beolvasottY;

		pontok[index].setX(beolvasottX);
		pontok[index].setY(beolvasottY);
	}


	cout << endl << "Pontok az egyenesen: " << Pont::getPontokAzEgyenesen() << endl;
	cout << "Pontok a pozitiv felsikban: " << Pont::getPontokPozitivFelsikban() << endl;
	cout << "Pontok a negativ felsikban: " << Pont::getPontokNegativFelsikban() << endl;

	
	if (pontokSzama >= 2)
	{
		double elsoMasodikTavolsag = tavolsag(pontok[0], pontok[1]);
		cout << endl << "Az elso ket pont tavolsaga: " << elsoMasodikTavolsag << endl;
	}

	Pont sulyponti = sulypont(pontok, pontokSzama);
	cout << "A pontok sulypontja: ";
	sulyponti.kiir();

	delete[] pontok;

	return 0;
}