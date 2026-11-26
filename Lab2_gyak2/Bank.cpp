#include "Bank.h"
#include <iostream>
using namespace std;

Bank::Bank(string ujBankKod)
	: bankKod(ujBankKod), kliensekSzama(0) 
{
	for (unsigned index = 0; index < MAX_KLIENSEK; ++index) 
	{
		kliensek[index] = nullptr;
	}
}
Bank::Bank(const Bank& other)
	: bankKod(other.bankKod), kliensekSzama(other.kliensekSzama) 
{
	for (unsigned index = 0; index < MAX_KLIENSEK; ++index) 
	{
		kliensek[index] = other.kliensek[index];
	}
}
string Bank::getBankKod() const
{
	return bankKod;
}

unsigned Bank::getKliensekSzama() const
{
	return kliensekSzama;
}
Kliens* Bank::getKliens(unsigned index) const
{
	if (index >= kliensekSzama)
	{
		return nullptr;
	}
	return kliensek[index];
}

void Bank::setBankKod(string ujBankKod)
{
	bankKod = ujBankKod;
}

void Bank::hozzaadKliens(Kliens* ujKliens)
{
	if (kliensekSzama >= MAX_KLIENSEK)
	{
		cout << "Hiba: A bank mar elerte a maximális kliensek szamat." << endl;
		return;
	}
	kliensek[kliensekSzama] = ujKliens;
	kliensekSzama++;

}

void Bank::kiirBank() const
{
	cout << "Bank kod: " << bankKod << endl;
	cout << "Kliensek szama: " << kliensekSzama << endl;
	for (unsigned index = 0; index < kliensekSzama; ++index)
	{
			kliensek[index]->kiirKliens();
		
	}
}