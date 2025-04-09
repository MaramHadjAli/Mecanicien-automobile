#include <vector>
using namespace std;

class Garage {
    static int nombreClients;
    vector<Mecanicien*> mecaniciens;
    vector<Client*> clients;
public:
    Garage();
    static void afficherNombreClients();
    void ajouterMecanicien(Mecanicien* m);
    void ajouterClient(Client* c);
    ~Garage();
};
