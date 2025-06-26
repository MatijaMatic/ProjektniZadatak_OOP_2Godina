#ifndef __kazino_h__
#define __kazino_h__
#include "igra.h"

class Kazino {
    double budzet;
    struct ListaDupla {
        Igra* igra;
        ListaDupla* sled;
        ListaDupla* prosli;
        ListaDupla(Igra* i) : igra(i), sled(nullptr), prosli(nullptr) {}
    };
    ListaDupla* glava;

public:
    Kazino(double budzet);
    double getBudzet() { return budzet; }
    void setBudzet(double a);
    void DodajNovuIgru(Igra* i);
    void PrikazListeIgara();
    void PovecatiBalans(Igrac& i, double a);
    int IzaberiIgru();
    ~Kazino();
};

#endif // !__kazino_h__
