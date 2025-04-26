#include "Employe.h"
#include <iostream>
using namespace std;

Employe::Employe(string n, string p, string t, float s): Personne(n, p, t), salaire(s) {}

void Employe::afficherSalaire() {
    cout << "Salaire: " << salaire << endl;
}
void Employe::afficherInfo() {
    cout << "Nom : " << nom << "\n"
         << "Prenom : " << prenom << "\n"
         << "Telephone : " << telephone << "\n"
         << "Salaire : " << salaire << " DT\n";
}
Employe::~Employe() {}

ostream& operator<<(ostream& out, const Employe& emp) {
    out << "Nom : " << emp.nom << "\n"
        << "Prenom : " << emp.prenom << "\n"
        << "Telephone : " << emp.telephone << "\n"
        << "Salaire : " << emp.salaire << " DT";
    return out;
}

istream& operator>>(istream& in, Employe& emp) {
    cout << "Nom : ";
    in >> emp.nom;
    cout << "Prenom : ";
    in >> emp.prenom;
    cout << "Telephone : ";
    in >> emp.telephone;
    cout << "Salaire : ";
    in >> emp.salaire;
    return in;
}
