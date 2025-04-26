#ifndef MOTO_H
#define MOTO_H
#include "Vehicule.h"
#include <string>
using namespace std;

class Moto : public Vehicule {
private:
    int puisFisc;
    string type_moto;
public:
    Moto();
    Moto(string i, string m, string mo, int a, string t, int pf, string tm);
    void afficherDetails();
    ~Moto();
    friend ostream& operator<<(ostream& os, const Moto& m);
    friend istream& operator>>(istream& is, Moto& m);
};

#endif
