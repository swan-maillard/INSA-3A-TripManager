using namespace std;

#include <iostream>
#include <cstring>

#include "../include/ElementTripList.h"
#include "../include/Trip.h"


ElementTripList::ElementTripList (const Trip & trip) {
  #ifdef MAP
      cout << "Appel au constructeur de <ElementTripList>" << endl;
  #endif

  this->trip = trip.Copy();
  this->next = NULL;
}

ElementTripList::ElementTripList(const ElementTripList & element) {
  #ifdef MAP
      cout << "Appel au constructeur de copie <ElementTripList>" << endl;
  #endif

  this->trip = element.trip->Copy();

  this->next = (element.next == NULL ? NULL : new ElementTripList(*element.next));
}

void ElementTripList::AddNext(ElementTripList * element) {
  ElementTripList * elementNext = element->next;
  while (elementNext != NULL)
    elementNext = elementNext->next;

  elementNext = this->next;
  this->next = element;
}


const Trip* ElementTripList::GetTrip() const {
  return trip;
}


ElementTripList* ElementTripList::GetNext() const {
  return next;
}


ElementTripList::~ElementTripList () {
  #ifdef MAP
      cout << "Appel au destructeur de <ElementTripList>" << endl;
  #endif

  delete trip;
}
