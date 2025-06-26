#ifndef __igra_h__
#define __igra_h__
#include "skor.h"


class Igra {
	string naziv;
	struct Lista {
		Skor* s;
		Lista* sled;
	};
	Lista* prvi;
public:
	string getNaziv() { return naziv; }
	Lista getLista() { return *prvi; }
	void operator+=(Skor * s);
	Skor* operator-(double rez);
	void SortirajMV();
	void SortirajVM();
	//void zapocni_igru(Igrac i);
	void PromeniBalans(double balans,Igrac& igrac);
	friend ostream& operator<<(ostream& out, Igra& i);
};

#endif // !__igra_h__
