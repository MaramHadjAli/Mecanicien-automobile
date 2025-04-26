#include <iostream>
#include <vector>
#include <map>
#include "Piece.h"
#include "Client.h"
#include "Employe.h"
#include "Mecanicien.h"
#include "Vehicule.h"
#include "Voiture.h"
#include "VoitureElectrique.h"
#include "Moto.h"
#include "Reparation.h"
#include "Facture.h"
#include "Garage.h"

using namespace std;

void menuPieces(map<string, Piece>& stock)
{
    int choix;
    do {
        cout << "\n-------- MENU PIECES --------\n";
        cout << "1. Ajouter une piece\n";
        cout << "2. Afficher le stock\n";
        cout << "0. Retour\n";
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                string reference_piece, nom;
                double prix;
                int quantite;
                cout << "Reference : ";
                cin >> reference_piece;
                cin.ignore(1000, '\n');

                cout << "Nom : ";
                getline(cin, nom);

                cout << "Prix : ";
                while (!(cin >> prix)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Prix invalide. Entrez un nombre : ";
                }

                cout << "Quantite : ";
                while (!(cin >> quantite)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Quantite invalide. Entrez un entier : ";
                }

                Piece piece(reference_piece, nom, static_cast<float>(prix), quantite);

                if (stock.find(reference_piece) != stock.end()) {
                    cout << "Piece deja existante.\n";
                } else {
                    stock[reference_piece] = piece;
                    cout << "Piece ajoutee avec succes !\n";
                }
                break;
            }

            case 2: {
                cout << "\n--- STOCK DES PIECES ---\n";
                if (stock.empty()) {
                    cout << "Le stock est vide.\n";
                } else {
                    for (map<string, Piece>::const_iterator it = stock.begin(); it != stock.end();++it)
                    {
                        cout << it->second << '\n';
                    }
                }
                break;
            }

            case 0:
                break;

            default:
                cout << "Choix invalide, essayez encore.\n";
        }
    } while (choix != 0);
}

void menuClients(vector<Client>& clients) {
    int choix;
    do {
        cout << "\n-------- MENU CLIENTS --------\n";
        cout << "1. Ajouter un client\n";
        cout << "2. Afficher tous les clients\n";
        cout << "0. Retour\n";
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                Client c;
                cin >> c;
                clients.push_back(c);
                break;
            }
            case 2: {
                for (vector<Client>::const_iterator it = clients.begin(); it != clients.end(); ++it)
                    cout << *it << endl;
                break;
            }
            case 0:
                break;
            default:
                cout << "Choix invalide\n";
        }
    } while (choix != 0);
}

void menuVehicules(vector<Vehicule>& vehicules) {
    int choix;
    do {
        cout << "\n-------- MENU VEHICULES --------\n";
        cout << "1. Ajouter un vehicule\n";
        cout << "2. Afficher tous les vehicules\n";
        cout << "3. Afficher derniere reparation\n";
        cout << "0. Retour\n";
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                string type;
                cout << "Type de vehicule (voiture/moto) : ";
                cin >> type;
                if (type == "voiture") {
                    string isElectrique;
                    cout << "Est-ce une voiture electrique ? (oui/non) : ";
                    cin >> isElectrique;
                    if (isElectrique == "oui") {
                        VoitureElectrique* ve = new VoitureElectrique();
                        cin >> *ve;
                        vehicules.push_back(*ve);
                        cout << "Voiture electrique ajoutee !\n";
                    } else {
                        Voiture* v = new Voiture();
                        cin >> *v;
                        vehicules.push_back(*v);
                        cout << "Voiture ajoutee !\n";
                    }
                } else if (type == "moto") {
                    Moto m;
                    cin >> m;
                    vehicules.push_back(m);
                    cout << "Moto ajoutee !\n";
                } else {
                    cout << "Type inconnu.\n";
                }
                break;
            }
            case 2:
                for (int i = 0; i < vehicules.size(); ++i) {
                    cout << vehicules[i] << endl;
                }
                break;
            case 3: {
                int i;
                cout << "Selectionnez le vehicule (0 a " << vehicules.size() - 1 << ") : ";
                cin >> i;
                if (i >= 0 && i < vehicules.size()) {
                    vehicules[i].afficherDetails();
                } else {
                    cout << "Index invalide.\n";
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Choix invalide\n";
        }
    } while (choix != 0);
}

