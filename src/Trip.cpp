/*************************************************************************
    Trip  -  Classe abstraite représentant un trajet pouvant être simple ou composé
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Trip> (fichier Trip.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//-------------------------------------------------------- Include personnel
#include "../include/Trip.h"


//----------------------------------------------------------------- PUBLIC

Trip::Trip() {
  #ifdef MAP
      cout << "Construction de <Trip>" << endl;
  #endif
}

Trip::~Trip() {
#ifdef MAP
    cout << "Destruction de <Trip>" << endl;
#endif
}
