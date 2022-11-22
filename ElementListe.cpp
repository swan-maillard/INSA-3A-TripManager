/*************************************************************************
                           ElementListe  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ElementListe> (fichier ElementListe.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ElementListe.h"
#include "Trajet.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type ElementListe::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

ElementListe::ElementListe (Trajet & trajet) {
  #ifdef MAP
      cout << "Appel au constructeur de <ElementListe>" << endl;
  #endif

  this->trajet = &trajet;
  this->next = NULL;

}

void ElementListe::AddNext(ElementListe * element) {
  #ifdef MAP
      cout << "Appel au AddNext de <ElementListe>" << endl;
  #endif

  element->next = this->next;
  this->next = element;
}

Trajet* ElementListe::getTrajet() const {
  #ifdef MAP
      cout << "Appel au getTrajet de <ElementListe>" << endl;
  #endif

  return trajet;
}

ElementListe* ElementListe::getNext() const {
  #ifdef MAP
      cout << "Appel au getNext de <ElementListe>" << endl;
  #endif

  return next;
}


ElementListe::~ElementListe ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <ElementListe>" << endl;
#endif
} //----- Fin de ~ElementListe


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
