#ifndef KLIENS_H
#define KLIENS_H

#include <string>
#include "Bankszamla.h"
using namespace std;

const unsigned MAX_KONTOK = 10;

class Kliens {
private:
	string vezeteknev;
	string keresztnev;
	string lakcim;
	unsigned kontokSzama;
	Bankszamla* kontok[MAX_KONTOK];

public:
	Kliens(string ujVezeteknev = "", string ujKeresztnev = "", string ujLakcim = "");
	Kliens(const Kliens& other);

	string getVezeteknev() const;
	string getKeresztnev() const;
	string getLakcim() const;
	unsigned getKontokSzama() const;
	Bankszamla* getKonto(unsigned index) const;

	void setVezeteknev(string ujVezeteknev);
	void setKeresztnev(string ujKeresztnev);
	void setLakcim(string ujLakcim);

	void hozzaadKonto(Bankszamla* ujKonto);

	void kiirKliens() const;
};

#endif // KLIENS_H