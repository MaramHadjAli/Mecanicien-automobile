#ifndef GARAGE_H
#define GARAGE_H

#include <vector>
#include <iostream>
#include "Mecanicien.h"
#include "Client.h"

class Garage {
    static int nombreClients;
    vector<Mecanicien*> mecaniciens;
    vector<Client*> clients;
public:
    Garage();
    static void afficherNombreClients();
    const vector<Mecanicien*>& obtenirMecaniciens() const {
        return mecaniciens;
    };
    const vector<Client*>& obtenirClients() const {
        return clients;
    }
    void ajouterMecanicien(Mecanicien* m);
    void ajouterClient(Client* c);
    ~Garage();
    friend ostream& operator<<(ostream& os, const Garage& g);
    friend istream& operator>>(istream& is, Garage& g);
};

#endif