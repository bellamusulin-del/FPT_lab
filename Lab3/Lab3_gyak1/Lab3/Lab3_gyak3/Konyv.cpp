#include "Konyv.h"

int Konyv::peldanyokSzama = 0;

Konyv::Konyv(string ujSzerzo, string ujCim, string ujIsbn, int ujEv)
	: szerzo(ujSzerzo), cim(ujCim), isbn(ujIsbn), ev(ujEv)
{
	peldanyokSzama++;
}

Konyv::Konyv(const Konyv& other)
	: szerzo(other.szerzo), cim(other.cim), isbn(other.isbn), ev(other.ev)
{
	peldanyokSzama++;
}

Konyv::~Konyv()
{
	peldanyokSzama--;
}

void Konyv::kiir() const
{
	cout << "Szerzo: " << szerzo
		<< " | Cim: " << cim
		<< " | ISBN: " << isbn
		<< " | Ev: " << ev << endl;
}