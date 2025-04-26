#include "Voiture.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

Voiture::Voiture() : Vehicule() {}
Voiture::Voiture(string i, string m, string mo, int a, string t, int np, int npl)
    : Vehicule(i, m, mo, a, t), nbPortes(np), nbPlaces(npl) {}

Voiture::~Voiture() {}

void Voiture::afficherDetails() {
    cout << "Voiture - Immatriculation: " << imma << endl;
    cout << "Marque: " << marque << endl;
    cout << "Modele: " << modele << endl;
    cout << "Annee: " << annee << endl;
    cout << "Nombre de portes: " << nbPortes << endl;
    cout << "Nombre de places: " << nbPlaces << endl;
}

ostream& operator<<(ostream& os, const Voiture& v) {
    os << "Immatriculation: " << v.imma << "\n"
       << "Marque: " << v.marque << "\n"
       << "Modele: " << v.modele << "\n"
       << "Annee: " << v.annee << "\n"
       << "Nombre de portes: " << v.nbPortes << "\n"
       << "Nombre de places: " << v.nbPlaces << "\n";
    return os;
}

istream& operator>>(istream& is, Voiture& v) {
    cout << "Immatriculation: ";
    is >> v.imma;
    cout << "Marque: ";
    is >> v.marque;
    cout << "Modele: ";
    is >> v.modele;
    cout << "Annee de fabrication: ";
    is >> v.annee;
    cout << "Nombre de portes: ";
    is >> v.nbPortes;
    cout << "Nombre de places: ";
    is >> v.nbPlaces;
    return is;
}

void Voiture::sauvegarderDansFichier(const string& nomFichier) const {
    try {
        ofstream fichier(nomFichier, ios::app);
        if (!fichier) {
            throw runtime_error("Erreur : impossible d'ouvrir le fichier pour l'ecriture !");
        }
        fichier << *this;
        fichier.close();
    } catch (const exception& e) {
        cerr << "Erreur de sauvegarde dans le fichier : " << e.what() << endl;
    }
}

void Voiture::chargerDepuisFichier(const string& nomFichier, vector<Voiture*>& voitures) {
    try {
        ifstream fichier(nomFichier);
        if (!fichier) {
            throw runtime_error("Erreur : impossible d'ouvrir le fichier pour la lecture !");
        }

        while (fichier.peek() != EOF) {
            Voiture* v = new Voiture();
            if (fichier >> *v) {
                voitures.push_back(v);
            } else {
                cerr << "Erreur de lecture d'une voiture. Objet ignore." << endl;
                delete v;
                break;
            }
        }
        fichier.close();
        cout << "Toutes les voitures ont ete chargees depuis " << nomFichier << endl;
    } catch (const exception& e) {
        cerr << "Erreur de chargement depuis le fichier : " << e.what() << endl;
    }
}
