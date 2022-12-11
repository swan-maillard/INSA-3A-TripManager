/*************************************************************************
    Iterator  -  Permet d'itérer sur les maillons des listes chainées TripList
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <Iterator> (fichier Iterator.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//-------------------------------------------------------- Include personnel
#include "../include/Iterator.h"


//----------------------------------------------------------------- PUBLIC

Iterator::Iterator(const ElementTripList * element) {
  #ifdef MAP
      cout << "Construction de <Iterator>" << endl;
  #endif

  currentElement = element;
}


Iterator::~Iterator() {
  #ifdef MAP
      cout << "Destruction de <Iterator>" << endl;
  #endif
}

const Trip * Iterator::Next() {
  #ifdef MAP
      cout << "Exécution de Next de <Iterator>" << endl;
  #endif

  const Trip * currentTrip = NULL;

  if (currentElement != NULL) {
    currentTrip = currentElement->GetTrip();
    currentElement = currentElement->GetNext();
  }

  return currentTrip;
}
