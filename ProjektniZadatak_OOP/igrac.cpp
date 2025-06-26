#include "igrac.h"

Igrac::Igrac(string ime, double balans) {
	id = br++;
	this->ime = ime;
	this->balans = balans;
}
Igrac::Igrac(Igrac& i) {
	ime = i.ime;
	balans = i.balans;
}

istream& operator>>(istream& in, Igrac& i) {
	in >> i.ime >> i.balans;
	return in;
}

ostream& operator<<(ostream& out, Igrac& i) {
	out << "ID: " << i.id << " Ime: " << i.ime << " Balans: " << i.balans;
	return out;
}