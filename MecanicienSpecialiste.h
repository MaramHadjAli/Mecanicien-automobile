#ifndef MECANICIENSPECIALISTE_H
#define MECANICIENSPECIALISTE_H

#include "Mecanicien.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class MecanicienSpecialiste : public Mecanicien {
    string domaineExpertise;
    vector<string> listeGarages;

public:
    MecanicienSpecialiste(string n, string p, string t, int exp, string d);
    void diagnostiquerProbleme();
    void afficherInfo();
    ~MecanicienSpecialiste();
    friend ostream& operator<<(ostream& out, const MecanicienSpecialiste& ms);
    friend istream& operator>>(istream& in, MecanicienSpecialiste& ms);
    void sauvegarderDansFichier(const string& nomFichier) const;
    void chargerDepuisFichier(const string& nomFichier);
};

#endif
