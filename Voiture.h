#include "Vehicule.h"
#include <vector>
using namespace std;

class Voiture : public Vehicule {
private:
    int nbPortes;
    int nbPlaces;
    vector<Mecanicien*> listeMecaniciens;
public:
    Voiture(string i, string m, string mo, int a, int np, int npl);
    void afficherDetails() override;
    ~Voiture();
};
