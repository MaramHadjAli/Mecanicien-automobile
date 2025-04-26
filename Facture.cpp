#include "Facture.h"
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

Facture::Facture(int id, float m, string s) : idFacture(id), montant(m), statutPaiement(s) {}
Facture::~Facture() {}
Facture::Facture(const Facture& other) {
    idFacture = other.idFacture;
    montant = other.montant;
    statutPaiement = other.statutPaiement;
    listeReparations = other.listeReparations;
}
Facture& Facture::operator=(const Facture& other) {
    if (this != &other) {
        idFacture = other.idFacture;
        montant = other.montant;
        statutPaiement = other.statutPaiement;
        listeReparations = other.listeReparations;
    }
    return *this;
}
void Facture::genererFacture() {
    cout << "Facture #" << idFacture << " - Montant : " << montant << " - Paiement : " << statutPaiement << endl;
}
int Facture::getId() const {
    return idFacture;
}
ostream& operator<<(ostream& os, const Facture& f) {
    os << "ID Facture       : " << f.idFacture << "\n";
    os << "Montant          : " << f.montant << " €\n";
    os << "Statut Paiement  : " << f.statutPaiement << "\n";
    return os;
}
istream& operator>>(istream& is, Facture& f) {
    return is >> f.idFacture >> f.montant >> f.statutPaiement;
}
Reparation* Facture::trouverReparation(int id) {
    map<int, Reparation>::iterator it = listeReparations.find(id);
    if (it != listeReparations.end()) {
        return &(it->second);
    }
    return nullptr;
}