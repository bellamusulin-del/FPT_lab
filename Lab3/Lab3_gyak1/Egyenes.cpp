#include "Egyenes.h"
#include "Pont.h"
#include<iostream>
using namespace std;
Egyenes::Egyenes(double ujMeredekseg, double ujSzabadtag)
	:meredekseg(ujMeredekseg), szabadtag(ujSzabadtag)
{
}
Egyenes::Egyenes(const Egyenes& other)
	:meredekseg(other.meredekseg), szabadtag(other.szabadtag)
{
}
Egyenes::~Egyenes()
{
}
double Egyenes::getMeredekseg() const
{
	return meredekseg;

}
double Egyenes::getSzabadtag() const {
	return szabadtag;
}
void Egyenes::setSzabadtag(double ujSzabadtag) {
	szabadtag = ujSzabadtag;
}
int Egyenes::helyzet(const Pont& pont) const {
	double kulonbseg = meredekseg * pont.x +szabadtag-pont.y;
	if (kulonbseg == 0)
	{
		return 0;
	}
	if (kulonbseg > 0)
	{
		return 1;
	}
	return -1;
}
void Egyenes::kiir() const
{
	cout << "Egyenes:y=" << meredekseg << "*x+" << szabadtag << endl;
}