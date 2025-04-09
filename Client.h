#include "Personne.h"
#include <vector>
using namespace std;

class Client : public Personne {
    string adresse;
    vector<Vehicule*> listeVehicules;
public:
    Client(string n, string p, string t, string a);
    void ajouterVehicule(Vehicule* v);
    void supprimerVehicule(string imma);
    void afficherInfo() override;
    ~Client();
};
