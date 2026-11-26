#include "Csomopont.h"

Csomopont::Csomopont(int ujAdat)
	: adat(ujAdat), kovetkezo(nullptr)
{
}
Csomopont::Csomopont(const Csomopont& other)
	: adat(other.adat), kovetkezo(nullptr)
{
}

Csomopont::~Csomopont()
{
}

int Csomopont::getAdat() const
{
	return adat;
}

void Csomopont::setAdat(int ujAdat)
{
	adat = ujAdat;
}