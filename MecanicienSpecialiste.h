#include "Mecanicien.h"
#include <vector>
using namespace std;

class MecanicienSpecialiste : public Mecanicien {
    string domaineExpertise;
    vector<Garage*> listeGarages;
public:
    MecanicienSpecialiste(string n, string p, string t, string s, int exp, string d);
    void diagnostiquerProbleme();
    void afficherInfo() override;
    ~MecanicienSpecialiste();
};
