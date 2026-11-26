#ifndef EGYENES_H
#define EGYENES_H

class Pont;

class Egyenes {
private:
	double meredekseg;
	double szabadtag;

public:
	Egyenes(double ujMeredekseg = 1, double ujSzabadtag = 0);

	Egyenes(const Egyenes& other);

	~Egyenes();

	double getMeredekseg() const;
	double getSzabadtag() const;
	void setMeredekseg(double ujMeredekseg);
	void setSzabadtag(double ujSzabadtag);

	int helyzet(const Pont& pont)const;

	void kiir()const;


};
#endif //EGYENES_H
