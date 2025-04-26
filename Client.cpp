#include "Client.h"
#include <iostream>
#include <algorithm>

using namespace std;

Client::Client() : Personne("", "", ""), adresse("") {}

Client::Client(string n, string p, string t, string a)
    : Personne(n, p, t), adresse(a) {}

Client::Client(const Client& c)
    : Personne(c.nom, c.prenom, c.telephone), adresse(c.adresse), listeVehicules(c.listeVehicules) {}

Client::~Client() {
    listeVehicules.clear();
}

void Client::ajouterVehicule(Vehicule* v) {
    listeVehicules.push_back(v);
}

void Client::supprimerVehicule(string imma) {
    listeVehicules.erase(
        remove_if(listeVehicules.begin(), listeVehicules.end(),
                  [imma](Vehicule* v) {
                      return v->getImmatriculation() == imma;
                  }),
        listeVehicules.end()
    );
}

Client& Client::operator=(const Client& c) {
    if (this != &c) {
        nom = c.nom;
        prenom = c.prenom;
        telephone = c.telephone;
        adresse = c.adresse;
        listeVehicules = c.listeVehicules;
    }
    return *this;
}

ostream& operator<<(ostream& out, const Client& c) {
    out << "Nom: " << c.nom << "\nPrenom: " << c.prenom
        << "\nTelephone: " << c.telephone << "\nAdresse: " << c.adresse
        << "\nNombre de vehicules: " << c.listeVehicules.size();
    return out;
}

istream& operator>>(istream& in, Client& c) {
    cout << "Nom: ";
    in >> c.nom;
    cout << "Prenom: ";
    in >> c.prenom;
    cout << "Telephone: ";
    in >> c.telephone;
    cout << "Adresse: ";
    in >> c.adresse;
    return in;
}

void Client::afficherInfo() {
    cout << *this << endl;
}
