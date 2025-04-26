#include "Moto.h"
#include <iostream>
using namespace std;

Moto::Moto() : Vehicule() {}

Moto::Moto(string i, string m, string mo, int a, string t, int pf, string tm): Vehicule(i, m, mo, a,t), puisFisc(pf), type_moto(t) {}

Moto::~Moto() {}

void Moto::afficherDetails() {
    cout << "Moto - Immatriculation: " << imma << endl;
    cout << "Marque: " << marque << endl;
    cout << "Modele: " << modele << endl;
    cout << "Annee: " << annee << endl;
    cout << "Puissance fiscale: " << puisFisc << " CV" << endl;
    cout << "Type: " << type << endl;
}

ostream& operator<<(ostream& os, const Moto& m) {
    os << "Moto - Immatriculation: " << m.imma << "\\n"
       << "Marque: " << m.marque << "\\n"
       << "Modele: " << m.modele << "\\n"
       << "Annee: " << m.annee << "\\n"
       << "Puissance fiscale: " << m.puisFisc << " CV\\n"
       << "Type: " << m.type << "\\n";
    return os;
}

istream& operator>>(istream& is, Moto& m) {
    cout << "Immatriculation: ";
    is >> m.imma;
    cout << "Marque: ";
    is >> m.marque;
    cout << "Modele: ";
    is >> m.modele;
    cout << "Annee de fabrication: ";
    is >> m.annee;
    cout << "Puissance fiscale: ";
    is >> m.puisFisc;
    cout << "Type: ";
    is.ignore();
    getline(is, m.type);
    return is;
}
