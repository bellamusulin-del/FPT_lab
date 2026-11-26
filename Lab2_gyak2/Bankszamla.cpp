#include "Bankszamla.h"
#include <iostream>
using namespace std;

Bankszamla::Bankszamla(string ujSzamlaSzam, float ujOsszeg, string ujPenznem)
	: szamlaSzam(ujSzamlaSzam), osszeg(ujOsszeg), penznem(ujPenznem)
{
}

Bankszamla::Bankszamla(const Bankszamla& other)
	: szamlaSzam(other.szamlaSzam), osszeg(other.osszeg), penznem(other.penznem)
{
}

string Bankszamla::getSzamlaSzam() const
{
	return szamlaSzam;
}

float Bankszamla::getAlapOsszeg() const
{
	return osszeg;
}

string Bankszamla::getPenznem() const
{
	return penznem;
}

void Bankszamla::setSzamlaSzam(string ujSzamlaSzam)
{
	szamlaSzam = ujSzamlaSzam;
}

void Bankszamla::setOsszeg(float ujOsszeg)
{
	osszeg = ujOsszeg;
}

void Bankszamla::setPenznem(string ujPenznem)
{
	penznem = ujPenznem;
}

// A kamat összegét adja vissza (nem a százalékot)
float Bankszamla::getKamat() const
{
	float kamatSzazalek = 0;

	if (penznem == "RON")
	{
		if (osszeg < 500)
		{
			kamatSzazalek = 0.3f;
		}
		else
		{
			kamatSzazalek = 0.8f;
		}
	}
	else if (penznem == "EUR")
	{
		kamatSzazalek = 0.1f;
	}

	return osszeg * kamatSzazalek / 100;
}

// A számlán lévő összeg kamattal együtt
float Bankszamla::getOsszeg() const
{
	return osszeg + getKamat();
}

void Bankszamla::letet(float befizetettOsszeg)
{
	if (befizetettOsszeg <= 0)
	{
		cout << "Hiba: a befizetett osszeg pozitiv kell legyen." << endl;
		return;
	}
	osszeg = osszeg + befizetettOsszeg;
}

void Bankszamla::kivet(float kivettOsszeg)
{
	if (kivettOsszeg <= 0)
	{
		cout << "Hiba: a kivett osszeg pozitiv kell legyen." << endl;
		return;
	}
	if (kivettOsszeg > osszeg)
	{
		cout << "Hiba: nincs eleg fedezet a szamlan." << endl;
		return;
	}
	osszeg = osszeg - kivettOsszeg;
}

void Bankszamla::transzfer(Bankszamla& hova, float atutaltOsszeg)
{
	// Csak RON számlák között lehet átutalni
	if (penznem != "RON" || hova.penznem != "RON")
	{
		cout << "Hiba: transzfer csak RON szamlak kozott lehetseges." << endl;
		return;
	}
	if (atutaltOsszeg <= 0)
	{
		cout << "Hiba: az atutalt osszeg pozitiv kell legyen." << endl;
		return;
	}
	if (atutaltOsszeg > osszeg)
	{
		cout << "Hiba: nincs eleg fedezet az atutalashoz." << endl;
		return;
	}

	kivet(atutaltOsszeg);
	hova.letet(atutaltOsszeg);
}

void Bankszamla::kiirSzamla() const
{
	cout << "    Szamla: " << szamlaSzam
		<< " | Osszeg: " << osszeg << " " << penznem
		<< " | Kamat: " << getKamat()
		<< " | Osszeg kamattal: " << getOsszeg() << endl;
}