#include "pseudorulet.h"

Pseudorulet::Pseudorulet() : KrajnjiIshod(0), boja('r'), ParniBrojevi(false), nizL(new bool[36]) {}

void Pseudorulet::NovaIgra() {
	KrajnjiIshod = 0;
	boja = 'r';
	ParniBrojevi = false;
	nizL = new bool[36];
}

void Pseudorulet::GenerisiBroj() {
	KrajnjiIshod = rand() % 37;
}

bool Pseudorulet::jelParan() {
	return KrajnjiIshod % 2 == 0;
}

bool Pseudorulet::jelCrven() {
	if ((KrajnjiIshod % 2 != 0) && ((0 < KrajnjiIshod && KrajnjiIshod <= 10) || (19 <= KrajnjiIshod && KrajnjiIshod <= 28)))
		return true;
	else if ((KrajnjiIshod % 2 == 0) && ((11 <= KrajnjiIshod && KrajnjiIshod <= 18) || (29 <= KrajnjiIshod && KrajnjiIshod <= 36))) {
		return true;
	}
	else
		return false;
}


void Pseudorulet::operator+=(int ishod) {
	nizL[ishod] = true;
}


bool& Pseudorulet::operator[](int a) {
	return nizL[a];
}

void Pseudorulet::operator*= (char b) {
	boja = b;
}

void Pseudorulet::operator/=(bool a) {
	ParniBrojevi = true;
}

void Pseudorulet::operator-=(bool a) {
	ParniBrojevi = false;
}

void Pseudorulet::operator+(Igrac& i) {
	if (nizL[KrajnjiIshod]) {
		i.setBalans(i.getBalans() + 1.0);
	}
	else {
		i.setBalans(i.getBalans() - 1.0);
	}
}


void Pseudorulet::zapocni_igru(Igrac& i) {
	cout << "\t|||PSEUDORULET|||\n";
	cout << "Unesite broj na koji se kladite!(0-36): ";
	int n;
	while (true) {
		cin >> n;
		if (n < 0 || n > 36)
			cout << "GRESKA! Unesite broj od 0 do 36!\n";
		else {
			cout << "Nema vise biranja kugla se izbacuje!\n";
			break;
		}
	}
	cout << "........Kugla se vrti.........\n";
	GenerisiBroj();
	if (KrajnjiIshod == n)
		nizL[KrajnjiIshod] = true;
	else nizL[KrajnjiIshod] = false;
	cout << "Kugla je pala na broj " << KrajnjiIshod<<endl;
	if (nizL[KrajnjiIshod])
		cout << "Pogodili ste broj! Cestitamo!\n";
	else
		cout << "Niste pogodili broj...vise srece sledeci put!\n";
	operator+(i);
}