void menuFactures(vector<Facture>& factures) {
    int choix;
    do {
        cout << "\n-------- MENU FACTURES --------\n";
        cout << "1. Ajouter une facture\n";
        cout << "2. Afficher toutes les factures\n";
        cout << "0. Retour\n";
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                int idFacture;
                float montant;
                string statutPaiement;
                cout << "Entrez l'ID de la facture : ";
                while (!(cin >> idFacture)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "ID invalide. Veuillez entrer un entier : ";
                }

                bool existe_deja = false;
                for (const Facture& f : factures) {
                    if (f.getId() == idFacture) {
                        existe_deja = true;
                        break;
                    }
                }
                if (existe_deja) {
                    cout << "Erreur : Une facture avec cet ID existe deja." << endl;
                    break;
                }

                cout << "Entrez le montant de la facture : ";
                while (!(cin >> montant)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Montant invalide. Veuillez entrer un nombre : ";
                }
                cin.ignore(1000, '\n');
                cout << "Entrez le statut du paiement : ";
                getline(cin, statutPaiement);

                Facture facture(idFacture, montant, statutPaiement);
                factures.push_back(facture);
                cout << "Facture ajoutee avec succes !" << endl;
                break;
            }
            case 2:
                if (factures.empty()) {
                    cout << "Aucune facture dans la liste.\n";
                } else {
                    for (const Facture& f : factures) {
                        cout << f << endl;
                    }
                }
                break;
            case 0:
                break;
            default:
                cout << "Choix invalide.\n";
        }
    } while (choix != 0);
}

void menuReparations(vector<Vehicule>& vehicules) {
    if (vehicules.empty()) {
        cout << "Aucun vehicule disponible. Ajoutez d'abord un vehicule.\n";
        return;
    }

    int i;
    cout << "Selectionnez le vehicule (0 a " << vehicules.size() - 1 << ") : ";
    cin >> i;
    if (i < 0 || i >= vehicules.size()) {
        cout << "Index invalide\n";
        return;
    }
    int choix;
    do {
        cout << "\n-------- MENU REPARATIONS VEHICULE " << i << " --------\n";
        cout << "1. Ajouter une reparation\n";
        cout << "2. Afficher les reparations\n";
        cout << "0. Retour\n";
        cout << "Votre choix : ";
        cin >> choix;
        switch (choix) {
            case 1: {
                Reparation* r = new Reparation();
                cin >> *r;
                vehicules[i].ajouterReparation(r);
                break;
            }
            case 2:
                vehicules[i].afficherListeReparations();
                break;
            case 0:
                break;
            default:
                cout << "Choix invalide\n";
        }
    } while (choix != 0);
}

#include "Mecanicien.h"
#include "MecanicienSpecialiste.h"
#include <fstream>

vector<Mecanicien> mecaniciens;
vector<MecanicienSpecialiste> mecaniciensSpecialistes;

void menuMecanicien() {
    int choix;
    do {
        cout << "\n-------- Menu Mecanicien --------" << endl;
        cout << "1. Ajouter un mecanicien" << endl;
        cout << "2. Ajouter un mecanicien specialiste" << endl;
        cout << "3. Afficher les mecaniciens" << endl;
        cout << "4. Sauvegarder tous les mecaniciens" << endl;
        cout << "5. Charger les mecaniciens depuis le fichier" << endl;
        cout << "0. Retour\n ";
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                Mecanicien m("", "", "", 0);
                try {
                    cin >> m;
                    mecaniciens.push_back(m);
                } catch (const exception& e) {
                    cerr << "Erreur : " << e.what() << endl;
                }
                break;
            }
            case 2: {
                MecanicienSpecialiste ms("", "", "", 0, "");
                try {
                    cin >> ms;
                    mecaniciensSpecialistes.push_back(ms);
                } catch (const exception& e) {
                    cerr << "Erreur : " << e.what() << endl;
                }
                break;
            }
            case 3: {
                cout << "\n-- Mecaniciens --" << endl;
                for (int i = 0; i < mecaniciens.size(); ++i) {
                    cout << mecaniciens[i] << endl;
                }

                cout << "\n-- Mecaniciens specialistes --" << endl;
                for (int i = 0; i < mecaniciensSpecialistes.size(); ++i) {
                    cout << mecaniciensSpecialistes[i] << endl;
                }
                break;
            }
            case 4: {
                try {
                    for (int i = 0; i < mecaniciens.size(); ++i) {
                        mecaniciens[i].sauvegarderDansFichier("mecaniciens.txt");
                    }
                    cout << "Tous les mecaniciens ont ete sauvegardes dans mecaniciens.txt" << endl;
                } catch (const exception& e) {
                    cerr << "Erreur : " << e.what() << endl;
                }
                break;
            }
            case 5: {
                    Mecanicien::chargerTousLesMecaniciens("mecaniciens.txt", mecaniciens);
                    break;
            }            
            case 0:
                break;
            default:
                cout << "Choix invalide.\n";
        }
    } while (choix != 0);
}

