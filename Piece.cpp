#include "Piece.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

Piece::Piece() : reference_piece(""), nom(""), prix(0.0f), stock(0) {}
Piece::Piece(string r, string n, float p, int s) : reference_piece(r), nom(n), prix(p), stock(s) {}

string Piece::getReference() const { return reference_piece; }

Piece Piece::operator+(const Piece& p) const {
    return Piece(reference_piece, nom, prix, stock + p.stock);
}

Piece Piece::operator-(int q) const {
    if (q > stock) throw runtime_error("Quantite a retirer superieure au stock disponible.");
    return Piece(reference_piece, nom, prix, stock - q);
}

ostream& operator<<(ostream& out, const Piece& p) {
    out << "Reference : " << p.reference_piece << " | "
        << "Nom : " << p.nom << " | "
        << "Prix : " << p.prix << " | "
        << "Quantite : " << p.stock;
    return out;
}

istream& operator>>(istream& in, Piece& p) {
    in >> p.reference_piece >> p.nom >> p.prix >> p.stock;
    return in;
}

void Piece::ajouterPiece(map<string, Piece>& stock)
{
    if (stock.find(reference_piece) != stock.end()) {
        cout << "Piece deja existante.\n";
        return;
    }
    stock[reference_piece] = *this;
    cout << "Piece ajoutee avec succes !\n";
}
