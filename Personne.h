#include <iostream>
#include <string>
using namespace std;

class Personne {
protected:
    string nom;
    string prenom;
    string telephone;
public:
    Personne(string n, string p, string t);
    virtual void afficherInfo() = 0;
    virtual ~Personne();
};
