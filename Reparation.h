#include <string>
using namespace std;

class Reparation {
private:
    int idReparation;
    string problemeDetecte;
    float cout;
    string dateEntree;
    string dateSortie;
public:
    Reparation(int id, string prob, float cout, string entree, string sortie);
    void ajouterReparation();
    void afficherDetails();
    ~Reparation();
};
