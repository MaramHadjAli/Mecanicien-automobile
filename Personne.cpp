#include "Personne.h"
#include <iostream>
using namespace std;

Personne::Personne(string n, string p, string t)
    : nom(n), prenom(p), telephone(t) {}

Personne::~Personne() {}

ostream& operator<<(ostream& out, const Personne& pers) {
    out << "Nom: " << pers.nom << "\nPrenom: " << pers.prenom << "\nTelephone: " << pers.telephone;
    return out;
}

istream& operator>>(istream& in, Personne& pers) {
    cout << "Nom: ";
    in >> pers.nom;
    cout << "Prenom: ";
    in >> pers.prenom;
    cout << "Telephone: ";
    in >> pers.telephone;
    return in;
}
