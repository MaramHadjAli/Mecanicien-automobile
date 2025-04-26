#include "Mecanicien.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

Mecanicien::Mecanicien() : Personne("", "", ""), experience(0) {}

Mecanicien::Mecanicien(string n, string p, string t, int exp) : Personne(n, p, t) {
    if (exp < 0) {
        throw runtime_error("L'experience ne peut pas etre negative.");
    }
    experience = exp;
}

Mecanicien::~Mecanicien() {
    for (int i = 0; i < listeVehicules.size(); ++i) {
        delete listeVehicules[i];
    }
    listeVehicules.clear();
}

void Mecanicien::afficherInfo() {
    cout << "=== Mecanicien ===" << endl;
    cout << "Nom: " << nom << "\nPrenom: " << prenom << "\nTelephone: " << telephone << endl;
    cout << "Experience: " << experience << " ans" << endl;
    cout << "Nombre de vehicules assignes : " << listeVehicules.size() << endl;
}

ostream& operator<<(ostream& os, const Mecanicien& m) {
    os << "Nom: " << m.nom << "\nPrenom: " << m.prenom << "\nTelephone: " << m.telephone << endl;
    os << "\nExperience: " << m.experience << " ans";
    return os;
}

istream& operator>>(istream& is, Mecanicien& m) {
    cout << "Nom: ";
    is >> m.nom;
    cout << "Prenom: ";
    is >> m.prenom;
    cout << "Telephone: ";
    is >> m.telephone;
    cout << "Experience (en annees): ";
    is >> m.experience;

    if (m.experience < 0) {
        throw runtime_error("Erreur : experience negative non autorisee !");
    }
    return is;
}

Mecanicien& Mecanicien::operator=(const Mecanicien& m) {
    if (this != &m) {
        nom = m.nom;
        prenom = m.prenom;
        telephone = m.telephone;
        experience = m.experience;
        for (int i = 0; i < listeVehicules.size(); ++i) {
            delete listeVehicules[i];
        }
        listeVehicules.clear();
        for (int i = 0; i < m.listeVehicules.size(); ++i) {
            listeVehicules.push_back(m.listeVehicules[i]);
        }
    }
    return *this;
}

void Mecanicien::sauvegarderDansFichier(const string& nomFichier) const {
    try {
        ofstream fichier(nomFichier, ios::app);
        if (!fichier.is_open()) {
            throw runtime_error("Erreur : impossible d'ouvrir le fichier pour l'ecriture !");
        }
        fichier << *this << endl;
        fichier.close();
    } catch (const exception& e) {
        cerr << "Erreur de sauvegarde dans le fichier : " << e.what() << endl;
    }
}


void Mecanicien::chargerTousLesMecaniciens(const string& fichier, vector<Mecanicien>& mecaniciens) {
    ifstream fichierStream(fichier);
    if (!fichierStream) {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        return;
    }

    Mecanicien m;
    while (fichierStream >> m) {
        if (m.getExperience() >= 0) { 
            mecaniciens.push_back(m);
        } else {
            cerr << "Donnees corrompues : experience negative. Mecanicien ignore." << endl;
        }
    }
    fichierStream.close();
    cout << "Tous les mecaniciens ont ete charges depuis " << fichier << endl;
}
