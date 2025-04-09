#include "Voiture.h"
using namespace std;

class VoitureElectrique : public Voiture {
    int autonomie;
    float capaciteBatterie;
public:
    VoitureElectrique(string imma, string m, string mod, int an, int aut, float cb);
    void afficherDetails() override;
    ~VoitureElectrique();
};
