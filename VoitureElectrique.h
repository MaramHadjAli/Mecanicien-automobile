#ifndef VOITUREELECTRIQUE_H
#define VOITUREELECTRIQUE_H
#include "Voiture.h"
using namespace std;

class VoitureElectrique : public Voiture {
private:
    int autonomie;
    float capaciteBatterie;
    string type = "voitureelectrique";
public:
    VoitureElectrique();
    VoitureElectrique(string imma, string m, string mod, int an, string t, int aut, float cb);
    void afficherDetails() override;
    int getNbPortes() const { return nbPortes; }
    int getNbPlaces() const { return nbPlaces; }
    float getAutonomie() const { return autonomie; }
    ~VoitureElectrique();
    friend ostream& operator<<(ostream& os, const VoitureElectrique& ve);
    friend istream& operator>>(istream& is, VoitureElectrique& ve);
    static void chargerDepuisFichier(const string& nomFichier, vector<Voiture*>& voitures);
    string getType() const override { return "voitureelectrique"; }
    };

#endif
