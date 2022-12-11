/*************************************************************************
    ElementTripList  -  Maillon de la liste chainée TripList, contenant un trajet
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <ElementTripList> (fichier ElementTripList.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//-------------------------------------------------------- Include personnel
#include "../include/ElementTripList.h"
#include "../include/Trip.h"


//----------------------------------------------------------------- PUBLIC

ElementTripList::ElementTripList (const Trip & trip) {
  #ifdef MAP
      cout << "Construction de <ElementTripList>" << endl;
  #endif

  this->trip = trip.Copy();
  this->next = NULL;
}

ElementTripList::ElementTripList(const ElementTripList & element) {
  #ifdef MAP
      cout << "Construction par copie de <ElementTripList>" << endl;
  #endif

  this->trip = element.trip->Copy();

  this->next = (element.next == NULL ? NULL : new ElementTripList(*element.next));
}

ElementTripList::~ElementTripList () {
  #ifdef MAP
      cout << "Destruction de <ElementTripList>" << endl;
  #endif

  delete trip;
}

void ElementTripList::AddNext(ElementTripList * element) {
  #ifdef MAP
      cout << "Exécution de AddNext de <ElementTripList>" << endl;
  #endif

  ElementTripList * elementNext = element->next;
  while (elementNext != NULL)
    elementNext = elementNext->next;

  elementNext = this->next;
  this->next = element;
}


const Trip* ElementTripList::GetTrip() const {
  #ifdef MAP
      cout << "Exécution de GetTrip de <ElementTripList>" << endl;
  #endif

  return trip;
}


ElementTripList* ElementTripList::GetNext() const {
  #ifdef MAP
      cout << "Exécution de GetNext de <ElementTripList>" << endl;
  #endif

  return next;
}