#ifndef KONYV_H
#define KONYV_H

#include <string>
#include <iostream>
using namespace std;

class Konyv {
private:
	string szerzo;
	string cim;
	string isbn;    
	int ev;
    static int peldanyokSzama;

public:
	Konyv(string ujSzerzo = "", string ujCim = "", string ujIsbn = "", int ujEv = 0);
	Konyv(const Konyv& other);
	~Konyv();
	string getSzerzo() const { return szerzo; }
	string getCim() const { return cim; }
	string getIsbn() const { return isbn; }
	int getEv() const { return ev; }
	void setSzerzo(string ujSzerzo) { szerzo = ujSzerzo; }
	void setCim(string ujCim) { cim = ujCim; }
	void setIsbn(string ujIsbn) { isbn = ujIsbn; }
	void setEv(int ujEv) { ev = ujEv; }
	bool szerzoEgyezik(const string& keresettSzerzo) const;
	static int getPeldanyokSzama() { return peldanyokSzama; }
	void kiir() const;
};

inline bool Konyv::szerzoEgyezik(const string& keresettSzerzo) const
{
	return szerzo == keresettSzerzo;
}

#endif // KONYV_H