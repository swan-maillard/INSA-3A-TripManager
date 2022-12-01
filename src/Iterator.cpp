/*************************************************************************
                           Iterator  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Iterator> (fichier Iterator.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "../include/Iterator.h"


Iterator::Iterator(const ElementListe * element) {
  #ifdef MAP
      cout << "Appel au constructeur de <Iterator>" << endl;
  #endif

  currentElement = element;
}


Iterator::~Iterator() {
  #ifdef MAP
      cout << "Appel au destructeur de <Iterator>" << endl;
  #endif
}

Trajet * Iterator::Next() {
  Trajet * currentTrajet = NULL;

  if (currentElement != NULL) {
    currentTrajet = currentElement->getTrajet();
    currentElement = currentElement->getNext();
  }

  return currentTrajet;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
