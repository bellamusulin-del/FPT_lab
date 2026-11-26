#include "Pont.h"
#include <iostream>
#include <cmath>
using namespace std;

Egyenes Pont::egyenes(2, 1);   // y = 2x + 1
int Pont::pontokAzEgyenesen = 0;
int Pont::pontokPozitivFelsikban = 0;
int Pont::pontokNegativFelsikban = 0;

void Pont::szamlalasHozzaad()
{
	int pontHelyzete = egyenes.helyzet(*this);

	if (pontHelyzete == 0)
	{
		pontokAzEgyenesen++;
	}
	else if (pontHelyzete > 0)
	{
		pontokPozitivFelsikban++;
	}
	else
	{
		pontokNegativFelsikban++;
	}
}

void Pont::szamlalasElvesz()
{
	int pontHelyzete = egyenes.helyzet(*this);

	if (pontHelyzete == 0)
	{
		pontokAzEgyenesen--;
	}
	else if (pontHelyzete > 0)
	{
		pontokPozitivFelsikban--;
	}
	else
	{
		pontokNegativFelsikban--;
	}
}

Pont::Pont(double ujX, double ujY)
	: x(ujX), y(ujY)
{
	szamlalasHozzaad();
}

Pont::Pont(const Pont& other)
	: x(other.x), y(other.y)
{
	szamlalasHozzaad();
}

Pont::~Pont()
{
	szamlalasElvesz();
}

double Pont::getX() const
{
	return x;
}

double Pont::getY() const
{
	return y;
}

void Pont::setX(double ujX)
{
	szamlalasElvesz();
	x = ujX;
	szamlalasHozzaad();
}

void Pont::setY(double ujY)
{
	szamlalasElvesz();
	y = ujY;
	szamlalasHozzaad();
}

int Pont::getPontokAzEgyenesen()
{
	return pontokAzEgyenesen;
}

int Pont::getPontokPozitivFelsikban()
{
	return pontokPozitivFelsikban;
}

int Pont::getPontokNegativFelsikban()
{
	return pontokNegativFelsikban;
}

void Pont::kiir() const
{
	cout << "(" << x << ", " << y << ")" << endl;
}

double tavolsag(const Pont& elsoPont, const Pont& masodikPont)
{
	double xKulonbseg = elsoPont.x - masodikPont.x;
	double yKulonbseg = elsoPont.y - masodikPont.y;
	double negyzetosszeg = xKulonbseg * xKulonbseg + yKulonbseg * yKulonbseg;
	return sqrt(negyzetosszeg);
}