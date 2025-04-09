#include <string>
using namespace std;

class Piece {
    string reference;
    string nom;
    float prix;
    int stock;
public:
    Piece(string r, string n, float p, int s);
    void afficherInfo();
    ~Piece();
};
