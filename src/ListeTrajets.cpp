/*************************************************************************
                           ListeTrajets  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <ListeTrajets> (fichier ListeTrajets.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "ListeTrajets.h"
#include "ElementListe.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

//-------------------------------------------- Constructeurs - destructeur


ListeTrajets::ListeTrajets () {
  #ifdef MAP
      cout << "Appel au constructeur de <ListeTrajets>" << endl;
  #endif

  size = 0;
  start = NULL;
  end = NULL;
}


ListeTrajets::~ListeTrajets () {
  #ifdef MAP
      cout << "Appel au destructeur de <ListeTrajets>" << endl;
  #endif

  ElementListe * currentElement = start;
  while (currentElement != NULL) {
    ElementListe * next = currentElement->getNext();
    delete currentElement;
    currentElement = next;
  }
} //----- Fin de ~ListeTrajets

void ListeTrajets::AddTrajetQueue(Trajet & trajet) {
  #ifdef MAP
      cout << "Appel au AddTrajetQueue de <ListeTrajets>" << endl;
  #endif

  ElementListe * newElement = new ElementListe(trajet);
  if (start == NULL)
    start = end = newElement;
  else {
    end->AddNext(newElement);
    end = newElement;
  }

  size++;
}

void ListeTrajets::AddTrajetAlpha(Trajet & trajet) {
  #ifdef MAP
      cout << "Appel au AddTrajetAlpha de <ListeTrajets>" << endl;
  #endif

  ElementListe * newElement = new ElementListe(trajet);
  if (start == NULL) {
    start = end = newElement;
  }
  else if (strcmp(trajet.getEnd(), start->getTrajet()->getEnd()) < 0) {
    newElement->AddNext(start);
    start = newElement;
  }
  else if (strcmp(trajet.getEnd(), end->getTrajet()->getEnd()) >= 0) {
    end->AddNext(newElement);
    end = newElement;
  }
  else {
    ElementListe * previousElement = start;
    ElementListe * currentElement = start->getNext();
    while (strcmp(trajet.getEnd(), currentElement->getTrajet()->getEnd()) >= 0) {
      previousElement = currentElement;
      currentElement = currentElement->getNext();
    }
    newElement->AddNext(currentElement);
    previousElement->AddNext(newElement);
  }

  size++;
}

ElementListe * ListeTrajets::GetStart() {
  #ifdef MAP
      cout << "Appel au GetStart de <ListeTrajets>" << endl;
  #endif

  return start;
}

ElementListe * ListeTrajets::GetEnd() {
  #ifdef MAP
      cout << "Appel au GetEnd de <ListeTrajets>" << endl;
  #endif

  return end;
}

int ListeTrajets::GetSize() {
  #ifdef MAP
      cout << "Appel au GetSize de <ListeTrajets>" << endl;
  #endif

  return size;
}


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
