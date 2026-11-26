#ifndef CSOMOPONT_H
#define CSOMOPONT_H


class SZLL;

class Csomopont {
private:
	int adat;
	Csomopont* kovetkezo;  
public:
	friend class SZLL;
    Csomopont(int ujAdat = 0);
	Csomopont(const Csomopont& other);
	~Csomopont();

	int getAdat() const;
	void setAdat(int ujAdat);
};

#endif // CSOMOPONT_H