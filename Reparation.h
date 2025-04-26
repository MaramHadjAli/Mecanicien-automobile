#ifndef REPARATION_H
#define REPARATION_H

#include <string>
#include <iostream>
using namespace std;

class Reparation {
private:
    int idReparation;
    string problemeDetecte;
    float cout_rep;
    string dateEntree;
    string dateSortie;

public:
    Reparation();
    Reparation(int id, string prob, float cout, string entree, string sortie);
    void ajouterReparation();
    void afficherDetails() const;
    Reparation& operator=(const Reparation& r);
    friend ostream& operator<<(ostream& os, const Reparation& r);
    friend istream& operator>>(istream& is, Reparation& r);
    ~Reparation();
};

#endif
