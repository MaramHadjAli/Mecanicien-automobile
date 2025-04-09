#include "Vehicule.h"
using namespace std;

class Moto : public Vehicule {
private:
    int puisFisc;
    string type;
public:
    Moto(string i, string m, string mo, int a, int pf, string t);
    void afficherDetails() override;
    ~Moto();
};
