#ifndef BANK_H
#define BANK_H

#include <string>
#include "Kliens.h"
using namespace std;

const unsigned MAX_KLIENSEK = 10;

class Bank {
private:
	string bankKod;
	unsigned kliensekSzama;
	Kliens* kliensek[MAX_KLIENSEK];

public:
	Bank(string ujBankKod = "");
	Bank(const Bank& other);

	string getBankKod() const;
	unsigned getKliensekSzama() const;
	Kliens* getKliens(unsigned index) const;
	void setBankKod(string ujBankKod);

	void hozzaadKliens(Kliens* ujKliens);

	void kiirBank() const;
};

#endif // BANK_H
