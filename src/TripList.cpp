/*************************************************************************
    TripList  -  Liste chainée contenant des trajets.
                 Ses maillons sont de type ElementTripList
                             -------------------
    début                : 13/12/2022
    copyright            : (C) 2022 par MALARD Sarah & MAILLARD Swan
    e-mail               : sarah.malard@insa-lyon.fr & swan.maillard@insa-lyon.fr
*************************************************************************/


//---------- Réalisation de la classe <TripList> (fichier TripList.cpp) ------------


//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <cstring>

//-------------------------------------------------------- Include personnel
#include "../include/TripList.h"
#include "../include/ElementTripList.h"
#include "../include/Trip.h"
#include "../include/Iterator.h"


//----------------------------------------------------------------- PUBLIC

TripList::TripList() {
  #ifdef MAP
      cout << "Construction de <TripList>" << endl;
  #endif

  size = 0;
  firstElem = lastElem= NULL;
}

TripList::TripList(const TripList & tripList) {
  #ifdef MAP
      cout << "Construction par copie de <TripList>" << endl;
  #endif

  size = tripList.size;

  if (tripList.firstElem == NULL) {
    firstElem = lastElem = NULL;
  }
  else {
    firstElem = new ElementTripList(*tripList.firstElem);
    if (tripList.firstElem == tripList.lastElem)
      firstElem = lastElem;
    else
      lastElem = new ElementTripList(*tripList.lastElem);
  }
}


TripList::~TripList() {
  #ifdef MAP
      cout << "Destruction de <TripList>" << endl;
  #endif

  ElementTripList * currentElement = firstElem;
  while (currentElement != NULL) {
    ElementTripList * next = currentElement->GetNext();
    delete currentElement;
    currentElement = next;
  }
}


void TripList::AddTripInQueue(const Trip & trip) {
  #ifdef MAP
      cout << "Exécution de AddtripInQueue de <TripList>" << endl;
  #endif

  ElementTripList * newElement = new ElementTripList(trip);

  if (firstElem == NULL) {
    firstElem = lastElem = newElement;
  }
  else {
    lastElem->AddNext(newElement);
    lastElem = newElement;
  }

  size++;
}


void TripList::AddTripAlpha(const Trip & trip) {
  #ifdef MAP
      cout << "Exécution de AddTripAlpha de <TripList>" << endl;
  #endif

  ElementTripList * newElement = new ElementTripList(trip);

  if (firstElem == NULL) {
    // La liste est vide
    firstElem = lastElem = newElement;
  }
  else if (strcmp(trip.GetFinishCity(), GetFirstTrip()->GetFinishCity()) < 0) {
    // Le nouveau trajet s'insère en tête
    newElement->AddNext(firstElem);
    firstElem = newElement;
  }
  else if (strcmp(trip.GetFinishCity(), GetLastTrip()->GetFinishCity()) >= 0) {
    // Le nouveau trajet s'insère en queue
    lastElem->AddNext(newElement);
    lastElem = newElement;
  }
  else {
    // On cherche où le trajet doit s'insérer en comparant les noms des villes d'arrivées
    ElementTripList * previousElement = firstElem;
    ElementTripList * currentElement = firstElem->GetNext();
    while (strcmp(trip.GetFinishCity(), currentElement->GetTrip()->GetFinishCity()) >= 0) {
      previousElement = currentElement;
      currentElement = currentElement->GetNext();
    }
    newElement->AddNext(currentElement);
    previousElement->AddNext(newElement);
  }

  size++;
}


const Trip * TripList::GetFirstTrip() const {
  #ifdef MAP
      cout << "Exécution de GetFirstTrip de <TripList>" << endl;
  #endif

  if (firstElem == NULL)
    return NULL;

  return firstElem->GetTrip();
}


const Trip * TripList::GetLastTrip() const {
  #ifdef MAP
      cout << "Exécution de GetLastTrip de <TripList>" << endl;
  #endif

  if (lastElem == NULL)
    return NULL;

  return lastElem->GetTrip();
}


int TripList::GetListSize() const {
  #ifdef MAP
      cout << "Exécution de GetListSize de <TripList>" << endl;
  #endif

  return size;
}


Iterator * TripList::CreateIterator() const {
  #ifdef MAP
      cout << "Exécution de CreateIterator de <TripList>" << endl;
  #endif

  Iterator * iterator = new Iterator(firstElem);
  return iterator;
}
