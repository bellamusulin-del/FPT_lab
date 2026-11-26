#ifndef SZLL_H
#define SZLL_H

#include "Csomopont.h"

class SZLL {
private:
	Csomopont* fej;    
	int meret;

public:
	SZLL();
	SZLL(const SZLL& other);
	~SZLL();

	int getMeret() const;
	bool ures() const;
	void beszurElejere(int ujAdat);
	void beszurVegere(int ujAdat);
	void beszurPozicioba(int ujAdat, int pozicio);  
    void torolElsot();
	void torolUtolsot();
	void torolPozicio(int pozicio);                 
    void kiir() const;
};

#endif // SZLL_H