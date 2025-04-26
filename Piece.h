#ifndef PIECE_H
#define PIECE_H
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

class Piece {
    string reference_piece;
    string nom;
    float prix;
    int stock;
public:
    Piece();
    Piece(string r, string n, float p, int s);
    string getReference() const;
    Piece operator+(const Piece& p) const;
    Piece operator-(int q) const;
    friend ostream& operator<<(ostream& out, const Piece& p);
    friend istream& operator>>(istream& in, Piece& p);
    void ajouterPiece(map<string, Piece>& stock);

};

#endif // PIECE_H
