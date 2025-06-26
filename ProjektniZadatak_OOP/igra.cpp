#include"igra.h"

void Igra::operator+=(Skor *s) {
	Lista *novi = new Lista;
	novi->s = s;
	novi->sled = prvi;
	prvi = novi;
}

Skor* Igra::operator-(double rez) {
	Lista* tek = prvi;
	while (tek != nullptr && tek->s->getRez() != rez)
	{
		tek = tek->sled;
	}
	return tek->s;
}
void Igra::SortirajMV() {
    if (prvi == nullptr || prvi->sled == nullptr) {
        return;
    }

    bool a;
    do {
        a = false;
        Lista* tek = prvi;
        Lista* sled = prvi->sled;
        Lista* prosli = nullptr;

        while (sled != nullptr) {
            if (tek->s->getRez() > sled->s->getRez()) {
                if (prosli != nullptr) {
                    prosli->sled = sled;
                }
                else {
                    prvi = sled;
                }

                tek->sled = sled->sled;
                sled->sled = tek;

                a = true;
            }

            prosli = tek;
            tek = sled;
            sled = sled->sled;
        }
    } while (a);
}

void Igra::SortirajVM() {
    if (prvi == nullptr || prvi->sled == nullptr) {
        return;
    }

    bool a;
    do {
        a = false;
        Lista* tek = prvi;
        Lista* sled = prvi->sled;
        Lista* prosli = nullptr;

        while (sled != nullptr) {
            if (tek->s->getRez() < sled->s->getRez()) {
                if (prosli != nullptr) {
                    prosli->sled = sled;
                }
                else {
                    prvi = sled;
                }

                tek->sled = sled->sled;
                sled->sled = tek;

                a = true;
            }

            prosli = tek;
            tek = sled;
            sled = sled->sled;
        }
    } while (a);
}

void Igra::PromeniBalans(double balans, Igrac& i) {
    i.setBalans(balans);
}

ostream& operator<<(ostream& out, Igra& i) {
    out << "Igra: " << i.getNaziv() << "\n";
    out << "Ime\tID\tRezultat\n";

    Igra::Lista* tek = i.prvi;
    while (tek != nullptr) {
        out << *(tek->s) << "\n";
        tek = tek->sled;
    }

    return out;
}