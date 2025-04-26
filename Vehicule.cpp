#include "Vehicule.h"
#include <iostream>
using namespace std;

Vehicule::Vehicule(const string& i, const string& m, const string& mo, int a, string t): VehiculeBase(i, m, mo, a, t) {}

Vehicule::~Vehicule() {
    if (derniereReparation)
        delete derniereReparation;
    for (int i = 0; i < listeReparations.size(); ++i) {
        delete listeReparations[i];
    }
    listeReparations.clear();
}

void Vehicule::afficherDetails() {
    cout << "Vehicule : " << marque << " " << modele
         << " (" << annee << ") - Immatriculation : " << imma << endl;
    if (derniereReparation)
        derniereReparation->afficherDetails();
    else
        cout << "Aucune reparation enregistree." << endl;
}

void Vehicule::ajouterReparation(Reparation* r) {
    listeReparations.push_back(r);
    derniereReparation = r;
}

void Vehicule::afficherListeReparations() const {
    if (listeReparations.empty()) {
        cout << "Aucune reparation enregistree." << endl;
    } else {
        cout << "Liste des reparations:" << endl;
        for (int i = 0; i < listeReparations.size(); ++i) {
            cout << *listeReparations[i] << endl;
        }
    }
}

Vehicule& Vehicule::operator=(const Vehicule& v) {
    if (this != &v) {
        imma = v.imma;
        marque = v.marque;
        modele = v.modele;
        annee = v.annee;
        if (derniereReparation) delete derniereReparation;
        derniereReparation = v.derniereReparation;
        for (int i = 0; i < listeReparations.size(); ++i)
            delete listeReparations[i];
        listeReparations.clear();
        for (int i = 0; i < v.listeReparations.size(); ++i)
            listeReparations.push_back(v.listeReparations[i]);
    }
    return *this;
}

ostream& operator<<(ostream& out, const Vehicule& v) {
    out << "Immatriculation: " << v.imma << endl;
    out << "Marque: " << v.marque << endl;
    out << "Modele: " << v.modele << endl;
    out << "Annee: " << v.annee << endl;
    return out;
}

istream& operator>>(istream& in, Vehicule& v) {
    cout << "Immatriculation: ";
    in >> v.imma;
    cout << "Marque: ";
    in >> v.marque;
    cout << "Modele: ";
    in >> v.modele;
    cout << "Annee: ";
    in >> v.annee;
    return in;
}

void Vehicule::afficherDerniereReparation() const {
    if (!listeReparations.empty()) {
            listeReparations.back()->afficherDetails();
        } else {
            cout << "Aucune reparation enregistree." << endl;
        }
}
