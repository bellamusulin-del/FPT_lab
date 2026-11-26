#include "Tort.h"
#include <iostream>
using namespace std;
int main() {
	Tort nullaTort;
	Tort egeszTort(5);
	Tort elsoTort(1, 2);
	Tort masodikTort(3, 4);
	Tort masolat(masodikTort);
	cout << "Konstruktorok tesztelese:";
	nullaTort.print();
	egeszTort.print();
	masolat.print();

	cout << "Osszeadas tesztelese:";
	elsoTort.osszead(masodikTort).print();


	cout << "Kivonas tesztelese:";
	elsoTort.kivon(masodikTort).print();

	cout << "Szorzas tesztelese : ";
		elsoTort.szoroz(masodikTort).print();

	cout<<"Osztas tesztelese:";
	elsoTort.oszt(masodikTort).print();

    cout<<"LNKO tesztelese(12,18):";
	cout << Tort::lnko(12, 18) << endl;

	Tort egyszerusitendo(6, 8);
	cout << "Egyszerusites tesztelese:";
	egyszerusitendo.egyszerusites().print();

	cout << "Forditott tesztelese:";
	masodikTort.forditott().print();

	Tort ketHarmad(2, 3);
	Tort Negyhatod(4, 6);
	if (ketHarmad.egyenlo(Negyhatod)) {
		cout << "2/3 es 4/6 egyenlo " << endl;
	}
	else
	{
		cout << "2/3 es 4/6 nem egyenlo " << endl;
	}
	return 0;
	
}