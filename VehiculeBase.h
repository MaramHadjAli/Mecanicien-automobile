#ifndef VEHICULEBASE_H
#define VEHICULEBASE_H
#include <string>
using namespace std;

class VehiculeBase {
protected:
    string imma;
    string marque;
    string modele;
    int annee;
    string type;

public:
    VehiculeBase(string i, string m, string mod, int a, string t);
    VehiculeBase();
    string getImmatriculation() const { return imma;}
    string getType() const { return type; }
    void setType(const string& t) { type = t; }
    virtual void afficherDetails() = 0;
    virtual ~VehiculeBase();
};
#endif
