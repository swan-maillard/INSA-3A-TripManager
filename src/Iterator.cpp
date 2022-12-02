using namespace std;

#include <iostream>
#include <cstring>

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

const Trajet * Iterator::Next() {
  const Trajet * currentTrajet = NULL;

  if (currentElement != NULL) {
    currentTrajet = currentElement->GetTrajet();
    currentElement = currentElement->GetNext();
  }

  return currentTrajet;
}
