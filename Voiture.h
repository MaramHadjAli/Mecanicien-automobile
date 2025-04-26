#ifndef VOITURE_H
#define VOITURE_H
#include "Vehicule.h"
#include <vector>
#include <string>
using namespace std;

class Mecanicien;
class Voiture : public Vehicule {
protected:
    int nbPortes;
    int nbPlaces;
    vector<Mecanicien*> listeMecaniciens;
public:
    Voiture();
    Voiture(string i, string m, string mo, int a, string t, int np, int npl);
    virtual ~Voiture();
    void afficherDetails();
    virtual string getType() const { return "voiture"; }
    friend ostream& operator<<(ostream& os, const Voiture& v);
    friend istream& operator>>(istream& is, Voiture& v);
    void sauvegarderDansFichier(const string& nomFichier) const;
    static void chargerDepuisFichier(const string& nomFichier, vector<Voiture*>& voitures);
};

#endif
