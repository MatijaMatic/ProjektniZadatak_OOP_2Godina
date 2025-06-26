#include "kazino.h"

Kazino::Kazino(double broj) : budzet(broj), glava(nullptr) {}

void Kazino::setBudzet(double a) {
    budzet += a;
}

void Kazino::DodajNovuIgru(Igra* i) {
    ListaDupla* novi = new ListaDupla(i);
    if (glava == nullptr) {
        glava = novi;
    }
    else {
        ListaDupla* tek = glava;
        while (tek->sled) {
            tek = tek->sled;
        }
        tek->sled = novi;
        novi->prosli = tek;
    }
}

void Kazino::PrikazListeIgara() {
    cout << "Igre:\n";
    ListaDupla* tek = glava;
    while (tek!=nullptr) {
        cout << tek->igra->getNaziv() << "\n";
        tek = tek->sled;
    }
}

void Kazino::PovecatiBalans(Igrac& i, double a) {
    i.setBalans(i.getBalans() + a);
}

int Kazino::IzaberiIgru()  {
    cout << "Igre:\n";
    PrikazListeIgara();

    int n;
    cout << "Izaberite sa 1 ili 2";
    cin >> n;
    return n;
}

Kazino::~Kazino() {
    ListaDupla* tek = glava;
    while (tek != nullptr) {
        ListaDupla* sled = tek->sled;
        delete tek->igra;
        delete tek;
        tek = sled;
    }
}