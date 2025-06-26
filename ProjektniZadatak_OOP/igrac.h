#ifndef __igrac_h__
#define __igrac_h__
#include <iostream>
#include <string>
using namespace std;


class Igrac {
	int id;
	string ime;
	double balans;
public:
	int br=1;
	Igrac(string ime,double balans);
	int getID() { return id; }
	string getIme() { return ime; }
	double getBalans() { return balans; }
	void setBalans(double a) { balans = a; }
	Igrac(Igrac& i);
	friend istream& operator>>(istream& in, Igrac& i);
	friend ostream& operator<<(ostream&, Igrac& i);
};


#endif // !__igrac_h__
