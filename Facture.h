#ifndef FACTURE_H
#define FACTURE_H
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Reparation.h"

using namespace std;

class Facture {
private:
    int idFacture;
    float montant;
    string statutPaiement;
    map<int, Reparation> listeReparations;
public:
    Facture(int id = 0, float m = 0.0f, string s = "");
    ~Facture();
    Facture(const Facture& other);
    Facture& operator=(const Facture& other);
    void genererFacture();
    int getId() const;
    Reparation* trouverReparation(int id);
    friend ostream& operator<<(ostream& os, const Facture& f);
    friend istream& operator>>(istream& is, Facture& f);
};

#endif
