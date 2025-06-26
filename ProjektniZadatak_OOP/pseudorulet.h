#ifndef __pseudorulet_h__
#define __pseudorulet_h__
#include "igra.h"
#include <cstdlib>


class Pseudorulet:public Igra{
	int KrajnjiIshod;
	bool *nizL;
	char boja;
	bool ParniBrojevi;
public:
	Pseudorulet();
	void NovaIgra();
	void GenerisiBroj();
	void SetVrednostNiza(int i,bool a);
	bool jelParan();
	bool jelCrven();
	void operator+=(int a);
	bool& operator[](int a);
	void operator*=(char b);
	void zapocni_igru(Igrac &i);
	void operator/=(bool a);
	void operator-=(bool a);
	void operator+(Igrac &i);
	~Pseudorulet() {
		delete[] nizL;
	}
};

#endif // !__pseudorulet_h__
