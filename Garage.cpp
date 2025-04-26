#include "Garage.h"
#include <iostream>
using namespace std;

int Garage::nombreClients = 0;

Garage::Garage() {}

Garage::~Garage() {
    for (int i = 0; i < mecaniciens.size(); ++i) {
        delete mecaniciens[i];
    }
    for (int i = 0; i < clients.size(); ++i) {
        delete clients[i];
    }
}

void Garage::ajouterMecanicien(Mecanicien* m) {
    if (!m) throw runtime_error("Mecanicien invalide !");
    mecaniciens.push_back(m);
}

void Garage::ajouterClient(Client* c) {
    if (!c) throw runtime_error("Client invalide !");
    clients.push_back(c);
    nombreClients++;
}

void Garage::afficherNombreClients() {
    cout << "Nombre total de clients : " << nombreClients << endl;
}

ostream& operator<<(ostream& os, const Garage& g) {
    os << "----- Liste des Mecaniciens -----" << endl;
    for (int i = 0; i < g.mecaniciens.size(); ++i) {
        os << *(g.mecaniciens[i]) << endl;
    }

    os << "----- Liste des Clients -----" << endl;
    for (int i = 0; i < g.clients.size(); ++i) {
        os << *(g.clients[i]) << endl;
    }

    return os;
}
istream& operator>>(istream& is, Garage& g) {
    int nbMec, nbCli;
    cout << "Nombre de mecaniciens a ajouter : ";
    is >> nbMec;
    for (int i = 0; i < nbMec; ++i) {
        Mecanicien* m = new Mecanicien("", "", "", 0);
        is >> *m;
        g.ajouterMecanicien(m);
    }
    cout << "Nombre de clients a ajouter : ";
    is >> nbCli;
    for (int i = 0; i < nbCli; ++i) {
        Client* c = new Client();
        is >> *c;
        g.ajouterClient(c);
    }
    return is;
}
