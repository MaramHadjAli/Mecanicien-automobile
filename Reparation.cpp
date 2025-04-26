#include "Reparation.h"
#include <iostream>
using namespace std;

Reparation::Reparation() : idReparation(0), cout_rep(0.0) {
    problemeDetecte = "";
    dateEntree = "";
    dateSortie = "";
}

Reparation::Reparation(int id, string prob, float c, string entree, string sortie)
    : idReparation(id), problemeDetecte(prob), cout_rep(c), dateEntree(entree), dateSortie(sortie) {}

void Reparation::ajouterReparation() {
}

void Reparation::afficherDetails() const {
    cout << "ID Reparation: " << idReparation << endl;
    cout << "Probleme detecte: " << problemeDetecte << endl;
    cout << "Cout de reparation: " << cout_rep << "dinars" << endl;
    cout << "Date d'entree: " << dateEntree << endl;
    cout << "Date de sortie: " << dateSortie << endl;
}


Reparation& Reparation::operator=(const Reparation& r) {
    if (this == &r) {
        return *this;
    }
    idReparation = r.idReparation;
    problemeDetecte = r.problemeDetecte;
    cout_rep = r.cout_rep;
    dateEntree = r.dateEntree;
    dateSortie = r.dateSortie;

    return *this;
}

ostream& operator<<(ostream& os, const Reparation& r) {
    os << "ID Reparation: " << r.idReparation << ", ";
    os << "Probleme: " << r.problemeDetecte << ", ";
    os << "Cout: " << r.cout_rep << "dinars, ";
    os << "Entree: " << r.dateEntree << ", ";
    os << "Sortie: " << r.dateSortie;
    return os;
}

istream& operator>>(istream& is, Reparation& r) {
    cout << "Entrez l'ID de la reparation: ";
    is >> r.idReparation;
    cout << "Entrez le probleme detecte: ";
    is >> r.problemeDetecte;
    cout << "Entrez le cout de la reparation: ";
    is >> r.cout_rep;
    cout << "Entrez la date d'entree : ";
    is >> r.dateEntree;
    cout << "Entrez la date de sortie : ";
    is >> r.dateSortie;
    return is;
}

Reparation::~Reparation() {
}
