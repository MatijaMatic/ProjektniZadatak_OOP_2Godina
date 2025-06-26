#ifndef __blackjack_h__
#define __blackjack_h__
#include "igra.h"
#include <cstdlib>
#include<ctime>

class Blackjack:public Igra {
	int spil[52];
	int ruka[9];
	int prvi_spil[52];
public:
	Blackjack();
	void NovaIgra();
	int SlucBroj();
	int TrenRez();
	int NovaKarta();
	void PrekidIgre(Igrac& i,int r);
	void zapocni_igru(Igrac& i);
	void ispis(int r);
};

#endif // !__blackjack_h__
