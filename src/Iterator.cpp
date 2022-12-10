using namespace std;

#include <iostream>
#include <cstring>

#include "../include/Iterator.h"


Iterator::Iterator(const ElementTripList * element) {
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

const Trip * Iterator::Next() {
  const Trip * currentTrip = NULL;

  if (currentElement != NULL) {
    currentTrip = currentElement->GetTrip();
    currentElement = currentElement->GetNext();
  }

  return currentTrip;
}
