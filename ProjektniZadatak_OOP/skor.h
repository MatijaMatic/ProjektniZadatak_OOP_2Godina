#ifndef __skor_h__
#define __skor_h__
#include "igrac.h"


class Skor {
	double rezultat;
	Igrac* igrac;
public:
	Skor() {
		rezultat = 0.0;
		igrac = nullptr;
	}
	Skor(const Skor& s) = delete;
	double getRez() { return rezultat; }
	void setRez(double a) { rezultat = a; }
	Igrac getIgrac(Igrac i) { return i; }
	Igrac setIgrac(Igrac i) { igrac = &i; }

	friend ostream& operator<<(ostream& out, Skor& s) {
		out << s.igrac->getIme() << "\t" << s.igrac->getID() << "\t" << s.rezultat;
		return out;
	}
};
#endif // !__skor_h__
