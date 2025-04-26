#include "MecanicienSpecialiste.h"
#include <iostream>
#include <fstream>

using namespace std;

MecanicienSpecialiste::MecanicienSpecialiste(string n, string p, string t, int exp, string d)
    : Mecanicien(n, p, t, exp), domaineExpertise(d) {}

void MecanicienSpecialiste::diagnostiquerProbleme() {
    cout << "Diagnostic en cours par le specialiste en " << domaineExpertise << "\n";
}

void MecanicienSpecialiste::afficherInfo() {
    Mecanicien::afficherInfo();
    cout << "Domaine d'expertise: " << domaineExpertise << endl;
    cout << "Nombre de garages affilies: " << listeGarages.size() << endl;
}

MecanicienSpecialiste::~MecanicienSpecialiste() {
    listeGarages.clear();
}

ostream& operator<<(ostream& out, const MecanicienSpecialiste& ms) {
    out << static_cast<const Mecanicien&>(ms);
    out << "\nDomaine d'expertise: " << ms.domaineExpertise;
    out << "\nNombre de garages affilies: " << ms.listeGarages.size();
    return out;
}

istream& operator>>(istream& in, MecanicienSpecialiste& ms) {
    in >> static_cast<Mecanicien&>(ms);
    cout << "Domaine d'expertise: ";
    in >> ms.domaineExpertise;
    return in;
}

#include <fstream>
#include "MecanicienSpecialiste.h"

void MecanicienSpecialiste::sauvegarderDansFichier(const string& nomFichier) const {
    try {
        ofstream fichier(nomFichier);
        if (!fichier) {
            throw runtime_error("Erreur : ouverture du fichier impossible pour ecriture");
        }
        fichier << *this;
        fichier.close();
    } catch (const exception& e) {
        cerr << "Erreur de sauvegarde fichier : " << e.what() << endl;
    }
}

void MecanicienSpecialiste::chargerDepuisFichier(const string& nomFichier) {
    try {
        ifstream fichier(nomFichier);
        if (!fichier) {
            throw runtime_error("Erreur : ouverture du fichier impossible pour lecture");
        }
        fichier >> *this;
        fichier.close();

        if (experience < 0) {
            throw runtime_error("Donnees corrompues : experience negative");
        }
    } catch (const exception& e) {
        cerr << "Erreur de chargement fichier : " << e.what() << endl;
    }
}