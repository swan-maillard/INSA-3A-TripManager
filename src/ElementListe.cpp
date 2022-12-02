using namespace std;

#include <iostream>
#include <cstring>

#include "../include/ElementListe.h"
#include "../include/Trajet.h"


ElementListe::ElementListe (const Trajet & trajet) {
  #ifdef MAP
      cout << "Appel au constructeur de <ElementListe>" << endl;
  #endif

  this->trajet = trajet.copy();
  this->next = NULL;
}


void ElementListe::AddNext(ElementListe * element) {
  #ifdef MAP
      cout << "Appel au AddNext de <ElementListe>" << endl;
  #endif

  ElementListe * elementNext = element->next;
  while (elementNext != NULL)
    elementNext = elementNext->next;

  elementNext = this->next;
  this->next = element;
}


const Trajet* ElementListe::GetTrajet() const {
  #ifdef MAP
      cout << "Appel au GetTrajet de <ElementListe>" << endl;
  #endif

  return trajet;
}


ElementListe* ElementListe::GetNext() const {
  #ifdef MAP
      cout << "Appel au GetNext de <ElementListe>" << endl;
  #endif

  return next;
}


ElementListe::~ElementListe () {
  #ifdef MAP
      cout << "Appel au destructeur de <ElementListe>" << endl;
  #endif

  delete trajet;
}
