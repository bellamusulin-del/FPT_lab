#include "Tort.h"
#include <iostream>
using namespace std;
Tort::Tort(int ujSzamlalo, int ujNevezo)
	:szamlalo(ujSzamlalo), nevezo(ujNevezo)
{
	if (nevezo == 0)
	{
		cout << "Hiba: a nevezo nem lehet 0, 1-re allitom." << endl;
		nevezo = 1;
	}
}
Tort::Tort(const Tort& other)
	:szamlalo(other.szamlalo), nevezo(other.nevezo) {

}
int Tort::getSzamlalo() const
{
	return szamlalo;
}
int Tort::getNevezo() const
{
	return nevezo;
}

int Tort::lnko(int elsoSzam, int masodikSzam)
{
	if (elsoSzam < 0)
	{
		elsoSzam = -elsoSzam;
	}
	if (masodikSzam < 0)
	{
		masodikSzam = -masodikSzam;
	}
	while (masodikSzam != 0)
	{
		int maradek = elsoSzam % masodikSzam;
		elsoSzam = masodikSzam;
		masodikSzam = maradek;
	}
	return elsoSzam;
}

Tort Tort::osszead(const Tort& other) const
{
	int ujSzamlalo = szamlalo * other.nevezo + other.szamlalo * nevezo;
	int ujNevezo = nevezo * other.nevezo;
	return Tort(ujSzamlalo, ujNevezo);
}

Tort Tort::kivon(const Tort& other) const
{
	int ujSzamlalo = szamlalo * other.nevezo - other.szamlalo * nevezo;
	int ujNevezo = nevezo * other.nevezo;
	return Tort(ujSzamlalo, ujNevezo);
}

Tort Tort::szoroz(const Tort& other) const
{
	int ujSzamlalo = szamlalo * other.szamlalo;
	int ujNevezo = nevezo * other.nevezo;
	return Tort(ujSzamlalo, ujNevezo);
}
Tort Tort::oszt(const Tort& other) const
{
	if (other.szamlalo == 0)
	{
		cout << "Hiba: nullaval valo osztas." << endl;
		return Tort(0, 1);
	}
	int ujSzamlalo = szamlalo * other.nevezo;
	int ujNevezo = nevezo * other.szamlalo;
	return Tort(ujSzamlalo, ujNevezo);
}
Tort Tort ::egyszerusites()
{
	int lnkoErtek = lnko(szamlalo, nevezo);
	szamlalo /= lnkoErtek;
	nevezo /= lnkoErtek;
	return *this;
}
Tort Tort::forditott() const
{
	return Tort(nevezo, szamlalo);
}
bool Tort::egyenlo(const Tort& other) const
{
	int bal = szamlalo * other.nevezo;
	int jobb = other.szamlalo * nevezo;
	return bal == jobb;
}
void Tort::print() const
{
	cout << szamlalo << "/" << nevezo << endl;
}