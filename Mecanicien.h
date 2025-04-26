#ifndef MECANICIEN_H
#define MECANICIEN_H

#include "Personne.h"
#include "Vehicule.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <fstream>

class Mecanicien : public Personne {
protected:
    int experience;
    vector<Vehicule*> listeVehicules;

public:
    Mecanicien();
    Mecanicien(string n, string p, string t, int exp);
    void afficherInfo();
    int getExperience() const { return experience; } ;
    ~Mecanicien();
    friend ostream& operator<<(ostream& os, const Mecanicien& m);
    friend istream& operator>>(istream& is, Mecanicien& m);
    Mecanicien& operator=(const Mecanicien& m);
    void sauvegarderDansFichier(const string& nomFichier) const;
    static void chargerTousLesMecaniciens(const string& fichier, vector<Mecanicien>& mecaniciens);

};

#endif
