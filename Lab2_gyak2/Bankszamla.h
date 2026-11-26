#ifndef BANKSZAMLA_H
#define BANKSZAMLA_H

#include <string>
#include <iostream>
#include "Muveletek.h"
using namespace std;

class Bankszamla : public Muveletek {
private:
	string szamlaSzam;
	float osszeg;
	string penznem;

public:
	Bankszamla(string ujSzamlaSzam = "", float ujOsszeg = 0.0f, string ujPenznem = "RON");
	Bankszamla(const Bankszamla& other);

	string getSzamlaSzam() const;
	float getAlapOsszeg() const;
	string getPenznem() const;
	void setSzamlaSzam(string ujSzamlaSzam);
	void setOsszeg(float ujOsszeg);
	void setPenznem(string ujPenznem);

	float getOsszeg() const;
	float getKamat() const;
	void letet(float befizetettOsszeg);
	void kivet(float kivettOsszeg);

	void transzfer(Bankszamla& hova, float atutaltOsszeg);

	void kiirSzamla() const;
};

#endif // BANKSZAMLA_H