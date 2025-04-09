#include "Personne.h"
#include <vector>
using namespace std;

class Mecanicien : public Personne {
    string specialisation;
    int experience;
    vector<Vehicule*> listeVehicules;
public:
    Mecanicien(string n, string p, string t, string s, int exp);
    void afficherInfo() override;
    ~Mecanicien();
};
