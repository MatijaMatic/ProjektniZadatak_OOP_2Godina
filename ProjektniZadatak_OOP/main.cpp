#include <iostream>
#include "pseudorulet.h"
#include "blackjack.h"
#include "kazino.h"
#include "greskaunos.h"

int main() {

    Kazino k(1000);
    Igrac i1("Pera Peric", 50);
    Igrac i1player2("Ranko Rankovic", 30);
    while (true) {
        cout << "\n\tDOBRO DOSLI U KAZINO!\n";
        cout << "Izaberite opciju:\n";
        cout << "1. Pseudorulet\n";
        cout << "2. Blekdzek\n";
        cout << "3. Balans igraca\n";
        cout << "4. Dodaj budzet kazinu\n";
        cout << "5. Izlaz\n";

        int a;
        cin >> a;

        switch (a) {
        case 1: {
            Pseudorulet pseudorulet;
            pseudorulet.zapocni_igru(i1);
            break;
        }
        case 2: {
            Blackjack blackjack;
            blackjack.zapocni_igru(i1);
            break;
        }
        case 3:
            cout << "Trenutni balans igraca " << i1.getIme() << " je " << i1.getBalans() << endl;
            break;
        case 4: {
            double budz;
            cout << "Unesite kliko novca dodajete budzetu kazina: ";
            cin >> budz;
            k.setBudzet(budz);
            cout << "Novi budzet kazina je: " << k.getBudzet() << endl;
            break;
        }
        case 5:
            cout << "Izasli ste iz kazina dovidjenja!.\n";
            return 0;
            default:
                throw UnosGreska("Pogresan broj! Unesite broj od 1-5\n");
            }
        if (i1.getBalans()<=0)
        {
            cout << "Potrisili ste novac, ne mozete vise igrati...\n";
            exit;
        }
    }
    return 0;
}