void menuEmployes(vector<Employe>& employes) {
    int choix;
    do {
        cout << "\n--- MENU EMPLOYES ---\n";
        cout << "1. Ajouter un employe\n";
        cout << "2. Afficher tous les employes\n";
        cout << "3. Afficher le salaire d'un employe\n";
        cout << "0. Retour au menu principal\n";
        cout << "Votre choix : ";
        cin >> choix;
        switch (choix) {
            case 1: {
                Employe emp("", "", "", 0);
                cin >> emp;
                employes.push_back(emp);
                cout << "Employe ajoute avec succes !" << endl;
                break;
            }
            case 2: {
                for (int i = 0; i < employes.size(); ++i) {
                    cout << "Employe #" << i << ":\n" << employes[i] << endl;
                }
                break;
            }
            case 3: {
                int index;
                cout << "Entrez l'index de l'employe pour afficher son salaire : ";
                cin >> index;
                if (index >= 0 && index < employes.size()) {
                    employes[index].afficherSalaire();
                } else {
                    cout << "Index invalide." << endl;
                }
                break;
            }
            case 0:
                break;
            default:
                cout << "Choix invalide." << endl;
        }

    } while (choix != 0);
}

void menuGarage(Garage& garage)
{
    int choix;
    do {
        cout << "--------  MENU  GARAGE  --------\n"
             << "1. Ajouter un mecanicien\n"
             << "2. Ajouter un client\n"
             << "3. Afficher le nombre de clients\n"
             << "4. Afficher les mecaniciens\n"
             << "5. Afficher les clients\n"
             << "0. Retour au menu principal\n"
             << "Votre choix : ";
        cin >> choix;
        cin.ignore(1000, '\n');

        switch (choix)
        {
        case 1: {
            int typeChoisi = -1;
            while (typeChoisi != 0 && typeChoisi != 1) {
                cout << "\nMecanicien specialiste ?  (0 = non, 1 = oui) : ";
                if (!(cin >> typeChoisi)) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    typeChoisi = -1;
                }
            }
            cin.ignore(1000, '\n');

            if (typeChoisi == 0) {
                cout << "\n--- Saisie du mecanicien ---\n";
                Mecanicien m("","","",0);
                cin >> m;
                garage.ajouterMecanicien(new Mecanicien(m));
                cout << "Mecanicien ajoute avec succes !\n";
            } else {
                cout << "\n--- Saisie du mecanicien specialiste ---\n";
                MecanicienSpecialiste ms("","","",0,"");
                cin >> ms;
                garage.ajouterMecanicien(new MecanicienSpecialiste(ms));
                cout << "Mecanicien specialiste ajoute avec succes !\n";
            }
            break;
        }

        case 2: {
            cout << "\n--- Saisie du client ---\n";
            Client c("","","","");
            cin >> c;
            garage.ajouterClient(new Client(c));
            cout << "Client ajoute avec succes !\n";
            break;
        }

        case 3:
            Garage::afficherNombreClients();
            break;

        case 4: {
            const vector<Mecanicien*>& mecs = garage.obtenirMecaniciens();
            if (mecs.empty())
                cout << "Aucun mecanicien.\n";
            else
                for (int i = 0; i < mecs.size(); ++i)
                    cout << *mecs[i] << '\n';
            break;
        }

        case 5: {
            const vector<Client*>& cls = garage.obtenirClients();
            if (cls.empty())
                cout << "Aucun client.\n";
            else
                for (int i = 0; i < cls.size(); ++i)
                    cout << *cls[i] << '\n';
            break;
        }

        case 0:
            break;

        default:
            cout << "Choix invalide.\n";
            break;
        }
    } while (choix != 0);
}

