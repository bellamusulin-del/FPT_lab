#pragma once 
#ifndef TORT_H
#define TORT_H
#include<iostream>
using namespace std;

class Tort {
private:
	int szamlalo;
	int nevezo;
public:
	Tort(int ujSzamlalo = 0, int ujNevezo = 1);

	Tort(const Tort& other);

	int getSzamlalo() const;
	int getNevezo() const;
	static int lnko(int elsoSzam, int masodikSzam);

	Tort osszead(const Tort& other) const;
	Tort kivon(const Tort& other) const;
	Tort szoroz(const Tort& other) const;
	Tort oszt(const Tort& other) const;

	Tort egyszerusites();
	Tort forditott() const;
	bool egyenlo(const Tort& other) const;
	void print() const;
};

#endif // TORT_H