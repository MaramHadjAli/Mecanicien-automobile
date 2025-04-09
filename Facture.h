#include <string>
#include <vector>
using namespace std;

class Facture {
    int idFacture;
    float montant;
    string statutPaiement;
    vector<Reparation> listeReparations;
public:
    Facture(int id, float m, string s);
    void genererFacture();
    ~Facture();
};
