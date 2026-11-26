#ifndef PONT_H
#define PONT_H

#include "Egyenes.h"

class Pont {
private:
	double x;
	double y;

	
	static Egyenes egyenes;

	
	static int pontokAzEgyenesen;
	static int pontokPozitivFelsikban;
	static int pontokNegativFelsikban;

	
	void szamlalasHozzaad();
	void szamlalasElvesz();

public:
	
	friend class Egyenes;

	friend double tavolsag(const Pont& elsoPont, const Pont& masodikPont);

	Pont(double ujX = 0, double ujY = 0);
	Pont(const Pont& other);
	~Pont();

	double getX() const;
	double getY() const;
	void setX(double ujX);
	void setY(double ujY);

	static int getPontokAzEgyenesen();
	static int getPontokPozitivFelsikban();
	static int getPontokNegativFelsikban();

	void kiir() const;
};

double tavolsag(const Pont& elsoPont, const Pont& masodikPont);

#endif // PONT_H