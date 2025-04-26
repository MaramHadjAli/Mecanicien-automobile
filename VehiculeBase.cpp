#include "VehiculeBase.h"
#include <iostream>
using namespace std;

VehiculeBase::VehiculeBase(string i, string m, string mod, int a, string t)
    : imma(i), marque(m), modele(mod), annee(a), type(t) {}

VehiculeBase::VehiculeBase() : imma(""), marque(""), modele(""), annee(0), type("") {}

void VehiculeBase::afficherDetails() {}

VehiculeBase::~VehiculeBase() {}
