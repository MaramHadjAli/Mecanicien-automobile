#ifndef VEHICULE_H
#define VEHICULE_H
#include "VehiculeBase.h"
#include "Reparation.h"
#include <string>
#include <vector>
using namespace std;

class Vehicule : public VehiculeBase {
protected:
    Reparation* derniereReparation;
    vector<Reparation*> listeReparations;

public:
    Vehicule() : VehiculeBase(), derniereReparation(nullptr) {}
    Vehicule(const string& imma, const string& marque, const string& modele, int annee, string t);
    void afficherDetails();
    void ajouterReparation(Reparation* r);
    void afficherListeReparations() const;
    void afficherDerniereReparation() const;
    Vehicule& operator=(const Vehicule& v);
    friend ostream& operator<<(ostream& out, const Vehicule& v);
    friend istream& operator>>(istream& in, Vehicule& v);
    virtual ~Vehicule();
};


#endif
