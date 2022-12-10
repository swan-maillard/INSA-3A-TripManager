using namespace std;

#include <iostream>
#include <cstring>

#include "../include/TripList.h"
#include "../include/ElementTripList.h"
#include "../include/Trip.h"
#include "../include/Iterator.h"

TripList::TripList() {
  #ifdef MAP
      cout << "Appel au constructeur de <TripList>" << endl;
  #endif

  size = 0;
  firstElem = lastElem= NULL;
}

TripList::TripList(const TripList & tripList) {
  #ifdef MAP
      cout << "Appel au constructeur de copie <TripList>" << endl;
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
      cout << "Appel au destructeur de <TripList>" << endl;
  #endif

  ElementTripList * currentElement = firstElem;
  while (currentElement != NULL) {
    ElementTripList * next = currentElement->GetNext();
    delete currentElement;
    currentElement = next;
  }
}


void TripList::AddTripInQueue(const Trip & trip) {
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
  ElementTripList * newElement = new ElementTripList(trip);

  if (firstElem == NULL) {
    firstElem = lastElem = newElement;
  }
  else if (strcmp(trip.GetFinishCity(), GetFirstTrip()->GetFinishCity()) < 0) {
    newElement->AddNext(firstElem);
    firstElem = newElement;
  }
  else if (strcmp(trip.GetFinishCity(), GetLastTrip()->GetFinishCity()) >= 0) {
    lastElem->AddNext(newElement);
    lastElem = newElement;
  }
  else {
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
  if (firstElem == NULL)
    return NULL;

  return firstElem->GetTrip();
}


const Trip * TripList::GetLastTrip() const {
  if (lastElem == NULL)
    return NULL;

  return lastElem->GetTrip();
}


int TripList::GetListSize() const {
  return size;
}


Iterator * TripList::CreateIterator() const {
  Iterator * iterator = new Iterator(firstElem);
  return iterator;
}
