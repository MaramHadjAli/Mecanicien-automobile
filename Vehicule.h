#include "VehiculeBase.h"
#include <string>
#include <vector>
using namespace std;

class Vehicule : public VehiculeBase {
protected:
    string imma;
    string marque;
    string model;
    int annee;
    Reparation* derniereReparation;
    vector<Reparation*> listeReparations;
public:
    Vehicule(string i, string m, string mod, int a);
    virtual ~Vehicule();
};