vector<Voiture*> voitures;

void menuVoitures() {
    int choix;
    do {
        cout << "\n-------- Menu Voiture --------" << endl;
        cout << "1. Ajouter une voiture" << endl;
        cout << "2. Ajouter une voiture electrique" << endl;
        cout << "3. Afficher les voitures" << endl;
        cout << "4. Sauvegarder les voitures" << endl;
        cout << "5. Charger les voitures" << endl;
        cout << "0. Retour\nChoix : ";
        cin >> choix;

        switch (choix) {
            case 1: {
                Voiture* v = new Voiture();
                try {
                    cin >> *v;
                    voitures.push_back(v);
                } catch (const exception& e) {
                    cerr << "Erreur : " << e.what() << endl;
                    delete v;
                }
                break;
            }
            case 2: {
                VoitureElectrique* ve = new VoitureElectrique();
                try {
                    cin >> *ve;
                    voitures.push_back(ve);
                } catch (const exception& e) {
                    cerr << "Erreur : " << e.what() << endl;
                    delete ve;
                }
                break;
            }
            case 3: {
                cout << "\n-- Voitures --" << endl;
                for (int i = 0; i < voitures.size(); ++i) {
                    if (voitures[i]->getType() != "voitureelectrique") {
                        voitures[i]->afficherDetails();
                    }
                }
                cout << "////// Voitures electriques //////" << endl;
                for (int i = 0; i < voitures.size(); ++i) {
                    if (voitures[i]->getType() == "voitureelectrique") {
                        voitures[i]->afficherDetails();
                    }
                }
                break;
            }
            case 4: {
                cout << "Sauvegarde des voitures...\n";
                for (int i = 0; i < voitures.size(); ++i) {
                    voitures[i]->sauvegarderDansFichier(voitures[i]->getType() == "voiture" ? "voitures.txt" : "voitures_electriques.txt");
                }
                break;
            }
            case 5: {
                cout << "Chargement des voitures...\n";
                for (int i = 0; i < voitures.size(); ++i) {
                    delete voitures[i];
                }
                voitures.clear();

                Voiture::chargerDepuisFichier("voitures.txt", voitures);
                VoitureElectrique::chargerDepuisFichier("voitures_electriques.txt", voitures);
                break;
            }
            case 0:
                break;
            default:
                cout << "Choix invalide.\n";
        }
    } while (choix != 0);
}

int main() {
    map<string, Piece> stock;
    vector<Client> clients;
    vector<Vehicule> vehicules;
    vector<Employe> employes;
    vector<Facture> factures;
    Garage garage;
    int choix;
    do {
        cout << "\n-------- MENU PRINCIPAL --------\n";
        cout << "1. Gestion des pieces\n";
        cout << "2. Gestion des clients\n";
        cout << "3. Gestion des vehicules\n";
        cout << "4. Gestion des voitures\n";
        cout << "5. Gestion des reparations\n";
        cout << "6. Gestion des mecaniciens\n";
        cout << "7. Gestion des employes \n";
        cout << "8. Gestion des factures \n";
        cout << "9. Gestion du garage \n";
        cout << "0. Quitter\n";
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix) {
            case 1:
                menuPieces(stock);
                break;
            case 2:
                menuClients(clients);
                break;
            case 3:
                menuVehicules(vehicules);
                break;
            case 4:
                menuVoitures();
                break;
            case 5:
                menuReparations(vehicules);
                break;
            case 6:
                menuMecanicien();
                break;
            case 7:
                menuEmployes(employes);
                break;
            case 8:
                menuFactures(factures);
                break;
            case 9:
                menuGarage(garage);
                break;
            case 0:
                cout << "Fermeture du programme.\n";
                break;
            default:
                cout << "Choix invalide\n";
        }
    } while (choix != 0);

    for (int i = 0; i < voitures.size(); ++i) {
        delete voitures[i];
    }
    voitures.clear();

    return 0;
}
