#include "VoitureElectrique.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

VoitureElectrique::VoitureElectrique() : Voiture(), autonomie(0), capaciteBatterie(0.0f) {
    Voiture::nbPortes = 4;
    Voiture::nbPlaces = 5;
}

VoitureElectrique::VoitureElectrique(string imma, string m, string mod, int an, string t, int aut, float cb)
    : Voiture(imma, m, mod, an, t, 4, 5), autonomie(aut), capaciteBatterie(cb) {}

VoitureElectrique::~VoitureElectrique() {}

void VoitureElectrique::afficherDetails() {
    Voiture::afficherDetails();
    cout << "Autonomie: " << autonomie << " km" << endl;
    cout << "Capacite de la batterie: " << capaciteBatterie << " kWh" << endl;
}

ostream& operator<<(ostream& os, const VoitureElectrique& ve) {
    os << static_cast<const Voiture&>(ve);
    os << "Autonomie: " << ve.autonomie << "\n";
    os << "CapaciteBatterie: " << ve.capaciteBatterie << "\n";
    return os;
}

istream& operator>>(istream& is, VoitureElectrique& ve) {
    cout << "Immatriculation: ";
    is >> ve.imma;
    cout << "Marque: ";
    is >> ve.marque;
    cout << "Modele: ";
    is >> ve.modele;
    cout << "Annee de fabrication: ";
    is >> ve.annee;
    ve.nbPortes = 4;
    ve.nbPlaces = 5;
    cout << "Autonomie (km): ";
    is >> ve.autonomie;
    cout << "Capacite de la batterie (kWh): ";
    is >> ve.capaciteBatterie;
    return is;
}

void VoitureElectrique::chargerDepuisFichier(const string& nomFichier, vector<Voiture*>& voitures) {
    try {
        ifstream fichier(nomFichier);
        if (!fichier) {
            throw runtime_error("Erreur : impossible d'ouvrir le fichier pour la lecture !");
        }

        VoitureElectrique* ve = nullptr;
        while (true) {
            ve = new VoitureElectrique();
            if (fichier >> *ve) {
                voitures.push_back(ve);
            } else {
                delete ve;
                if (fichier.fail()) {
                    fichier.clear();
                }
                break; 
            }
        }
        fichier.close();
        cout << "Toutes les voitures electriques ont ete chargees depuis " << nomFichier << endl;
    } catch (const exception& e) {
        cerr << "Erreur de chargement depuis le fichier : " << e.what() << endl;
    }
}

