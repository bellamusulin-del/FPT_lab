#include "Kliens.h"
#include <iostream>
using namespace std;

Kliens::Kliens(string ujVezeteknev, string ujKeresztnev, string ujLakcim) :
	vezeteknev(ujVezeteknev), keresztnev(ujKeresztnev), lakcim(ujLakcim), kontokSzama(0) {
	for (unsigned index = 0; index < MAX_KONTOK; ++index) {
		kontok[index] = nullptr;
	}
}

Kliens::Kliens(const Kliens& other) :
	vezeteknev(other.vezeteknev), keresztnev(other.keresztnev), lakcim(other.lakcim), kontokSzama(other.kontokSzama) {
	for (unsigned index = 0; index < MAX_KONTOK; ++index) {
		kontok[index] = other.kontok[index];
	}
}
string Kliens::getVezeteknev() const {
	return vezeteknev;
}
string Kliens::getKeresztnev() const {
	return keresztnev;
}
string Kliens::getLakcim() const
{
	return lakcim;
}

unsigned Kliens::getKontokSzama() const
{
	return kontokSzama;
}

Bankszamla* Kliens::getKonto(unsigned index) const
{
	if (index >= kontokSzama)
	{
		return nullptr;
	}
	return kontok[index];
}

void Kliens::setVezeteknev(string ujVezeteknev)
{
	vezeteknev = ujVezeteknev;
}

void Kliens::setKeresztnev(string ujKeresztnev)
{
	keresztnev = ujKeresztnev;
}

void Kliens::setLakcim(string ujLakcim)
{
	lakcim = ujLakcim;
}

void Kliens::hozzaadKonto(Bankszamla* ujKonto)
{
	if (kontokSzama >= MAX_KONTOK)
	{
		cout << "Hiba: a kliensnek nem lehet tobb szamlaja." << endl;
		return;
	}
	kontok[kontokSzama] = ujKonto;
	kontokSzama++;
}

// Kiírja a kliens adatait, majd meghívja minden számla kiírását
void Kliens::kiirKliens() const
{
	cout << "  Kliens: " << vezeteknev << " " << keresztnev
		<< " | Lakcim: " << lakcim
		<< " | Szamlak szama: " << kontokSzama << endl;

	for (unsigned index = 0; index < kontokSzama; index++)
	{
		kontok[index]->kiirSzamla();
	}
}