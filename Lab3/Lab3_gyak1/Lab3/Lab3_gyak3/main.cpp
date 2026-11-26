#include "Konyv.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int konyvekSzama = 0;
	cout << "Hany konyvet szeretnel megadni? ";
	cin >> konyvekSzama;

	if (konyvekSzama <= 0)
	{
		cout << "Hiba: a konyvek szama pozitiv kell legyen." << endl;
		return 0;
	}

	cin.ignore();

	Konyv* konyvek = new Konyv[konyvekSzama];

	for (int index = 0; index < konyvekSzama; index++)
	{
		string beolvasottSzerzo;
		string beolvasottCim;
		string beolvasottIsbn;
		int beolvasottEv = 0;

		cout << endl << (index + 1) << ". konyv adatai:" << endl;

		
		cout << "Szerzo: ";
		getline(cin, beolvasottSzerzo);

		cout << "Cim: ";
		getline(cin, beolvasottCim);

		cout << "ISBN: ";
		getline(cin, beolvasottIsbn);

		cout << "Ev: ";
		cin >> beolvasottEv;
		cin.ignore();

		konyvek[index].setSzerzo(beolvasottSzerzo);
		konyvek[index].setCim(beolvasottCim);
		konyvek[index].setIsbn(beolvasottIsbn);
		konyvek[index].setEv(beolvasottEv);
	}


	string keresettSzerzo;
	cout << endl << "Add meg a keresett szerzot: ";
	getline(cin, keresettSzerzo);


	cout << endl << "A(z) " << keresettSzerzo << " altal irt konyvek:" << endl;

	int talaltKonyvekSzama = 0;
	for (int index = 0; index < konyvekSzama; index++)
	{
		if (konyvek[index].szerzoEgyezik(keresettSzerzo))
		{
			konyvek[index].kiir();
			talaltKonyvekSzama++;
		}
	}

	if (talaltKonyvekSzama == 0)
	{
		cout << "Nincs ilyen szerzo a konyvek kozott." << endl;
	}


	cout << endl << "A Konyv osztaly peldanyainak szama: "
		<< Konyv::getPeldanyokSzama() << endl;


	delete[] konyvek;

	cout << "Felszabaditas utan a peldanyok szama: "
		<< Konyv::getPeldanyokSzama() << endl;

	return 0;
}