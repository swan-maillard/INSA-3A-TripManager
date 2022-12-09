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

ElementListe::ElementListe(const ElementListe * element) {
  #ifdef MAP
      cout << "Appel au constructeur de copie <ElementListe>" << endl;
  #endif

  this->trajet = element->trajet->copy();

  this->next = (element->next == NULL ? NULL : new ElementListe(element->next));
}

void ElementListe::AddNext(ElementListe * element) {
  ElementListe * elementNext = element->next;
  while (elementNext != NULL)
    elementNext = elementNext->next;

  elementNext = this->next;
  this->next = element;
}


const Trajet* ElementListe::GetTrajet() const {
  return trajet;
}


ElementListe* ElementListe::GetNext() const {
  return next;
}


ElementListe::~ElementListe () {
  #ifdef MAP
      cout << "Appel au destructeur de <ElementListe>" << endl;
  #endif

  delete trajet;
}
