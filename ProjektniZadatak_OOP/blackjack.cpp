#include "blackjack.h"
#include "kazino.h"

Blackjack::Blackjack() {
	int BrKarata[13] = { 4,4,4,4,4,4,4,4,4,4,4,4,4 };
	for (int i = 0; i <52 ; i++)
	{
		int r = rand() % 13;
		if (BrKarata[r]>0)
		{
			spil[i] = r;
			BrKarata[r]--;
		}
		else
		{
			i--;
		}
		for (int i = 0; i < 9; i++)
		{
			ruka[i] = 0;
		}
		for (int i = 0; i < 52; i++)
		{
			prvi_spil[i] = spil[i];
		}
	}
	srand(time(NULL));
}

void Blackjack::NovaIgra() {
	for (int i = 0; i < 52; i++)
		spil[i] = prvi_spil[i];
	for (int i = 0; i < 9; i++)
		ruka[i] = 0;
}

int Blackjack::SlucBroj() {
	return rand() % 13 + 1;
}

int Blackjack::TrenRez() {
	int s=0;
	for (int i = 0; i < 9; i++){
		if (1 < ruka[i] < 10)
			s += ruka[i];
		else if (10<ruka[i]<=13) 
			s += 10;
		else if (ruka[i] == 1){
			if (s > 10)
				s += 1;
			else
				s += 11;
		}
	}
	return s;
}

int Blackjack::NovaKarta() {
	for (int i = 0; i < 52; i++){
		if (spil[i]!=0){
			for (int j = 0; j < 9; j++){
				if (ruka[j] == 0 ){
					ruka[j] = spil[i]; 
					spil[i] = 0;
					i = 53;
					break;
				}
			}
		}
	}
	return TrenRez();
}

void Blackjack::PrekidIgre(Igrac& i, int r) {
	int a = TrenRez();
	if (a > 21) {
		cout << "BUST! Kazino dobija!  -3\n";
		i.setBalans(i.getBalans() - 3);
		return;
	}
	else if (r >= 15 && r <= 21 && r > a)
	{
		cout << "Dealer dobija!  -3\n";
		i.setBalans(i.getBalans() - 3);
		return;
	}
	else if(a<=21 && r>21){
		cout << "Dealer bust!  +3\n";
		i.setBalans(i.getBalans() + 3);
	}
	else if((a<=21)&& (a>r)){
		cout << "Pobedili ste!  +3\n";
		i.setBalans(i.getBalans() + 3);
		return;
	}
}

void Blackjack::ispis(int r) {
	cout << "Dobili ste ";
	for (int i = 0; i < 9; i++)
	{
		if (ruka[i] != 0)
		{
			cout << "|" << ruka[i] << "|";
		}
	}
	cout << "\nUkupno: " << TrenRez() << endl;
	cout << "Dealer: " << r << endl;
}

void Blackjack::zapocni_igru(Igrac& i) {
	cout << "\t|||BLACKJACK|||\n";
	int r = rand() % 11 + 15;
	ovde:
	cout << "Dealer deli karte....\n";
	NovaKarta(); NovaKarta();
	ispis(r);
	char k = NULL;
	while (k != 's')
	{
		cout << "Hit/Stand?\t(h/s)";
		cin >> k;
		if (k == 'h') {
			NovaKarta();
			ispis(r);
		}
	}
	PrekidIgre(i, r);
	cout << "Nova igra\t(d/n) "; cin >> k;
	if (k == 'd')
	{
		NovaIgra();
		goto ovde;
	}
	cout << "Dovidjenja!\n";


}