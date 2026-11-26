#include "SZLL.h"
#include <iostream>
using namespace std;

SZLL::SZLL()
	: fej(nullptr),meret(0)
{
}
SZLL::SZLL(const SZLL& other)
	: fej(nullptr), meret(0)
{
	Csomopont* aktualis = other.fej;

	while (aktualis != nullptr)
	{
		beszurVegere(aktualis->adat);
		aktualis = aktualis->kovetkezo;
	}
}


SZLL::~SZLL()
{
	Csomopont* aktualis = fej;

	while (aktualis != nullptr)
	{
		Csomopont* torlendo = aktualis;
		aktualis = aktualis->kovetkezo;
		delete torlendo;
	}

	fej = nullptr;
	meret = 0;
}

int SZLL::getMeret() const
{
	return meret;
}

bool SZLL::ures() const
{
	return fej == nullptr;
}


void SZLL::beszurElejere(int ujAdat)
{
	Csomopont* ujCsomopont = new Csomopont(ujAdat);


	ujCsomopont->kovetkezo = fej;
	fej = ujCsomopont;
	meret++;
}

void SZLL::beszurVegere(int ujAdat)
{
	Csomopont* ujCsomopont = new Csomopont(ujAdat);

	if (fej == nullptr)
	{
	
		fej = ujCsomopont;
	}
	else
	{
		Csomopont* aktualis = fej;
		while (aktualis->kovetkezo != nullptr)
		{
			aktualis = aktualis->kovetkezo;
		}
		aktualis->kovetkezo = ujCsomopont;
	}
	meret++;
}

void SZLL::beszurPozicioba(int ujAdat, int pozicio)
{
	if (pozicio < 0 || pozicio > meret)
	{
		cout << "Hiba: ervenytelen pozicio." << endl;
		return;
	}

	if (pozicio == 0)
	{
		beszurElejere(ujAdat);
		return;
	}

	Csomopont* elozo = fej;
	for (int lepes = 0; lepes < pozicio - 1; lepes++)
	{
		elozo = elozo->kovetkezo;
	}

	Csomopont* ujCsomopont = new Csomopont(ujAdat);

	ujCsomopont->kovetkezo = elozo->kovetkezo;
	elozo->kovetkezo = ujCsomopont;
	meret++;
}


void SZLL::torolElsot()
{
	if (fej == nullptr)
	{
		cout << "Hiba: a lista ures." << endl;
		return;
	}

	Csomopont* torlendo = fej;
	fej = fej->kovetkezo;
	delete torlendo;
	meret--;
}
void SZLL::torolUtolsot()
{
	if (fej == nullptr)
	{
		cout << "Hiba: a lista ures." << endl;
		return;
	}

	if (fej->kovetkezo == nullptr)
	{
		delete fej;
		fej = nullptr;
		meret--;
		return;
	}

	
	Csomopont* aktualis = fej;
	while (aktualis->kovetkezo->kovetkezo != nullptr)
	{
		aktualis = aktualis->kovetkezo;
	}

	delete aktualis->kovetkezo;
	aktualis->kovetkezo = nullptr;
	meret--;
}
void SZLL::torolPozicio(int pozicio)
{
	if (pozicio < 0 || pozicio >= meret)
	{
		cout << "Hiba: ervenytelen pozicio." << endl;
		return;
	}

	if (pozicio == 0)
	{
		torolElsot();
		return;
	}
	Csomopont* elozo = fej;
	for (int lepes = 0; lepes < pozicio - 1; lepes++)
	{
		elozo = elozo->kovetkezo;
	}

	Csomopont* torlendo = elozo->kovetkezo;
	elozo->kovetkezo = torlendo->kovetkezo;
	delete torlendo;
	meret--;
}

void SZLL::kiir() const
{
	if (fej == nullptr)
	{
		cout << "(ures lista)" << endl;
		return;
	}

	Csomopont* aktualis = fej;
	while (aktualis != nullptr)
	{
		cout << aktualis->adat;
		if (aktualis->kovetkezo != nullptr)
		{
			cout << " -> ";
		}
		aktualis = aktualis->kovetkezo;
	}
	cout << endl;
}