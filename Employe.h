#include <vector>
#include <iostream>
#include <stdexcept>
#include "Personne.h"
using namespace std;
class Employe: public Personne {
        float salaire;
    public:
        Employe(string n, string p, string t, float s);
        virtual void afficherSalaire();
        virtual ~Employe();
        friend ostream& operator<<(ostream& out, const Employe& emp);
        friend istream& operator>>(istream& in, Employe& emp);
        void afficherInfo();
    };

