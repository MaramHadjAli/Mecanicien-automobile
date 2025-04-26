#ifndef CLIENT_H
#define CLIENT_H

#include "Personne.h"
#include "Vehicule.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

class Client : public Personne {
    string adresse;
    vector<Vehicule*> listeVehicules;
public:
    Client();
    Client(string n, string p, string t, string a);
    Client(const Client& c);
    void ajouterVehicule(Vehicule* v);
    void supprimerVehicule(string imma);
    Client& operator=(const Client& c);
    friend ostream& operator<<(ostream& out, const Client& c);
    friend istream& operator>>(istream& in, Client& c);
    void afficherInfo();
    ~Client();
};

#endif
