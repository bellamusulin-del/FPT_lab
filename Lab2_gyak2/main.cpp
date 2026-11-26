#include "Bank.h"
#include <iostream>
using namespace std;

// Megkérdezi a klienst és a számlát, és visszaadja a kiválasztott számla címét.
// Hibás választásnál nullptr-t ad vissza.
Bankszamla* szamlaKivalasztas(Bank& bank)
{
	unsigned kliensSorszam = 0;
	unsigned szamlaSorszam = 0;

	cout << "Hanyadik kliens? (1-" << bank.getKliensekSzama() << "): ";
	cin >> kliensSorszam;

	// A felhasználó 1-t?l számol, a tömb 0-tól
	Kliens* valasztottKliens = bank.getKliens(kliensSorszam - 1);
	if (valasztottKliens == nullptr)
	{
		cout << "Hiba: ilyen kliens nincs." << endl;
		return nullptr;
	}

	cout << "Hanyadik szamla? (1-" << valasztottKliens->getKontokSzama() << "): ";
	cin >> szamlaSorszam;

	Bankszamla* valasztottSzamla = valasztottKliens->getKonto(szamlaSorszam - 1);
	if (valasztottSzamla == nullptr)
	{
		cout << "Hiba: ilyen szamla nincs." << endl;
		return nullptr;
	}

	return valasztottSzamla;
}

void menuKiir()
{
	cout << "===== MENU =====" << endl;
	cout << "1 - Bank adatainak kiirasa" << endl;
	cout << "2 - Letet" << endl;
	cout << "3 - Kivetel" << endl;
	cout << "4 - Transzfer" << endl;
	cout << "5 - Kamat es osszeg kiirasa egy szamlara" << endl;
	cout << "0 - Kilepes" << endl;
	cout << "Valasztas: ";
}

int main()
{
	// Számlák
	Bankszamla elsoEurSzamla("RO01EUR0001", 200, "EUR");
	Bankszamla elsoRonSzamla("RO01RON0001", 1000, "RON");
	Bankszamla masodikRonSzamla("RO02RON0001", 300, "RON");
	Bankszamla harmadikRonSzamla("RO02RON0002", 600, "RON");

	// Kliensek
	Kliens elsoKliens("Nagy", "Anna", "Marosvasarhely, Fo ter 1");
	Kliens masodikKliens("Kovacs", "Peter", "Marosvasarhely, Hid utca 5");

	// Az els? kliensnek 1 EUR és 1 RON számlája van
	elsoKliens.hozzaadKonto(&elsoEurSzamla);
	elsoKliens.hozzaadKonto(&elsoRonSzamla);

	// A második kliensnek 2 RON számlája van
	masodikKliens.hozzaadKonto(&masodikRonSzamla);
	masodikKliens.hozzaadKonto(&harmadikRonSzamla);

	// Bank
	Bank bank("BTRLRO22");
	bank.hozzaadKliens(&elsoKliens);
	bank.hozzaadKliens(&masodikKliens);

	int valasztas = -1;

	// A menü addig ismétl?dik, amíg a felhasználó 0-t nem választ
	do
	{
		menuKiir();
		cin >> valasztas;

		switch (valasztas)
		{
		case 1:
		{
			bank.kiirBank();
			break;
		}
		case 2:
		{
			Bankszamla* szamla = szamlaKivalasztas(bank);
			if (szamla != nullptr)
			{
				float osszeg = 0;
				cout << "Mennyit szeretnel betenni? ";
				cin >> osszeg;
				szamla->letet(osszeg);
				szamla->kiirSzamla();
			}
			break;
		}
		case 3:
		{
			Bankszamla* szamla = szamlaKivalasztas(bank);
			if (szamla != nullptr)
			{
				float osszeg = 0;
				cout << "Mennyit szeretnel kivenni? ";
				cin >> osszeg;
				szamla->kivet(osszeg);
				szamla->kiirSzamla();
			}
			break;
		}
		case 4:
		{
			cout << "--- Honnan ---" << endl;
			Bankszamla* honnanSzamla = szamlaKivalasztas(bank);

			if (honnanSzamla != nullptr)
			{
				cout << "--- Hova ---" << endl;
				Bankszamla* hovaSzamla = szamlaKivalasztas(bank);

				if (hovaSzamla != nullptr)
				{
					float osszeg = 0;
					cout << "Mennyit szeretnel atutalni? ";
					cin >> osszeg;
					honnanSzamla->transzfer(*hovaSzamla, osszeg);
					honnanSzamla->kiirSzamla();
					hovaSzamla->kiirSzamla();
				}
			}
			break;
		}
		case 5:
		{
			Bankszamla* szamla = szamlaKivalasztas(bank);
			if (szamla != nullptr)
			{
				szamla->kiirSzamla();
			}
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

